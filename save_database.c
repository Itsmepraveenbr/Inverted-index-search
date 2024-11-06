#include"inverted_search.h"

//function to save the database to a file
void save_database( Wlist *head[])
{
    //prompt the user to enter the file name
    char file_name[FNAME_SIZE];
    do
    {
         printf("Enter the fileame with .txt extension\n");
         scanf("%s" , file_name);
    
         if (strstr(file_name, ".") != NULL && strcmp(strstr(file_name, "."), ".txt") == 0)
         {
            // Valid filename with ".txt" extension, break the loop
            break;
         }
         else
         {
             printf("Invalid filename. Please enter a filename with .txt extension.\n");
         }

} while (1); //to repeat until a valid file name is entered
    
    //while(!strcmp(strstr(file_name,"."),".txt")==0);
      
    //open the file
    FILE *fptr = fopen(file_name, "w");
    
    if (fptr == NULL)
    {
        perror("Error opening file");
        return;
    }
    
    //loop all the head pointers
    for(int i = 0 ; i < 27 ; i++)
    {
        if(head[i] != NULL)
        {
           write_databasefile(head[i] , fptr);
       
        }

    }

    printf("The Database is saved in %s \n:",file_name);
    
   }

//function to write the database to the file
void write_databasefile(Wlist *head, FILE* databasefile)
{
    
     Wlist* temp = head;       

	//Checking the Wlist empty or not
     while (temp != NULL)
     {
          int index = tolower(temp -> word[0]) % 97;
           
          fprintf(databasefile,"#%d:\n%s:%d:", index , temp -> word, temp -> file_count);
            
          Ltable* l_temp = temp -> Tlink;
       
          while (l_temp != NULL)
          {
                fprintf(databasefile,"%s:%d:",l_temp -> file_name, l_temp -> word_count);
                l_temp = l_temp -> table_link;
          }
      
          fprintf(databasefile,"#\n");

	       //Moving temp to next node
           temp = temp -> link;

        }
  
    
        
}



