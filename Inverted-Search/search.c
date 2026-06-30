#include "inverted_Search.h"

int search( Wlist *head, char *word)
{
    
    //check if head is empty
    if(head==NULL)
    {
        printf("No such word found. List is empty\n");
        return FAILURE;
    }

    //if list is non empty
    Wlist *temp=head;
    while(temp!=NULL)
    {
        if((strcmp(temp->word,word))==0)
        {
            printf("Word %s is present in %d files\n",word, temp->file_count);
            Ltable *thead=temp->Tlink;
            while(thead!=NULL)
            {
                printf("In file %s %d times\n",thead->file_name,thead->word_count);
                thead = thead->table_link;
                
            }
            return SUCCESS;

        }
        temp=temp->link;
    }
    printf("word %s not found!\n",word);
    return SUCCESS;
}