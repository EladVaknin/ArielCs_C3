#include <stdio.h>
#include "findtxt.h"
#include <string.h>
#include <stdlib.h>
#define LINE 256
#define WORD 30
#define LINES 250
#define WORDS 32000

int get_line(char s[])
{
    int count = 0;
    char c;

    while( ((c=getchar())!=EOF)  && (c != '\n'))
    {
        
        *(s+count)=c;
        count ++;
    }
    *(s+count)='\0';
    return count; 
}

//returns number of characters in a text
int getword(char w[])
{
    int count = 0;
    char c;
    while( ((c=getchar())!=EOF ) && (c != '\n') && (c != '\t') && (c != ' '))
    {
        *(w+count)=c;
        count ++;
    }
    *(w+count)='\0';
    return count; 
}

int substring( char * str1, char * str2)
{
    //str1 is the word and str2 is the checked
    
    int i =0;
    int j = 0;

    while(*(str2+i)!='\0')
    {
        if(*(str1+j)=='\0')
        {
            return 1;
        }
        else if(*(str1+j)==*(str2+i))
        {
            i++;
            j++;
        }
        else
        {
            i++;
            j=0;
        }
    }
    if(*(str1+j)=='\0')
    {
        return 1;
    }
    return 0;    
}

int similar (char *s, char *t, int n)
{
    //t is the objective and s is the word being searched
    int i = 0;
    int j = 0;
    while(*(s+i)!='\0')
    {
        if(*(s+i)!=*(t+j))
        {
            n--;
            i++;
        }
        else if(n<0)
        {
            return 0;
        }
        else{
            i++;
            j++;
        }
    }
    if(*(t+j)=='\0'&&n>=0)
    {
        return 1;
    }
    return 0;   
}

void print_lines(char * str)
{
    char line [LINE];
    
    while(get_line(line))
    {   
        
        if(substring(str,line)){
            printf("%s\n" ,line);
        }
       
    }
}

void print_similar_words(char * str)
{
    char word [WORD];
    
    while(getword(word))
    {
        if(similar(word,str,1)){
            printf("%s\n" ,word);
        }
       
    }
}

int main()
{
    char word [WORD];
    scanf("%s", word);

    char c;
    
    scanf(" %c", &c);
    scanf(" ");
    if(c == 'a'){
       
        print_lines(word);}
    if(c == 'b'){print_similar_words(word);}
    return 0;
}

