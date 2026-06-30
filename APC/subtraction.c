#include "header.h"

int sub(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head_res, Dlist **tail_res,int *flag)
{
    //function call to count number of nodes in both the lists
    int count1=count_node(*head1);
    int count2=count_node(*head2);

    //initialize flag to 0, which tracks if second imput is greater than second input
    *flag=0;
    //initialize temp1 and temp2 to NULL
    Dlist *temp1=NULL,*temp2=NULL;
    
    if(count1>count2)  //if first list has more nodes than second list(input no: num1 > num2)
    {
        temp1=*tail1;     //initialize temp1 as tail1 and temp2 as tail2
        temp2=*tail2;
    }
    if(count1<count2)  //if first list has less nodes than second list (input no: num1 < num2)
    {
        temp1=*tail2;   //initialize temp1 as tail2 and temp2 as tail1
        temp2=*tail1;
        *flag=1;         //set flag to 1 indicating the output should be negative

    }  
    if(count1==count2)   //if both list has same number of nodes (no of digits are same)
    {
        Dlist *temp_1=*head1,*temp_2=*head2;  //compare node by node till tail starting from head node
        while(temp_1!=NULL && temp_2!=NULL)  
        {
            if((temp_1->data) == (temp_2->data))   //if both the digits of nodes of list1 and list2 are same then move to next node
            {
                temp_1=temp_1->next;
                temp_2=temp_2->next;
            }
            else if((temp_1->data)>(temp_2->data))   //if digit of temp_1 is greater than digit of temp_2,then num1 > num2
            {
                temp1=*tail1;          //initialize temp1 as tail1 and temp2 as tail2 and stop comparison          
                temp2=*tail2;
                break;
            }
            else if((temp_1->data)<(temp_2->data))   //if digit of temp_1 is less than digit of temp_2,then num1 < num2
            {
                temp1=*tail2;       //initialize temp1 as tail2 and temp2 as tail1 and stop comparison
                temp2=*tail1;
                *flag=1;            //set flag to 1 indicating the output should be negative
                break;
            }

        }
        if(temp_1 == NULL && temp_2 == NULL)   //if both pointers read NULL and none of the condition is satisfied,then num1 == num2
        {
            if(insert_at_first(head_res,tail_res,0)==FAILURE)   //the result of subtraction will 0 if num1 == num2
            {                                                   //insert 0 to the result list and stop
                printf("INFO :Failed to insert\n");
                return FAILURE;
            }
            return SUCCESS;
        }
        
    }
    //for input num1 > num2 or num1 < num2
    //initialize variables and borrow to 0, here temp1 holds address of higher and temp2 holds addree of lower number
    int res,borrow=0,num1,num2;   
    while(temp1!=NULL)   //run loop till temp reaches NULL
    {
        num1=(temp1->data) -borrow;   //store the data of temp1 in num1 and subtarct borrow from it

        if(temp2!=NULL)     //check if temp is not equal to NULL
        {
            num2=temp2->data;   //store data of temp2 in num2
            if(num1 >= num2)    //if digit1 > digit2, subtract and set borrow to 0
            {
                 res=num1 - num2;   
                 borrow=0;
            }
            else      //if digit1 < digit2, add 10 to num1 and then subtract num2 from it and set borrow as 1
            {
                res=(num1+10)-num2;
                borrow=1;   
                /*setting borrow to 1 indicates, before preforming subtarction of next digits, 
                 1 should be subtracted from num1(digit1)*/
            }
        }
        else   //if temp2 is NULL 
        {
            if(num1<0)  //check if num1<0 
            {
                 res=num1+10;
                 borrow=1;
            }
            else   //if num1>=0 set res as num1 and borrow to 0
            {
                res=num1;
                borrow=0;
            }
        }
        if(insert_at_first(head_res,tail_res,res)==FAILURE) //insert the res in the result list
        {
             printf("INFO :Failed to insert\n");
             return FAILURE;
        } 
        temp1=temp1->prev;  //move temp1 to previous node
        if(temp2!=NULL)  //if temp2 has not reached NULL, move temp2 to previous node
        {
            temp2=temp2->prev;
        }
    }

    while(*head_res!=NULL && (*head_res)->next!=NULL && (*head_res)->data==0)
    {
         Dlist *temp=*head_res;
         *head_res=(*head_res)->next;
         (*head_res)->prev=NULL;
         free(temp);
    }

    return SUCCESS;
}