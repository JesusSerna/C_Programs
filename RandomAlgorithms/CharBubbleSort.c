#import <stdio.h>
#import <string.h>

void Bubblesort(char String[],long size);                       //sorting function
int times_repeated(char String[11], int position);              //function to count number of times repeated

int main(void)
{
    int i, repeated = 0;                                        //initializing variables to be used
    char String[11];
    printf("Please provide me with a 10 character string.\n");  //asking for user input
    gets(String);                                               //reading user input
    
    Bubblesort(String,strlen(String)-1);                        //bubblesort function call
    
    for (i = 0; i < strlen(String); i++)
    {
        if (String[i] == String[i+1] && String[i] != ' ')       //checking if there is a repeat
        {
            repeated = times_repeated(String, i);               //calculating number of times a character is repeated
            printf("\"%c\" is repeated %d times.\n",String[i],repeated);
            i+=repeated-1;                                      //updating position to the next different character
        }
    }
    
    if (repeated == 0)                                          //checing if there was any repeated characters
    {
        printf("There are no repeated characters");             //printing in case no repeated characters
    }
}

void Bubblesort(char String[],long size)                        //begin bubblesort
{
    int i,j;
    char temp;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size-i; j++)
        {
            if (String[j] > String[j+1])
            {
                temp = String[j];
                String[j] = String[j+1];
                String[j+1] = temp;
                
            }
        }
    }
}

int times_repeated(char String[11], int position)               //begin counting function
{
    int i,repeated =0;                                          //initializing variables to be used
    for (i = 0; i < strlen(String); i++)
    {
        if (String[position] == String[i])                      //checking specific character against all other characters
        {
            
            repeated++;                                         //recording number of times a char is repeated
        }
    }
    return repeated;                                            //returning number of times the character is repeated
}

