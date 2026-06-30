#include "inverted_Search.h"
extern char *fname;

int insert_at_last(Wlist **head, data_t *data)
{
    //create a newnode
    Wlist *newnode=malloc(sizeof(Wlist));
    if(newnode==NULL)
    {
        return FAILURE;
    }
    //update the data
    newnode->file_count=1  ;
    strcpy(newnode->word,data);
    newnode->Tlink=NULL;
    newnode->link=NULL;

    //update the link table which consists of word count in each file
    update_link_table(&newnode);
    //check if list is empty
    if(*head==NULL)
    {
        *head=newnode;
        return SUCCESS;
    }
    //if list is not empty
    Wlist *temp=*head;
    while(temp->link)
    {
        temp=temp->link;
    }
    temp->link=newnode;
    return SUCCESS;

}

int update_link_table(Wlist *head[])
{
    //create L table node
    Ltable *newnode = malloc(sizeof(Ltable));
    if(newnode == NULL)
    {
        return FAILURE;
    }
    newnode->word_count = 1;
    strcpy(newnode->file_name, fname);
    newnode->table_link = NULL;

    //link the L table node to Word list node
    (*head)->Tlink = newnode;
    return SUCCESS;

}