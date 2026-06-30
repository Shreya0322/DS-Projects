#include "inverted_Search.h"

//Function to display the database on the terminal screen
void display_database(Wlist *head[])
{
    printf("\n==========================================================================\n");
    printf("%-6s %-15s %-12s %-18s %-10s\n",
           "Index", "Word", "FileCount", "Filename", "WordCount");
    printf("==========================================================================\n");

    for (int i = 0; i < 27; i++)
    {
        if (head[i] != NULL)
        {
            print_word_count(head[i], i);
        }
    }
    printf("==========================================================================\n");
}
//print the details
int print_word_count(Wlist *head, int index)
{
    while (head != NULL)
    {
        Ltable *temp = head->Tlink;
        if (temp != NULL)
        {
            printf("%-6d %-15s %-12d %-18s %-10d\n",index+1,head->word,head->file_count,temp->file_name,temp->word_count);

            temp = temp->table_link;
        }

    
        while (temp != NULL)
        {
            printf("%-6s %-15s %-12s %-18s %-10d\n","", "", "", temp->file_name, temp->word_count);

            temp = temp->table_link;
        }
        printf("-----------------------------------------------------------------------------");
        printf("\n");  

        head = head->link;
    }

    return SUCCESS;
}