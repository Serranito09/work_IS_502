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
            cout << "Error2, no se puede establecer conexión con la base de datos." << endl;
            exit(-1);
        }

        string datoLeido;
        int id, aforo;
        string nombre, coordinador, descripcion, fechainicio,recurso;
        double precio;
        while (getline(f, datoLeido, ';'))
        {
            id = stoi(datoLeido);
            getline(f, datoLeido, ';');
            nombre = datoLeido;
            getline(f, datoLeido, ';');
            coordinador = datoLeido;
            getline(f, datoLeido, ';');
            fechainicio = datoLeido;
            getline(f, datoLeido, ';');
            descripcion = datoLeido;
            getline(f, datoLeido, ';');
            aforo = stoi(datoLeido);
            getline(f, datoLeido, ';');
            precio = stod(datoLeido);
            getline(f, datoLeido, '\n');
            recurso = datoLeido;

            Curso aux(id, nombre, coordinador, fechainicio, descripcion, precio, aforo,recurso);

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
            cout << "Error2, no se puede establecer conexión con la base de datos." << endl;
            exit(-1);
        }

        string datoLeido;
        int id, edad;
        string edadString, idString;
        string nombre, apellidos, correo, lugar, Dni;
        while (getline(f, datoLeido, ';'))
        {
            Dni = datoLeido;
            getline(f, datoLeido, ';');
            nombre = datoLeido;
            getline(f, datoLeido, ';');
            apellidos = datoLeido;
            getline(f, datoLeido, ';');
            edadString = to_string(edad);
            getline(f, datoLeido, ';');
            lugar = datoLeido;
            getline(f, datoLeido, ';');
            correo = datoLeido;
            getline(f, datoLeido, '\n');
            idString = to_string(id);
            Persona aux(Dni, nombre, apellidos, edad, lugar, correo, id);

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
    bool modificarCursos(int modificar)
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
                    cout << "7--->Recursos\n";
                    cout << "8--->Salir\n";
                    cin >> op;
                    system("clear");
                    switch (op)
                    {
                    case 1:
                        cout << "Introduzca la nueva fecha de inicio: \n";
                        cin >> cambiarS;
                        (*it).set_Fechainicio(cambiarS);
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
                        system("clear");
                        break;
                    case 7:
                        cout << "Introduzca los nuevos recursos: \n ";
                        cin.ignore();
                        getline(cin, cambiarS);
                        (*it).set_Recursos(cambiarS);
                        system("clear");
                        break;

                    case 8:
                        repetir = false;
                        break;
                    }
                } while (repetir);
                return true;
            }

        }
        return false;
    }

    bool modificarR(int modificar)
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
                    cout << "1--->Recursos\n";
                    cout << "2--->Aforo\n";
                    cout << "3--->Salir\n";
                    cin >> op;
                    system("clear");
                    switch (op)
                    {

                    case 1:
                        cout << "Introduzca los nuevos recursos: \n ";
                        cin.ignore();
                        getline(cin, cambiarS);
                       if (((*it).set_Recursos(cambiarS))==false){
                        cout<<"prueba\n";
                       }
                        system("clear");
                        break;

                    case 2:
                        cout << "Introduzca el nuevo aforo: ";
                        cin >> cambiarI;
                        (*it).set_Aforo(cambiarI);
                        system("clear");
                        break;

                    case 3:
                    repetir = false;
                        break;
                    
                    }
                    
                        
                } while (repetir);
                return true;
            }
        }
        return false;
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
    // Función para ar un curso
     bool insertarCurso()
    {
        int id, aforo;
        double precio;
        string nombre, descripcion, coordinador, fechaini, recurso;
        Curso c1;
        cout << "Introduzca el id del nuevo curso: \n";
        cin >> id;
        if ((c1.set_id(id, cursos_)) == false)
        {
            for (int i = 0; i < 99; i++)
            {
                if ((c1.set_id(id, cursos_)) == false)
                {
                    cout << "Esta id ya pertenece a otro curso, introduzca uno nuevo: \n";
                    cin >> id;
                }
            }
        }

        cout << "Introduzca el precio del nuevo curso: \n";
        cin >> precio;
        c1.set_Precio(precio);
        cout << "Introduzca el nombre del nuevo curso: \n";
        cin.ignore();
        getline(cin, nombre);
        c1.set_nombre(nombre);
        cout << "Introduzca la fecha de inicio del nuevo curso(DD/MM/AA): \n";
        cin >> fechaini;
        c1.set_Fechainicio(fechaini);
        cout << "Introduzca la descripción del nuevo curso: \n";
        cin.ignore();
        getline(cin, descripcion);
        c1.set_Descripcion(descripcion);
        cout << "Introduzca el coordinador del nuevo curso: \n";
        getline(cin, coordinador);
        c1.set_Coordinador(coordinador);
        cout << "Introduzca el aforo del nuevo curso: \n";
        cin >> aforo;
        cout << "Introduzca los recursos del nuevo curso: \n";
        cin.ignore();
        getline(cin, recurso);
        c1.set_Recursos(recurso);

        if ((c1.set_Aforo(aforo)) == false)
        {
            for (int i = 0; i < 99; i++)
            {
                if ((c1.set_Aforo(aforo)) == false)
                {
                    cout << "No se ha podido fijar el aforo, recuerde que este debe ser mayor que 0 y menor e igual que 200,introduzca un nuevo aforo correcto\n";
                    cin >> aforo;
                }
            }
        }
        cursos_.push_back(c1);
        return true;
    }

    void insertarParticipante()
    {
        int id, edad;
        string nombre, apellidos, correo, lugar, Dni;
        Persona p1;
        cout << "Introduzca el DNI del nuevo participante: \n ";
        cin >> Dni;
        if ((p1.setDni(Dni, personas_)) == false)
        {
            for (int i = 0; i < 99; i++)
            {
                if ((p1.setDni(Dni, personas_)) == false)
                {
                    cout << "Este DNI ya pertenece a otra persona, introduzca el DNI correcto: \n";
                    cin >> Dni;
                }
            }
        }

        cout << "Introduzca el nombre del nuevo participante: \n";
        cin.ignore();
        getline(cin, nombre);
        p1.setNombre(nombre);
        cout << "Introduzca los apellidos del nuevo participante: \n";
        getline(cin, apellidos);
        p1.setApellidos(apellidos);
        cout << "Introduzca el correo del nuevo participante: \n";
        cin >> correo;
        p1.setCorreo(correo);
        cout << "Introduzca el lugar de residencia del nuevo participante: \n";
        cin.ignore();
        getline(cin, lugar);
        p1.setLugar(lugar);
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
                    cout << "5--->Edad\n";
                    cout << "6--->Id del curso al que pertenece\n";
                    cout << "7--->Salir\n";
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
                        cout << "Introduzca la nueva edad: ";
                        cin >> cambiarI;
                        (*it).setEdad(cambiarI);
                        system("clear");
                        break;

                    case 6:
                        cout << "Introduzca el id del nuevo curso al que pertenece: ";
                        cin >> cambiarI;
                        (*it).setId(cambiarI);
                        system("clear");
                        break;

                    case 7:
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
    bool Contacto(){
        return true;
          cout << "\n\nCURSOS DE EXTENSIÓN---MODO COORDINADOR DE RECURSOS\n"
           << endl;
      cout << "Álvaro David Serrano López" << endl;
      cout << "i12seloa@uco.es" << endl;
      
    }
};

#endif