#include "curso.h"
#include <vector>
#include <string>
#include "bd.h"
using namespace std;

void BD::menu()
{
  int tecla;//QUITAR
  int opcion;
  int modificar;//QUITAR
  bool repetir = true;
  do{
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

    switch(opcion){
      case 1: cout << "CURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n" << endl;
      menuadministrador();
      system("clear");
      break;


      case 2: cout << "\n\nCURSOS DE EXTENSIÓN---MODO PARTICIPANTE\n" << endl;
      //menuparticipante()
      system("clear");
      break;


      case 3: cout << "\n\nCURSOS DE EXTENSIÓN---MODO COORDINADOR DE CURSO\n" << endl;
      //menucoordinadordecurso()
      system("clear");
      break;


      case 4: cout << "\n\nCURSOS DE EXTENSIÓN---MODO VISITANTE\n" << endl;
      //menuvisitante()
      system("clear");
      break;


      case 5: cout << "\n\nCURSOS DE EXTENSIÓN---MODO COORDINADOR DE RECURSOS\n" << endl;
      //menucoordinadorderecursos()
      system("clear");
      break;
      case 0:
      repetir = false;
      break;

    }

  }while (repetir);
}




  void BD::menuadministrador(){
  int tecla;
  int opcion;
  int modificar;
  bool repetir = true;
  do{
    cout << "1.VER CURSOS" << endl;
    cout << "2.AÑADIR CURSOS" << endl;
    cout << "3.ELIMINAR CURSOS" << endl;
    cout << "4.MODIFICAR CURSOS" << endl;
    cout << "5.VER PARTICIPANTES" << endl;
    cout << "0.SALIR" << endl;

    cout << "\nIngrese una opcion: ";
    cin >> opcion;
    system("clear");

    switch(opcion){
      case 1:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n" << endl;
      // FUNCION DE MOSTRAR CURSOS
      mostrarCursos();
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

      case 2:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n" << endl;
      // funcion de añadir cursos
      insertar();
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

      case 3:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n" << endl;
      cout << "Introduzca la id del curso que desea eliminar: \n";
      cin >> modificar;
      // eliminar cursos
      eliminar(modificar);
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

       case 4:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n" << endl;
      // funcion de modificar cursos
      cout << "Introduzca la id del curso que desea modificar: \n";
      cin >> modificar;
      modificarCursos(modificar);
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;
      
      case 5:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO ADMINISTRADOR\n" << endl;
      // FUNCION DE MOSTRAR PARTICIPANTES
      mostrarParticipantes();
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

   void BD::menuparticipante(){

    int tecla;
    int opcion;
    int modificar;
    bool repetir = true;
    do{
      cout << "1.VER CURSOS" << endl;
      cout << "2.INSCRIPCIÓN EN CURSOS" << endl;
      cout << "3.CONTACTO" << endl;
      cout << "0.SALIR" << endl;

      cout << "\nIngrese una opcion: ";
      cin >> opcion;
      system("clear");

      switch(opcion){
        case 1:
          cout << "\n\nCURSOS DE EXTENSIÓN---MODO PARTICIPANTE\n" << endl;
          // FUNCION DE MOSTRAR CURSOS
          mostrarCursos();
          cout << "0. SALIR" << endl;
          cout << "\nIngrese una opcion: ";
          cin >> tecla;
          system("clear");
          break;

        case 2:
          cout << "\n\nCURSOS DE EXTENSIÓN---MODO PARTICIPANTE\n" << endl;
        // funcion de inscribir en cursos
          cout << "0. SALIR" << endl;
          cout << "\nIngrese una opcion: ";
          cin >> tecla;
          system("clear");
          break;
        case 3:
          cout << "\n\nCURSOS DE EXTENSIÓN---MODO PARTICIPANTE\n"<< endl;
          cout <<"Álvaro David Serrano López" << endl;
          cout <<"i12seloa@uco.es"<< endl;
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
   

   void BD::menuvisitante(){

  
  int tecla;
  int opcion;
  int modificar;
  bool repetir = true;
  do{

      cout << "1.VER CURSOS" << endl;
      cout << "2.CONTACTO" << endl;
      cout << "0.SALIR" << endl;

      cout << "\nIngrese una opcion: ";
      cin >> opcion;
      system("clear");

    switch(opcion){
       case 1:
          cout << "\n\nCURSOS DE EXTENSIÓN---MODO VISITANTE\n" << endl;
          // FUNCION DE MOSTRAR CURSOS
          mostrarCursos();
          cout << "0. SALIR" << endl;
          cout << "\nIngrese una opcion: ";
          cin >> tecla;
          system("clear");
          break;

      case 2:
        cout << "\n\nCURSOS DE EXTENSIÓN---MODO VISITANTE\n" << endl;
        cout <<"Álvaro David Serrano López" << endl;
        cout <<"i12seloa@uco.es"<< endl;
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


   void BD::menucoordinadordecursos(){

  
  int tecla;
  int opcion;
  int modificar;
  bool repetir = true;
  do{
      cout << "1.VER CURSOS" <<endl;
      cout << "2.AÑADIR CURSO" << endl;
      cout << "3.ELIMINAR CURSO" << endl;
      cout << "4.MODIFICAR CURSO" << endl;
      cout << "5.VER PARTICIPANTES DE TU CURSO" <<endl;
      cout << "6.CONTACTO" <<endl;
      cout << "0.SALIR" << endl;
      
      cout << "\nIngrese una opcion: ";
      cin >> opcion;
      system("clear");

    switch(opcion){
      case 1:
          cout << "\n\nCURSOS DE EXTENSIÓN---MODO COORDINADOR DE CURSOS\n" << endl;
          // FUNCION DE MOSTRAR CURSOS
          mostrarCursos();
          cout << "0. SALIR" << endl;
          cout << "\nIngrese una opcion: ";
          cin >> tecla;
          system("clear");
          break;
      
      case 2:
          cout << "\n\nCURSOS DE EXTENSIÓN---MODO COORDINADOR DE CURSO\n" << endl;
           // funcion de añadir cursos
          insertar();
          cout << "0. SALIR" << endl;
          cout << "\nIngrese una opcion: ";
          cin >> tecla;
          system("clear");
          break;

      case 3:
          cout << "\n\nCURSOS DE EXTENSIÓN---MODO COORDINADOR DE CURSO\n" << endl;
          cout << "Introduzca la id del curso que desea eliminar: \n";
          cin >> modificar;
          // eliminar cursos
          eliminar(modificar);
          cout << "0. SALIR" << endl;
          cout << "\nIngrese una opcion: ";
          cin >> tecla;
          system("clear");
          break;
     
      case 4:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO COORDINADOR DE CURSO" << endl;
      // funcion de modificar cursos
      cout << "Introduzca la id del curso que desea modificar: \n";
      cin >> modificar;
      modificarCursos(modificar);
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

      case 5:
      cout << "\n\nCURSOS DE EXTENSIÓN---MODO COORDINADOR DE CURSO" << endl;
      //FUNCION MOSTRAR ALUMNOS DE UN CURSO
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

      case 6:
          cout << "\n\nCURSOS DE EXTENSIÓN---MODO PARTICIPANTE\n"<< endl;
          cout <<"Álvaro David Serrano López" << endl;
          cout <<"i12seloa@uco.es"<< endl;
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


//MENU CC
   void BD::menucoordinadorderecursos(){
  int tecla;
  int opcion;
  int modificar;
  bool repetir = true;
  do{
      cout << "1.VER CURSOS" << endl;
      cout << "2.MODIFICAR" << endl;
      cout << "3.CONTACTO" << endl;
      cout << "0.SALIR" << endl;

      cout << "\nIngrese una opcion: ";
      cin >> opcion;
      system("clear");

    switch(opcion){


    }
    
    } while (repetir);
  }
 

/*ESTO SERÁ BORRADO SERRANO ES EL FOKING FEO DEL PROGRAMA DE IS
  do
  {

    // Texto del menú que se verá cada vez
    cout << "\n\nCURSOS DE EXTENSIÓN" << endl;
    cout << "1.VER CURSOS" << endl;
    cout << "2.AÑADIR CURSOS" << endl;
    cout << "3.ELIMINAR CURSOS" << endl;
    cout << "4.INSCRIPCIÓN EN CURSOS" << endl;
    cout << "5.MODIFICAR CURSOS" << endl;
    cout << "6.CONTACTO" << endl;
    cout << "0.SALIR" << endl;

    cout << "\nIngrese una opcion: ";
    cin >> opcion;
    system("clear");

    switch (opcion)
    {
    case 1:
      cout << "\n\nCURSOS DE EXTENSIÓN" << endl;
      // FUNCION DE MOSTRAR CURSOS
      mostrarCursos();
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;
      

    case 2:
      cout << "\n\nCURSOS DE EXTENSIÓN" << endl;
      // funcion de añadir cursos
      insertar();
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 3:
      cout << "\n\nCURSOS DE EXTENSIÓN" << endl;
      cout << "Introduzca la id del curso que desea eliminar\n";
      cin >> modificar;
      // eliminar cursos
      eliminar(modificar);
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 4:
      cout << "\n\nCURSOS DE EXTENSIÓN" << endl;
      // funcion de inscribir en cursos
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;
    case 5:
      cout << "\n\nCURSOS DE EXTENSIÓN" << endl;
      // funcion de modificar cursos
      cout << "Introduzca la id del curso que desea modificar\n";
      cin >> modificar;
      modificarCursos(modificar);
      cout << "0. SALIR" << endl;
      cout << "\nIngrese una opcion: ";
      cin >> tecla;
      system("clear");
      break;
    case 6:
    cout << "\n\nCURSOS DE EXTENSIÓN" << endl;
    cout <<"Álvaro David Serrano López" << endl;
    cout <<"i12seloa@uco.es"<< endl;
    cout << "0. SALIR" << endl;
    cin >> tecla;
    system("clear");
    break;

    case 0:
      repetir = false;
      break;
    }
  } while (repetir);//de aqui paarrIBA SE BORRARA
*/