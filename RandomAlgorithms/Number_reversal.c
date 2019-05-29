#import <stdio.h>

int main(void)
{
    int Number, Sum,temp;                           //initializing variables to be used
    int Reverse=0;
    
    printf("Please enter a number:\n");             //asking for user input
    scanf("%d", &Number);                           //reading user input
    
    temp = Number;                                  //defining temporary variable as user's number
    
    while (temp != 0)
    {
        Reverse = Reverse * 10;                     //moving number to the left by multiplying by 10
        Reverse = Reverse + temp%10;                //getting right most digit in temp
        temp    = temp/10;                          //dividing by 10 to get rid of the right most digit
    }                                               //repeat until there are no more digits in temp
    
    Sum = Reverse + Number,                         //adding user's number to the reverse number
    printf("%d + %d = %d\n",Number, Reverse, Sum);  //print result
}
