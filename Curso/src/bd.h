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
  

public:
    void nfC(char *nombreFichero,vector<Curso>curso);
    void nfP(char *nombreFichero,vector<Persona>persona);
    void mostrarParticipantes(vector<Persona> *personas);
    void mostrarCursos(vector<Curso> *curso);
    bool modificarCursos(int modificar, vector<Curso> *curso);
    bool modificarR(int modificar, vector<Curso> *curso);
    bool eliminar(int modificar, vector<Curso> *curso);
    bool insertarCurso(vector<Curso> *curso);
    void insertarParticipante(vector<Persona> *personas, vector<Curso> *curso);
    bool inscribirseCurso(int id, string Dni, vector<Curso> *curso, vector<Persona> *personas);
    void mostrarCaP(string Dni, vector<Curso> curso, vector<Persona> personas);
    void mostrarCP(int id, vector<Curso> curso, vector<Persona> personas);
    void backupC(char *nombreFichero, vector<Curso> curso);
    void backupP(char *nombreFichero, vector<Persona> personas);
    void menu(vector<Curso> *curso, vector<Persona> *persona);
    void menu_administrador(vector<Curso> *curso, vector<Persona> *persona);
    void menu_visitante(vector<Curso> *curso, vector<Persona> *persona);
    void menu_coordinador_de_cursos(vector<Curso> *curso, vector<Persona> *persona);
    void menu_participante(vector<Curso> *curso, vector<Persona> *persona);
    void menu_coordinador_de_recursos(vector<Curso> *curso, vector<Persona> *persona);
    void modificarParticipante(string modificarp, vector<Persona> *personas, vector<Curso> *curso);
    bool eliminarP(string modificarp, vector<Persona> *personas);
    bool Contacto();
};

#endif