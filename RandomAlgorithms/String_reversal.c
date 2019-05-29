#import <stdio.h>
#import <string.h>

int main(void)
{
    char String[100], temp;                         //initializing variables to be used
    int length, i;
    puts("Please provide me with a String");        //asking for user input
    gets(String);                                   //reading user input
    
    length = strlen(String)-1;                      //defining the length of user's string

    for(i = 0; i <= length/2; i++)
    {
        temp = String[i];                           //defining temp as first first char in user's string
        String [i] = String[length-i];              //moving last character to position 1
        String[length-i] = temp;                    //setting first character to last position using temp
    }
    
    printf("Your String reversed is:  ");           //printing header
    
    for(i=0;i<=length;i++)
    {
        printf("%c",String[i]);                     //printing user's string reversed
    }
    printf("\n");
    
}
