/*
Documentation

Name: Shreya Shanbhag
Date: 04-04-2026
Description:
This project is an inverted search system implemented using the C programming language. 
It reads multiple text files and creates a database of words along with the files in which they appear and the number of times they occur. 
The program uses hashing and linked lists to organize the data efficiently. 
It also provides options to create the database, display it, search for a word, update it with new files, and save the data to a file. 
This helps in quickly finding where a particular word is present across different files.
*/
#include "inverted_Search.h"

int main(int argc, char *argv[])
{
    //system("clear");// clears screen from the previous execution contents

    //CLA validation
    if(argc<=1)
    {
        printf("Enter atleast 2 arguments to proceed\n");
        printf("INFO:Enter in the given format ./output.exe file.txt file2.txt\n");
        return FAILURE;
    }
    //create linked list of files
    Flist *f_head=NULL;
    
    Wlist *head[27]={NULL};
    //validation of files -content availability, repetation
    file_validation_n_file_list(&f_head,argv);
    if(f_head==NULL)
    {
        printf("Files are not added to the linked list.Execution terminated\n");
        return FAILURE;
    }

    //display menu
    while (1)
    {
        printf("\n===== INVERTED SEARCH MENU =====\n");
        printf("1. Create Database\n");
        printf("2. Display Database\n");
        printf("3. Search Database\n");
        printf("4. Update Database\n");
        printf("5. Save Database\n");
        printf("6. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: create_database(f_head, head);
                    printf("Database created successfully\n");
                    break;

            case 2: display_database(head);
                    break;

            case 3:char word[50];
                    printf("Enter word to search (all in lowercase): ");
                    scanf("%s", word);
                    int index =tolower(word[0]) % 97; // Hash function 
                    search(head[index], word);
                    break;

            case 4:update_database(head, &f_head);
                    printf("Database updated successfully\n");
                    break;

            case 5: save_database(head);
                    printf("Database saved successfully\n");
                    break;

            case 6: printf("Exiting...\n");
                    return 0;

            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;

}