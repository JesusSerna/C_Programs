//
//  main.c
//  HomeWork_1
//
//  Created by Jesus Serna on 9/13/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

//global variables
int word_count=0;
int word_index[100];
int itterations;

//function prototypes
void display (char *text);
void insertion_sort (char *text);
void lowercase (char *str1);
int binary_search (char *text, char *search);

int main()
{
    char text[10000],search[50];
    int exit =0,found;
    
    //asking user to enter words to be sorted
    printf("Enter the text:\n");
    scanf("%[^\r\n]s",text);
    
    //printing header for unsorted words
    printf("\n\nWords and indexes (the printed words are 'cleaned'):");
    display(text);
    insertion_sort(text);
    
    //printing header for sorted words
    printf("\nThe sorted data (the printed words are 'cleaned'):");
    display(text);
    printf("\nBinary search. ---- Enter words to search for. Stop with -1.\n");
    while(exit != -1)
    {
        //asking user for word to search
        scanf("%s",search); //storing user specified word in "search" variable
        
        if(search[0] == '-' && search[1] == '1')
        {
            exit=-1;
        }
        else
        {
            printf(" (original: %s) \ncleaned: ",search);
            
            lowercase(search);
            printf("%s",search);    //printing and converting all words to lowercase
            
            found = binary_search(text, search);
            if (found == 1)
            {
                printf(" - found (%d iterations)\n", itterations);
            }
            else printf(" - not found (%d iterations)\n", itterations);
        }
    }
    
    //displaying the original text
    printf("\nThe original text is still the same: %s\n", text);
   // printf("ends here%d\n",word_count);
    return 0;
}

//function to display table
void display(char *text)
{
    //itteraters to use in while/for loops
    int i = 0,k = 0;
    
    //temporary string to store 1 word
    char temp[50];
    
    //printing header
    printf("\n i   |index[i]|  word\n");
    printf("-----|--------|------------------\n");
    
    //counting the number of words in "text"
    if (word_count == 0)
    {
        while(text[i] != '\0' && text[i] != '\n')
        {
            while(text[i] == ' ')
            {
               i++;
            }
            sscanf(&text[i],"%s",temp);
            word_index[word_count]=i;   //storing index numbers for each word
            i += strlen(temp);          //going to next possible word index
            while (text[i] == ' ')
                i++;
            word_count++;               //keeping track of number of words in "text"
        }
    }
    
    //printing word numbers, word indexes, and words from "text"
    while (k < word_count)
    {
        sscanf(&text[word_index[k]],"%s",temp);
        printf("%4d |%7d |  ", k ,word_index[k]);
        for(i=0; i < strlen(temp);i++)
        {
            if(text[word_index[k]+i] != '.' && text[word_index[k]+i] != ',' && text[word_index[k]+i] != '?' && text[word_index[k]+i] != '!' && text[word_index[k]+i] != ';' && text[word_index[k]+i] != ':') //making sure not to print any non-alphabetical character
            {
                printf("%c",tolower(text[word_index[k]+i]));    //printing and converting all words to lowercase
            }
        }
        printf("\n");
        k++;
    }
}

void insertion_sort(char *text)
{
    //itteraters to use in while/for loops
    int i, j,temp;
    
    //temporary variables used to store the two strings that will be compared
    char str1[50],str2[50];
    
    //itterating through "text" to compare words to sort
    for (i = 1 ; i < word_count; i++) {
        j = i;
        
        //grabbing words to be compared
        sscanf(&text[word_index[j]],"%s",str2);
        sscanf(&text[word_index[j-1]],"%s",str1);
        
        //converting words to lowercase to compare
        lowercase(str2);
        lowercase(str1);
        
        //checking if words need to be swapped based on alphabetical order
        while (j > 0 && strcmp(str1,str2) > 0)
        {
            //swaping indexes
            temp = word_index[j];
            word_index[j] = word_index[j-1];
            word_index[j-1] = temp;
            j--;
            
            //grabbing previous words to be compared in the chain
            sscanf(&text[word_index[j]],"%s",str2);;
            sscanf(&text[word_index[j-1]],"%s",str1);
            
            //converting words to lowercase to compare
            lowercase(str2);
            lowercase(str1);
        }
        
    }
}

//lowercase function for converting any word to lowercase
void lowercase (char *str1)
{
    int i;
    for(i=0; i < strlen(str1);i++)
    {
        if(str1[i] >= 'A' && str1[i] <= 'z')  //making sure to only convert alphabetial characters as all others could result in error
        {
            str1[i] = tolower(str1[i]);
        }
    }
    if(str1[strlen(str1)-1] == '.' || str1[strlen(str1)-1] == ',' || str1[strlen(str1)-1] == '?' || str1[strlen(str1)-1] == '!' || str1[strlen(str1)-1] == ';' || str1[strlen(str1)-1] == ':')
    {
        str1[strlen(str1)-1] = '\0';
    }
}

int binary_search(char *text, char *search)
{
    int start = 0 ,end = word_count-1,middle=0;
    char word[50];
    
    itterations = 1;
    while (start <= end)
    {
        middle = start + (end-start)/2;
        sscanf(&text[word_index[middle]],"%s",word);
        lowercase(word);
        if (strcmp(word, search) == 0)
        {
            start = end + 1;
            return 1;
        }
        else if (strcmp(word, search) < 0)
        {
            itterations++;
            start = middle+1;
        }
        else if (start == end && strcmp(word, search) != 0)
        {
            start = end + 1;
            return 0;
        }
        else
        {
            end = middle-1;
            itterations++;
        }
       
    }
    itterations--;
    return 0;
}