#include "curso.h"
#include "persona.h"
#include <vector>
#include <string>
#include "bd.h"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[39m"
#define ANSI_COLOR_GREEN "\x1b[32m"

using namespace std;

void BD::menu(vector<Curso> *curso, vector<Persona> *persona)
{
  string Dni;
  Persona p1;
  int opcion, tecla;
  bool repetir = true;
  do
  {

    std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "1.LOGIN\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "2.VISITANTE\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "0.SALIR\n" ANSI_COLOR_RESET;
    cin >> opcion;
    system("clear");

    switch (opcion)
    {
    case 1:
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---LOGIN\n" ANSI_COLOR_RESET;
      login(persona, curso);
      std::cout << ANSI_COLOR_GREEN "0.SALIR\n" ANSI_COLOR_RESET;
      cin >> tecla;
      system("clear");

      break;

    case 2:
      menu_visitante(curso, persona);
      system("clear");
      break;
    case 0:
      repetir = false;
    default:
      opcion = 0;
      break;
    }
  } while (repetir);
}

void BD::login(vector<Persona> *persona, vector<Curso> *curso)
{
  string Dni;
  Persona p1;
  cout << "\nIngrese su Dni: ";
  cin >> Dni;
  int rol;
  if ((p1.ComprobarDni(Dni, *persona) == false))
  {
    for (int i = 0; i < 99; i++)
    {
      if ((p1.ComprobarDni(Dni, *persona)) == false)
      {
        cout << "Este DNI no esta registrado, introduzca un Dni registrado,en caso de no estar registrado contacte con el administrador: \n";
        cin >> Dni;
      }
      else
      {
        rol = p1.ComprobarRol(Dni, (persona));
      }
    }
  }
else
{
  rol = p1.ComprobarRol(Dni, (persona));
}
system("clear");

if (rol == 1)
{
  menu_administrador(curso, persona);
}

if (rol == 2)
{

  menu_participante(curso, persona);
}

if (rol == 3)
{

  menu_coordinador_de_cursos(curso, persona);
}

if (rol == 4)
{

  menu_coordinador_de_recursos(curso, persona);
}
if (rol == 0)
{
  cout << "ERROR\n";
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
    std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO ADMINISTRADOR\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "1.VER CURSOS\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "2-.AÑADIR CURSOS\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "3.ELIMINAR CURSOS\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "4.MODIFICAR CURSOS\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "5.VER PARTICIPANTES\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "6.AÑADIR PARTICIPANTES\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "7.MODIFICAR PARTICIPANTES\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "8.ELIMINAR PARTICIPANTES\n" ANSI_COLOR_RESET;

    std::cout << ANSI_COLOR_GREEN "0.SALIR\n" ANSI_COLOR_RESET;

    cout << "\nIngrese una opcion: ";
    cin >> opcion;
    system("clear");

    switch (opcion)
    {
    case 1:
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO ADMINISTRADOR\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN DE MOSTRAR CURSOS
      mostrarCursos(curso);
      std::cout << ANSI_COLOR_GREEN "O. SALIR\n" ANSI_COLOR_RESET;

      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 2:
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO ADMINISTRADOR\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN AÑADIR CURSOS
      insertarCurso(curso);
      std::cout << ANSI_COLOR_GREEN "O. SALIR\n" ANSI_COLOR_RESET;

      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 3:
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO ADMINISTRADOR\n" ANSI_COLOR_RESET
                << endl;
      cout << "Introduzca la id del curso que desea eliminar: \n";
      cin >> modificar;

      // FUNCIÓN ELIMINAR CURSOS
      if (eliminar(modificar, curso) == true)
      {
        cout << "Ha sido eliminado con éxito\n\n";
      }
      else
      {
        cout << "No ha podido eliminarse el curso,debido a que no existe\n";
      }
      std::cout << ANSI_COLOR_GREEN "O. SALIR\n" ANSI_COLOR_RESET;

      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 4:
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO ADMINISTRADOR\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN MODIFICAR CURSOS
      cout << "Introduzca la id del curso que desea modificar: \n";
      cin >> modificar;
      if (modificarCursos(modificar, curso) == true)
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
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO ADMINISTRADOR\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN DE MOSTRAR PARTICIPANTES
      mostrarParticipantes(persona);
      std::cout << ANSI_COLOR_GREEN "O. SALIR\n" ANSI_COLOR_RESET;

      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 6:
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO ADMINISTRADOR\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN DE AÑADIR PARTICIPANTES

      insertarParticipante(persona, curso);
      std::cout << ANSI_COLOR_GREEN "O. SALIR\n" ANSI_COLOR_RESET;

      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;
    case 7:
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO ADMINISTRADOR\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN DE MODIFICAR PARTICIPANTES
      cout << "Introduzca el dni del participante que desea modificar: \n";
      cin >> modificarp;
      modificarParticipante(modificarp, persona, curso);
      cout << "0.VOLVER AL MENÚ" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 8:
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO ADMINISTRADOR\n" ANSI_COLOR_RESET
                << endl;
      cout << "Introduzca el dni del participante que desea eliminar: \n";
      cin >> modificarp;
      // FUNCIÓN ELIMINAR PARTICIPANTES

      if (eliminarP(modificarp, persona) == true)
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
    std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO PARTICIPANTE\n" ANSI_COLOR_RESET
              << endl;
    std::cout << ANSI_COLOR_GREEN "1.VER CURSOS\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "2.INSCRIPCION EN CURSOS\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "3.CONTACTO\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "4.VER CURSOS EN LOS QUE ESTOY INSCRITO\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "0.SALIR\n" ANSI_COLOR_RESET;

    cout << "\nIngrese una opcion: ";
    cin >> opcion;
    system("clear");

    switch (opcion)
    {
    case 1:
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO PARTICIPANTE\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN DE MOSTRAR CURSOS
      mostrarCursos(curso);
      std::cout << ANSI_COLOR_GREEN "O. SALIR\n" ANSI_COLOR_RESET;

      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 2:
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO PARTICIPANTE\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN INSCRIPCIÓN EN CURSOS
      cout << "Introduzca su DNI:\n";
      cin >> Dni;
      cout << "Introduzca el id del curso desea inscribirse\n ";
      cin >> id;
      if (inscribirseCurso(id, Dni, curso, persona) == true)
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
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO PARTICIPANTE\n" ANSI_COLOR_RESET
                << endl;
      cout << "Álvaro David Serrano López" << endl;
      cout << "i12seloa@uco.es" << endl;
      std::cout << ANSI_COLOR_GREEN "O. SALIR\n" ANSI_COLOR_RESET;

      cin >> tecla;
      system("clear");
      break;

    case 4:
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO PARTICIPANTE\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN VER CURSO INSCRITO
      cout << "Introduzca su DNI: \n";
      cin >> Dni;
      mostrarCaP(Dni, curso, persona);
      std::cout << ANSI_COLOR_GREEN "O. SALIR\n" ANSI_COLOR_RESET;

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
    std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO VISITANTE\n" ANSI_COLOR_RESET
              << endl;
    std::cout << ANSI_COLOR_GREEN "1.VER CURSOS\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "2.CONTACTO\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "0.SALIR\n" ANSI_COLOR_RESET;

    cout << "\nIngrese una opcion: ";
    cin >> opcion;
    system("clear");

    switch (opcion)
    {
    case 1:
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO VISITANTE\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN DE MOSTRAR CURSOS
      mostrarCursos(curso);
      std::cout << ANSI_COLOR_GREEN "O. SALIR\n" ANSI_COLOR_RESET;

      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 2:
      // FUNCIÓN CONTACTO ADMINISTRADOR
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO VISITANTE\n" ANSI_COLOR_RESET
                << endl;
      cout << "Álvaro David Serrano López" << endl;
      cout << "i12seloa@uco.es" << endl;
      std::cout << ANSI_COLOR_GREEN "O. SALIR\n" ANSI_COLOR_RESET;

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
    std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO COORDINADOR DE CURSOS\n" ANSI_COLOR_RESET
              << endl;
    std::cout << ANSI_COLOR_GREEN "1.VER CURSOS\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "2.AÑADIR CURSO\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "3.ELIMINAR CURSO\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "4.MODIFICAR CURSO\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "5.VER PARTICIPANTES DE TU CURSO\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "6.CONTACTO\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "0.SALIR\n" ANSI_COLOR_RESET;

    cout << "\nIngrese una opcion: ";
    cin >> opcion;
    system("clear");

    switch (opcion)
    {
    case 1:
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO COORDINADOR DE CURSOS\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN DE MOSTRAR CURSOS
      mostrarCursos(curso);
      std::cout << ANSI_COLOR_GREEN "O. SALIR\n" ANSI_COLOR_RESET;

      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 2:
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO COORDINADOR DE CURSOS\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN DE AÑADIR CURSOS
      insertarCurso(curso);
      std::cout << ANSI_COLOR_GREEN "O. SALIR\n" ANSI_COLOR_RESET;

      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 3:
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO COORDINADOR DE CURSOS\n" ANSI_COLOR_RESET
                << endl;
      cout << "Introduzca la id del curso que desea eliminar: \n";
      cin >> modificar;
      // FUNCIÓN ELIMINAR CURSOS
      if (eliminar(modificar, curso) == true)
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
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO COORDINADOR DE CURSOS\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN MODIFICAR CURSOS
      cout << "Introduzca la id del curso que desea modificar: \n";
      cin >> modificar;
      if (modificarCursos(modificar, curso) == true)
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
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO COORDINADOR DE CURSOS\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN MOSTRAR ALUMNOS DE UN CURSO
      cout << "Introduzca el id del curso del que desea ver los participantes: \n";
      cin >> id;
      mostrarCP(id, curso, persona);
      std::cout << ANSI_COLOR_GREEN "O. SALIR\n" ANSI_COLOR_RESET;

      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 6:
      // FUNCIÓN CONTACTO ADMINISTRADOR
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO COORDINADOR DE CURSOS\n" ANSI_COLOR_RESET
                << endl;
      cout << "Álvaro David Serrano López" << endl;
      cout << "i12seloa@uco.es" << endl;
      std::cout << ANSI_COLOR_GREEN "O. SALIR\n" ANSI_COLOR_RESET;

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
    std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO COORDINADOR DE RECURSOS\n" ANSI_COLOR_RESET
              << endl;
    std::cout << ANSI_COLOR_GREEN "1.VER CURSOS\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "2.ASIGNAR RECURSOS\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "3.CONTACTO\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "0.SALIR\n" ANSI_COLOR_RESET;

    cout << "\nIngrese una opcion: ";
    cin >> opcion;
    system("clear");

    switch (opcion)
    {
    case 1:
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO COORDINADOR DE RECURSOS\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN DE MOSTRAR CURSOS
      mostrarCursos(curso);
      std::cout << ANSI_COLOR_GREEN "O. SALIR\n" ANSI_COLOR_RESET;

      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 2:
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO COORDINADOR DE RECURSOS\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN ASIGNAR RECURSOS
      cout << "Introduzca la id del curso al que desea asignar recursos: \n";
      cin >> modificar;
      if (modificarR(modificar, curso) == true)
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
      std::cout << ANSI_COLOR_RED "CURSOS DE EXTENSION---MODO COORDINADOR DE RECURSOS\n" ANSI_COLOR_RESET
                << endl;
      cout << "Álvaro David Serrano López" << endl;
      cout << "i12seloa@uco.es" << endl;
      std::cout << ANSI_COLOR_GREEN "O. SALIR\n" ANSI_COLOR_RESET;

      cin >> tecla;
      system("clear");
      break;

    case 0:
      repetir = false;
      break;
    }
  } while (repetir);
}
