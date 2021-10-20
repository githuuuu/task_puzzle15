#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int rand(void);

int end=0,row=3,column=3,temprow=3,tempcolumn=3;

void movezero/*swaps zero element with element chosen by move function*/
(int arr[4][4], int rT, int cT, int r, int c) 
{ 
	int temp=0;  
	temp = arr[rT][cT];
	arr[rT][cT]=0;
	arr[r][c] = temp; 
}

void move(ch)/*choses what element to swap with zero element, checks if input is correct*/
{
  switch (ch)
  {
   case 'S': case 's': case 0:
     if(row==3)
       {if(end==1)
     printf("You can't move zero further down\n");}
       else
       temprow++;
       break;
     	
   case 'D': case 'd': case 1:
      if(tempcolumn==3)
      {if (end==1)
     printf("You can't move zero further right\n");}
       else
       tempcolumn++;
      break;
   	
   case 'W': case 'w': case 2:
       if(row==0)
     {if (end==1)
     	printf("You can't move zero further up\n");}
       else
       temprow--;
       break;
     
   case 'A': case 'a': case 3:
        if(tempcolumn==0)
     {if (end==1)
     	printf("You can't move zero further left\n");}
       else
       tempcolumn--;
      break;

   default:
       printf("\n unrecognised response \n");
       break;
   }
}
	
int main()
{
/*declaring array with elements matching puzzle elements*/
int array[4][4]={
	1,  2,  3,  4,
	5,  6,  7,  8,
	9,  10, 11, 12, 
	13, 14, 15, 0
	};
	
/*declaring array to save win position*/
int arrclean[4][4]={
	1,  2,  3,  4,
	5,  6,  7,  8,
	9,  10, 11, 12, 
	13, 14, 15, 0
	};
	
array[row][column]=0;
array[temprow][tempcolumn]=0;
	
srand(time(0));/*for random values*/
int moves=0;
int maxmoves=0;
	
printf("\nHow many times would you like program to move elements?\n");
	scanf("%d", &maxmoves);

/*programm shuffles elements*/
	while(moves<maxmoves)
	{
		row=temprow;
		column=tempcolumn;
   
	int chosealg = rand() % 4;                
	move(chosealg);
moves++;
movezero(array, temprow, tempcolumn, row, column);
     }
     
/*programm returns element zero to starting position*/
	while(temprow!=3 || tempcolumn!=3)
	{
	row=temprow;
	column=tempcolumn;
   
	int chosealg = rand() % 2;                
	move(chosealg);
movezero(array, temprow, tempcolumn, row, column);
    }
end++;

/*game*/
while(end!=2)
{
	
printf("\n");
	
int i = 0;
int j = 0;
	
/*prints state of the board*/
for(i=0;i<4;i++)
   {
   	for(j=0;j<4;j++)
   	{
    printf("%d\t",array[i][j]);
    }
    printf("\n");
   }
   
row=temprow;
column=tempcolumn;
   
/*player moves element zero*/
printf("\nchose your move\n\n");
   
char chose = 0;                  

   printf("\nup left down right\n");
   printf("(w) (a)   (s)  (d)\n\n");
   scanf(" %c", &chose);
   move(chose);
   movezero(array, temprow, tempcolumn, row, column);

  /*check for win conditions*/
   int counter=0;
for(i=0; i<4; i++)
   {
   for(j=0; j<4; j++)
      {
      if(array[i][j]==arrclean[i][j])
        {counter++;}
else
        {
        break;
        }
 if(counter==16)
 {
 printf("\nYou have won!\n");
 end=2;//stops loop
 }
 else
 {
 }
 }
 }
 }
 }
