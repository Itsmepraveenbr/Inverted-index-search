#include "inverted_search.h"

extern char * fname;

int insert_at_last(Wlist **head, data_t *data)
{
    //create a node
    Wlist *new = malloc(sizeof(Wlist));

    //error check
    if(new == NULL)
    {
        return FAILURE;
    }

    //update fields
    new -> file_count = 1;
    strcpy( new -> word,data);
    new -> Tlink = NULL;
    new -> link = NULL;

    //call fun() to update Ltable node
     update_link_table(&new);

    //check Wlist is empty or not
    if(*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    //non empty
    Wlist * temp = *head;

    //traverse through the list
    while(temp -> link)
    {
        temp = temp -> link;
    }
    temp -> link = new;
    return SUCCESS;

}

int update_link_table(Wlist **head)
{
    //create node
    Ltable *new = malloc(sizeof(Ltable));
    //error check
    if(new == NULL)
    {
        return FAILURE;
    }
    
    //update the link filelds
    new -> word_count = 1;
    strcpy(new -> file_name,fname);
    new -> table_link = NULL;

    (*head) -> Tlink = new;
}
