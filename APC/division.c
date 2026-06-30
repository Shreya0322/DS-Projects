#include "header.h"

int divi(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head_res, Dlist **tail_res,Dlist **count_head,Dlist **count_tail)
{
    // function counts the numbers of nodes in both lists
    int count1=count_node(*head1);
    int count2=count_node(*head2);
    
    //if first number is less than second number, result is 
    if(count1<count2)
    {
        if(insert_at_first(count_head,count_tail,0)==FAILURE)
        {
            printf("INFO :Failed to insert\n");
            return FAILURE;
        }
        return SUCCESS;
    }
    // temp1-> dividend
    //temp2 -> divisor
    if(count1==count2)
    {
        Dlist *temp_1=*head1,*temp_2=*head2;
        while(temp_1!=NULL && temp_2!=NULL)
        {
            if((temp_1->data) == (temp_2->data))
            {
                temp_1=temp_1->next;
                temp_2=temp_2->next;
            }
            else if((temp_1->data)<(temp_2->data))  // if the dividend is smaller than divisor , the result is 0
            {
               if(insert_at_first(count_head,count_tail,0)==FAILURE)
               {
                    printf("INFO :Failed to insert\n");
                    return FAILURE;
               }
               return SUCCESS;
            }
            else
            {
                break;
            }
        }
        if(temp_1==NULL && temp_2==NULL)  //if dividend and divisor are equal the result is 1
        {
            if(insert_at_first(count_head,count_tail,1)==FAILURE)
            {
                printf("INFO :Failed to insert\n");
                return FAILURE;
            }
            return SUCCESS;
        }
    }
    //Division - repetitive subtraction
    int count=0,neg=0;
    if(copy_list(*head1, head_res, tail_res) == FAILURE) // copy the dividend list in the result list initially
    {
        printf("INFO : Failed to copy list\n");
         return FAILURE;
    }
    //print_list(*head_res);
    while(compare(*head_res,*head2))  // compare result list and divisor if it is >=divisor continue
    {
        neg=0;
        Dlist *temp_head = NULL;
        Dlist *temp_tail = NULL;
        //subtarct dividend and sivisor and store in a temp result
        if(sub(head_res, tail_res, head2, tail2, &temp_head, &temp_tail, &neg)==FAILURE)  
    
         {
            printf("INFO : Division Failed\n");
            return FAILURE;

         }

         delete_list(head_res, tail_res); // copy the result of subtraction in result
         *head_res = temp_head;
         *tail_res = temp_tail;
         //after each subtraction increment count , which is the quotient value
         count++;

    }
    while(count)
    {
        int res=count%10;
        if(insert_at_first(count_head,count_tail,res)==FAILURE)
        {
            printf("INFO :Failed to insert\n");
            return FAILURE;
        }
        count=count/10;

    }
    return SUCCESS;

}