#include "header.h"

int insert_at_last(Dlist **head, Dlist **tail, char ch)
{
    //create a newnode
    Dlist *newnode=malloc(sizeof(Dlist));

    //validate newnode
    if(newnode==NULL)
    {
        return FAILURE;
    }
    newnode->data=ch-'0';
    newnode->prev=NULL;
    newnode->next=NULL;

    //if list is empty
    if(*head==NULL)
    {
        *head=newnode;
        *tail=newnode;
    }
    else
    {
        newnode->prev=*tail;
        (*tail)->next=newnode;
        *tail=newnode;

    }
    return SUCCESS;
}