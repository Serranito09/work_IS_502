#include "curso.h"
#include "persona.h"
#include <vector>
#include <string>
#include "bd.h"
void BD::nfC(char *nombreFichero, vector<Curso> *curso)
{
    (*curso).clear();
    ifstream f(nombreFichero);
    if (!f.is_open())
    {
        cout << "Error2, no se puede establecer conexión con la base de datos." << endl;
        exit(-1);
    }

    string datoLeido;
    int id, aforo;
    string nombre, coordinador, descripcion, fechainicio, recurso;
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

        Curso aux(id, nombre, coordinador, fechainicio, descripcion, precio, aforo, recurso);

        (*curso).push_back(aux);
    }

    f.close();
}
void BD::nfP(char *nombreFichero, vector<Persona> *persona)
{

    (*persona).clear();
    ifstream f(nombreFichero);
    if (!f.is_open())
    {
        cout << "Error2, no se puede establecer conexión con la base de datos." << endl;
        exit(-1);
    }

    string datoLeido;
    int id, edad, rol;
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
        getline(f, datoLeido, ';');
        id = stoi(datoLeido);
        getline(f, datoLeido, '\n');
        rol = stoi(datoLeido);
        Persona aux(Dni, nombre, apellidos, edad, lugar, correo, id, rol);

        (*persona).push_back(aux);
    }

    f.close();
}

void BD::mostrarParticipantes(vector<Persona> *personas)
{
    for (auto it = (*personas).begin(); it != (*personas).end(); it++)
    {
        cout << it->getFulldata();
    }
}
void BD::mostrarCursos(vector<Curso> *curso)
{
    for (auto it = (*curso).begin(); it != (*curso).end(); it++)
    {
        cout << it->getData();
    }
}
// Funcion para modificar los cursos
bool BD::modificarCursos(int modificar, vector<Curso> *curso)
{
    int repetir;
    int op;
    int cambiarI;
    string cambiarS;
    Curso c1;
    for (auto it = (*curso).begin(); it != (*curso).end(); it++)
    {
        if (((*it).getid()) == modificar)
        {
            do
            {
                cout << "Introduzca el número correspondiente al parámetro que desee modificar: \n\n";
                cout << "1.Fecha de inicio\n";
                cout << "2.Precio\n";
                cout << "3.Nombre\n";
                cout << "4.Descripcion\n";
                cout << "5.Coordinador\n";
                cout << "6.Aforo\n";
                cout << "7.Recursos\n";
                cout << "8.Salir\n";
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
                    if (c1.comprobarAforo(cambiarI) == false)
                    {
                        for (int i = 0; i < 99; i++)
                        {
                            if (c1.comprobarAforo(cambiarI) == false)
                            {
                                cout << "error no se puede introducir un aforo mayor de 200" << endl;
                            }
                        }
                    }
                    else
                    {
                        (*it).set_Aforo(cambiarI);
                    }
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

bool BD::modificarR(int modificar, vector<Curso> *curso)
{
    int repetir;
    int op;
    int cambiarI;
    string cambiarS;
    Curso c1;
    for (auto it = (*curso).begin(); it != (*curso).end(); it++)
    {
        if (((*it).getid()) == modificar)
        {
            do
            {
                cout << "Introduzca el número correspondiente al parámetro que desee modificar: \n\n";
                cout << "1.Recursos\n";
                cout << "2.Aforo\n";
                cout << "3.Salir\n";
                cin >> op;
                system("clear");
                switch (op)
                {

                case 1:
                    cout << "Introduzca los nuevos recursos: \n ";
                    cin.ignore();
                    getline(cin, cambiarS);
                    (*it).set_Recursos(cambiarS);
                    system("clear");
                    break;

                case 2:
                    cout << "Introduzca el nuevo aforo: ";
                    cin >> cambiarI;
                    if (c1.comprobarAforo(cambiarI) == false)
                    {
                        for (int i = 0; i < 99; i++)
                        {
                            if (c1.comprobarAforo(cambiarI) == false)
                            {
                                cout << "error no se puede introducir un aforo mayor de 200" << endl;
                            }
                        }
                    }
                    else
                    {
                        (*it).set_Aforo(cambiarI);
                    }
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
bool BD::eliminar(int modificar, vector<Curso> *curso)
{
    if (modificar == 0)
    {
        return false;
    }
    for (auto it = ((*curso).begin()); it != ((*curso).end()); it++)
    {
        if (((*it).getid()) == modificar)
        {
            (*curso).erase(it);
            return true;
        }
    }
    return false;
}
// Función para ar un curso
bool BD::insertarCurso(vector<Curso> *curso)
{
    int id, aforo;
    double precio;
    string nombre, descripcion, coordinador, fechaini, recurso;
    Curso c1;
    cout << "Introduzca el id del nuevo curso: \n";
    cin >> id;
    if (c1.comprobarID(id, curso) == true)
    {
        for (int i = 0; i < 99; i++)
        {
            if (c1.comprobarID(id, curso) == true)
            {
                cout << "error esa id no existe,introduzca una correcta" << endl;
                cin >> id;
            }
            else
            {
                c1.set_id(id);
            }
        }
    }
    else
    {
        c1.set_id(id);
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
    if ((c1.comprobarAforo(aforo)) == false)
    {
        for (int i = 0; i < 99; i++)
        {
            if ((c1.comprobarAforo(aforo)) == false)
            {
                cout << "No se ha podido fijar el aforo, recuerde que este debe ser mayor que 0 y menor e igual que 200,introduzca un nuevo aforo correcto\n";
                cin >> aforo;
            }
            else
            {
                c1.set_Aforo(aforo);
            }
        }
    }
    else
    {
        c1.set_Aforo(aforo);
    }
    cout << "Introduzca los recursos del nuevo curso: \n";
    cin.ignore();
    getline(cin, recurso);
    c1.set_Recursos(recurso);
    (*curso).push_back(c1);
    return true;
}

void BD::insertarParticipante(vector<Persona> *personas, vector<Curso> *curso)
{
    int id, edad;
    string nombre, apellidos, correo, lugar, Dni;
    Persona p1;
    Curso c1;
    cout << "Introduzca el DNI del nuevo participante: \n ";
    cin >> Dni;
    if ((p1.ComprobarDni(Dni, (*personas))) == true)
    {
        for (int i = 0; i < 99; i++)
        {
            if ((p1.ComprobarDni(Dni, (*personas))) == true)
            {
                cout << "Este DNI ya pertenece a otra persona, introduzca el DNI correcto: \n";
                cin >> Dni;
            }
        }
    }
    else
    {
        p1.setDni(Dni);
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
    if (c1.comprobarID(id, curso) == false)
    {
        for (int i = 0; i < 99; i++)
        {
            if (c1.comprobarID(id, curso) == false)
            {
                cout << "error esa id no existe,introduzca una correcta" << endl;
                cin >> id;
            }
        }
    }
    else
    {
        p1.setId(id);
    }
    (*personas).push_back(p1);
}

bool BD::inscribirseCurso(int id, string Dni, vector<Curso> *curso, vector<Persona> *personas)
{
    for (auto it = (*curso).begin(); it != (*curso).end(); it++)
    {

        if (((*it).getid()) == id)
        {
            for (auto it2 = (*personas).begin(); it2 != (*personas).end(); it2++)
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
void BD::mostrarCaP(string Dni, vector<Curso> *curso, vector<Persona> *personas)
{
    for (auto it = (*curso).begin(); it != (*curso).end(); it++)
    {
        for (auto it2 = (*personas).begin(); it2 != (*personas).end(); it2++)
        {
            if (((*it).getid()) == ((*it2).getId()) && ((*it2).getDni()) == Dni)
            {
                cout << "Usted está inscrito en el curso de " << (*it).getNombreC() << endl;
            }
        }
    }
}

void BD::mostrarCP(int id, vector<Curso> *curso, vector<Persona> *personas)
{
    for (auto it = (*curso).begin(); it != (*curso).end(); it++)
    {
        for (auto it2 = (*personas).begin(); it2 != (*personas).end(); it2++)
        {
            if (((*it).getid()) == ((*it2).getId()) && ((*it2).getId()) == id)
            {
                cout << (*it2).getFulldata();
            }
        }
    }
}

void BD::backupC(char *nombreFichero, vector<Curso> curso)
{
    ofstream f(nombreFichero);
    if (!f.is_open())
    {
        cout << "Error, no se puede establecer conexión con la base de datos." << endl;
        exit(-1);
    }

    for (auto it = curso.begin(); it != curso.end(); it++)
    {
        f << it->getid() << ";" << it->getNombreC() << ";" << it->getCoordinador() << ";" << it->getFechainicio() << ";" << it->getDescripcion() << ";" << it->getAforo() << ";" << it->get_precio() << ";" << it->getRecursos() << "\n";
    }

    f.close();
}

void BD::backupP(char *nombreFichero, vector<Persona> personas)
{
    ofstream f(nombreFichero);
    if (!f.is_open())
    {
        cout << "Error, no se puede establecer conexión con la base de datos." << endl;
        exit(-1);
    }

    for (auto it = personas.begin(); it != personas.end(); it++)

    {
        f << it->getDni() << ";" << it->getNombreP() << ";" << it->getApellidos() << ";" << it->getEdad() << ";" << it->getLugar() << ";" << it->getCorreo() << ";" << it->getId() << ";" << it->getRol() << "\n";
    }

    f.close();
}

void BD::modificarParticipante(string modificarp, vector<Persona> *personas, vector<Curso> *curso)
{
    int repetir;
    int op;
    int cambiarI;
    string cambiarS;
    Curso c1;
    Persona p1;
    for (auto it = (*personas).begin(); it != (*personas).end(); it++)
    {
        if (((*it).getDni()) == modificarp)
        {
            do
            {
                cout << "Introduzca el número correspondiente al parámetro que desee modificar: \n\n";
                cout << "1.Nombre\n";
                cout << "2.Apellidos\n";
                cout << "3.Correo\n";
                cout << "4.Lugar de Residencia\n";
                cout << "5.Edad\n";
                cout << "6.Id del curso al que pertenece\n";
                cout << "7.Salir\n";
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
                    if (c1.comprobarID(cambiarI, curso) == false)
                    {
                        for (int i = 0; i < 99; i++)
                        {
                            if (c1.comprobarID(cambiarI, curso) == false)
                            {
                                cout << "error esa id no existe,introduzca una correcta" << endl;
                                cin >> cambiarI;
                            }
                        }
                    }
                    else
                    {
                        p1.setId(cambiarI);
                    }
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

bool BD::eliminarP(string modificarp, vector<Persona> *personas)
{
    for (auto it = (*personas).begin(); it != (*personas).end(); it++)
    {
        if (((*it).getDni()) == modificarp)
        {
            (*personas).erase(it);
            return true;
        }
    }
    return false;
}
