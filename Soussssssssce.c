#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
///Assaignment:1
//Author:Ron Abutbul,ID:315333237
enum Bool { TRUE, FALSE };
int Sieres(int Num);
int CheckTowPrimes(int Num);
int PrintTowPrime();
int Power(int base, int exp);
long Omit(int Num, int Digit);
//int Third(int Num);
void Rectangle(int rows, int cols);

int main()
{
	// Get the number 
	int Num;
	int Digit;
	printf("plase enter a Row\n");
	scanf("%d", &Num);
	printf("plase enter a Colm\n");
	scanf("%d", &Digit);
	Rectangle(Num, Digit);
	return 0;

}

int Sieres(int Num)
{

	int Length = 0, Odd = 0, SumEven = 0, Even = 0, Max = 0, Min = 0;
	Min = Num;
	Max = Num;
	if (Num < 0)
		printf("Please enter a number  above 0");
	else {
		while (Num > 0)
		{
			Length++;
			printf("Pleas enter a number:\n");//inform the user
			scanf("%d", &Num);//get input
			if (Num % 2 == 0)
				Odd++;
			else
				SumEven = SumEven + Num;
			if (Num >= Max)
				Max = Num;
			if ((Num <= Min) && (Num > 0))
				Min = Num;
		}
		printf("Length= %d\n", Length);
		printf("Odd =%d\n", Odd);
		printf("Sum Even=%d\n", SumEven);
		printf("Max=%d\n", Max);
		printf("Min=%d\n", Min);
	}
	return 0;

}

int CheckTowPrimes(int Num) {
	int Counter = 0, i;
	//scan for  2 semiprime
	//if the counter is above 2 that mean
	//there are more then 2 prime dividers
	for (i = 2; (i < Num) && (Counter < 2); ++i)
	{
		 
		while (Num%i == 0)
		{
			Num = Num / i;
			Counter++;
		}
	}
	//if the number is above 1 add to the prieme counter
	//that mean the number remain is a prime number
	if (Num > 1)
		Counter++;
	//if the cunter is 2 that means that divde by 2 prime
	if (Counter == 2)
		return TRUE;
	else
	{
		return FALSE;
	}

}

int PrintTowPrime() {
	//declare variables
	int Counter = 0;
	int i;
	for (int i = 100; i <= 999; i++)
	{
		//print all the proudoct of prime numbers
		if (CheckTowPrimes(i) == TRUE) {
			//count how much proudoct of prime numbers
			Counter++;
			printf("%d\t", i);
		}
	}
	return Counter;
}

int Power(int base, int exp)
{
	//A power function-exmp-5^2=25
	int result = 1;
	for (int i = 1; i <= exp; i++)
		result = result * base;
	return result;
}

long Omit(int Num, int Digit)
{
	
	int New_Num = 0, Counter = 0;
	//Only numbers between 0-9
	if (Digit >= 0 && Digit < 9) {
		// Loop with the number
		for (int i = 0; Num > 0; i++) {
			//scan the lastdigit
			int Lastdigit = (Num % 10);
			//set the new num
			Num = Num / 10;
			
			if (Digit != Lastdigit)
			{
				//form the new number 
				New_Num = New_Num + Lastdigit * Power(10, Counter);
				Counter++;
			}
		}
		return New_Num;
	}
	else
		return Num;
}

/*int Third(int Num)
{
	int Length = 0, Max = Num, Second = 0, Thired = 0;
	while (Num>0)
	{
		//Length++;
		//if (Max <= Num)
		//	Max = Num;
		if (true)
		{

		}

	}



}
*/
void Rectangle(int rows, int cols)
{
	int i, j,Counter=1;
	for (i = 1; i <= rows; i++)
	{
		for (j = 1; j <= cols; j++)
		{
			//for the
			if (i == rows || i == 1)
				printf("1");
			else
			{
				if (j == 1 || j == cols)
						printf("1");
				else if (Counter > 1)
						Counter++;
				else if (i == Counter || i == rows-1)
					printf("%d",Counter);
				else if (j==Counter||j==cols-1)
					printf("%d",Counter);
				else
					printf("%d",Counter+1);
			}
		}
		printf("\n");
	}
}
