#ifndef CURSO_H
#define CURSO_H
#include <string>
#include <iostream>
#include <cmath>
using namespace std;


class Curso
{
    private:
        string id_;//int
        string nombre_;
        string coordinador_;//quitarlo
        int fechainicio_;//quitarlo
        double precio_;
        string descripcion_ ;
        //añadir double precio,int aforo,int fechainicio,string coordinador,string descripcion
        //menu:opciones Mostrar cursos,Añadir eliminar cursos,contacto,modificar cursos,inscribirse

    public:
    Curso(){};
    Curso(string id,string nombre,string coordinador,int fechainicio,string descripcion,double precio){
        id_=id;
        nombre_=nombre;
        coordinador_=coordinador;
        fechainicio_=fechainicio;
         descripcion_=descripcion;
        precio_=precio;
    }
    

    //Observadores
    string getDni(){
        return id_;
    }
    string getNombre(){
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
        return "id: "+id_+"\n"+  
        "Nombre: "+nombre_+"\n"
        +"Coordinador: "+coordinador_+" \n"
        +"Fecha inicio: "+to_string(fechainicio_)+ "\n"
        +"Descripcion: "+descripcion_+"\n"
        +"Precio: "+to_string(precio_)+"\n"
        +"\n";
    }

    //Modificadores
    bool set_Dni(string id){
        if(id ==" "){
            return false;
        }
        else{
            id_=id;
            return true;
        }
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

