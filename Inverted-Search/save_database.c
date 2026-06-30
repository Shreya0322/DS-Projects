#include "inverted_Search.h"

int save_database(Wlist *head[])
{
    char file_name[FNAME_SIZE];

    printf("Enter the filename: ");
    scanf("%s", file_name);

    FILE *fptr = fopen(file_name, "w");
    if (fptr == NULL)
    {
        printf("Failed to open the file\n");
        return FAILURE;
    }

    for (int i = 0; i < 27; i++)
    {
        if (head[i] != NULL)
        {
            write_databasefile(head[i], &fptr, i);
        }
    }

    fclose(fptr);   

    return SUCCESS;
}
void write_databasefile(Wlist *head, FILE** databasefile,int index)
{
    //#index: [word]:[file_count]:filename:[wordcount]-format to save the data into database file
    if(head==NULL)
    {
        return;
    }

    while(head!=NULL)
    {
        // Print index, word and file_count
        fprintf(*databasefile, "#%d;%s;%d", index, head->word, head->file_count);

        //Traverse link table 
        Ltable *temp = head->Tlink;

        while (temp != NULL)
        {
            fprintf(*databasefile, ";%s;%d", temp->file_name, temp->word_count);
            temp = temp->table_link;
        }

        // End of one word entry
        fprintf(*databasefile, ";\n");
        head=head->link;
    }

}