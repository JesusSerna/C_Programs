#import <stdio.h>

void BubbleSort(int A[],int Size);          //function
int main(void)
{
    int A[18], B[5], i, j=0;                //initializing variables that will be used
    
    printf("Please supply 13 integers.\n");   //asking for user input
    
    for (i = 0; i < 13; i++)
    {
        scanf("%d",&A[i]);                  //reading user input
    }
    
    printf("Please supply 5 integers.\n");    //asking for second user input
    for (i = 0; i < 5; i++)
    {
        scanf("%d",&B[i]);                  //reading second user input
    }
    
    for(i = 0; i < sizeof(A)/4;i++)         //start of array combanation
    {
        if (i<13)
        {
            A[i]=A[i];                      //taking the first 13 elements from the first array
        }
        else
        {
            A[i]=B[j];                      //taking the last 5 elements from the second array
            j++;
        }
    }
    
    BubbleSort(A, sizeof(A)/4);             //sorting the combined array
    
    for (i=0;i<sizeof(A)/4;i++)
    {
        printf("%d,",A[i]);                //printing the sorted array
    }
    printf("\n");
}

void BubbleSort(int A[],int Size)           //start of sorting function
{
    int i,tmp = 0, j;                       //initializing variables for sorting function
    for(i = 0; i<Size-1; i++)
    {
        for(j = 0; j<Size-i-1; j++)
        {
            if(A[j]>A[j+1])                 //comparing element at position j to positions j+1
            {                                  //based on result, swap the two elements
                tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
            }
        }
    }
}
