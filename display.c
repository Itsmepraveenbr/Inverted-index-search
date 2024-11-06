#include "inverted_search.h"

//function to displat the database
 void display_database( Wlist *head[] )
{
    printf("[index]     [word]      filr_count file/s       File: File_name      word_count\n");

    //loop all the head pointers and print the words
    for(int i = 0 ; i < 27 ; i++)
    {
        if(head[i] != NULL)
        {
            printf("\r");
            printf("[%d]",i);
            
            print_word_count(head[i]);
        }
    }
}

//function to print the words
int print_word_count(Wlist *head)
{
    //traverse through the Wlist
    while(head != NULL)
    {
        int i = tolower(head -> word[0]) % 97;

        //if the words start with alphabets
        if(i >= 0 && i <= 25)
        {
            i = i;
        }
        else    //if the words are not alphabets
        {
            i = 26;
        }
      //  printf("[%d]         [%s]       %d  file/s :     " ,i, head -> word , head -> file_count);
          printf("         [%s]            %d  file/s :     " , head -> word , head -> file_count);  
          

       Ltable *Thead = head -> Tlink;

       //traverse through the link table
        while(Thead)
        {
            printf(" File :%s      %d ", Thead -> file_name,Thead -> word_count);
            Thead = Thead -> table_link;
        }
       
        printf("\n");
        printf("   ");
        head = head -> link;
    }
}



                               
