// header guards
#ifndef OBJECTS_H
#define OBjECTS_H

// preprocessor directives
#include <iostream>
#include <string>

// namespace prevents variable name conflicts when multiple files are merged
// ex: sally::cost (:: is scope resolution operator) & bill::cost, both have same
// variable names, but they don't conflict because they're using namespace
// namespace std allows you to use cin, cout without syntax std::cin, std::cout
// using is a keyword
using namespace std;

// declare class (only syntax difference is declaring class instead of structure)
class vehicleType
{
    // declare public function so can be seen by main code, in object oriented programming, data is private by default
public:
    // this is called a CONSTRUCTOR
    // no return type on a CONSTRUCTOR
    // CONSTRUCTOR name is the same as CLASS NAME
    vehicleType() { cout << "Object Created" << endl; }

    // CONSTRUCTOR with OVERLOADED FUNCTION; can use as many CONSTRUCTOR OVERLOAD as you want
    vehicleType(string carName) { name = carName; }
    vehicleType(bool radio);

    // declare function prototype inside a class, is called METHOD
    void SetName(string newCar);

    void PrintHasRadio(int index) { cout << "Radio # " << index << ": " << hasARadio << endl; }
    void PrintHasRadio(void) { cout << "Radio present: " << hasARadio << endl; }

    // function prototype with inline function is the {;} part, ; needs to be inside{}; this is an inline METHOD
    void SetTires(int tires)
    {
        numberOfTires = tires;
    }
    void SetHasRadio(bool value) { hasARadio = value; }

    // DESTRUCTOR starts with '~'
    // DESTRUCTOR CANNOT BE OVERLOADED & CANNOT HAVE PARAMETERS
    ~vehicleType()
    {
        static int count = 0;
        count++;
        cout << "Object number " << count << " has been destroyed" << endl;
    }

    // protected class can be seen child class, in between public and private in terms of visibility
protected:
    // method is function inside a class
    void ClearName(void) { name = ""; }

private:
    string name;
    int numberOfTires;
    bool hasARadio;
};

// class car can see public class of vehicleType, but not private; class by default is private though, so need to set public
class car : public vehicleType
{
public:
    car() { SetName("Toyoter"); }

    // SetName is a public function, so it can be seen by class car
    car(string newName) { SetName(newName); }

    void foo()
    {
        cout << "Called from parent" << endl;
    }

    // destructor ~ and has same name as class, can have no parameters
    ~car() { ClearName(); }

private:
    int value;
};

class bike : public vehicleType
{
public:
    bike()
    {
        SetHasRadio(false);
        SetTires(2);
    }

    void foo() { cout << "Called from bike" << endl; }

private:
    string pedals;
    string handleBars;
};

// function prototype declarations
void allCarsToHaveARadio(vehicleType arrayOfCars[], int size);
void PrintRadio(vehicleType array[], int size);

// close header guard
#endif