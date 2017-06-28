#include "clist.h"
#include <assert.h>

struct node_t
{
    int info;
    struct node_t *next;
};

struct node_t *create(int info)
{
    struct node_t *tmp = malloc(sizeof(*tmp));
    if (tmp)
    {
        tmp->info = info;
        tmp->next = NULL;
    }

    return tmp;
}

int add(struct node_t **s, int info)
{
    struct node_t *new = create(info);
    if (!new)
        return 0;       // ADD error

    if ((*s) == NULL)
    {
        new->next = new;
        *s = new;
    }
    else
    {
        new->next = (*s)->next;
        (*s)->next = new;
    }

    return 1;           // ADD without error
}

void display(const struct node_t *s)
{
    int save = s->info, tmp = s->next->info;
    printf(" %d", save);
    while (tmp != s)
    {
        printf(" %d", tmp);
        s = s->next;
        tmp = s->info;
    }
    printf("\n");
}

struct node_t *remov(struct node_t *s)
{
    struct node_t *cur = s;

};
