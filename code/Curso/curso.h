#ifndef CURSO_H
#define CURSO_H
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Curso
{
    private:
        int id_;//int
        string nombre_;
        string coordinador_;
        int fechainicio_;
        double precio_;
        string descripcion_ ;
        int aforo_;

        //añadir double precio,int aforo,int fechainicio,string coordinador,string descripcion
        //menu:opciones Mostrar cursos,Añadir eliminar cursos,contacto,modificar cursos,inscribirse

    public:
    Curso(){
        aforo_=1;
    };
    Curso(int id,string nombre,string coordinador,int fechainicio,string descripcion,double precio,int aforo=1){
        id_=id;
        nombre_=nombre;
        coordinador_=coordinador;
        fechainicio_=fechainicio;
         descripcion_=descripcion;
        precio_=precio;
        aforo_=aforo;
    }
    

    //Observadores
    int getaforo(){
        return aforo_;
    }
    int getid(){
        return id_;
    }
    string getNombreC(){
        return nombre_;
    }
    string getCoordinador(){
        return coordinador_;
    }
    double getFechainicio(){
        return fechainicio_;
    }
    string getDescripcion(){
       return descripcion_;
    }
    double get_precio(){
        return precio_;
    }
    
    string getData(){
        return "id: "+to_string(id_)+"\n"+  
        "Nombre: "+nombre_+"\n"
        +"Coordinador: "+coordinador_+" \n"
        +"Fecha inicio: "+to_string(fechainicio_)+ "\n"
        +"Descripcion: "+descripcion_+"\n"
        +"Aforo: "+to_string(aforo_)+"\n"
        +"Precio: "+to_string(precio_)+"\n"
        +"\n";
    }

    int getAforo()
    {
        return aforo_;
    }

    //Modificadores

    bool set_Aforo(int aforo){
        if(aforo==0){
            return false;
        }
        else{
            aforo_=aforo;
            return true;
        }
    }
    bool set_id(int id,vector<Curso> c){
      for(auto it=c.begin();it!=c.end();it++){
        if(((*it).getid())==id){
            return false;
        }
      }
      return true;
    }
    bool set_nombre(string nombre){
        if(nombre ==" "){
            return false;
        }
        else{
            nombre_=nombre;
            return true;
        }
    }
    void set_Fechainicio(double fechainicio){
        fechainicio_=fechainicio;
        }


    void set_Descripcion(string  descripcion ){
        descripcion_=descripcion ;
    }
    void set_Precio(double precio){
        precio_=precio;
    }
    void set_Coordinador(string coordinador){
        coordinador_=coordinador;
    }

    


};

#endif

