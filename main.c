#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 30000


void getUniqueNumber(int p[]);
void straight_selection(int p[], int *counter);
void straight_insertion(int p[], int *counter);
void bubblesort(int p[], int *counter);
void quicksort(int left, int right, int p[], int *counter);

int main() 
{
	int p[N],s[N],i,j,counter[20][4];
	clock_t t;
	float elapsed[20][4],sum[4];
	FILE *f;
	
	for (i=0;i<20;i++)
	{
		for (j=0;j<4;j++)
		{
			counter[i][j]=0;
			sum[j]=0;
		}
	}
	
	for (i=0;i<20;i++)
	{
		if(i==0)
			printf("Please Wait a Moment...\n\n");
		for(j=0;j<N;j++)
		{
			getUniqueNumber(s);
		}
		
		
		//BubbleSort
		for(j=0;j<N;j++)
		{
			p[j]=s[j];
		}
		t = clock();
		bubblesort(p,&counter[i][0]);
		t =  clock() - t;
		elapsed[i][0] = ((double)t) / CLOCKS_PER_SEC;
		sum[0] = sum[0] + elapsed[i][0];
		
		//SelectionSort
		for(j=0;j<N;j++)
		{
			p[j]=s[j];
		}
		t = clock();
		straight_selection(p,&counter[i][1]);
		t =  clock() - t;
		elapsed[i][1] = ((double)t) / CLOCKS_PER_SEC;
		sum[1] = sum[1] + elapsed[i][1];
		
		//InsertionSort
		for(j=0;j<N;j++)
		{
			p[j]=s[j];
		}
		t = clock();
		straight_insertion(p,&counter[i][2]);
		t =  clock() - t;
		elapsed[i][2] = ((double)t) / CLOCKS_PER_SEC;
		sum[2] = sum[2] + elapsed[i][2];
		
		//Quicksort
		for(j=0;j<N;j++)
		{
			p[j]=s[j];
		}
		t = clock();
		quicksort(0,N-1,p,&counter[i][3]);
		t =  clock() - t;
		elapsed[i][3] = ((double)t) / CLOCKS_PER_SEC;
		sum[3] = sum[3] + elapsed[i][3];
		
		
		if(i==0)
		{
			printf("Array = %d\n",N);
			printf("\t\tTable of Execution Times (in seconds)");
			printf("\n\tBubbleSort\tSelectionSort\tInsertionSort\tQuickSort\n");
			printf("\t=============================================================\n");
		}
		printf("\t%0.1f\t\t%0.1f\t\t%0.1f\t\t%0.1f\n",elapsed[i][0],elapsed[i][1],elapsed[i][2],elapsed[i][3]);
	}
	printf("Average:%0.1f\t\t%0.1f\t\t%0.1f\t\t%0.1f\n",sum[0]/20,sum[1]/20,sum[2]/20,sum[3]/20);
	
	f = fopen("Table_of_Execution_Times.txt","w"); //Anoigma arxeiou Table_of_Execution_Times.txt
		
	for (i=0;i<20;i++)
	{
		if(i==0)
		{
			fprintf(f,"Array = %d\n",N);
			fprintf(f,"\t\tTable of Execution Times (in seconds)");
			fprintf(f,"\n\tBubbleSort\tSelectionSort\tInsertionSort\tQuickSort\n");
			fprintf(f,"\t=============================================================\n");
		}
		fprintf(f,"\t%0.1f\t\t%0.1f\t\t%0.1f\t\t%0.1f\n",elapsed[i][0],elapsed[i][1],elapsed[i][2],elapsed[i][3]);
	}
	fprintf(f,"Average:\t%0.1f\t\t%0.1f\t\t%0.1f\t\t%0.1f\n",sum[0]/20,sum[1]/20,sum[2]/20,sum[3]/20);
	
	fclose(f); //Kleisimo arxeiou Table_of_Execution_Times.txt
	
	for(j=0;j<4;j++) //midenismos toy pinaka sum
		sum[j]=0;
	
	f = fopen("Table_of_Swaps.txt","w");  //Anoigma arxeiou Table_of_Swaps.txt
	
	for (i=0;i<20;i++)
	{
		if(i==0)
		{
			fprintf(f,"\nArray = %d\n",N);
			fprintf(f,"\t\t\t\tTable of Swaps");
			fprintf(f,"\n\tBubbleSort\tSelectionSort\tInsertionSort\tQuickSort\n");
			fprintf(f,"\t=============================================================\n");
		}
		fprintf(f,"\t%d\t\t%d\t\t%d\t\t%d\n",counter[i][0],counter[i][1],counter[i][2],counter[i][3]);
		sum[0] += counter[i][0];
		sum[1] += counter[i][1];
		sum[2] += counter[i][2];
		sum[3] += counter[i][3];
	}
	fprintf(f,"Average:\t%0.1f\t%0.1f\t\t%0.1f\t%0.1f\n",sum[0]/20,sum[1]/20,sum[2]/20,sum[3]/20);
	
	fclose(f); //Kleisimo arxeiou Table_of_Swaps.txt
	
	for (i=0;i<20;i++)
	{
		if(i==0)
		{
			printf("\nArray = %d\n",N);
			printf("\t\t\t\tTable of Swaps");
			printf("\n\tBubbleSort\tSelectionSort\tInsertionSort\tQuickSort\n");
			printf("\t=============================================================\n");
		}
		printf("\t%d\t%d\t\t%d\t%d\n",counter[i][0],counter[i][1],counter[i][2],counter[i][3]);
	}
	printf("Average:%0.1f\t%0.1f\t\t%0.1f\t%0.1f\n",sum[0]/20,sum[1]/20,sum[2]/20,sum[3]/20);
	
	
	printf("\n\n\nPress any key to finish!");
	printf("\n==============End of Program===============\n");
	printf("Tilsizoglou Anastasios 3878\n");
	getchar();
	return 0;
}

//--------------------------------------------------------------------//
void getUniqueNumber(int p[])
{
	int j;
	srand(time(NULL));
	for(j=0;j<N;j++)
		p[j]=rand();
}
//---------------------------------------------//
void straight_selection(int p[], int *counter)
{
	int i,j,min,k;
	for (i=0; i<N-1; i++)
	{
		k = i;
		min = p[i];
		for (j = i+1; j<N; j++)
		{
			if (p[j] < min)
			{
				k = j;
				min = p[j];
				(*counter)=(*counter)+1;
			}
		}
		p[k] = p[i];
		p[i] = min;
	} 
}
//---------------------------------------------//
void straight_insertion(int p[], int *counter)
{
	int i,j,x;
	for(i=1; i<N; i++)
	{
		x = p[i];
		j = i -1;
		while(x<p[j] && j>=0)
		{
			p[j+1] = p[j];
			j = j-1;
			(*counter)=(*counter)+1;
		}
		p[j+1] = x;
	}
}
//---------------------------------------------//
void bubblesort(int p[], int *counter)
{
	int i,j,temp;
	for (i=1; i<N; i++)
	{
		for (j=N-1; j>=i; j--)
		{
			if (p[j-1] > p[j])
			{
				temp = p[j-1];
				p[j-1] = p[j] ;
				p[j] = temp ;
				(*counter)=(*counter)+1;
			}	
		}
	}
}
//---------------------------------------------//
void quicksort(int left, int right, int p[], int *counter)
{
	int i, j, mid, x, temp;
	if (left < right)
	{
		i = left;
		j = right;
		mid = (left+right)/2;
		x = p[mid];
		while (i < j)
		{
			while (p[i] < x)
			i++;
			while (p[j] > x)
			j--;
			if (i < j)
			{
				if (p[i] == p[j])
				{
					if (i<mid)
						i++;
					if (j>mid)
						j--;
				}
				else
				{
					temp = p[i];
					p[i] = p[j];
					p[j] = temp;
					(*counter)=(*counter)+1;
				}
			}
		}
		quicksort(left,j-1,p,counter);
		quicksort(j+1,right,p,counter);
	}
}
