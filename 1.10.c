#include <stdio.h>
#include <stdlib.h>

typedef struct list_element
{
    char f[10];
    
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

void push (list_element* netx, list_element* a)
{

    while ( netx->next != NULL)
    {
        netx = netx->next;
    }
    netx->next = a;
    a->prev = netx;
    a->next = NULL;
}
main ()
{
    while(1)
    {
        scanf("%s", str);
        if (s[1] == 'I')
        {
            
        }
        else
        {
           if (s[1] == 'F')
           {
               
           }
           else
           {
               printf("unknown command")
           }
        }
        
    }
    
}
