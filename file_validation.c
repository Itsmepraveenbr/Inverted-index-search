#include"inverted_search.h"

//function to validate the input file and add it to file linked list
void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1 , empty;

    while(argv[i] != NULL)
    {
      empty = isFileEmpty(argv[i]);  //checking if empty file is passed

      if(empty == FILE_NOTAVAILABLE)
      {
           printf("File : %s is not available\n", argv[i]);
           printf("Hence we are not adding that file\n");
           i++;
           continue;
      }
        
      
      else if(empty == FILE_EMPTY)
      {
           printf("File : %s is empty\n",argv[i]);
           printf("Hence we are not adding that file\n");
           i++;
           continue;
      }
      
      else
      {
       int ret_val = to_create_list_of_files(f_head,argv[i]);     //if the file is valid adding the file to the file linked list
        
        if(ret_val == SUCCESS)
        {
            printf("Successfull : in inserting the file %s into file LL \n" , argv[i]);
        
        }

        else if(ret_val == REPEATATION)               //if the filealready exists printing repeated file is passed
        {
            printf("This file %s is  repeated , hence we are not adding that filr\n" , argv[i]);
        }

        else
        {
            printf("Failure\n");
        }
        i++;
        
      }
    }
}

//this function is used to check for file availability and for its contents
int isFileEmpty(char *filename)
{
    FILE *fptr = fopen(filename, "r");

    if(fptr == NULL)
    {
        if(errno == ENOENT)
        {
            return FILE_NOTAVAILABLE;
        }
    }

    fseek(fptr,0,SEEK_END);
    if(ftell(fptr) == 0)
    {
        return FILE_EMPTY;
    }
}

//function to create file linked list
int to_create_list_of_files(Flist **f_head, char *name)
{  
    //check for duplicancy
    Flist* temp = (*f_head);
    while (temp != NULL)
    {
        if (strcmp(temp -> file_name, name) == 0)
        {
            return REPEATATION;
        }
        temp = temp->link;
    }
    
    //.......insert_last().......
    //Creating new node
    Flist* new_file = malloc(sizeof(Flist));

    //Validating new
    if (new_file == NULL)
    {
        return FAILURE;
    }

    //Updating filename and link part
    strcpy(new_file -> file_name, name);

    new_file -> link = NULL;

    if (*f_head == NULL)
    {
        *f_head = new_file;
         return SUCCESS;
    }

    temp = *f_head;

    while (temp -> link != NULL)
    {
        temp = temp -> link;
    }

    temp -> link = new_file;
    return  SUCCESS;
        
}





