#import <stdio.h>
#import <math.h>

int Nth_Term(int n);                                //function
int main(void)
{
    int N,i;                                          //initializing variables to be used
    printf("Provide me with a position location.\n");  //asking for users input
    scanf("%d",&N);                                 //reading user input
    
    for (i = 0; i <= N; i++)
    {
        printf("%d ",Nth_Term(i));                  //print all numbers in the sequence up to N
    }
}

int Nth_Term(int N)                                 //start of recursive function
{
    if (N == 0)
    {
        return 0;                                   //defining base condition
    }
    N = pow(Nth_Term(N-1),2)+1;                     //recursively solving equation
    return N;                                       //returning Nth term in the series
}
