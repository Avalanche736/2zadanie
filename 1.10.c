#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

typedef struct list_element
{
    char name[10];
    char number[12];

    struct list_element* next;
    struct list_element* prev;
} list_element;



list_element* list_new ()
{

    list_element* ad = malloc(sizeof(list_element));
    strncpy(ad->name, "", 10);
    strncpy(ad->number, "", 12);
    ad->next = NULL;
    ad->prev = NULL;
    return ad;
}



void list_delete (list_element* ad)
{
    list_element* netx;
    list_element* add;
    netx = ad;
    while ( netx != NULL)
    {
        add = netx->next;
        free(netx);
        netx = add;
    }
}


void push (list_element* list, list_element* a)
{

    while ( list->next != NULL)
    {
        list = list->next;
    }
    list->next = a;
    a->prev = list;
    a->next = NULL;
}


list_element* find (list_element* list, char name[10])
{
    list_element* finded = list_new();
    finded->number[0] = 'N';
    finded->number[1] = 'O';
    while ( list->next != NULL)
    {
        list = list->next;
        if (strcmp (list->name, name) == 0)
        {
            free(finded);
            finded = list;
        }
    }
    return finded;
}


void write_to_list_from_file (list_element* list, FILE* file) //первый элемент списка служебный
{

    char name[10];
    list_element* e1 = list_new();
    push(list, e1);
    fscanf(file, "%s", name);

    while(name[0] != '#')
    {
        fscanf(file, "%s", e1->number);
        strcpy(e1->name, name);
        fscanf(file, "%s", name);
        push(list, e1);
        e1 = list_new();
    }
}



void write_to_file_from_list (list_element* list, FILE* file)
{
    if (list != NULL)
    {
        while ( list->next != NULL)
        {
            list = list->next;
            fprintf(file, "%s %s\n", list->name, list->number);
        }
    }

    fprintf(file,"#");
}




int main ()
{

    FILE* mynotebook;
    mynotebook = fopen("notebook.txt", "r");
    if(mynotebook == NULL)
    {
        printf("ошибка открытия notebook.txt");
        return 0;
    }
    int i = 0;
    char command[6], name[10], number[12];
    list_element* notebook = list_new();
    list_element* finded = list_new();
    list_element* list = notebook;
    write_to_list_from_file(list, mynotebook);
    fclose(mynotebook);


    while(1)
    {

        scanf("%s", command);
        if (strcmp(command, "shutdown") == 0)
        {
            printf("%s", notebook->name);
            mynotebook = fopen("notebook.txt", "w");
            write_to_file_from_list(notebook, mynotebook);
            fclose(mynotebook);

            return 0;
        }


        if  (strcmp (command, "INSERT") == 0 || strcmp (command, "Insert") == 0 || strcmp (command, "insert") == 0)
        {
            scanf ("%s %s", name, number);
            while ( list->next != NULL)
            {
                list = list->next;
                if (strcmp (list->name, name) == 0)
                {
                    printf("Changed. Old value = %s\n", list->number);
                    strcpy(list->number, number);
                    i++;
                }
            }
            if (i == 0)
            {
                list_element* kontakt = list_new();
                strcpy(kontakt->name, name);
                strcpy(kontakt->number, number);
                push (list, kontakt);
                printf("OK\n");
            }
        }


        else
        {
            if (strcmp (command, "FIND") == 0 || strcmp (command, "Find") == 0 || strcmp (command, "find") == 0)
            {
                scanf ("%s", name);
                finded = find(notebook, name);
                printf("%s\n", finded->number);
            }


            else
            {
                printf("unknown command\n");
            }
        }

    }
}
