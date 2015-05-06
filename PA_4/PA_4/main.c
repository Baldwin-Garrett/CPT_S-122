#include "Header.h"

int main (void)
{
	Queue expressQueue, normalQueue;

	unsigned long time_index = 0, simulation_time = 0,
		arrival_flag_standard = 0, arrival_flag_express = 0,
		id_index = 1;

	int n = 0, departure_countdown_standard = 0, departure_countdown_express = 0;

	srand ((unsigned int)time (NULL));

	init_queue (&expressQueue);
	init_queue (&normalQueue);

	//scan for length of simulation
	printf ("Please enter the simulation time (minutes):");
	scanf ("%lu",  &simulation_time);
	simulation_time++;

	system ("cls");

	//main simulation loop
	for (time_index = 0; time_index < simulation_time; time_index++)
	{
		//check if new customers arrived
		if (time_index >= arrival_flag_standard)
		{
			n = getServiceTime ();
			enqueue (&normalQueue, id_index, n);
			arrival_flag_standard = getServiceTime () + time_index;
			id_index++;
		}
		if (time_index >= arrival_flag_express)
		{
			n = getExpressTime ();
			enqueue (&expressQueue, id_index, n);
			arrival_flag_standard = getExpressTime () + time_index;
			id_index++;
		}
		//check if customer in checkout is leaving
		if (!departure_countdown_standard)
		{
			//dequeue customer
			dequeue (&normalQueue);
			//set departure flag to next customer
			departure_countdown_standard = getServiceTime ();
		}
		else
		{
			--departure_countdown_standard;
		}
		if (!departure_countdown_express)
		{
			//dequeue customer
			dequeue (&expressQueue);
			//set departure flag to next customer
			departure_countdown_express = getExpressTime ();
		}
		else
		{
			--departure_countdown_express;
		}
		//check if time index is a multiple of 10 for a print of the lines
		if (time_index % 10 == 0)
		{
			system ("cls");
			printf ("Standard lane:\n");
			printQueue (&normalQueue);

			system ("pause");

			system ("cls");

			printf ("Express lane:\n");
			printQueue (&expressQueue);

			system ("pause");
		}
	}
	return (0);
}