#include <string.h>
#include "curso.h"
#include <iostream>
#include <vector>
#include "bd.h"

using namespace std;

int main()
{
  int op, cambiarI, modificar;
  string cambiarS; // variables para cambiar datos
  Curso c1;        // objeto curso
  vector<Curso> c;
  vector<Persona> p; // vector de cursos
  char fichero[] = "curso.txt";
  char fichero1[] = "participante.txt";
  BD bd;
  bd.nfP(fichero1,&p);
  bd.nfC(fichero,&c); // vuelco el fichero en un vector
  bd.menu(&c,&p);
  bd.backupP(fichero1,p);
  bd.backupC(fichero,c);

}
