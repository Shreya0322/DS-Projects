#include "header.h"

int add(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head_res, Dlist **tail_res)
{
    //initailaise variables and carry to 0
    int carry=0,res;

    //initialise 2 pointers of type Dlist(structure) and store both the list tail address in it
    Dlist *temp1=*tail1, *temp2=*tail2;

    //Run a loop till both list points to NULL starting from tail address
    while(temp1!=NULL || temp2!=NULL)
    {
        //if temp2 list becomes null, add data of temp1 and carry 
        if(temp1!=NULL && temp2==NULL)
        {
            res=(temp1->data)+ carry;
        }
        //if temp1 list becomes null, add data of temp2 and carry
        else if(temp1==NULL && temp2!=NULL)
        {
            res=(temp2->data) + carry;
        }
        //if non of the list is pointing to null the add the data of both the list pointed by temp as well as carry
        else
        {
            res= (temp1->data) + (temp2->data) + carry;
        }
        //if the result of addition is greater than 9 then store the last digit in the list and set carry to 1
        if(res>9)
        {
            res=res%10;
            carry=1;
        }
        //if the result of addition is less than 9 stores result directly into the list and reset carry to 0
        else
        {
            carry=0;
        }
        
        //insert the result in the result list 
        if(insert_at_first(head_res,tail_res,res)==FAILURE)
        {
            printf("INFO :Failed to insert\n");
            return FAILURE;
        }

        //check if the previous node is null or not , if not move to previous node
        if(temp1!=NULL)
        {
            temp1=temp1->prev;

        }
        if(temp2!=NULL)
        {
            temp2=temp2->prev;

        }
    }
    //after completing digit wise addition still carry is 1 then add carry to the result list
    if(carry)
    {
        if(insert_at_first(head_res,tail_res,carry)==FAILURE)
        {
             printf("INFO :Failed to insert\n");
            return FAILURE;
        } 
    }
    return SUCCESS;
}