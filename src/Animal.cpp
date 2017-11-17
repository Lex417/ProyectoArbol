#include "Animal.h"

Animal::Animal()
{
   id = 0;
   nombre = "";
}
Animal::Animal(int id, string nombre)
{
    this->id = id;
    this->nombre = nombre;
}
void Animal::setId(int id)
{
    this->id = id;
}
void Animal::setNombre(string nombre)
{
    this->nombre=nombre;
}
int Animal::getId()
{
    return id;
}
string Animal::getNombre()
{
    return nombre;
}
Animal::~Animal()
{
    //dtor
}
