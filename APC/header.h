#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}Dlist;

int create_list(char *str, Dlist **head, Dlist **tail);
int insert_at_last(Dlist **head, Dlist **tail, char ch);
int insert_at_first(Dlist **head, Dlist **tail, int data);
int delete_list(Dlist **head, Dlist **tail);
int add(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head_res, Dlist **tail_res);
int sub(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head_res, Dlist **tail_res,int *flag);
int mul(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head_res, Dlist **tail_res);
int divi(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head_res, Dlist **tail_res,Dlist **count_head,Dlist **count_tail);
int count_node(Dlist *head);
int compare(Dlist *head1, Dlist *head2);
void print_list(Dlist *head);
int copy_list(Dlist *head1, Dlist **head_res, Dlist **tail_res);

#endif