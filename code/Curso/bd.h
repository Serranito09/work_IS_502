#ifndef BD_H
#define BD_H

#include "curso.h"
#include "persona.h"
#include <vector>
#include <fstream>
#include <string>

using namespace std;
//Clase para volcar los vectores de registros de cursos en un vector
class BD
{
private:
    vector<Curso> cursos_;
    vector<Persona> personas_;

public:
    void nfC(char *nombreFichero)
    {
        cursos_.clear();
        ifstream f(nombreFichero);
        if (!f.is_open())
        {
            cout << "Error, no se puede establecer conexión con la base de datos." << endl;
            exit(-1);
        }

        string datoLeido;
        int id, fechainicio, aforo;
        string nombre, coordinador, descripcion;
        double precio;
        while (getline(f, datoLeido, ';'))
        {
            id = stoi(datoLeido);
            getline(f, datoLeido, ';');
            nombre = datoLeido;
            getline(f, datoLeido, ';');
            coordinador = datoLeido;
            getline(f, datoLeido, ';');
            fechainicio = stoi(datoLeido);
            getline(f, datoLeido, ';');
            descripcion = datoLeido;
            getline(f, datoLeido, ';');
            aforo = stoi(datoLeido);
            getline(f, datoLeido, '\n');
            precio = stod(datoLeido);

            Curso aux(id, nombre, coordinador, fechainicio, descripcion, precio, aforo);

            cursos_.push_back(aux);
        }

        f.close();
    }
    void nfP(char *nombreFichero)
    {

        personas_.clear();
        ifstream f(nombreFichero);
        if (!f.is_open())
        {
            cout << "Error, no se puede establecer conexión con la base de datos." << endl;
            exit(-1);
        }

        string datoLeido;
        int id,edad;
        string nombre,apellidos,correo,lugar,Dni;
        double precio;
        while (getline(f, datoLeido, ';'))
        {
            Dni = datoLeido;
            getline(f, datoLeido, ';');
            nombre = datoLeido;
            getline(f, datoLeido, ';');
            apellidos = datoLeido;
            getline(f, datoLeido, ';');
            correo = datoLeido;
            getline(f, datoLeido, ';');
            edad = stoi(datoLeido);
            getline(f, datoLeido, ';');
            lugar = datoLeido;
            getline(f, datoLeido, '\n');
            id = stoi(datoLeido);
            Persona aux(Dni,nombre,apellidos,edad, lugar, correo,id);
            personas_.push_back(aux);
        }

        f.close();
    }
    //Funcion para mostrar los cursos

     void mostrarParticipantes()
    {
        for (auto it = personas_.begin(); it != personas_.end(); it++)
        {
            cout << it->getFulldata();
        }
    }
    void mostrarCursos()
    {
        for (auto it = cursos_.begin(); it != cursos_.end(); it++)
        {
            cout << it->getData();
        }
    }
    //Funcion para modificar los cursos
    void modificarCursos(int modificar)
    {

        int op;
        int cambiarI;
        string cambiarS;
        for (auto it = cursos_.begin(); it != cursos_.end(); it++)
        {
            if (((*it).getid()) == modificar)
            {
                do
                {
                    cout << "Introduzca el número correspondiente al parámetro que desee modificar: \n\n";
                    cout << "1--->Fecha de inicio\n";
                    cout << "2--->Precio\n";
                    cout << "3--->Nombre\n";
                    cout << "4--->Descripcion\n";
                    cout << "5--->Coordinador\n";
                    cout << "6--->Aforo\n";
                    cout << "7--->Salir\n";
                    cin >> op;
                    system("clear");
                    switch (op)
                    {
                    case 1:
                        cout <<"Introduzca la nueva fecha de inicio: \n";
                        cin >> cambiarI;
                        (*it).set_Fechainicio(cambiarI);
                        system("clear");
                        break;
                    case 2:
                        cout <<"Introduzca el nuevo precio: ";
                        cin >> cambiarI;
                        (*it).set_Precio(cambiarI);
                        system("clear");
                        break;
                    case 3:
                        cout <<"Introduzca el nuevo nombre: ";
                        cin >> cambiarS;
                        (*it).set_nombre(cambiarS);
                        system("clear");
                        break;
                    case 4:
                        cout <<"Introduzca la nueva descripción: ";
                        cin.ignore();
                        getline(cin, cambiarS);
                        (*it).set_Descripcion(cambiarS);
                        system("clear");
                        break;
                    case 5:
                        cout <<"Introduzca el nombre del nuevo coordinador: ";
                        cin >> cambiarS;
                        (*it).set_Coordinador(cambiarS);
                        system("clear");
                        break;

                    case 6:
                        cout <<"Introduzca el nuevo aforo: ";
                        cin >> cambiarI;
                        (*it).set_Aforo(cambiarI);

                    default:
                        cout << "La opción introducida no es válida\n\n";
                        break;
                    }
                } while (op != 7);
            }
        }
    }
//Funcion para eliminar un registro
    void eliminar(int modificar){
        for (auto it = cursos_.begin(); it != cursos_.end(); it++)
  {
    if (((*it).getid()) == modificar)
    {
      cursos_.erase(it);
      break;
    }
  }
    }
//Función para insertar un curso
    void insertar(){
        int id,fechaini;
        double precio;
        string nombre,descripcion,coordinador;
        Curso c1;
        cout<<"Introduzca el id del nuevo curso: \n";
        cin>>id;
         c1.set_id(id);
         cout<<"Introduzca el precio del nuevo curso: \n";
         cin>>precio;
    c1.set_Precio(precio);
    cout<<"Introduzca el nombre del nuevo curso: \n";
     cin.ignore();
    getline(cin,nombre);
    c1.set_nombre(nombre);
     cout<<"Introduzca la fecha de inicio del nuevo curso: \n";
     cin>>fechaini;
     c1.set_Fechainicio(fechaini);
     cout<<"Introduzca la descripción del nuevo curso: \n";
      cin.ignore();
    getline(cin, descripcion);
    c1.set_Descripcion(descripcion);
    cout<<"Introduzca el coordinador del nuevo curso: \n";
    cin>>coordinador;
    c1.set_Coordinador(coordinador);
    cursos_.push_back(c1);
    }


void backup(char *nombreFichero)
{
    ofstream f(nombreFichero);
    if (!f.is_open())
    {
        cout << "Error, no se puede establecer conexión con la base de datos." << endl;
        exit(-1);
    }

    for (auto it = cursos_.begin(); it != cursos_.end(); it++)
    {
        f << it->getid() << ";" << it->getNombre() << ";" << it->getCoordinador() << ";" << it->getFechainicio() << ";" << it->getDescripcion() << ";" << it->getAforo() << ";" << it->get_precio() << "\n";
    }

    f.close();
}
void menu();
void menuadministrador();
void menuvisitante();
void menucoordinadordecursos();
void menuparticipante();
void menucoordinadorderecursos();
};



#endif