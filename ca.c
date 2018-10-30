/*
	Name: Liam Stewart
	Matric Number:160009896
	Module Code: AC21008
*/

#include <stdio.h>
#include <stdlib.h>


int rules(int left, int middle, int right)
{

		if(left == 0 && middle == 0 && right == 0)
		{
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
	/*setting the size of the automaton*/
	printf("How long would you like the grid?\n");
	scanf("%d", &length);
	printf("How many lines would you like to print?\n");
	scanf("%d", &height);

	int gen1[length];
	int gen2[length];

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

		for (int i = 0; i < length; ++i)
		{
		printf("%d", gen2[i]);
		}

	

		for (int i = 0; i < length; ++i)
		{
			gen1[i] = gen2[i];
		}
	}



	return 0;
}


	int main()
	{
		setGrid();

		return 0;
		
	}



	
   

