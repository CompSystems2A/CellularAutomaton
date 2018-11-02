/*
	Name: Liam Stewart
	Matric Number:160009896
	Module Code: AC21008
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <tgmath.h>
#include <math.h>

void DectoBin();
int ruleset[7];



int rules(int left, int middle, int right)
{

		if(left == 0 && middle == 0 && right == 0){
			return ruleset[7];
		}
        	else if(left == 0 && middle == 0 && right == 1){
               return ruleset[6];
            }
            else if(left == 0 && middle == 1 && right == 0){
               return ruleset[5];
            }
            else if(left == 0 && middle == 1 && right == 1){
               return ruleset[4];
            }
            else if(left == 1 && middle == 0 && right == 0){
               return ruleset[3];
            }
            else if(left == 1 && middle == 0 && right == 1){
               return ruleset[2];
            }
            else if(left == 1 && middle == 1 && right == 0){
               return ruleset[1];
            }
            else
            {
               return ruleset[0];
            }	
}

/*this function will initiate the size of the rows and sets the rules for each cell in the program*/

int setGrid()
{
	int length;
	int height;
	/*setting the size of the automaton*/
	printf("How long would you like the grid?\n");
	scanf("%d", &length);
	printf("How many lines would you like to print?\n");
	scanf("%d", &height);
	printf("What rule would you like to print?\n");
	DectoBin();

	int gen1[length];
	int gen2[length];

	FILE *fi = fopen ("output.txt","a");

	if (fi ==NULL)
	{
	printf("error opening file!\n");
	exit(1);
	}

	for (int i = 0; i < length; ++i)
	{
		if (length/2 == i)
		{
			gen1[i] = 1;
			
		}
		else
		{
			gen1[i] = 0;
		}
	}

	printf("\n");

	for (int i = 0; i < length; ++i)
	{
		printf("%d", gen1[i]);
		fprintf(fi,"%d", gen1[i]);
	}

	for (int i = 0; i < height; ++i)
	{
		for (int i = 0; i < length; ++i)
		{
			int left = gen1[i-1];
			int middle = gen1[i];
			int right  = gen1[i+1];
			gen2[i] = rules(left,middle,right);
		}

			printf("\n");
			fprintf(fi,"\n");

		for (int i = 0; i < length; ++i)
		{
			printf("%d", gen2[i]);
			fprintf(fi,"%d", gen2[i]);
		}

	

		for (int i = 0; i < length; ++i)
		{
			gen1[i] = gen2[i];
		}
	}

	return 0;
}

int BinToDec()
{
  long binary;   
  printf("Enter a binary number: ");
  scanf("%ld", &binary);

  

  long decimal = 0
  long i = 1
  int remainder;
  while (binary!=0)
  {
	remainder = binary%10;
	decimal = decimal+remainder*i;
	i=i*2;
	binary=binary/10;
  }
  
  printf("\n The decimal value is : %ld\n\n",dno);

  return dno;

}
void DectoBin()
{
	int decimal;
	int newArray[7];
	printf("\n\n Function : convert decimal to binary :\n");
	printf("-------------------------------------------\n");    
	printf("Enter any decimal number: ");
	scanf("%d",&decimal);

	//convert the decimal to a binary number
	int binary=0,remainder,f=1;
	while(decimal != 0)
	{
		remainder = decimal % 2;
		binary = binary + remainder * f;
		f = f * 10;
		decimal = decimal / 2;
	}


	int c = 0; 
	int temp = binary;
	int temp2 = binary;

	//beginning of converting binary to
	//an array of ints
	while (binary != 0)
	{
		binary /= 10;
		c++;
	}

	c = 0;  

	int count = 0;

	while (temp2 != 0)
	{
		temp2 /= 10;
		count++;
	}

	count = count-1;
	//set the size of the array
	//to be the size of the binary number
	int numberArray[count];  

	//extract digits
	while (temp != 0)
	{
		numberArray[c] = temp % 10;
		temp /= 10;
		c++;
	}
	


	//if the array has less than 8 elements
	if(count<7)
	{
		//create a new area of 8 elements
		int newArray[7];
		//find the difference between the 
		int diff = 8-(count+1);

		//create an array of 0s
		for(int i=0; i<8; i++)
		{
			newArray[i]=0;
		}
		//put the elements of the first array
		//into the second array
		for(int i=count; i>=0; i--, diff++)
		{
			newArray[(diff)]=numberArray[i];
		}

		//define the new array as the ruleset
		for (int i=0; i<8; i++)
		{
			ruleset[i] = newArray[i];
		}
	}
	else
	{

		//Copying elements to reverse
		//the array
		int d;
		//temporary array
		int temp[100];

		for (int c = count, d = 0; c >= 0; c--, d++)
		{
			temp[d] = numberArray[c];
		}

		//Copying reversed array into the original
		for (int c = 0; c < count+1; c++)
		{
			numberArray[c] = temp[c];
		}

		//define the array is the ruleset
		for (int i=0; i<8; i++)
		{
			ruleset[i] = numberArray[i];
		}
	}

	printf("\n The Binary value is : ");

	//print the ruleset/binary number
	for (int i = 0; i < 8; i++ ) 
	{
		printf("%d", ruleset[i]);
	}

	printf("\n");
}



	/*Menu for program*/
	int main()
	{
		int i;
		do{

		printf("\n");			
		printf("Welcome to our Cellular Automaton program!\n");
		printf("1.Generate a Cellular Automaton\n");
		printf("2.Decimal to Binary\n");
		printf("3.Binary to decimal\n");
		printf("4.Save & Exit program\n");
		scanf("%d", &i);

			switch(i)
			{
			case 1:
			 setGrid();
			break;
			case 2:
			DectoBin();
			break;
			case 3:
			BinToDec();
			break;
			case 4:
			 printf("Automaton saved to File : output.txt\n");
			 printf("Exiting Program...\n");
			break;
			default: printf("invalid choice, try again\n");
			break;

			}
		
	  		}while(i!=4);

	  return 0;
		
	}

   