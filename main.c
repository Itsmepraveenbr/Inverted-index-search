//Name : Praveen B R
//Date : 24/08/2024
//Description: Inverted search project



#include "inverted_search.h"

int main(int argc , char *argv[])
{
    system("clear");

    //initializing all the head elements to null    
    Wlist *head[27] = {NULL};
   
    //validation
    //if the file is not passed    
    if(argc <= 1)
    {
        printf("Enter the valid no of arguments\n");
        printf("./slist.exe file1.exe file2.exe ..........\n");
        return 0;
    }
    
    //declare head pointer 
   Flist * f_head = NULL;

    //validate the file
   file_validation_n_file_list(&f_head , argv);
   
        if(f_head == NULL)
        {
            printf("No files are available in file LL\n");
            printf("Hence the process got terminated\n");
            return 1;
        }
        
        //prompt the user for choice
        int choice;
        char option;
        char word[WORD_SIZE];
        int flag = 1;    //variable to stop multiple times database being created

        do
        {
            printf("Select your choice among following options: \n");
            printf("1. Create DATABASE \n2. Display Database \n3. Update DATABASE \n4. Search \n5. Save Database \n6. Exit \n Enter your Choice \n");
                
            scanf("%d",&choice);
            
            
            switch(choice)
            {
                case 1 : //create Database
                         //create database if flag is 1 and make flag 0 
                         if(flag == 1)
                         {                       
                            create_database(f_head , head);
                            flag = 0;
                         }
                         printf("Database is created please add files by selecting update database\n");
                         
                         break;
                         
                case 2 : //display database
                         display_database(head);
                         break;

                case 3 : // Update Database
                         update_database(head , &f_head);
                         break;

                case 4 : //Search
                         printf("Enter the word\n");
                         scanf("%s" , word);

                          int i = tolower(word[0]) % 97;

                          if(i >= 0 && i <= 25)
                          {       
                             //search(head[tolower(word[0]) % 97], word);
                             search(head[i] ,word);
                          }
                          else
                          {
                              search(head[26] ,word);
                          }
                              break;

                case 5 :  //Save Database

                         save_database(head);
                         break;

                case 6 : //Exit
                         exit(0);

                         break;

                default :   
                         break;
            }
            printf("Do you want to continue (y/n): ");
            getchar();
             scanf("%c",&option);

    } while (option == 'Y'|| option == 'y');

 
}
