#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


class Persona
{
    private:
    string Dni_;
    string nombre_;
    string apellidos_;
    int edad_;
    string lugar_;
    string correo_;
    int id_;

    public:
    Persona(){};
    Persona(string Dni,string nombre,string apellidos,int edad,string lugar,string correo,int id){
        Dni_=Dni;
        nombre_=nombre;
        apellidos_=apellidos;
        edad_=edad;
        lugar_=lugar;
        correo_=correo;
        id_=id;

    }
    //observadores
    int getId(){
        return id_;
    }
    string getDni(){
        return Dni_;
    }
    string getNombreP(){
        return nombre_;
    }
    string getApellidos(){
        return apellidos_;
    }
    string getfullName(){
        return nombre_+"  "+apellidos_;
    }
    int getEdad(){
        return edad_;
    }
    string getLugar(){
        return lugar_;
    }
    string getCorreo(){
        return correo_;
    }

    string getFulldata(){
        return "DNI: "+Dni_+"\n"
        +"Nombre completo: "+getfullName()+"\n"
        +"Correo: "+correo_+"\n"
        +"Edad: "+ to_string(edad_)+"\n"
        +"Lugar de residencia: "+lugar_+"\n" 
        +"id curso: "+to_string(id_)+"\n\n";
    }

    //modificadores
    bool setDni(string dni){
        if(dni==""){
            return false;
        }
        else{
            Dni_=dni;
            return true;
        }
    }
    void setNombre(string nombre){
        nombre_=nombre;
    }
    void setApellidos(string apellidos){
        apellidos_=apellidos;
    }
    
    bool setEdad(int edad){
        if(edad>99){
            return false;
        }
        else{
            edad_=edad;
            return false;
        }
    }
    bool setLugar(string lugar){
        if(lugar==""){
            return false;
        }
        else{
            lugar_=lugar;
            return true;
        }
    }
    void setCorreo(string correo){
        correo_=correo;
    }
    void setId(int id){
        id_=id;
    }


};



#endif