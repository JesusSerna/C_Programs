#import <stdio.h>
#include <string.h>

void Alphabetical(char Strings[5][5], int row, int column);             //function

int main(void)
{
    char Strings[5][5];                                                 //initializing variables to be used
    int i;
    
    printf("Provide me with 5 strings, each containing 4 letters.\n");  //asking for user input
    for (i = 0; i < 5; i++)
    {
        scanf("%s", Strings[i]);                                        //reading user input
    }
    
    Alphabetical(Strings,4,4);                                          //sort function call
    
    printf("The sorted strings are:\n");                                //printing heading
    for (i = 0; i < 5; i++)
    {
        printf("%s\n",Strings[i]);                                      //printing sorted strings
    }
    
}

void Alphabetical(char Strings[5][5], int row, int column)              //start of sorting function
{
    int i,j,k;                                                          //initializing variables to be used
    char temp[5];
    
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < row - i; j++)
        {
            if (strcmp(Strings[j],Strings[j+1]) > 0)                    //comparing string in poistion j to string
            {                                                              //in position j+1
                for (k = 0; k < column; k++)
                {
                    temp[k]=Strings[j][k];                              //setting temporary variable as current string
                    Strings[j][k] = Strings[j+1][k];                    //setting current position to next string
                    Strings[j+1][k] = temp[k];                            //setting next position to current string using temp
                }
            }
        }
    }
}
