
#ifndef OBJECTSEX_H
#define OBJECTSEX_H

#include <iostream>
#include <string>

using namespace std;

class vechicleType
{
public:
    // Constructor
    // There is never a return type on a constructor
    // The constructor name is the same as the class name
    vechicleType() { cout << "Object Created" << endl; }

    // This is a constructor overload
    // You can have as many overloads as you want
    vechicleType(string carName) { name = carName; }
    vechicleType(bool radio);

    // Function inside a class is called method.
    void SetName(string newCar);

    void PrintHasRadio(int index);

    virtual void foo(void) = 0;

    void PrintHasRadio(void)
    {
        cout << "Radio present: " << hasARadio << endl;
    }

    // Methods written inside a class are called in-line
    void SetTires(int tires) { numberOfTires = tires; }
    void SetHasRadio(bool value) { hasARadio = value; }

    // Destructor -- Always starts with a ~
    // Destructor CANNOT be overloaded and CANNOT have parameters
    ~vechicleType()
    {
        static int count = 0;
        count++;

        cout << "Object number " << count << " has been destroyed" << endl;
    }

protected:
    void ClearName(void)
    {
        name = "";
        cout << "Name is clear\n";
    }

private:
    string name;
    int numberOfTires;
    bool hasARadio;
};

class car : public vechicleType
{
public:
    car() { SetName("Racer"); }
    car(string newName) { SetName(newName); }

    void foo() { cout << "Called from car\n"
                      << endl; }

    ~car() { ClearName(); }

private:
    int value;
};

class bike : public vechicleType
{
public:
    bike()
    {
        SetHasRadio(false);
        SetTires(2);
    }

    void foo(void) { cout << "Called from bike\n"; }

private:
    string peddals;
    string handleBars;
};

#endif
