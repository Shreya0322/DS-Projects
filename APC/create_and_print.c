#include"header.h"
/*
The create list function takes the input string and converts them to double linked list
*/
int create_list(char *str, Dlist **head, Dlist **tail)
{
    int i=0;
    //if the first character is + or - move to next character
    if(str[0]=='+'||str[0]=='-')
    {
        i++;
    }
    while(str[i]!='\0')
    {
        //check if the character is in the range of 0-9 or not
       if(str[i]<'0'||str[i]>'9')
       {
          printf("Invalid Number\n");
          return 0;
       }

       //if character is in the range create a node and form list
       if(insert_at_last(head,tail,str[i])==FAILURE)
       {
           printf("INFO : Failed to insert a node\n");
           return FAILURE;
       }

       i++;
       

    }
    return SUCCESS;
}
/*
Print list function prints the list by traversing through the list
*/
void print_list(Dlist *head)
{
    if(head==NULL)
    {
        printf("INFO : List is empty\n");
    }
    else
    {
        Dlist *temp=head;
        while(temp)
        {
            printf("%d",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }

}
/*
The count function counts the number of nodes starting from head node
If the count is 0 and the initial nodes are 0 it skips and starts counting from non zero digit and return the count.
*/
int count_node(Dlist *head)
{
    Dlist *temp=head;
    int count=0;
    while(temp!=NULL)
    {
        if(count==0 && temp->data==0)
        {
            temp=temp->next;
        }
        else
        {
            count++;
            temp=temp->next;

        }
    }
    return count;

}
/*
The compare function compares the two list  by value and by count
case 1: If the first list is  greater than second list returns 1
case 2: If the first list is smaller than second list returns 0
*/
int compare(Dlist *head1, Dlist *head2)
{
    int count1=count_node(head1);
    int count2=count_node(head2);

    if(count1>count2)
    {
        return 1;
    }
    else if(count1<count2)
    {
        return 0;
    }

    Dlist *temp1=head1,*temp2=head2;
    //If the numbers of nodes are same in both the list
    //Traverse through the list starting from head and compare the data in each node
    while(temp1!=NULL && temp2!=NULL)
    {
        if((temp1->data)<(temp2->data))
        {
            return 0;
        }
        else if((temp1->data)>(temp2->data))
        {
            return 1;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return 1;
}
/*
The copy list function copies one list into another
*/
int copy_list(Dlist *head1, Dlist **head_res, Dlist **tail_res)
{
    Dlist *temp = head1;

    while(temp != NULL)
    {
        if(insert_at_last(head_res, tail_res, temp->data+'0') == FAILURE)
        {
            printf("INFO : Failed to copy list\n");
            return FAILURE;
        }

        temp = temp->next;
    }

    return SUCCESS;
}