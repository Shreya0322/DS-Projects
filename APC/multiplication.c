#include "header.h"

int mul(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head_res, Dlist **tail_res)
{
    // function counts the numbers of nodes in both lists
    int count1=count_node(*head1);
    int count2=count_node(*head2);
    Dlist *temp1=NULL, *temp2=NULL;

    //initializing temp1 and temp2 based on the count
    if(count1 > count2)
    {
        temp1=*tail1;
        temp2=*tail2;
    }
    else if(count1 < count2)
    {
        temp1=*tail2;
        temp2=*tail1;
    }
    else 
    {
        temp1=*tail1;
        temp2=*tail2;
    }
    
    //initialize two list to store the intermediate results
    Dlist *res1_head=NULL, *res1_tail=NULL, *res2_head, *res2_tail;
    int count=0;  //initialize count to 0, to append number of zeros 
    while(temp1!=NULL)  //loop to traverse through the list which has more number of nodes
    {
        Dlist *temp=temp2;
        res2_head=NULL;
        res2_tail=NULL;
        Dlist *temp_head=NULL, *temp_tail=NULL;
       
        int carry=0; //initialize carry to 0
        while(temp!=NULL)  //loop to traverse through the list with least number of nodes
        {
            
            
            int res=(temp->data)*(temp1->data)+ carry; //multiply digits and add carry to the result
            int digit=res%10; // get the unit digit 
            carry=res/10;   // calculate carry

            if(insert_at_first(&res2_head, &res2_tail,digit)==FAILURE)  //insert the result digit in the temp result list
            {
                    printf("INFO :Failed to insert\n");
                    return FAILURE;
            }
            
            temp=temp->prev; //move to previous node
        }
        if(carry>0)  //if carry is generated then add carry to the list
        {
            insert_at_first(&res2_head, &res2_tail, carry);
        }

        for(int i=0;i<count;i++)  // based on the count insert 0's to end of res2 list
        {
            if(insert_at_last(&res2_head, &res2_tail,'0')==FAILURE)
            {
                printf("INFO :Failed to insert\n");
                return FAILURE;
            }
        }
        //add the res1 list and res2 list and stire the result in temp result list
        if(res1_head==NULL)
        {
            copy_list(res2_head, &res1_head, &res1_tail);
        }
        else
        {
            if(add(&res1_head, &res1_tail, &res2_head, &res2_tail, &temp_head, &temp_tail)==FAILURE)
            {
                printf("INFO : Multiplication failed\n");
                return FAILURE;
            }

            //copy_list the result of addition into res1 list for next step addition
            res1_head = temp_head;
            res1_tail = temp_tail;
        }
        count++; //incerment move to previous node
        temp1=temp1->prev;
        
    }
    copy_list(res1_head, head_res, tail_res); //copy thr final result into result list
    return SUCCESS;

}