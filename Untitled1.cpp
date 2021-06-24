#include<stdio.h>
#include<time.h>
#include<stdlib.h>


void display(char *array,int size, int cols)
{
	for (int x=0 ; x< size ; x++)
	{
		printf("\t");
		if(*(array+x) == 32)
			printf("%c",*(array+x)); // printing character symbol
		else
			printf("%d",*(array+x)); // printing character ascii code
			
		printf("\t|");
		if((x+1)%cols == 0)  // going to next line after reaching column length
		{
			printf("\n\n");
		}
	}
}

void random(char *array,int size)
{
	for (int i = 0; i < size-1; i++) {     // filling array in sequence
	    *(array+i) = i+1;
	}
		*(array+(size-1)) = ' ';
	
	srand(time(NULL));
	for (int i = 0; i < size; i++) {    // shuffling random locations
	    char temp = *(array+i);
	    int randomIndex = rand() % size;
	
	    *(array+i) = *(array+randomIndex);
	    *(array+randomIndex) = temp;
	}
}

int wincheck(char *array , int size)
{
	int check=0;
	if (*(array+(size-1))== ' ')
		{
			check = 0;
			for (int i=0 ; i<size-2 ; i++) // checking if all the values from 1 to size are in sequence
			{
				if(*(array+i) != i+1)
				{
					check=1;	
				}
				
			}
			if (check == 0)
			{
				return 1;
			}
		}
		
		else
			return 0;
}


int main()
{
	int rows,cols;
//	do
//	{
		printf("enter number of rows (3-8): "); // taking number of rows
		scanf("%d",&rows);
//	}while(rows<3 || rows >8);

//	do
//	{
		printf("enter number of cols(3-8): "); // taking number of columns
		scanf("%d",&cols);
//	}while(cols<3 || cols >8);

	
	int size = rows*cols;
	char array[size];
	
	random(array,size);
			
	printf("\n");
	
	display(array,size,cols);
	
	int n;
	int loc,move,count=1;
	do
	{
		printf("(MOVE#%d)choose number to move or enter 0 to exit: ",count++);
		scanf("%d",&n);
		if(n=='0')
		{
			return 0;
		}
		
		for (int x=0 ; x< size ; x++) // getting location of entered number
		{
			if(array[x] == n)
			{
				move = x; 
			}
		}
			
		for (int x=0 ; x< size ; x++) // getting location of space character
		{
			if(array[x] == ' ')
			{
				loc = x;
			}
		}
		
		if((move == loc+1 || move == loc-1 || move == loc+cols || move == loc-cols)) // moving up down and left right
		{
			if((loc%cols==0 && move == loc-1) || ((loc+1)%cols==0 && move%cols == 0)) // checking for loc+1 and loc-1 invalid moves
			{
				printf("Invalid move!!!!!!!!!!!!!!!!!!!!\n");	
			}
			else
			{
				char temp = array[move]; // swapping values
				array[move] = array[loc];
				array[loc] = temp;
			}
		}
		else
			printf("Invalid move!!!!!!!!!!!!!!!!!!!!\n");
		
		
		display(array,size,cols);
		
		if (wincheck(array,size) == 1)
			break;
		

	}while(1);
	
	printf("\n*********************You Win*****************\n");
	printf("enter 1 to play again or any other number to exit: "); // restart or end
	scanf("%d",&n);
	if(n==1)
	{
		system("CLS"); // to clear screen
		main();
	}
	
	return 0;
}
