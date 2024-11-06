#include "inverted_search.h"

//function to update the database
 void update_database( Wlist *head[], Flist **f_head)
{   
    //prompt the user for new file
    char file_name[FNAME_SIZE];
    printf("Enter the new file for updating the database\n");
    scanf("%s",file_name);
    
    //validation
    int empty;
    empty = isFileEmpty(file_name);
 
        if(empty == FILE_NOTAVAILABLE)
        {
             printf("File : %s is not available\n",file_name);
             printf("Hence we are not adding that file\n");
                 return;
            
        }
        else if(empty == FILE_EMPTY)
        {
             printf("File : %s is empty\n",file_name);
             printf("Hence we are not adding that file\n");
             return;
        }
        
        int ret_val =  to_create_list_of_files(f_head,file_name);
 
        if(ret_val == SUCCESS)
        {
             printf("Successfull : in inserting the file %s into file LL \n" , file_name);
 
        }
        else if(ret_val == REPEATATION)
        {
            printf("This file %s is  repeated , hence we are not adding that filr\n" ,file_name);
            return;
        }
        else
        {
              printf("Failure\n");
              return;
        }
        
  //update_database
  //create_Database for the new file

    Flist *f_temp = *f_head;
    while(f_temp)
    {
       if (!(strcmp((f_temp) -> file_name,file_name)))
       {
           create_database(f_temp,head);
           return;
       }
       f_temp = (f_temp) -> link;
    }
    printf("Database updated successfully !! \n");
  
}
