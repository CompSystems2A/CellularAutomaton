#include <stdlib.h>
#include <stdio.h> 
#include <string.h> 
#include <tgmath.h>
#include <math.h>
 

void DectoBin();
int BinToDec();

int main()
{
    
    DectoBin();
    BinToDec();
    printToFile();

    return 0;
}
void DectoBin()
{

  int dno;

  printf("\n\n Function : convert decimal to binary :\n");
  printf("-------------------------------------------\n");    
  printf("Enter any decimal number: ");
  scanf("%d",&dno);

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

int BinToDec()
{
  long bno;
  printf("\n\n Function : convert binary to decimal :\n");
  printf("-------------------------------------------\n");   
  printf("Enter a binary number: ");
  scanf("%ld", &bno);

  

  long dno = 0, i = 1, remainder;
  while (bno!=0)
  {
      remainder = bno%10;.
      dno = dno+remainder*i;
      i=i*2;
      bno=bno/10;


  }
  
  printf("\n The decimal value is : %ld\n\n",dno);

  return dno;

}

void printToFile
{
  for (i = 0; i < size; i++) 
  {
    printf("%d ", v[i]);
    fprintf(fpIn, "%d ", v[i]);
  }

  perm_count++;
  printf("\n");
  fprintf(fpIn, "\n");
}

