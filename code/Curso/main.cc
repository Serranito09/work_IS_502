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
  vector<Curso> p; // vector de cursos
  char fichero[] = "curso.txt";
  char fichero1[]="participante.txt";
  BD bd;
  bd.nfP(fichero1);
  bd.nfC(fichero);//vuelco el fichero en un vector
  bd.menu();
  bd.backup(fichero1);
  bd.backup(fichero);
}
