#ifndef BD_H
#define BD_H

#include "curso.h"
#include "persona.h"
#include <vector>
#include <fstream>
#include <string>

using namespace std;
// Clase para volcar los vectores de registros de cursos en un vector
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
        int id, edad;
        string nombre, apellidos, correo, lugar, Dni;
        while (getline(f, datoLeido, ';'))
        {
            Dni = datoLeido;
            getline(f, datoLeido, ';');
            nombre = datoLeido;
            getline(f, datoLeido, ';');
            apellidos = datoLeido;
            getline(f, datoLeido, ';');
            edad = stoi(datoLeido);
            getline(f, datoLeido, ';');
            lugar = datoLeido;
            getline(f, datoLeido, ';');
            correo = datoLeido;
            getline(f, datoLeido, '\n');
            id = stoi(datoLeido);
            Persona aux(Dni, nombre, apellidos, edad, lugar, correo, id);
            // 31885014e;alvaro;serrano;19;Cordoba;i12seloa@uco.es;2
            personas_.push_back(aux);
        }

        f.close();
    }

    // Funcion para mostrar los cursos

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
    // Funcion para modificar los cursos
    void modificarCursos(int modificar)
    {
        int repetir;
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
                        cout << "Introduzca la nueva fecha de inicio: \n";
                        cin >> cambiarI;
                        (*it).set_Fechainicio(cambiarI);
                        system("clear");
                        break;
                    case 2:
                        cout << "Introduzca el nuevo precio: ";
                        cin >> cambiarI;
                        (*it).set_Precio(cambiarI);
                        system("clear");
                        break;
                    case 3:
                        cout << "Introduzca el nuevo nombre: ";
                        cin >> cambiarS;
                        (*it).set_nombre(cambiarS);
                        system("clear");
                        break;
                    case 4:
                        cout << "Introduzca la nueva descripción: ";
                        cin.ignore();
                        getline(cin, cambiarS);
                        (*it).set_Descripcion(cambiarS);
                        system("clear");
                        break;
                    case 5:
                        cout << "Introduzca el nombre del nuevo coordinador: ";
                        cin >> cambiarS;
                        (*it).set_Coordinador(cambiarS);
                        system("clear");
                        break;

                    case 6:
                        cout << "Introduzca el nuevo aforo: ";
                        cin >> cambiarI;
                        (*it).set_Aforo(cambiarI);
                    case 7:
                        repetir = false;
                        break;
                    }
                } while (repetir);
            }
        }
    }
    // Funcion para eliminar un registro
    bool eliminar(int modificar)
    {
        for (auto it = cursos_.begin(); it != cursos_.end(); it++)
        {
            if (((*it).getid()) == modificar)
            {
                cursos_.erase(it);
                return true;
            }
        }
        return false;
    }
    // Función para insertar un curso
    void insertarCurso()
    {
        int id, fechaini, aforo;
        double precio;
        string nombre, descripcion, coordinador;
        Curso c1;
        cout << "Introduzca el id del nuevo curso: \n";
        cin >> id;
        c1.set_id(id);
        cout << "Introduzca el precio del nuevo curso: \n";
        cin >> precio;
        c1.set_Precio(precio);
        cout << "Introduzca el nombre del nuevo curso: \n";
        cin.ignore();
        getline(cin, nombre);
        c1.set_nombre(nombre);
        cout << "Introduzca la fecha de inicio del nuevo curso: \n";
        cin >> fechaini;
        c1.set_Fechainicio(fechaini);
        cout << "Introduzca la descripción del nuevo curso: \n";
        cin.ignore();
        getline(cin, descripcion);
        c1.set_Descripcion(descripcion);
        cout << "Introduzca el coordinador del nuevo curso: \n";
        cin >> coordinador;
        c1.set_Coordinador(coordinador);
        cout << "Introduzca el aforo del nuevo curso: \n";
        cin >> aforo;
        c1.set_Aforo(aforo);
        cursos_.push_back(c1);
    }

    void insertarParticipante()
    {
        int id, edad;
        string nombre, apellidos, correo, lugar, Dni;
        Persona p1;
        cout << "Introduzca el nombre del nuevo participante: \n";
        cin.ignore();
        getline(cin, nombre);
        p1.setNombre(nombre);
        cout << "Introduzca los apellidos del nuevo participante: \n";
        cin.ignore();
        getline(cin, apellidos);
        p1.setApellidos(apellidos);
        cout << "Introduzca el correo del nuevo participante: \n";
        cin >> correo;
        p1.setCorreo(correo);
        cout << "Introduzca el lugar de residencia del nuevo participante: \n";
        cin >> lugar;
        p1.setLugar(lugar);
        cout << "Introduzca el dni del nuevo participante: \n";
        cin >> Dni;
        p1.setDni(Dni);
        cout << "Introduzca la edad del nuevo participante: \n";
        cin >> edad;
        p1.setEdad(edad);
        cout << "Introduzca el id del curso al que pertenece el participante si no pertenece a ninguno introduzca un 0: \n";
        cin >> id;
        p1.setId(id);
        personas_.push_back(p1);
    }

    bool inscribirseCurso(int id, string Dni)
    {
        for (auto it = cursos_.begin(); it != cursos_.end(); it++)
        {

            if (((*it).getid()) == id)
            {
                for (auto it2 = personas_.begin(); it2 != personas_.end(); it2++)
                {
                    if (((*it2).getDni()) == Dni)
                    {
                        (*it2).setId(id);
                        return true;
                    }
                }
            }
        }
        return false;
    }
    void mostrarCaP(string Dni)
    {
        for (auto it = cursos_.begin(); it != cursos_.end(); it++)
        {
            for (auto it2 = personas_.begin(); it2 != personas_.end(); it2++)
            {
                if (((*it).getid()) == ((*it2).getId()) && ((*it2).getDni()) == Dni)
                {
                    cout << "Usted está inscrito en el curso de " << (*it).getNombreC() << endl;
                }
            }
        }
    }

    void mostrarCP(int id)
    {
        for (auto it = cursos_.begin(); it != cursos_.end(); it++)
        {
            for (auto it2 = personas_.begin(); it2 != personas_.end(); it2++)
            {
                if (((*it).getid()) == ((*it2).getId()) && ((*it2).getId()) == id)
                {
                    cout << (*it2).getFulldata();
                }
            }
        }
    }

    void backupC(char *nombreFichero)
    {
        ofstream f(nombreFichero);
        if (!f.is_open())
        {
            cout << "Error, no se puede establecer conexión con la base de datos." << endl;
            exit(-1);
        }

        for (auto it = cursos_.begin(); it != cursos_.end(); it++)
        {
            f << it->getid() << ";" << it->getNombreC() << ";" << it->getCoordinador() << ";" << it->getFechainicio() << ";" << it->getDescripcion() << ";" << it->getAforo() << ";" << it->get_precio() << "\n";
        }

        f.close();
    }

    void backupP(char *nombreFichero)
    {
        ofstream f(nombreFichero);
        if (!f.is_open())
        {
            cout << "Error, no se puede establecer conexión con la base de datos." << endl;
            exit(-1);
        }

        for (auto it = personas_.begin(); it != personas_.end(); it++)

        {
            f << it->getDni() << ";" << it->getNombreP() << ";" << it->getApellidos() << ";" << it->getEdad() << ";" << it->getLugar() << ";" << it->getCorreo() << ";" << it->getId() << "\n";
        }

        f.close();
    }
    void menu();
    void menu_administrador();
    void menu_visitante();
    void menu_coordinador_de_cursos();
    void menu_participante();
    void menu_coordinador_de_recursos();

    void modificarParticipante(string modificarp)
    {
        int repetir;
        int op;
        int cambiarI;
        string cambiarS;
        for (auto it = personas_.begin(); it != personas_.end(); it++)
        {
            if (((*it).getDni()) == modificarp)
            {
                do
                {
                    cout << "Introduzca el número correspondiente al parámetro que desee modificar: \n\n";
                    cout << "1--->Nombre\n";
                    cout << "2--->Apellidos\n";
                    cout << "3--->Correo\n";
                    cout << "4--->Lugar de Residencia\n";
                    cout << "5--->DNI\n";
                    cout << "6--->Edad\n";
                    cout << "7--->Id del curso al que pertenece\n";
                    cout << "8--->Salir\n";
                    cin >> op;
                    system("clear");
                    switch (op)
                    {
                    case 1:
                        cout << "Introduzca el nuevo nombre: \n";
                        cin.ignore();
                        getline(cin, cambiarS);
                        (*it).setNombre(cambiarS);
                        system("clear");
                        break;
                    case 2:
                        cout << "Introduzca los nuevos apellidos: ";
                        cin.ignore();
                        getline(cin, cambiarS);
                        (*it).setApellidos(cambiarS);
                        system("clear");
                        break;
                    case 3:
                        cout << "Introduzca el nuevo correo: ";
                        cin >> cambiarS;
                        (*it).setCorreo(cambiarS);
                        system("clear");
                        break;
                    case 4:
                        cout << "Introduzca el nuevo lugar de residencia: ";
                        cin.ignore();
                        getline(cin, cambiarS);
                        (*it).setLugar(cambiarS);
                        system("clear");
                        break;
                    case 5:
                        cout << "Introduzca el nuevo DNI: ";
                        cin >> cambiarS;
                        (*it).setDni(cambiarS);
                        system("clear");
                        break;

                    case 6:
                        cout << "Introduzca la nueva edad: ";
                        cin >> cambiarI;
                        (*it).setEdad(cambiarI);
                        system("clear");
                        break;

                    case 7:
                        cout << "Introduzca el id del nuevo curso al que pertenece: ";
                        cin >> cambiarI;
                        (*it).setId(cambiarI);
                        system("clear");
                        break;

                    case 8:
                        repetir = false;
                        break;
                    }
                } while (repetir);
            }
        }
    }

    bool eliminarP(string modificarp)
    {
        for (auto it = personas_.begin(); it != personas_.end(); it++)
        {
            if (((*it).getDni()) == modificarp)
            {
                personas_.erase(it);
                return true;
            }
        }
        return false;
    }
};

#endif