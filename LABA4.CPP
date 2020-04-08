#include <stdio.h>
#include <conio.h>
#include <dos.h>

#define box 105
#define TonyCount 82
#define A4 440
#define B4 494
#define C5 523
#define D5 587 
#define E5 659
#define G5 784
#define A5 880
#define B5 988
#define C6 1047

#define box2 110
#define RoundaboutCount 32
#define Fd4 370
#define G4  392
#define E4  330
#define D4  294
#define C4  262
#define B3  247
#define A3  220
#define G3  196

#define box3 130
#define ThomasCount 48
#define G6 1568
#define A6 1760
#define B6 1976
#define F6 1397
#define Gd6 1661
#define Fd6 1480
#define Dd6 1245
#define Ad6 1865
#define C7 2093
#define D7 2349
#define E7 2637

#define MAX_VAL 65536

void TonyIgyAstronomia();
void ThomasTheTrain();
void Roundabout();
void DivisionCoefficientComputation();
void StatusWord();
void RandomNumber();

void main()
{
	clrscr();
	char choice;
	do
	{
		printf("1. Tony Igy - Astronomia.\n2. Roundabout.\n3. Thomas the Train.\n4. Status word.\n5. Division coefficient for chanels.\n6. Random number.\n0. Exit.\n");
		rewind(stdin);
		printf("\nYour choise: ");
		scanf("%c", &choice);

		switch (choice)
		{
			case '1': TonyIgyAstronomia(); break;
			case '2': Roundabout(); break;
			case '3': ThomasTheTrain(); break;
			case '4': StatusWord(); break;
			case '5': DivisionCoefficientComputation(); break;
			case '6': RandomNumber(); break;
		}
	} while (choice != '0');
}

void ThomasTheTrain() {
	printf("Thomas The Train\n");

	int frequency[ThomasCount] = { G6, A6, B6, C7, D7, E7, Gd6, A6, F6, A6, G6, G6, A6, F6,
								  F6, A6, G6, Fd6, G6, Fd6, G6, Fd6, G6, G6, Fd6, G6, Fd6, G6,
								  Gd6, Gd6, Gd6, Gd6, Dd6, F6, Fd6, G6, G6, G6, Ad6, Ad6, Ad6, F6,
								  F6, F6, G6, G6, G6, Gd6 };

	int durability[ThomasCount] = { 2 * box3, 0.5 * box3, box3, 3 * box3, box3, 2 * box3, 12 * box3, 2 * box3, box3, box3, 8 * box3,
									box3, 2 * box3, box3, 2 * box3, box3, 3 * box3, box3, box3, box3, box3, box3, 3 * box3, box3,
									box3, box3, box3, box3, box3, box3, box3, box3, box3, box3, box3, box3, box3, box3, box3,
									box3, box3, box3, box3, box3, box3, box3, box3, 4 * box3 };

	int delayCounter[ThomasCount] = { 0, 1.5 * box3, box3, box3, box3, 2 * box3, 4 * box3, 0, box3, box3, box3, 0, 0, box3, 0, 0, box3, 0,0,0,0,0,
									  box3, 6 * box3, 0,0,0, box3, 0,0,box3, 5 * box3, box3,box3,box3, 0,0, box3,0,0,box3, 0,0,box3, 0,0,box3,0 };
	long unsigned base = 1193180;
	int frequencyCounter;
	int divisionCoefficient;

	for (frequencyCounter = 0; frequencyCounter < ThomasCount; frequencyCounter++)
	{
		outp(0x43, 0xB6);
		divisionCoefficient = base / frequency[frequencyCounter];
		outp(0x42, divisionCoefficient % 256);									//Low
		divisionCoefficient /= 256;												//Pause
		outp(0x42, divisionCoefficient);										//High
		outp(0x61, inp(0x61) | 3);                                              //Turn on    
		delay(durability[frequencyCounter]);                                    //Wait
		outp(0x61, inp(0x61) & 0xFC);									        //Turn off
		delay(delayCounter[frequencyCounter]);									//Delay
	}
}

void Roundabout() {
	printf("Roundabout\n");

	int frequency[RoundaboutCount] = { Fd4, G4, Fd4, E4, D4, E4, D4, C4, B3, D4, B3, C4, A3, B3, G3, A3,
							  E4, E4, Fd4, G4, Fd4, G4, Fd4, G4, Fd4, E4, E4, E4, Fd4, G4, Fd4, E4 };

	int durability[RoundaboutCount] = { box2, box2, box2, box2, box2, box2, box2, box2, box2, box2, box2,
							   box2, box2, box2, box2, box2, box2, box2, box2, box2, box2, box2,
							   box2, box2, box2, box2, box2, box2, box2, box2, box2, box2, };
	int delayCounter[RoundaboutCount] = { box2, 0, 0, box2, box2, box2, box2, box2, box2, box2, box2,
								 box2, box2, box2, box2, box2, 3 * box2, box2, 3 * box2, 3 * box2, 3 * box2, 3 * box2,
								 box2, 5 * box2, 3 * box2, box2, 3 * box2, 3 * box2, box2, 0 };
	long unsigned base = 1193180;
	int frequencyCounter;
	int divisionCoefficient;

	for (frequencyCounter = 0; frequencyCounter < RoundaboutCount; frequencyCounter++)
	{
		outp(0x43, 0xB6);
		divisionCoefficient = base / frequency[frequencyCounter];
		outp(0x42, divisionCoefficient % 256);									//Low
		divisionCoefficient /= 256;												//Pause
		outp(0x42, divisionCoefficient);										//High
		outp(0x61, inp(0x61) | 3);                                              //Turn on    
		delay(durability[frequencyCounter]);                                    //Wait
		outp(0x61, inp(0x61) & 0xFC);									        //Turn off
		delay(delayCounter[frequencyCounter]);									//Delay
	}
}

void TonyIgyAstronomia() {
	printf("Tony Igy - Astronomia\n");

	int frequency[TonyCount] = { C5, C5, C5, C5, E5, E5, E5, E5,
							 D5, D5, D5, D5, G5, G5, G5, G5,
							 A5, A5, A5, A5, A5, A5, A5, A5,
							 A5, A5, A5, A5, E5, D5, C5, B4,

							 A4, A4, E5, D5, C5, B4, B4, B4,
							 D5, C5, B4, A4, A4, C6, B5, C6,
							 B5, C6, A4, A4, C6, B5, C6, B5, C6,
							 A4, A4, E5, D5, C5, B4, B4, B4,
							 D5, C5, B4, A4, A4, C6, B5, C6,
							 B5, C6, A4, A4, C6, B5, C6, B5, C6 };

	int durability[TonyCount] = { (2 * box) - 10, (2 * box) - 10, (2 * box) - 10, (2 * box) - 10,
							  (2 * box) - 10, (2 * box) - 10, (2 * box) - 10, (2 * box) - 10,
							  (2 * box) - 10, (2 * box) - 10, (2 * box) - 10, (2 * box) - 10,
							  (2 * box) - 10, (2 * box) - 10, (2 * box) - 10, (2 * box) - 10,
							  box, box, box, box, box, box, box, box, box, box, box, box,
							  2 * box, 2 * box, 2 * box, 2 * box,

							  2 * box, 2 * box, 2 * box, 2 * box, 2 * box, 2 * box, 2 * box,
							  2 * box, 2 * box, 2 * box, 2 * box, 3 * box, 2 * box,
							  2 * box, 2 * box, 2 * box, 2 * box, 2 * box, 2 * box,
							  2 * box, 2 * box, 2 * box, 2 * box, 2 * box, 2 * box,
							  2 * box, 2 * box, 2 * box, 2 * box, 2 * box, 2 * box, 2 * box,
							  2 * box, 2 * box, 2 * box, 2 * box, 3 * box, 2 * box,
							  2 * box, 2 * box, 2 * box, 2 * box, 2 * box, 2 * box,
							  2 * box, 2 * box, 2 * box, 2 * box, 2 * box, 2 * box };
	int delayCounter[TonyCount] = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
								box, box, box, box, box, box, box, box, box, box, box, box , 0, 0 ,0, 0,

								2 * box, 0, 0, 2 * box, 2 * box, 2 * box, 0, 0, 2 * box, 0, 0, box, 0, 0, 0, 0, 0, 0, 2 * box, 0, 0, 0, 0, 0, 20,
								2 * box, 0, 0, 2 * box, 2 * box, 2 * box, 0, 0, 2 * box, 0, 0, box, 0, 0, 0, 0, 0, 0, 2 * box, 0, 0, 0, 0 };
	long unsigned base = 1193180;
	int frequencyCounter;
	int divisionCoefficient;

	for (frequencyCounter = 0; frequencyCounter < TonyCount; frequencyCounter++)
	{
		outp(0x43, 0xB6);
		divisionCoefficient = base / frequency[frequencyCounter];
		outp(0x42, divisionCoefficient % 256);									//Low
		divisionCoefficient /= 256;												//Pause
		outp(0x42, divisionCoefficient);										//High
		outp(0x61, inp(0x61) | 3);                                              //Turn on
		delay(durability[frequencyCounter]);                                    //Wait
		outp(0x61, inp(0x61) & 0xFC);									        //Turn off
		delay(delayCounter[frequencyCounter]);									//Delay
	}
}

void DivisionCoefficientComputation()
{
	unsigned long j;
	int Channel;
	int ports[] = { 0x40, 0x41, 0x42 };
	int controlWords[] = { 0, 64, 128 };
	unsigned divisionCoefficientLow, divisionCoefficientHigh, divisionCoefficient, max;

	printf("\n\nCoefficient of division: \n");

	for (Channel = 0; Channel < 3; Channel++)
	{
		divisionCoefficient = 0;
		max = 0;

		if (Channel == 2)
			outp(0x61, inp(0x61) | 3);		//turn ON

		for (j = 0; j < MAX_VAL; j++)
		{
			outp(0x43, controlWords[Channel]);
			divisionCoefficientLow = inp(ports[Channel]);
			divisionCoefficientHigh = inp(ports[Channel]);
			divisionCoefficient = divisionCoefficientHigh * 256 + divisionCoefficientLow;

			if (divisionCoefficient > max)
			{
				max = divisionCoefficient;
			}
		}
		if (Channel == 2)
			outp(0x61, inp(0x61) & 0xFC);	//turn OFF
		printf("\nChannel %d: %4X\n", Channel, max);
	}
}

void StatusWord()
{
	printf("\n\nStatus word: \n");
	char stateWord[8];
	int Channel, state;
	int ports[] = { 0x40, 0x41, 0x42 };
	int controlWords[] = { 226, 228, 232 };		//command words,
												//acording to the rules

	for (Channel = 0; Channel < 3; Channel++)
	{
		outp(0x43, controlWords[Channel]);
		state = inp(ports[Channel]);            //read state

		for (int i = 7; i >= 0; i--)
		{
			stateWord[i] = state % 2 + '0';
			state /= 2;
		}
		printf("\nChannel %d: ", Channel);
		for (i = 0; i < 8; i++)
		{
			printf("%c", stateWord[i]);
		}
		printf("\n");
	}
}

void RandomNumber()
{
	char choice;
	unsigned int limit = MAX_VAL - 1, numberLow, numberHigh, number;

	do
	{
		printf("\n\n1. Set higher bound.\n2. Get random number.\n0. Exit\n");
		fflush(stdin);
		printf("\nChoise: ");
		scanf("%s", &choice);

		switch (choice)
		{
		case '1':
		{
			do
			{
				printf("\nEnter a limit in range [+1 ; +65635].\n");
				fflush(stdin);
			} while (!scanf("%d", &limit) || limit < 1);

			outp(0x43, 0xB4);
			outp(0x42, limit % 256);
			limit /= 256;
			outp(0x42, limit);
			outp(0x61, inp(0x61) | 1);
			break;
		}
		case '2':
		{
			outp(0x43, 128);
			numberLow = inp(0x42);
			numberHigh = inp(0x42);
			number = numberHigh * 256 + numberLow;

			printf("\nRandom number: %u\n", number);

			break;
		}
		}
	} while (choice != '0');
	outp(0x61, inp(0x61) & 0xFC);
}