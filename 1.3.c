#include <stdio.h> //допилить ретёрны нуля или единицы функциями
#include <stdlib.h>

typedef struct list_element
{
    int a;
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

list_element* pop (list_element*ad)
{
    list_element* netx = ad;
    while ( netx->next != NULL)
    {
        netx = netx->next;
    }
    netx->prev->next = NULL;
    return netx;
}


void unshift (list_element* add, list_element* e)
{
    add->prev = e;
    e->next = add;
    e->prev = NULL;
}

list_element* shift (list_element* add)
{
    return add->next;
}

void reverse (list_element* add)
{
    list_element* ad = list_new;
    list_element* netx = add;
    while ( netx->next != NULL)
    {
        netx = netx->next;
    }
    ad = add;
    list_element* e = ad;

    while (netx->prev != NULL) 
    {
        e->next = netx;
        netx->prev = e;
        e = netx;
        netx = netx->prev;
    }

}



int main()
{
    printf("Hello world!\n");
    return 0;
}
