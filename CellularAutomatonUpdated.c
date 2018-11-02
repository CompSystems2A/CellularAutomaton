/*
	Name: Liam Stewart, Brenyn Goodwin
	Matric Number:160009896, 170008681
	Module Code: AC21008
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <tgmath.h>
#include <math.h>


//sets the rules for displaying the automaton
int rules(int left, int middle, int right)
{

		if(left == 0 && middle == 0 && right == 0){
			return 0;
		}
        	else if(left == 0 && middle == 0 && right == 1){
               return 1;
            }
            else if(left == 0 && middle == 1 && right == 0){
               return 1;
            }
            else if(left == 0 && middle == 1 && right == 1){
               return 1;
            }
            else if(left == 1 && middle == 0 && right == 0){
               return 1;
            }
            else if(left == 1 && middle == 0 && right == 1){
               return 0;
            }
            else if(left == 1 && middle == 1 && right == 0){
               return 0;
            }
            else
            {
               return 0;
            }	
}

/*this function will initiate the size of the rows and sets the rules for each cell in the program*/

int setGrid()
{
	int length;
	int height;
	/*setting the size of the automaton from user input*/
	printf("How long would you like the grid?\n");
	scanf("%d", &length);
	printf("How many lines would you like to print?\n");
	scanf("%d", &height);

	//setting the array lengths
	int gen1[length];
	int gen2[length];

	//Opens a text file which will be written to
	FILE *fi = fopen ("output.txt","a");

	//file is not found
	if (fi ==NULL)
	{
	printf("error opening file!\n");
	exit(1);
	}

	//assigning rules to display the automaton in the array
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

	//printing the array
	for (int i = 0; i < length; ++i)
	{
		printf("%d", gen1[i]);
		//writing to the file
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
//function to convert binary to decimal 
int BinToDec()
{
  long bno;   
 
  //get binary number from user
  printf("Enter a binary number: ");
  scanf("%ld", &bno);
  
  //Converting into decimal 
  long dno = 0, i = 1, remainder;
  while (bno!=0);
  {
      remainder = bno%10;
      dno = dno+remainder*i;
      i=i*2;
      bno=bno/10;


  }
  
  printf("\n The decimal value is : %ld\n\n",dno);

  return dno;

}

//function to convert decimal to binary
void DectoBin()
{

  int dno;

  
  //get decimal number from user  
  printf("Enter any decimal number: ");
  scanf("%d",&dno);

  //converting into binary
  long bno=0,remainder,f=1;
  while(dno != 0)
  {
       remainder = dno % 2;
       bno = bno + remainder * f;
       f = f * 10;
       dno = dno / 2;
  }

  printf("\n The Binary value is : %ld\n\n",bno);

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