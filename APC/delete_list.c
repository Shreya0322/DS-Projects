#include "header.h"
int delete_list(Dlist **head, Dlist **tail)
{
    if(*head==NULL)
    {
        return FAILURE;
    }
    if(*head==*tail)
    {
        *head=NULL;
        *tail=NULL;
        return SUCCESS;
    }
    Dlist *temp=*head;
    while(temp!=NULL)
    {
        *head=temp->next;
        free(temp);
        temp=*head;
    }
    *tail=NULL;
}