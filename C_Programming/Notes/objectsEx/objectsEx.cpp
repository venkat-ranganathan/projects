
#include "objectsEx.h"

int main(void)
{
	vechicleType *pointerArray[2];

	pointerArray[0] = new car();
	pointerArray[1] = new bike();

	for (int index = 0; index < 2; index++)
	{
		pointerArray[index]->foo();
	}

	for (int index = 0; index < 2; index++)
	{
		delete pointerArray[index];
	}
	car newCar("Dancer");

	newCar.SetTires(4);

	newCar.foo();

	bike tike;

	tike.foo();

	return 0;
}

void vechicleType::SetName(string newCar)
{
	name = newCar;
}

vechicleType::vechicleType(bool radio)
{
	hasARadio = radio;
}

void vechicleType::PrintHasRadio(int index)
{
	cout << "Radio # " << index << ": " << hasARadio << endl;
}