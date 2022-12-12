#include <string.h>
#include "curso.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int op, cambiarI,modificar;
  string cambiarS; // variables para cambiar datos
  Curso c1;                   // objeto curso
  vector<Curso> p;            // vector de cursos

  // insertar
  for (int i = 0; i < 4; i++)
  {
    c1.set_Dni(i);
    c1.set_Precio(4.3);
    c1.set_nombre("alvaro");
    c1.set_Descripcion("esta es una pequeña descripcion");
    c1.set_Coordinador(to_string(i));
    p.push_back(c1);
  }
  // mostrar
  for (auto it = p.begin(); it != p.end(); it++)
  {
    cout << (*it).getData();
  }

  // modificar
  cout << "Que curso desea cambiar\n";
  cin >> modificar;
  system("clear");
 p=c1.modificarVector(p,modificar);

  // eliminar
  for (auto it = p.begin(); it != p.end(); it++)
  {
    cout << (*it).getData();
  }
  cout << "Que curso desea eliminar\n";
  cin >> modificar;
  system("clear");
  for (auto it = p.begin(); it != p.end(); it++)
  {
    if (((*it).getDni()) == modificar)
    {
      p.erase(it);
      break;
    }
  }
  // mostrar
  for (auto it = p.begin(); it != p.end(); it++)
  {
    cout << (*it).getData();
  }
}
