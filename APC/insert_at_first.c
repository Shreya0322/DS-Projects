#include "header.h"

int insert_at_first(Dlist **head, Dlist **tail, int data)
{
    //create a newnode
    Dlist *newnode=malloc(sizeof(Dlist));

    //validate newnode
    if(newnode==NULL)
    {
        return FAILURE;
    }
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    
    //check if list is empty
    if(*head==NULL)
    {
        *head=newnode;
        *tail=newnode;
    }
    //if list is non empty
    else
    {
        newnode->next=*head;
        (*head)->prev=newnode;
        *head=newnode;
    }
    return SUCCESS;
}