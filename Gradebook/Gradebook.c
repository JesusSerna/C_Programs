#import <stdio.h>
#import <string.h>
#import <ctype.h>
#include <stdlib.h>

/* Function prototypes */
void print_records(char F[][20], char L[][20], double S[], int size);
void search_first(char F[][20], char L[][20], double S[], int size);
void search_last(char F[][20], char L[][20], double S[], int size);
void sort_score(char F[][20], char L[][20], double S[], int size);
void sort_last(char F[][20], char L[][20], double S[], int size);
void main_menu(char First_names[][20],char  Last_names[][20], double scores[], int size);

int main()
{
    /* Initializing variables to be used in main function */
    int size, i;
    
    /* Asking for the number of records the user wants to store */
    printf("Please indicate the number of records you want to enter (min 5, max 15):\n");
    scanf("%d", &size);
    while (size < 5 || size > 15)
    {
        printf("Please only enter a min of 5 and a max of 15 records.\n");
        scanf("%d", &size);
    }
    
    /* Initializing variables that depend on "size" */
    char First_names[size][20], Last_names[size][20];
    double scores[size];
    
    /* Asking user to enter the records to be stored */
    printf("\nPlease input records of students (enter a new line after each record), with following format: \nfirst name last name score\n");
    /* Storing records */
    for (i = 0; i < size; i++)
    {
        scanf("%s",First_names[i]);
        scanf("%s", Last_names[i]);
        scanf("%lf", &scores[i]);
    }
    main_menu(First_names, Last_names, scores, size);
}

/* Main menu */
void main_menu(char First_names[][20],char  Last_names[][20], double scores[], int size)
{
    int exit = 0;
    while (exit != 1)
    {
        int function;
        
        printf("\nPrint records (press 1)\nSearch by first name (press 2)\nSearch by last name (press 3)\nSort by score (press 4)\nSort by last name (press 5)\nExit the program (press 0)\n");
        scanf("%d", &function);
        while (function < 0|| function > 5)
        {
            printf("Please use the given options.\n");
            scanf("%d", &function);
        }
        switch (function)
        {
            case 0:
                exit = 1;
                break;
            case 1:
                print_records(First_names, Last_names, scores, size);
                break;
            case 2:
                search_first(First_names, Last_names, scores, size);
                break;
            case 3:
                search_last(First_names, Last_names, scores, size);
                break;
            case 4:
                sort_score(First_names, Last_names, scores, size);
                break;
            case 5:
                sort_last(First_names, Last_names, scores, size);
                break;
        }
    }
}

/* Begin print function using simple for loop */
void print_records(char F[][20], char L[][20], double S[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("\t%s %s %.2lf\n", F[i],L[i],S[i]);
    }
}

/* Begin search function */
void search_first(char F[][20], char L[][20], double S[], int size)
{
    int i;
    char F_N[20];
    
    /* Asking user for the first name to search for */
    printf("Enter first name\n");
    scanf("%s", F_N);
    
    /* Start for loop to compare names */
    for (i = 0; i < size; i++)
    {
        if (strcmp(F_N,F[i]) == 0)          //Comparing user given name to name in array
        {
            printf("\t%s %s %.2lf\n", F[i],L[i],S[i]);  //Printing match
        }
    }
    
}

/* Begin search function */
void search_last(char F[][20], char L[][20], double S[], int size)
{
    int i;
    char L_N[20];
    
    /* Asking user for the first name to search for */
    printf("Enter last name\n");
    scanf("%s", L_N);
    
    /* Start for loop to compare names */
    for (i = 0; i < size; i++)
    {
        if (strcmp(L_N,L[i]) == 0)      //Comparing user given name to name in array
        {
            printf("\t%s %s %.2lf\n", F[i],L[i],S[i]);  //Printing match
        }
    }
    
}

/* Begin sort function using altered bubble sort */
void sort_score(char F[][20], char L[][20], double S[], int size)
{
    int i, j, k, tmp;
    char tempstring[20];
    
    for(i = 0; i< size-1; i++)
    {
        for(j = 0; j<size-i-1; j++)
        {
            if(S[j]>S[j+1])
            {
                tmp = S[j];
                S[j] = S[j+1];
                S[j+1] = tmp;
                
                for (k = 0; k <= strlen(F[j]); k++)
                {
                    tempstring[k] = F[j][k];
                    F[j][k] = F[j+1][k];
                    F[j+1][k] = tempstring[k];
                }
                for (k = 0; k <= strlen(L[j]); k++)
                {
                    tempstring[k] = L[j][k];
                    L[j][k] = L[j+1][k];
                    L[j+1][k] = tempstring[k];
                }
            }
        }
    }
    print_records(F, L, S, size);
}

/* Begin sort function using altered bubble sort */
void sort_last(char F[][20], char L[][20], double S[], int size)
{
    int i, j, k, tmp;
    char tempstring[20];
    
    for(i = 0; i< size-1; i++)
    {
        for(j = 0; j<size-i-1; j++)
        {
            if(strcmp(L[j],L[j+1]) > 0)
            {
                tmp = S[j];
                S[j] = S[j+1];
                S[j+1] = tmp;
                
                for (k = 0; k <= strlen(F[j]); k++)
                {
                    tempstring[k] = F[j][k];
                    F[j][k] = F[j+1][k];
                    F[j+1][k] = tempstring[k];
                }
                for (k = 0; k <= strlen(L[j]); k++)
                {
                    tempstring[k] = L[j][k];
                    L[j][k] = L[j+1][k];
                    L[j+1][k] = tempstring[k];
                }
            }
        }
    }
    print_records(F, L, S, size);
}