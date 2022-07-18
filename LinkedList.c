//Hard-coded linked list implementation
#include <stdio.h>
#include <stdlib.h>

// Structure of each node in linked list
typedef struct node
{
    int number;
    struct node* next;
}
node;

int main(void)
{
    // Head of list
    node* list = NULL;
    
    // Dynamically allocate a new node, check for null, and set it's value and next pointer
    node* n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 1;
    n->next = NULL;
    // Set the head to point at the first node in list
    list = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    list->next = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list->next);
        free(list);
        return 1;
    }
    n->number = 3;
    n->next = NULL;
    list->next->next = n;
    
    // Print out list
    for (node* tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }
    
    // Delete linked list without memory leak
    while (list != NULL)
    {
        node* tmp = list->next;
        free(list);
        list = tmp;
    }

}
