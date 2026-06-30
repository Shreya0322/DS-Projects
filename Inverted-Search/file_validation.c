#include "inverted_Search.h"

//This function validates the files for empty, repeated file and then adds to the list
void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i=1, empty;

    while(argv[i]!=NULL)
    {
        empty=isFileEmpty(argv[i]);
        if(empty==FILE_NOTAVAILABLE)
        {
            printf("INFO: File %s is not available so cannot be added to list\n",argv[i]);
            i++;
            continue;
        }
        else if(empty==FILE_EMPTY)
        {
            printf("INFO: File %s does not have any content\n",argv[i]);
            i++;
            continue;
        }
        else  //add file to the linked list
        {
            int ret=to_create_list_of_files(f_head,argv[i]);
            if(ret==SUCCESS)
            {
                printf("File %s is added to the list\n",argv[i]);
            }
            else if(ret==REPEATATION)
            {
                printf("INFO: File %s has been repeated\n",argv[i]);
                
            }
            else
            {
                printf("INFO:Error please check the files and content\n");
            }

        }
        i++;
    }
    
}
int isFileEmpty(char *filename)
{
    FILE *fptr=fopen(filename,"r");
    if(fptr==NULL)
    {
        if(errno == ENOENT)
        {
            return FILE_NOTAVAILABLE;
        }
        return FILE_NOTAVAILABLE;
    }
    fseek(fptr,0,SEEK_END);
    if(ftell(fptr)==0)
    {
        return FILE_EMPTY;
    }
    return SUCCESS;
}

//This function adds the file into the list if the file fi=ound is unique and non empty
int to_create_list_of_files(Flist **f_head, char *name)
{
    
    Flist *temp = *f_head;

    while (temp != NULL)
    {
        //Check for duplicate file
        if (strcmp(temp->file_name, name) == 0)
        {
            return REPEATATION;  
        }
        temp = temp->link;
    }

    // Create new node
    Flist *newnode = (Flist *)malloc(sizeof(Flist));
    if (newnode == NULL)
    {
        return FAILURE;
    }

    strcpy(newnode->file_name, name);
    newnode->link = NULL;

    //Insert at last
    if (*f_head == NULL)
    {
        *f_head = newnode;
    }
    else
    {
        temp = *f_head;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = newnode;
    }

    return SUCCESS;
}