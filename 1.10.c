#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_element
{
    char name[10];
    char number [12];

    struct list_element* next;
    struct list_element* prev;
} list_element;

list_element* list_new ()
{

    list_element* ad = malloc(sizeof(list_element));
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
    finded->number[1] = 'N';
    finded->number[1] = 'O';
    while ( list->next != NULL)
    {
        list = list->next;
        if (strcmp (list->name, name) == 0)
        {
            finded = list;
        }
    }
    return finded;
}






main ()
{
    //не знаю как организовать запись из файла в список
    //FILE *mynotebook;
    //mynotebook = fopen("notebook.txt", 'w');
    char command[6], name[10], number[12];
    list_element* notebook = list_new();
    list_element* finded = list_new();


    while(strcmp (command, 'shutdown') != 0)//не знаю как придумать условие цикла, чтобы он считывал воод с клавиатуры, пока, не ввели "shutdown"
    {

        scanf("%s", command);

        if  (strcmp (command, 'INSERT') == 0 || strcmp (command, 'Insert') == 0 || strcmp (command, 'insert') == 0)
        {
            list_element* kontakt = list_new();
            scanf ("%s %s", name, number);
            strcpy(kontakt->name, name);
            strcpy(kontakt->number, number);
            push (notebook, kontakt);
        }


        else
        {
           if (strcmp (command, 'FIND') == 0 || strcmp (command, 'Find') == 0 || strcmp (command, 'find') == 0)
           {
               scanf ("%s", name);
               finded = find(notebook, name);
               printf("%s", finded->number);
           }


           else
           {
               printf("unknown command\n");
           }
        }

    }
    //не знаю как организовать вывод списка в файл

}
