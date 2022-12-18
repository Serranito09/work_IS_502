#include "curso.h"
#include "persona.h"
#include <vector>
#include <string>
#include "bd.h"

using namespace std;

void BD::menu(vector<Curso> *curso,vector<Persona> *persona)
{
     string Dni;
     Persona p1;
     int opcion,tecla;
     bool repetir=true;
     do{
    cout << "CURSOS DE EXTENSIÓN" << endl;
    cout<<"1--->LOGIN\n";
    cout<<"2--->VISITANTE\n";
    cout<<"3--->SALIR DEL SISTEMA\n";
    cin>>opcion;
    system("clear");

    switch (opcion)
    {
    case 1:
     cout << "CURSOS DE EXTENSIÓN---LOGIN" << endl;
     login(persona,curso);
     cout<<"0---SALIR\n";
     cin>>tecla;
     system("clear");
      
      break;
    
    case 2:
    cout << "CURSOS DE EXTENSIÓN---MODO VISITANTE" << endl;
     menu_visitante(curso,persona);
     system("clear");
     break;
    case 0:
     repetir=false;
    default:
      opcion=0;
      break;

    }
    }while(repetir);
}
    



  void BD::login(vector<Persona> *persona,vector<Curso>*curso){
    string Dni;
    Persona p1;
    cout << "\nIngrese su Dni: ";
    cin >> Dni;
    int rol;
    if ((p1.ComprobarDni(Dni,*persona) == false))
    {
        for (int i = 0; i < 99; i++)
        {
            if ((p1.ComprobarDni(Dni,*persona)) == false)
            {
                cout << "Este DNI no esta registrado, introduzca un Dni registrado,en caso de no estar registrado contacte con el administrador: \n";
                cin >> Dni;
            }
        }
    }
    else
    {
        rol=p1.ComprobarRol(Dni,(persona));
    }
    system("clear");


    if(rol==1){
      cout << "CURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n";
      menu_administrador(curso,persona);
    }

    if(rol==2){
      cout << "CURSOS DE EXTENSIÓN---MODO PARTICIPANTE\n";
      menu_participante(curso,persona);
    }

   if(rol==3){
      cout << "CURSOS DE EXTENSIÓN---MODO COORDINADOR DE CURSO\n";
      menu_coordinador_de_cursos(curso,persona);
   }
    

   if(rol==4){
      cout << "CURSOS DE EXTENSIÓN---MODO COORDINADOR DE RECURSOS\n";
      menu_coordinador_de_recursos(curso,persona);
   }
   if(rol==0){
    cout<<"ERROR\n";
   }

    }

// MENU DEL ADMINISTRADOR
void BD::menu_administrador(vector<Curso> *curso, vector<Persona> *persona)
{

  int tecla;
  int opcion;
  int modificar;
  string modificarp;
  bool repetir = true;
  do
  {
     cout << "CURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n";
    cout << "1.VER CURSOS" << endl;
    cout << "2.AÑADIR CURSOS" << endl;
    cout << "3.ELIMINAR CURSOS" << endl;
    cout << "4.MODIFICAR CURSOS" << endl;
    cout << "5.VER PARTICIPANTES" << endl;
    cout << "6.AÑADIR PARTICIPANTE" << endl;
    cout << "7.MODIFICAR PARTICIPANTE" << endl;
    cout << "8.ELIMINAR PARTICIPANTE" << endl;
    cout << "0.SALIR" << endl;

    cout << "\nIngrese una opcion: ";
    cin >> opcion;
    system("clear");

    switch (opcion)
    {
    case 1:
      cout << "CURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n"
           << endl;
      // FUNCIÓN DE MOSTRAR CURSOS
      mostrarCursos(curso);
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 2:
      cout << "CURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n"
           << endl;
      // FUNCIÓN AÑADIR CURSOS
      insertarCurso(curso);
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 3:
      cout << "CURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n"
           << endl;
      cout << "Introduzca la id del curso que desea eliminar: \n";
      cin >> modificar;
     
      // FUNCIÓN ELIMINAR CURSOS
      if (eliminar(modificar,curso) == true)
      {
        cout << "Ha sido eliminado con éxito\n\n";
      }
      else
      {
        cout << "No ha podido eliminarse el curso,debido a que no existe\n";
      }
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 4:
      cout << "CURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n"
           << endl;
      // FUNCIÓN MODIFICAR CURSOS
      cout << "Introduzca la id del curso que desea modificar: \n";
      cin >> modificar;
       if (modificarCursos(modificar,curso) == true)
      {
        cout << "Ha sido modificado con éxito\n\n";
      }
      else
      {
        cout << "No ha podido modificarse el curso,debido a que no existe\n";
      }
      cout << "0.VOLVER AL MENÚ" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 5:
      cout << "CURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n"
           << endl;
      // FUNCIÓN DE MOSTRAR PARTICIPANTES
      mostrarParticipantes(persona);
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 6:
      cout << "CURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n"
           << endl;
      // FUNCIÓN DE AÑADIR PARTICIPANTES

      insertarParticipante(persona,curso);
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;
    case 7:
      cout << "CURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n"
           << endl;
      // FUNCIÓN DE MODIFICAR PARTICIPANTES
      cout << "Introduzca el dni del participante que desea modificar: \n";
      cin >> modificarp;
      modificarParticipante(modificarp,persona,curso);
      cout << "0.VOLVER AL MENÚ" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 8:
      cout << "CURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n"
           << endl;
      cout << "Introduzca el dni del participante que desea eliminar: \n";
      cin >> modificarp;
      //FUNCIÓN ELIMINAR PARTICIPANTES
      
      if (eliminarP(modificarp,persona) == true)
      {
        cout << "Ha sido eliminado con éxito\n\n";
      }
      else
      {
        cout << "No ha podido eliminarse el participante\n";
      }
      
      
      cout << "0.VOLVER AL MENÚ" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 0:
      repetir = false;
      break;
    }

  } while (repetir);
}

// MENU PARTICIPANTE
void BD::menu_participante(vector<Curso> *curso, vector<Persona> *persona)
{
  int id;
  string Dni;
  int tecla;
  int opcion;
  int modificar;
  bool repetir = true;
  do
  {
    cout << "1.VER CURSOS" << endl;
    cout << "2.INSCRIPCIÓN EN CURSOS" << endl;
    cout << "3.CONTACTO" << endl;
    cout << "4.VER CURSOS EN LOS QUE ESTOY INSCRITO\n";
    cout << "0.SALIR" << endl;

    cout << "\nIngrese una opcion: ";
    cin >> opcion;
    system("clear");

    switch (opcion)
    {
    case 1:
      cout << "CURSOS DE EXTENSIÓN---MODO PARTICIPANTE\n"
           << endl;
      // FUNCIÓN DE MOSTRAR CURSOS
      mostrarCursos(curso);
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 2:
      cout << "CURSOS DE EXTENSIÓN---MODO PARTICIPANTE\n"
           << endl;
      // FUNCIÓN INSCRIPCIÓN EN CURSOS
      cout << "Introduzca su DNI:\n";
      cin >> Dni;
      cout << "Introduzca el id del curso desea inscribirse\n ";
      cin >> id;
      if (inscribirseCurso(id, Dni,curso,persona) == true)
      {
        cout << "Ha sido inscrito con éxito\n\n";
      }
      else
      {
        cout << "No ha podido inscribirse en el curso\n";
      }
      cout << "0.VOLVER AL MENÚ" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 3:
      // FUNCIÓN CONTACTO ADMINISTRADOR
      cout << "CURSOS DE EXTENSIÓN---MODO PARTICIPANTE\n"
           << endl;
      cout << "Álvaro David Serrano López" << endl;
      cout << "i12seloa@uco.es" << endl;
      cout << "0. SALIR" << endl;
      cin >> tecla;
      system("clear");
      break;

    case 4:
      cout << "CURSOS DE EXTENSIÓN---MODO PARTICIPANTE\n"
           << endl;
      // FUNCIÓN VER CURSO INSCRITO
      cout << "Introduzca su DNI: \n";
      cin >> Dni;
      mostrarCaP(Dni,curso,persona);
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 0:
      repetir = false;
      break;
    }

  } while (repetir);
}

// MENU VISITANTE
void BD::menu_visitante(vector<Curso> *curso, vector<Persona> *persona)
{
  int tecla;
  int opcion;
  int modificar;
  bool repetir = true;
  do
  {

    cout << "1.VER CURSOS" << endl;
    cout << "2.CONTACTO" << endl;
    cout << "0.SALIR" << endl;

    cout << "\nIngrese una opcion: ";
    cin >> opcion;
    system("clear");

    switch (opcion)
    {
    case 1:
      cout << "CURSOS DE EXTENSIÓN---MODO VISITANTE\n"
           << endl;
      // FUNCIÓN DE MOSTRAR CURSOS
      mostrarCursos(curso);
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 2:
      // FUNCIÓN CONTACTO ADMINISTRADOR
      cout << "CURSOS DE EXTENSIÓN---MODO VISITANTE\n"
           << endl;
      cout << "Álvaro David Serrano López" << endl;
      cout << "i12seloa@uco.es" << endl;
      cout << "0. SALIR" << endl;
      cin >> tecla;
      system("clear");
      break;

    case 0:
      repetir = false;
      break;
    }

  } while (repetir);
}

// MENU CC
void BD::menu_coordinador_de_cursos(vector<Curso> *curso, vector<Persona> *persona)
{
  int id;
  int tecla;
  int opcion;
  int modificar;
  bool repetir = true;
  do
  {
    cout << "1.VER CURSOS" << endl;
    cout << "2.AÑADIR CURSO" << endl;
    cout << "3.ELIMINAR CURSO" << endl;
    cout << "4.MODIFICAR CURSO" << endl;
    cout << "5.VER PARTICIPANTES DE TU CURSO" << endl;
    cout << "6.CONTACTO" << endl;
    cout << "0.SALIR" << endl;

    cout << "\nIngrese una opcion: ";
    cin >> opcion;
    system("clear");

    switch (opcion)
    {
    case 1:
      cout << "CURSOS DE EXTENSIÓN---MODO COORDINADOR DE CURSOS\n";
      // FUNCIÓN DE MOSTRAR CURSOS
      mostrarCursos(curso);
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 2:
      cout << "CURSOS DE EXTENSIÓN---MODO COORDINADOR DE CURSO\n";
      // FUNCIÓN DE AÑADIR CURSOS
      insertarCurso(curso);
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 3:
      cout << "CURSOS DE EXTENSIÓN---MODO COORDINADOR DE CURSO\n\n";
      cout << "Introduzca la id del curso que desea eliminar: \n";
      cin >> modificar;
      // FUNCIÓN ELIMINAR CURSOS
      if (eliminar(modificar,curso) == true)
      {
        cout << "Ha sido eliminado con éxito\n\n";
      }
      else
      {
        cout << "No ha podido eliminarse el curso,debido a que no existe \n";
      }
      cout << "0. VOLVER AL MENÚ" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 4:
      cout<<"CURSOS DE EXTENSIÓN---MODO COORDINADOR DE CURSO\n"
           << endl;
      // FUNCIÓN MODIFICAR CURSOS
      cout << "Introduzca la id del curso que desea modificar: \n";
      cin >> modificar;
           if (modificarCursos(modificar,curso) == true)
      {
        cout << "Ha sido modificado con éxito\n\n";
      }
      else
      {
        cout << "No ha podido modificarse el curso,debido a que no existe\n";
      }
      cout << "0.VOLVER AL MENÚ" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 5:
      cout << "CURSOS DE EXTENSIÓN---MODO COORDINADOR DE CURSO\n"
           << endl;
      // FUNCIÓN MOSTRAR ALUMNOS DE UN CURSO
      cout << "Introduzca el id del curso del que desea ver los participantes: \n";
      cin >> id;
      mostrarCP(id,curso,persona);
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 6:
      // FUNCIÓN CONTACTO ADMINISTRADOR
      cout << "CURSOS DE EXTENSIÓN---MODO COORDINADOR DE CURSO\n"
           << endl;
      cout << "Álvaro David Serrano López" << endl;
      cout << "i12seloa@uco.es" << endl;
      cout << "0. SALIR" << endl;
      cin >> tecla;
      system("clear");
      break;

    case 0:
      repetir = false;
      break;
    }
  } while (repetir);
}

// MENU CR
void BD::menu_coordinador_de_recursos(vector<Curso> *curso, vector<Persona> *persona)
{

  int tecla;
  int opcion;
  int modificar;
  bool repetir = true;
  do
  {
    cout << "1.VER CURSOS" << endl;
    cout << "2.ASIGNAR RECURSOS" << endl;
    cout << "3.CONTACTO" << endl;
    cout << "0.SALIR" << endl;

    cout << "\nIngrese una opcion: ";
    cin >> opcion;
    system("clear");

    switch (opcion)
    {
    case 1:
      cout << "CURSOS DE EXTENSIÓN---MODO COORDINADOR DE RECURSOS\n"
           << endl;
      // FUNCIÓN DE MOSTRAR CURSOS
      mostrarCursos(curso);
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 2:
      cout << "CURSOS DE EXTENSIÓN---MODO COORDINADOR DE RECURSOS\n"
           << endl;
      // FUNCIÓN ASIGNAR RECURSOS
      cout << "Introduzca la id del curso al que desea asignar recursos: \n";
      cin >> modificar;
           if (modificarR(modificar,curso) == true)
      {
        cout << "Ha sido modificado con éxito\n\n";
      }
      else
      {
        cout << "No ha podido modificarse el recurso, debido a que no existe un curso con esa id\n";
      }
      cout << "0.VOLVER AL MENÚ" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 3:
      // FUNCIÓN CONTACTO ADMINISTRADOR
      cout << "CURSOS DE EXTENSIÓN---MODO COORDINADOR DE RECURSOS\n"
           << endl;
      cout << "Álvaro David Serrano López" << endl;
      cout << "i12seloa@uco.es" << endl;
      cout << "0. SALIR" << endl;
      cin >> tecla;
      system("clear");
      break;

    case 0:
      repetir = false;
      break;
    }
  } while (repetir);
}


