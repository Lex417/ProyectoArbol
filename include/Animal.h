#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>

using namespace std;

class Animal
{
    public:
        Animal();
        Animal(int, string);
        void setId(int);
        void setNombre(string);

        int getId();
        string getNombre();
        virtual ~Animal();

    protected:

    private:
        int id;
        string nombre;
};

#endif // ANIMAL_H
