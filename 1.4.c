#include <stdio.h>
#include <stdlib.h>

typedef struct skobka skobka;

struct skobka
{
    char item;
    skobka *next;
};

skobka *head = NULL;

void push(char item)
{
    skobka *new_item = (skobka *)malloc(sizeof(skobka));
    new_item->item = item;
    new_item->next = head;
    head = new_item;
}

void pop()
{
    if (head)
    {
        skobka *old = head;
        head = head->next;
        free(old);
    }
}

void lose()
{
    while (head)
    {
        pop();
    }
    puts("NO");
    exit(0);
}

char front()
{
    if (head)
        return head->item;
    return 0;
}

int main()
{
    char c;
    while (scanf("%c", &c) && (c == '(' || c == '{' || c == '[' || c == '<' || c == ')' || c == '}' || c == ']' || c == '>'))
    {
        if (c == '(' || c == '{' || c == '[' || c == '<')
            push(c);
        else if (c - front() == 2 || c - front() == 1)
            pop();
        else
            lose();
    }
    if (head)
        lose();
    else
        puts("YES");
    return 0;
}
