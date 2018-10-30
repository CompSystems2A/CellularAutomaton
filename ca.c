/*
	Name: Liam Stewart
	Matric Number:160009896
	Module Code: AC21008
*/

#include <stdio.h>
#include <stdlib.h>

/*this function will initiate the size of the rows and sets the rules for each cell in the program*/
int main()
{

	/*variables to be used in program*/
	int length;
	int left[length];
	int middle[length];
	int right[length];
	int cell[length];

	/*setting the size of the automaton*/
	printf("How many cells would you like in this run?\n");
	scanf("%d", &length);

	/*for loop for ruleset*/
	for (int i = 0; i < length; ++i)
	{

		if(left[i-1] == 0 && middle[i] == 0 && right[i+1] == 0){
			cell[i] = 0;
		}
        	else if(left[i-1] == 0 && middle[i] == 0 && right[i+1] == 1){
               cell[i] = 1;
            }
            else if(left[i-1] == 0 && middle[i] == 1 && right[i+1] == 0){
               cell[i] = 1;
            }
            else if(left[i-1] == 0 && middle[i] == 1 && right[i+1] == 1){
               cell[i] = 1;
            }
            else if(left[i-1] == 1 && middle[i] == 0 && right[i+1] == 0){
               cell[i] = 1;
            }
            else if(left[i-1] == 1 && middle[i] == 0 && right[i+1] == 1){
               cell[i] = 0;
            }
            else if(left[i-1] == 1 && middle[i] == 1 && right[i+1] == 0){
               cell[i] = 0;
            }
            else if(left[i-1] == 1 && middle[i] == 1 && right[i+1] == 1){
               cell[i] = 0;
            }

            for (int i = 0; i < length; ++i)
            {
            	if (cell == 0)

            	{
            		printf("%d", 0);
            	}
            	else if(cell ==)
            	{
            		printf("%d", 1);
            	}
            }

            printf("%d", cell);

           
		
	}

	return 0;
    
}
