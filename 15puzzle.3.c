#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int rand(void);

int main()
{

//declaring array with elements matching puzzle elements 
	
int array[4][4]={
	
	1,  2,  3,  4,
	5,  6,  7,  8,
	9,  10, 11, 12, 
	13, 14, 15, 0
	
	};
	
//declaring array to save win position
	
int arrclean[4][4]={
	
	1,  2,  3,  4,
	5,  6,  7,  8,
	9,  10, 11, 12, 
	13, 14, 15, 0
	
	};
	
	
int a=0;
int n=0;
	
int row = 3;
int column = 3;
	
int temprow=row;
int tempcolumn=column;
	
array[row][column]=0;
array[temprow][tempcolumn]=0;
	
	
srand(time(0));//for random values
	
int moves=0;
int maxmoves=0;
	
printf("\nHow many times would you like program to move elements?\n");
	scanf("%d", &maxmoves);

//programm shuffles elements
	while(moves<maxmoves)
	{
		row=temprow;
		column=tempcolumn;
   
	int chosealg = rand() % 4;                switch (chosealg)
         {
         case 0: 
         if(row==0)
         {;}
         else
         {
         temprow--;
         }
         break;
     
         case 1:
         if(row==3)
         {;}
         else
         {
         temprow++;
         }
         break;
     
         case 2: 
         if(tempcolumn==3)
         {;}
         else
         {
         tempcolumn++;
         }
         break;
     
         case 3: 
         if(tempcolumn==0)
         {;}
         else
         {
         tempcolumn--;
         }
         break;

         default:
       
         break;
         }
moves++;
   
n=array[temprow][tempcolumn];
array[temprow][tempcolumn]=0;
array[row][column]=n;
		
}
	
//programm returns element zero to starting position
	while(temprow!=3 || tempcolumn!=3)
	{
	row=temprow;
	column=tempcolumn;
    
    temprow++;
          
    n=array[temprow][tempcolumn];
    array[temprow][tempcolumn]=0;
    array[row][column]=n;
         
		while(tempcolumn!=3)
		{
			row=temprow;
	        column=tempcolumn;
    
            tempcolumn++;
          

     		n=array[temprow][tempcolumn];
   		    array[temprow][tempcolumn]=0;
  	        array[row][column]=n;
		}
		
    }
	
//game
while(a!=1)
{
	
printf("\n");
	
int i = 0;
int j = 0;
	
//prints state of the board
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
   

	//	player moves element zero
printf("\nchose your move\n\n");
   
char chose = 0;                  


   printf("\nup left down right\n");
   printf("(u) (l)   (d)  (r)\n\n");
   scanf(" %c", &chose);

   switch (chose)
   {
     case 'U': case 'u': 
       if(row==0)
     {printf("You can't move zero further up\n");}
       else
       {
       temprow--;
       }
       break;
     
     case 'D': case 'd':
         if(row==3)
     {printf("You can't move zero further down\n");}
       else
       {
       temprow++;
       }
       break;
     
     case 'r': case 'R': 
       if(tempcolumn==3)
     {printf("You can't move zero further right\n");}
       else
       {
       tempcolumn++;
       };
      break;
     
     case 'L': case 'l': 
        if(tempcolumn==0)
     {printf("You can't move zero further left\n");}
       else
       {
       tempcolumn--;
       }
      break;

     default:
       printf("\n unrecognised response \n");
       break;
   }
   
n=array[temprow][tempcolumn];
array[temprow][tempcolumn]=0;
array[row][column]=n;

  //check for win conditions
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
a=1;//stops loop
}
else
{
	
}

}


}

}
}
