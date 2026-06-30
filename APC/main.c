/*
Documentation:
Name: Shreya Shanbhag
Date: 21-04-2026
Description: Arbitrary Precision Calculator (APC) is a program designed to perform mathematical operations on numbers of any size,
beyond the limits of the standard data types such as int, float, double or long.It works by storing the numbers as lists(data structure)
and manually implementing operations such as addition, subtraction, multiplication and division. digit by didgt by traversing through 
linked list. It handles the operation on very lage numbers without overflow.

Sample input: 11111111111111111111 + 22222222222222222222
Sample output: Result is: 33333333333333333333
*/
#include "header.h"

int main(int argc, char *argv[])
{
    //Validate argc 
    if(argc!=4)
    {
        printf("INFO : Provide 4 arguments\n");
        printf("Usage: ./a.out <operand1> <operator> <operand2>\n");
        printf("INFO : To perform multiplication do not use *. Use  * (star within quotes)\n"); //use "*"
        return 0;
    }
    //validate the argv[2] -operator
    if(strcmp(argv[2],"+")!=0 && strcmp(argv[2],"-")!=0 && strcmp(argv[2],"*")!=0 && strcmp(argv[2],"/")!=0)
    {
        printf("INFO : Provide the appropriate operator(+ - *(within quotes) \n");
        return 0;
    }
    Dlist *head1 = NULL, *head2 = NULL, *tail1 = NULL, *tail2 = NULL;

    //Create the lists - chek the sign of the operators
    int sign_op1=1;
    if(argv[1][0]=='-')
    {
        sign_op1=-1;
    }
    if(create_list(argv[1],&head1,&tail1)==FAILURE)
    {
        printf("INFO: Failed to create a list\n");
        return 0;
    }
    int sign_op2=1;
    if(argv[3][0]=='-')
    {
        sign_op2=-1;
    }
    if(create_list(argv[3],&head2,&tail2)==FAILURE)
    {
        printf("INFO : Failed to create list\n");
        return 0;
    }

    //print the list
    printf("Operand1=");
    if(sign_op1==-1)
    {
        printf("-");
    }
    print_list(head1);
    printf("Operator= %s\n",argv[2]);
    printf("Operand2=");
    if(sign_op2==-1)
    {
        printf("-");
    }
    print_list(head2);
    
    //initialize a result list to store the results after preforming the operations
    Dlist *head_res=NULL, *tail_res=NULL;
    
    /*
    If operator is + -->Addition
    case1: If both number have same sign, then add two numbers and sign will be same
    case2: If both numbers have different sign, then subtract them and the sign of the result will the sign of the greater number
    */
    if(strcmp(argv[2],"+")==0)
    {
        if(sign_op1 == sign_op2)
        {
            if(add(&head1, &tail1, &head2, &tail2, &head_res, &tail_res)==FAILURE)
            {
                printf("INFO : Addition failed!\n");
                return 0;
            }

            printf("Result is = ");
            if(sign_op1 == -1)
            {
                printf("-");
            }
            print_list(head_res);
        }
        else
        {
            int flag;
            int *ptr = &flag;

            int cmp = compare(head1, head2);

            if(cmp > 0)
            {
                if(sub(&head1, &tail1, &head2, &tail2, &head_res, &tail_res, ptr)==FAILURE)
                {
                    printf("INFO : Subtraction failed!\n");
                    return 0;
                }

                printf("Result is = ");
                if(sign_op1 == -1)
                {
                    printf("-");
                }
            }
            else if(cmp < 0)
            {
                if(sub(&head2, &tail2, &head1, &tail1, &head_res, &tail_res, ptr)==FAILURE)
                {
                    printf("INFO : Subtraction failed!\n");
                    return 0;
                }

                printf("Result is = ");
                if(sign_op2 == -1)
                {
                    printf("-");
                }
            }
            else
            {
                printf("Result is = 0");
                return 0;
            }

            print_list(head_res);
        }
    }
    /*
    If operator is - -->Subtraction
    case 1: If both the numbers have different sign, then add both and sign of the result will be the sign of the greater number
    case 2: If both have different sign, then subtract then and the sign of the result will be the sign of the greater number
    */
    else if(strcmp(argv[2],"-")==0)
    {
        int flag;
        int *ptr = &flag;

        printf("Result is = ");

        
        if(sign_op1 != sign_op2)
        {
            if(add(&head1, &tail1, &head2, &tail2, &head_res, &tail_res)==FAILURE)
            {
                printf("INFO : Subtraction failed!\n");
                return 0;
            }

            if(sign_op1 == -1)
            {
                printf("-");
            }

            print_list(head_res);
        }
        else
        {
            
            if(sign_op1 == 1)
            {
                if(sub(&head1, &tail1, &head2, &tail2, &head_res, &tail_res, ptr)==FAILURE)
                {
                    printf("INFO : Subtraction failed!\n");
                 return 0;
                }

                if(*ptr == 1)
                {
                     printf("-");
                }
            }
            else
            {
                if(sub(&head2, &tail2, &head1, &tail1, &head_res, &tail_res, ptr)==FAILURE)
                {
                    printf("INFO : Subtraction failed!\n");
                    return 0;
                }

                if(*ptr == 1)
                {
                    printf("-");
                }
            }

            print_list(head_res);
        }
    }
    /*
    If operator is * -->Multiplication
    case 1: if one of the numbers is 0, then the result is 0
    case 2: if one of the numbers is 1, then the result is another number
    case 3: if both have same sign, then sign of the result will be same 
    case 4: if one of the numbers is -ve then the sign of the result will be -ve
    */
    else if(strcmp(argv[2],"*")==0)
    {
        if(strcmp(argv[3],"0")==0)
        {
            printf("Result is = 0\n");
            return 0;
        }

        if(strcmp(argv[3],"1")==0)
        {
            printf("Result is = ");
            if(sign_op1 * sign_op2 == -1)
            {
                printf("-");
            }
            print_list(head1);
            return 0;
        }

        if(mul(&head1, &tail1, &head2, &tail2, &head_res, &tail_res)==FAILURE)
        {
            printf("INFO : Multiplication failed!\n");
            return 0; 
        }

        printf("Result is = ");
        if(sign_op1 * sign_op2 == -1)
        {
            printf("-");
        }
        print_list(head_res);
    }
    /*
    If operator is / -->Division
    case 1: if denominator is 0, then error cannot perform division
    case 2: if denominator is 1, then the result will numerator value
    case 3: if both have same sign, then sign of the result will be same 
    case 4: if one of the numbers is -ve then the sign of the result will be -ve
    case 5: if numerator is 0, then the result is 0
    */
    else if(strcmp(argv[2],"/")==0)
    {
        if(strcmp(argv[3],"0")==0)
        {
            printf("INFO : Invalid input. Cannot divide by 0\n");
            return 0;
        }

        if(strcmp(argv[3],"1")==0)
        {
            printf("Result is = ");
            if(sign_op1 * sign_op2 == -1)
            {
                printf("-");
            }
            print_list(head1);
            return 0;
        }

        Dlist *count_head=NULL,*count_tail=NULL;

        int res=divi(&head1, &tail1, &head2, &tail2, &head_res, &tail_res, &count_head, &count_tail);
        if(res==FAILURE)
        {
            printf("INFO : Division failed!\n");
            return 0;
        }

        printf("Result is = ");
        if(sign_op1 * sign_op2 == -1)
        {
            printf("-");
        }
        print_list(count_head);
    }


   return 0;
}