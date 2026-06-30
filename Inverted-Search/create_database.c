#include "inverted_Search.h"
char *fname;

/*
create database function reads the contents from each file by traversing through 
each file from linked list.
*/
int create_database(Flist *f_head, Wlist *head[])
{
    //Read files one by one
    while(f_head)
    {
        //read data from each file one by one
        read_datafile(f_head,head,f_head->file_name);
        add_file(f_head->file_name); 
        
        //move f_head pointer to next node to read data from the next file till f_head reaches NULL
        f_head=f_head->link;
        
    }
    return SUCCESS;
}

/*
This function reads data from each file and created a word list.
word list consists of all the words in a file stored in the form of linked list in alphabetical order.
It also has the file name in which the word exists and word count(no of times the word repeated in a file)

*/
Wlist * read_datafile(Flist *file, Wlist *head[], char *filename)
{
    //open the file in read mode
    FILE *fptr=fopen(filename,"r");
    fname=filename;
    int flag;
    if(fptr==NULL)
    {
        printf("Failed to open the file\n");
        return NULL;
    }

    char word[WORD_SIZE];
    //read each word till fptr reach EOF
    while(fscanf(fptr,"%s", word) != EOF)
    {
        convert_to_lowercase(word);  //convert all to lowercase

        if (strlen(word) == 0)   
        {
            continue;
        }
        flag=1;
        //To place the word alphabetically in hash table find the index using first letter of each word
        int index=tolower(word[0])- 'a';
        if(index<0||index>25)
        {
            index=26; //last index for special characters 
        }
        //traverse through the word list to find if the word exists or not . if exists check if it is repeated.
        if(head[index]!=NULL)
        {
            Wlist *temp=head[index];
            while(temp!=NULL)
            {
                if((strcmp(temp->word, word))==0)  //if word already present in wlist update word count at the file
                {
                    update_word_count(&temp, filename);
                    flag=0;
                    break;
                }
                temp=temp->link;
            }
        }
        if(flag == 1)
        {
            insert_at_last(&head[index], word);
        }


    }
    fclose(fptr);
    return NULL;

}

int update_word_count(Wlist **head, char *filename)
{
    //check filename are same or not
    //if filename is same -- increment the word count
    //if filename are different -- increment file_count
    //create a new Ltable node
    Wlist *wnode=*head;
    Ltable  *temp=wnode->Tlink;
    if (*head == NULL)
    {
        return FAILURE;
    }

    //if a word appears for first time
    if(temp==NULL)
    {
        Ltable *newnode=malloc(sizeof(Ltable));
        if(newnode==NULL)
        {
            return FAILURE;
        }
        //update data into newnode
        newnode->word_count=1;
        strcpy(newnode->file_name,filename);
        newnode->table_link=NULL;

        //make it as head node
        wnode->Tlink=newnode;
        wnode->file_count=1;

        return SUCCESS;

    }

    //if word already exists in the database
    Ltable *prev=NULL;
    while(temp!=NULL)
    {
        if(strcmp(temp->file_name, filename)==0) 
        {
            temp->word_count++; //increment word count  in the same file
            return SUCCESS;

        }
        prev=temp;
        temp = temp->table_link;;
    }
    // New file  then add new node
    Ltable *newnode = malloc(sizeof(Ltable));
    if (newnode == NULL)
    {
        return FAILURE;
    }

    strcpy(newnode->file_name, filename);
    newnode->word_count = 1;
    newnode->table_link = NULL;

    prev->table_link = newnode;

    (wnode->file_count)++;   

    return SUCCESS;


}

//function to convert all the lettwers to lowecase to maintain similarity
void convert_to_lowercase(char *word)
{
    int i = 0, j = 0;
    char temp[WORD_SIZE];

    while (word[i] != '\0')
    {
        if (isalnum(word[i])) //check if it is alphabet 
        {
            temp[j] = tolower(word[i]);
            j++;
        }
        i++;
    }

    temp[j] = '\0';

    strcpy(word, temp);
}
