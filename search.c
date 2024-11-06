#include "inverted_search.h"

//function to search the word 
void search( Wlist *head, char *word)
{   
    //head is empty or not
    if(head == NULL)
    {
        printf("Search word is not available in the list as the list is empty\n");
        return ;
    }

    //traverse and compare    
    while(head)
    {

        //compare the search word with each node word
        if(! strcmp(head -> word, word))
        {
            printf("Word %s is present in %d file / s\n",word, head->file_count);

            Ltable *Thead = head -> Tlink;

            while(Thead)
            {
                printf("In file : %s  %d times\n",Thead -> file_name, Thead->word_count);
                Thead = Thead -> table_link;
            }
            printf("\n");
            return ;
        }
        head = head -> link;

    }

    printf("The search word not found \n" );

}





            




