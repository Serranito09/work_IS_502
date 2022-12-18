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
    int rol_;

public:
    Persona(string Dni = "empty", string nombre = "empty", string apellidos = "empty", int edad = 0, string lugar = "empty", string correo = "empty", int id = 0, int rol = 0)
    {
        Dni_ = Dni;
        nombre_ = nombre;
        apellidos_ = apellidos;
        edad_ = edad;
        lugar_ = lugar;
        correo_ = correo;
        id_ = id;
        rol_ = rol;
    }
    // observadores
    int getRol()
    {
        return rol_;
    }
    int getId()
    {
        return id_;
    }
    string getDni()
    {
        return Dni_;
    }
    string getNombreP()
    {
        return nombre_;
    }
    string getApellidos()
    {
        return apellidos_;
    }
    string getfullName()
    {
        return nombre_ + "  " + apellidos_;
    }
    int getEdad()
    {
        return edad_;
    }
    string getLugar()
    {
        return lugar_;
    }
    string getCorreo()
    {
        return correo_;
    }

    string getFulldata()
    {
        return "DNI: " + Dni_ + "\n" + "Nombre completo: " + getfullName() + "\n" + "Correo: " + correo_ + "\n" + "Edad: " + to_string(edad_) + "\n" + "Lugar de residencia: " + lugar_ + "\n" + "id curso: " + to_string(id_) + "\n\n";
    }

    // modificadores
    void setDni(string dni)
    {
        Dni_ = dni;
    }
    void setNombre(string nombre)
    {
        nombre_ = nombre;
    }
    void setApellidos(string apellidos)
    {
        apellidos_ = apellidos;
    }

    void setEdad(int edad)
    {
        edad_ = edad;
    }
    void setLugar(string lugar)
    {

        lugar_ = lugar;
    }
    void setCorreo(string correo)
    {
        correo_ = correo;
    }
    void setId(int id)
    {
        id_ = id;
    }
    void setRol(int rol)
    {
        rol_ = rol;
    }

    bool ComprobarDni(string dni, vector<Persona> p)
    {
        for (auto it = p.begin(); it != p.end(); it++)
        {
            if (((*it).getDni()) == dni)
            {
                return true;
            }
        }
        return false;
    }
    int ComprobarRol(string dni,vector<Persona>*p)
    {
        for(auto it=(*p).begin();it!=(*p).end();it++){
            if((*it).getDni()==dni){
                return (*it).getRol();
            }
        }
        return 0;
    
    }
};

#endif