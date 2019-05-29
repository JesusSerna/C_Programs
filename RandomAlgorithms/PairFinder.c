#import <stdio.h>

int main()
{
    int Target, pairs_found = 0, i, j;
    
    int array[20];    //creating and storing values in array
    printf("Please provide me with the array content.\n");
    for(i = 0; i < 20; i++)
    {
        scanf("%d",&array[i]);
    }
    
    printf("Please provide me with a target value.\n");
    scanf("%d",&Target);     //defining x
    
    
    for(i = 0; i < 10; i++)       //getting digit in position i
    {
        for(j = i; j < 10; j++)   //matching digit i with every digit at, or after, position i
        {
            if (array[i]+array[j]== Target)   //checking pairs
            {
                pairs_found++;
                if(pairs_found == 1)    //printing header once
                {
                    printf("These are the positions and qualifying pairs in the array:\n");
                }
                printf("(%d,%d)\n",i,j);    //printing positions of qualifying pair
                printf("%d + %d = %d\n\n",array[i],array[j], Target);    //printing qualifying pair
            }
        }
    }
    if(pairs_found == 0)    //checking if there were any pairs
    {
        printf("There are no such pairs.\n");   //no pairs found
    }
}
