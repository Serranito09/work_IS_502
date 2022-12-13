#include "curso.h"
#include "persona.h"
#include <vector>
#include <string>
#include "bd.h"

using namespace std;

void BD::menu()
{
  int opcion;

  bool repetir = true;
  do
  {
    cout << "CURSOS DE EXTENSIÓN" << endl;
    cout << "1.ADMINISTRADOR" << endl;
    cout << "2.PARTICIPANTE" << endl;
    cout << "3.COORDINADOR DE CURSOS" << endl;
    cout << "4.VISITANTE" << endl;
    cout << "5.COORDINADOR DE RECURSOS" << endl;
    cout << "0.SALIR" << endl;

    cout << "\nIngrese su rol: ";
    cin >> opcion;
    system("clear");

    switch (opcion)
    {
    case 1:
      cout << "CURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n"
           << endl;
      menu_administrador();
      system("clear");
      break;

    case 2:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO PARTICIPANTE\n"
           << endl;
      menu_participante();
      system("clear");
      break;

    case 3:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO COORDINADOR DE CURSO\n"
           << endl;
      menu_coordinador_de_cursos();
      system("clear");
      break;

    case 4:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO VISITANTE\n"
           << endl;
      menu_visitante();
      system("clear");
      break;

    case 5:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO COORDINADOR DE RECURSOS\n"
           << endl;
      menu_coordinador_de_recursos();
      system("clear");
      break;
    case 0:
      repetir = false;
      break;
    }

  } while (repetir);
}

// MENU DEL ADMINISTRADOR
void BD::menu_administrador()
{

  int tecla;
  int opcion;
  int modificar;
  string modificarp;
  bool repetir = true;
  do
  {
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
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n"
           << endl;
      // FUNCIÓN DE MOSTRAR CURSOS
      mostrarCursos();
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 2:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n"
           << endl;
      // FUNCIÓN AÑADIR CURSOS
      insertarCurso();
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 3:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n"
           << endl;
      cout << "Introduzca la id del curso que desea eliminar: \n";
      cin >> modificar;
      // FUNCIÓN ELIMINAR CURSOS
      if (eliminar(modificar) == true)
      {
        cout << "Ha sido eliminado con éxito\n\n";
      }
      else
      {
        cout << "No ha podido eliminarse el curso\n";
      }
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 4:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n"
           << endl;
      // FUNCIÓN MODIFICAR CURSOS
      cout << "Introduzca la id del curso que desea modificar: \n";
      cin >> modificar;
      modificarCursos(modificar);
      cout << "0.VOLVER AL MENÚ" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 5:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n"
           << endl;
      // FUNCIÓN DE MOSTRAR PARTICIPANTES
      mostrarParticipantes();
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 6:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n"
           << endl;
      // FUNCIÓN DE AÑADIR PARTICIPANTES

      insertarParticipante();
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;
    case 7:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n"
           << endl;
      // FUNCIÓN DE MODIFICAR PARTICIPANTES
      cout << "Introduzca el dni del participante que desea modificar: \n";
      cin >> modificarp;
      modificarParticipante(modificarp);
      cout << "0.VOLVER AL MENÚ" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 8:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n"
           << endl;
      cout << "Introduzca el dni del participante que desea eliminar: \n";
      cin >> modificarp;
      // FUNCIÓN ELIMINAR PARTICIPANTES
      if (eliminarP(modificarp) == true)
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
void BD::menu_participante()
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
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO PARTICIPANTE\n"
           << endl;
      // FUNCIÓN DE MOSTRAR CURSOS
      mostrarCursos();
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 2:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO PARTICIPANTE\n"
           << endl;
      // FUNCIÓN INSCRIPCIÓN EN CURSOS
      cout << "Introduzca su DNI:\n";
      cin >> Dni;
      cout << "Introduzca el id del curso desea inscribirse\n ";
      cin >> id;
      if (inscribirseCurso(id, Dni) == true)
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
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO PARTICIPANTE\n"
           << endl;
      cout << "Álvaro David Serrano López" << endl;
      cout << "i12seloa@uco.es" << endl;
      cout << "0. SALIR" << endl;
      cin >> tecla;
      system("clear");
      break;

    case 4:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO PARTICIPANTE\n"
           << endl;
      // FUNCIÓN VER CURSO INSCRITO
      cout << "Introduzca su DNI: \n";
      cin >> Dni;
      mostrarCaP(Dni);
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
void BD::menu_visitante()
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
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO VISITANTE\n"
           << endl;
      // FUNCIÓN DE MOSTRAR CURSOS
      mostrarCursos();
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 2:
      // FUNCIÓN CONTACTO ADMINISTRADOR
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO VISITANTE\n"
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
void BD::menu_coordinador_de_cursos()
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
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO COORDINADOR DE CURSOS\n"
           << endl;
      // FUNCIÓN DE MOSTRAR CURSOS
      mostrarCursos();
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 2:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO COORDINADOR DE CURSO\n"
           << endl;
      // FUNCIÓN DE AÑADIR CURSOS
      insertarCurso();
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 3:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO COORDINADOR DE CURSO\n"
           << endl;
      cout << "Introduzca la id del curso que desea eliminar: \n";
      cin >> modificar;
      // FUNCIÓN ELIMINAR CURSOS
      if (eliminar(modificar) == true)
      {
        cout << "Ha sido eliminado con éxito\n\n";
      }
      else
      {
        cout << "No ha podido eliminarse el curso\n";
      }
      cout << "0. VOLVER AL MENÚ" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 4:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO COORDINADOR DE CURSO\n"
           << endl;
      // FUNCIÓN MODIFICAR CURSOS
      cout << "Introduzca la id del curso que desea modificar: \n";
      cin >> modificar;
      modificarCursos(modificar);
      cout << "0.VOLVER AL MENÚ" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 5:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO COORDINADOR DE CURSO\n"
           << endl;
      // FUNCIÓN MOSTRAR ALUMNOS DE UN CURSO
      cout << "Introduzca el id del curso del que desea ver los participantes: \n";
      cin >> id;
      mostrarCP(id);
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 6:
      // FUNCIÓN CONTACTO ADMINISTRADOR
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO COORDINADOR DE CURSO\n"
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
void BD::menu_coordinador_de_recursos()
{

  int tecla;
  int opcion;
  int modificar;
  bool repetir = true;
  do
  {
    cout << "1.VER CURSOS" << endl;
    cout << "2.MODIFICAR" << endl;
    cout << "3.CONTACTO" << endl;
    cout << "0.SALIR" << endl;

    cout << "\nIngrese una opcion: ";
    cin >> opcion;
    system("clear");

    switch (opcion)
    {
    case 1:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO COORDINADOR DE RECURSOS\n"
           << endl;
      // FUNCIÓN DE MOSTRAR CURSOS
      mostrarCursos();
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 2:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO COORDINADOR DE RECURSOS\n"
           << endl;
      // FUNCIÓN MODIFICAR CURSOS
      cout << "Introduzca la id del curso que desea modificar: \n";
      cin >> modificar;
      modificarCursos(modificar);
      cout << "0.VOLVER AL MENÚ" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 3:
      // FUNCIÓN CONTACTO ADMINISTRADOR
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO COORDINADOR DE RECURSOS\n"
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
