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
  BD bd(fichero);//vuelco el fichero en un vector
  bd.mostrarCursos();
  bd.insertar();
  cout << "Que curso desea cambiar\n";
  cin >> modificar;
  bd.modificarCursos(modificar);
  bd.mostrarCursos();
  cout << "Que curso desea eliminar\n";
  cin >> modificar;
  system("clear");
  bd.eliminar(modificar);
  bd.mostrarCursos();
  bd.backup(fichero);
}
