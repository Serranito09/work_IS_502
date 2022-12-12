#include "curso.h"
#include <vector>
#include <string>
using namespace std;

vector<Curso> Curso:: modificarVector(vector<Curso> p,int modificar)
{
    int op;
    int cambiarI;
    string cambiarS;
    for (auto it = p.begin(); it != p.end(); it++)
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
          cout<<"Que nuevo aforo desea ponerle: ";
          cin>> cambiarI;
          (*it).set_Aforo(cambiarI);

        default:
          cout << "opcion no valida\n\n";
          break;
        }
      } while (op != 7);
    }
  }
  return p;
}