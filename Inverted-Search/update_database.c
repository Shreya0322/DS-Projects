#include "inverted_Search.h"
char processed_files[MAX_FILES][FNAME_SIZE];
int file_count = 0;

int update_database(Wlist *head[], Flist **f_head)
{
    char filename[FNAME_SIZE];

    printf("Enter the filename: ");
    scanf("%s", filename);

    //check for duplicate or already passed file
    if (is_file_present(filename))
    {
        printf("File %s already processed\n", filename);
        return FAILURE;
    }


    // Check if file exists in file list
    to_create_list_of_files(f_head, filename);
    Flist *temp = *f_head;

    while (temp != NULL)
    {
        if (strcmp(temp->file_name, filename) == 0)
        {
            // update database
            read_datafile(temp, head, filename); 
            add_file(filename); 

            printf("Database updated successfully for file: %s\n", filename);
            return SUCCESS;
        }

        temp = temp->link;
    }

    //File not found in list
    printf("File %s not found in file list\n", filename);
    return FAILURE;
}

int is_file_present(char *filename)
{
    for (int i = 0; i < file_count; i++)
    {
        if (strcmp(processed_files[i], filename) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void add_file(char *filename)
{
    if (file_count < MAX_FILES)
    {
        strcpy(processed_files[file_count], filename);
        file_count++;
    }
}