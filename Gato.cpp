#include "Gato.h"

Gato::Gato(int edad, char sexo, string nombre, string raza)
{
    this->edad = edad;//4+1+10+10
    this->sexo = sexo;
    this->nombre = nombre;
    this->raza = raza;
}

Gato::~Gato()
{
    //dtor
}
