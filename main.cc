#include <string.h>
#include "persona.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int op,cambiarI;
    string modificar,cambiarS;//variables para cambiar datos
    Curso c1;//objeto curso
   vector <Curso> p;//vector de cursos
  
  
   //insertar
   for(int i=0;i<4;i++){
    c1.set_Dni(to_string(i));
    c1.set_Precio(4.3);
    c1.set_nombre("alvaro");
    c1.set_Descripcion("esta es una pequeña descripcion");
    c1.set_Coordinador(to_string(i));
        p.push_back(c1);
   }
    //mostrar
      for(auto it=p.begin();it!=p.end();it++){
      cout<<(*it).getData();
      }
      
      //modificar
      cout<<"Que curso desea cambiar\n";
      cin>>modificar;
        system("clear");  
      for(auto it=p.begin();it!=p.end();it++){
        if(((*it).getDni())==modificar){
            do
            {
                  cout<<"Que desea modificar\n\n";
            cout<<"1--->Fecha de inicio\n";
            cout<<"2--->Precio\n";
            cout<<"3--->Nombre\n";
            cout<<"4--->Descripcion\n";
            cout<<"5--->Coordinador\n";
            cout<<"6--->Salir\n";
            cin>>op;
            system("clear");
            switch (op)
            {
            case 1:
                cout<<"Que nueva Fecha de inicio desea introducir\n";
                cin>>cambiarI;
                (*it).set_Fechainicio(cambiarI);
                system("clear");
                break;
            case 2:
                cout<<"Que nuevo precio desea ponerle: ";
                cin>>cambiarI;
                (*it).set_Precio(cambiarI);
                system("clear");
                break;
            case 3:
                cout<<"Que nuevo nombre desea ponerle: ";
                cin>>cambiarS;
                (*it).set_nombre(cambiarS);
                system("clear");
                break;
            case 4:
                cout<<"Que nueva Descripcion desea ponerle: ";
                cin.ignore();
                getline(cin,cambiarS);
                (*it).set_Descripcion(cambiarS);
                system("clear");
                break;
            case 5:
                    cout<<"Que nuevo Coordinador desea ponerle: ";
                    cin>>cambiarS;
                (*it).set_Coordinador(cambiarS);
                system("clear");
                break;
            default:
            cout<<"opcion no valida\n";
                break;
            }
            } while (op!=6);
            
           
      }
}
     
  //eliminar   
for(auto it=p.begin();it!=p.end();it++){
      cout<<(*it).getData();
      }
      cout<<"Que curso desea eliminar\n";
      cin>>modificar;
        system("clear");
      for(auto it=p.begin();it!=p.end();it++){
        if(((*it).getDni())==modificar){
            p.erase(it);
            break;
        }

}
//mostrar
for(auto it=p.begin();it!=p.end();it++){
      cout<<(*it).getData();
      }
}


