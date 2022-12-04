// objects are in cpp, not c
// difference between structure and class:
// classes defaut to private, structures default to public

// preprocessor directives
#include "objects.h"

// main function
int main()
{
    vehicleType *pointerArray[2];

    pointerArray[0] = new car();
    pointerArray[1] = new bike();

    /*for (int index = 0; index < 2; index++)
    {
        pointerArray[index]->foo();
    }

    for (int index = 0; index < 2; index++)
    {
        delete pointerArray[index];
    }
    */

    car newCar("Doggo");

    newCar.SetTires(4);

    newCar.foo();

    bike tike;

    tike.foo();

    // call class and define; carA is called an INSTANCE, the variable is called the OBJECT
    // instance of class is called an object
    // vehicleType carA;

    // call second constructor by passing in string "skull"
    // vehicleType carA("Skull");

    // create an array of five cars
    vehicleType carA[5];

    PrintRadio(carA, 5);
    allCarsToHaveARadio(carA, 5);

    // set variables: carA.n, will list all declare varibles in structure
    // but class is private, so can't see variables in class when using carA.n
    // resolve this by declaring class as public: inside class {} in header file
    // carA.name = "My Car";
    // carA.hasARadio = true;
    // carA.numberOfTires = 4;

    // after declaring function prototype inside public class with inline function in header file
    // carA.SetName("Beast");
    // carA.SetHasRadio(true);
    // carA.SetTires(4);

    return 0;
}

// this is a normal function
void allCarsToHaveARadio(vehicleType arrayOfCars[], int size)
{
    for (int index = 0; index < size; index++)
    {
        // set every carA array element to have a radio
        arrayOfCars[index].SetHasRadio(true);
    }
}

void PrintRadio(vehicleType array[], int size)
{
    for (int index = 0; index < size; index++)
    {
        array[index].PrintHasRadio(index);
    }
}

// need to use scope resolution operator to call class function
// this class public function has access to all class private data
void vehicleType::SetName(string newCar)
{
    // can call a class private data without re-declaring variable
    name = newCar;
}

// need to declare vehicleType prototype in class
vehicleType::vehicleType(bool radio)
{
    // "this." gives list of all public and private variables; becomes "this->" when executed
    // "this." is a pointer that points back to itself, in this case "carA"
    // orange box is PUBLIC; green box is PRIVATE#
    this->hasARadio = radio;
}