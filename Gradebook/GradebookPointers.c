#import <string.h>
#import <stdio.h>
#import <stdlib.h>

void main_menu(char **F, char **L, double *S, int size);
int FREE_EVERYTHING(char **F, char **L, double *S, int size);

/*1*/ void print_records(char **F, char **L, double *S, int size);
/*2*/ void add_record(char ***F, char ***L, double **S, int *size);
/*3*/ void delete_record(char **F, char **L, double *S, int *size);
      void unallocate(char ***F, char ***L, double **S, int *size);
/*4*/ void search_last(char **F, char **L, double *S, int size);
/*5*/ void sort_score(char **F, char **L, double *S, int size);
/*6*/ void sort_last(char **F, char **L, double *S, int size);
/*7*/ void Median_score(char **F, char **L, double *S, int size);

int main()
{
    /* Initializing variables to be used in main function */
    int size, i;
    
    /* Asking for the number of records the user wants to store */
    printf("Please indicate the number of records you want to enter (min 5):\n");
    scanf("%d", &size);
    while (size < 5)
    {
        printf("Please only enter a min of 5 records.\n");
        scanf("%d", &size);
    }
    
    // Initializing pointers
    char **First_names = (char**)malloc(size * sizeof(char*));
    for (i = 0; i<size; i++)
    {
        First_names[i] = (char *)malloc(21);
    }
    char **Last_names = (char **)malloc(size * sizeof(char*));
    for (i = 0; i<size; i++)
    {
        Last_names[i] = (char *)malloc(21);
    }
    
    double *Scores = (double *)malloc(sizeof(double) * size);

    /* Asking user to enter the records to be stored */
    printf("\nPlease input records of students (enter a new line after each record), with following format: \nfirst name[max 20 char] last name[max 20 char] score\n");
        /* Storing records */
    for (i = 0; i < size; i++)
    {
        scanf("%s",First_names[i]);
        scanf("%s",Last_names[i]);
        scanf("%lf",&Scores[i]);
    }
    
    main_menu(First_names, Last_names, Scores, size);
}

void main_menu(char **F, char **L, double *S, int size)
{
    int exit = 0;
    while (exit != 1)
    {
        int function;
        
        printf("\nPrint records \t\t(press 1) \nAdd a new record(s) (press 2) \nDelete record(s) \t(press 3) \nSearch by last name (press 4) \nSort by score \t\t(press 5) \nSort by last name \t(press 6) \nFind median score \t(press 7) \nExit the program \t(press 0)\n");
        scanf("%d", &function);
        while (function < 0|| function > 7)
        {
            printf("Please use the given options.\n");
            scanf("%d", &function);
        }
        switch (function)
        {
            case 0:
                exit = FREE_EVERYTHING(F, L, S, size);
                break;
            case 1:
                print_records(F, L, S, size);
                break;
            case 2:
                add_record(&F, &L, &S, &size);
                break;
            case 3:
                
                delete_record(F, L, S, &size);
                unallocate(&F, &L, &S, &size);
                break;
            case 4:
                search_last(F, L, S, size);
                break;
            case 5:
                sort_score(F, L, S, size);
                print_records(F, L, S, size);
                break;
            case 6:
                sort_last(F, L, S, size);
                print_records(F, L, S, size);
                break;
            case 7:
                Median_score(F, L, S, size);
            
        }
    }
}

/* Begin simple print function */
void print_records(char **F, char **L, double *S, int size)
{
    printf("\n");
    int i;
    for (i = 0; i < size; i++)
    {
        printf("First Name: %s Last Name: %s Score: %.2lf\n", F[i], L[i], S[i]);
    }
}

/* Adding new record using pass by reference */
void add_record(char ***F, char ***L, double **S, int *size)
{
    int sum,i;
    printf("How many records would you like to add?\n");
    scanf("%d",&sum);
    sum = (*size)+sum;
    (*F) = (char**)realloc((*F),sum * sizeof(char*));
    (*L) = (char**)realloc((*L),sum * sizeof(char*));
    (*S) = (double*)realloc((*S),sum * sizeof(double));
    printf("\nPlease input records of students (enter a new line after each record), with following format: \nfirst name[max 20 char] last name[max 20 char] score\n");
    for (i = (*size); i < sum; i++)
    {
        (*F)[i] = (char*)malloc(21);
        (*L)[i] = (char*)malloc(21);
        
        scanf("%s",(*F)[i]);
        scanf("%s",(*L)[i]);
        scanf("%lf",&(*S)[i]);
    }
    
    (*size) =sum;
}

/* Begin search function */
void search_last(char **F, char **L, double *S, int size)
{
    int i;
    char L_N[21];
    
    /* Asking user for the first name to search for */
    printf("Enter last name\n");
    scanf("%s", L_N);
    
    /* Start for loop to compare names */
    for (i = 0; i < size; i++)
    {
        if (strcmp((L_N),L[i]) == 0)      //Comparing user given name to name in array
        {
            printf("First Name: %s Last Name: %s Score: %.2lf\n", F[i], L[i], S[i]); //Printinf match
        }
    }
    
}

/* Begin sort function using altered bubble sort */
void sort_score(char **F, char **L, double *S, int size)
{
    int i, j, tmp;
    char *tempstring;
    
    for(i = 0; i< size-1; i++)
    {
        for(j = 0; j<size-i-1; j++)
        {
            if(S[j]>S[j+1])
            {
                //Switch the scores
                tmp = S[j];
                S[j] = S[j+1];
                S[j+1] = tmp;
                
                //Switch the first names
                tempstring = F[j];
                F[j] = F[j+1];
                F[j+1] = tempstring;
                
                //Switch the last names
                tempstring = L[j];
                L[j] = L[j+1];
                L[j+1] = tempstring;
                
            }
        }
    }

}
/* Begin sort function using altered bubble sort */
void sort_last(char **F, char **L, double *S, int size)
{
    int i, j, tmp;
    char *tempstring;
    
    for(i = 0; i< size-1; i++)
    {
        for(j = 0; j<size-i-1; j++)
        {
            if(strcmp(L[j],L[j+1]) > 0)
            {
                tmp = S[j];
                S[j] = S[j+1];
                S[j+1] = tmp;
                //Switch the first names
                tempstring = F[j];
                F[j] = F[j+1];
                F[j+1] = tempstring;
                
                //Switch the last names
                tempstring = L[j];
                L[j] = L[j+1];
                L[j+1] = tempstring;
            }
        }
    }
}

void unallocate(char ***F, char ***L, double **S, int *size)
{
    
    (*F) = (char**)realloc((*F),(*size) * sizeof(char*));
    (*L) = (char**)realloc((*L),(*size) * sizeof(char*));
    (*S) = (double*)realloc((*S),(*size) * sizeof(double));
    
}

void delete_record(char **F, char **L, double *S, int *size)
{
    int i, end = (*size);
    char name[21];
    /* Asking user for the last name to search for */
    printf("Enter a last name.\n");
    scanf("%s", name);
    /* Start for loop to compare names */
    for (i = 0; i < end; i++)
    {
        if (strcmp(name,L[i]) == 0)      //Comparing user given name to name in array
        {
            free(F[i]);
            free(L[i]);
            F[i] = NULL;
            L[i] = NULL;
            S[i] = 9999999;
            (*size) -= 1;
        }
    }
    sort_score(F, L, S, end);
}

int FREE_EVERYTHING(char **F, char **L, double *S, int size)
{
    int i;
    for (i=0;i<size;i++)
    {
        free(F[i]);
        free(L[i]);
    }
    free(F);
    free(L);
    free(S);
    return 1;
}

void Median_score(char **F, char **L, double *S, int size)
{
    double first, last, Average, median = 0;
    char choice;
    int i;
    sort_score(F, L, S, size);
    if (size % 2 == 0)
    {
        first = S[(size / 2)-1];
        last = S[(size / 2)];
        Average = (first + last)/2;
        median = Average;
    }
    else if (size %2 != 0)
    {
        median = S[size / 2];
    }
    printf("The median score is %.2f \n", median);
    printf("There are %.0f students at or above the median score of %.2f\n",size/2.0, median);
    printf("Would you like me to print the records of the students who have a score at or above the median score? [Y/N]\n");
    scanf("%s",&choice);
    if (choice == 'Y' || choice == 'y')
    {
        for (i = size /2 ; i < size; i++)
            printf("First Name: %s Last Name: %s Score: %.2lf\n", F[i], L[i], S[i]);
    }
}

