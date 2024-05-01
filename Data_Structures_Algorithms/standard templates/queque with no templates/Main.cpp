
#include "Queue.h"

using namespace std;

int main(void)
{
	queueType queue;

	int value;

	for (int counter = 0; counter < 5; counter++)
	{
		queue.Enqueue(counter);
	}

	while (queue.Dequeue(&value))
	{
		// the value to the screen
		printf("%d\n", value);
	}

	return 0;
}