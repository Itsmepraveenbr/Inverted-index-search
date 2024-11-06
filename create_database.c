#include "inverted_search.h"      

char *fname;

//function to create database
void create_database(Flist *f_head, Wlist *head[])
{
    //traverse through this file linked list

    while(f_head)
    {
        read_datafile(f_head, head , f_head->file_name);
        f_head = f_head -> link;

    }

}


//read the contents of file
Wlist * read_datafile(Flist *file, Wlist *head[], char *filename)
{
    //open the file in read mode
    FILE *fptr = fopen(filename,"r");
  
    if(fptr == NULL)
    {
        printf("Error in opening %s file \n",filename);
    }
    fname = filename;
   
    //declare an array to store the word
    char word[WORD_SIZE];


    while(fscanf(fptr , "%s" , word) != EOF)
    {
        int flag = 1;
        int index;
  
          // if((word[0]>='A' && word[0]<='Z') || (word[0]>='a' &&word[0]<='z'))
          //to calculate the index of word
        index = tolower(word[0]) % 97;
          // printf("%d\n",index);
             // other then alphabet
        if(! (index >= 0 && index <= 25 ))
        {          
            index = 26;
        }



        //check whether words are repeated or not
        if(head[index] != NULL)
        {
            Wlist *temp = head[index];
            //compare the new word with each node words
            while(temp)
            {
               if(!strcmp(temp -> word, word))
               {
                   update_word_count(&temp, filename);
                   flag = 0;
                   break;
               }
               temp = temp -> link;
            }
        }
        if(flag == 1)
        {     
              //if words are not repeated
              insert_at_last(&head[index], word);
         }

    }       
            printf("Successful in creation of database for %s file\n", filename);
}


//function to update the word count
int update_word_count(Wlist ** head, char * file_name)
{    
    Ltable * temp = (*head) -> Tlink, *prev = NULL;

    while(temp != NULL)
    {
         //check file names are same or not
        if(! (strcmp(temp -> file_name, file_name)))
        {
            //filenames are same  =>increment word count
            temp -> word_count++;
            return SUCCESS;           
        }

        //filenames are different -> increment file_count , create new Ltable node
        else
        {
        
            ((*head) -> file_count) += 1;

            Ltable * new = malloc(sizeof(Ltable));
            //error check
            if(new == NULL)
            {
                return FAILURE;
            }

            //update the link table
            new -> word_count = 1;
           strcpy( new -> file_name,file_name);
            new->table_link = NULL;

            // update the address of the previous node
            temp -> table_link = new;
            return SUCCESS; 
        }
    }
}
