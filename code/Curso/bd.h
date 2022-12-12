#ifndef BD_H
#define BD_H

#include "curso.h"
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class BD
{
private:
    vector<Curso> cursos_;

public:
    BD(char *nombreFichero)
    {
        cursos_.clear();
        ifstream f(nombreFichero);
        if (!f.is_open())
        {
            cout << "Error, no se puede establecer conexión con la base de datos." << endl;
            exit(-1);
        }

        // Curso(int id,string nombre,string coordinador,int fechainicio,string descripcion,double precio,int aforo=1)
        // 2;Curso 2;Francisco;222222;Curso de prueba;23;200.00

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

    void mostrarCursos()
    {
        for (auto it = cursos_.begin(); it != cursos_.end(); it++)
        {
            cout << it->getData();
        }
    }
    void modificarCursos(int modificar)
    {

        int op;
        int cambiarI;
        string cambiarS;
        for (auto it = cursos_.begin(); it != cursos_.end(); it++)
        {
            if (((*it).getDni()) == modificar)
            {
                do
                {
                    cout << "Que desea modificar\n\n";
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
                        cout << "Que nueva Fecha de inicio desea introducir\n";
                        cin >> cambiarI;
                        (*it).set_Fechainicio(cambiarI);
                        system("clear");
                        break;
                    case 2:
                        cout << "Que nuevo precio desea ponerle: ";
                        cin >> cambiarI;
                        (*it).set_Precio(cambiarI);
                        system("clear");
                        break;
                    case 3:
                        cout << "Que nuevo nombre desea ponerle: ";
                        cin >> cambiarS;
                        (*it).set_nombre(cambiarS);
                        system("clear");
                        break;
                    case 4:
                        cout << "Que nueva Descripcion desea ponerle: ";
                        cin.ignore();
                        getline(cin, cambiarS);
                        (*it).set_Descripcion(cambiarS);
                        system("clear");
                        break;
                    case 5:
                        cout << "Que nuevo Coordinador desea ponerle: ";
                        cin >> cambiarS;
                        (*it).set_Coordinador(cambiarS);
                        system("clear");
                        break;

                    case 6:
                        cout << "Que nuevo aforo desea ponerle: ";
                        cin >> cambiarI;
                        (*it).set_Aforo(cambiarI);

                    default:
                        cout << "opcion no valida\n\n";
                        break;
                    }
                } while (op != 7);
            }
        }
    }

    void eliminar(int modificar){
        for (auto it = cursos_.begin(); it != cursos_.end(); it++)
  {
    if (((*it).getDni()) == modificar)
    {
      cursos_.erase(it);
      break;
    }
  }
    }

    void insertar(){
        int id,fechaini;
        double precio;
        string nombre,descripcion,coordinador;
        Curso c1;
        cout<<"Que id desea introducir\n";
        cin>>id;
         c1.set_Dni(id);
         cout<<"Que precio desea introducir\n";
         cin>>precio;
    c1.set_Precio(precio);
    cout<<"Digame el nombre del curso\n";
     cin.ignore();
    getline(cin,nombre);
    c1.set_nombre(nombre);
     cout<<"Digame la fecha de inicio\n";
     cin>>fechaini;
     c1.set_Fechainicio(fechaini);
     cout<<"Digame la descripcion que desea introducir\n";
      cin.ignore();
    getline(cin, descripcion);
    c1.set_Descripcion(descripcion);
    cout<<"digame el nombre del coordinador\n";
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
        f << it->getDni() << ";" << it->getNombre() << ";" << it->getCoordinador() << ";" << it->getFechainicio() << ";" << it->getDescripcion() << ";" << it->getAforo() << ";" << it->get_precio() << "\n";
    }

    f.close();
}
}
;

#endif