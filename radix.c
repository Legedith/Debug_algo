// Implement a generic single linked list.
// Using the implemented generic single linked list, implement Radix sorting technique to sort positive integer numbers.

// Input/Output Specification:
// Input is a sequent of positive numbers:
// n i1 i2 i3 i4 ... in

// n: number of elements to sort (n > 0)
// ik: kth element of the list (ik >= 0 for all k)

// -If input is invalid display INVALID INPUT
// -otherwise display the sorted array

// Sample Input/Output:
// Input: 6 20 100 30 40 90 200
// Output: 20 30 40 90 100 200

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    void* data;
    struct node *next;
};

struct sll{
    struct node *head;
};

struct sll *create_sll()
{
    struct sll *sll = (struct sll *)malloc(sizeof(struct sll));
    sll->head = NULL;
    return sll;
}
// Insert at the end of the list
void insert_sll(struct sll *sll, void *data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if(sll->head == NULL)
    {
        sll->head = new_node;
        // printf("%d ", *(int *)sll->head->data);
    }
    else
    {
        // printf("%d ", *(int *)sll->head->data);
        struct node* temp = sll->head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        // printf("%d ", *(int *)temp->next->data);
        // printf("%d ", *(int *)sll->head->data);
    }
    // print vlaue at *data 
    // printf("%d ", *(int *)data);
}

// Delete from front and return the data
void* delete_sll(struct sll *sll)
{
    if(sll->head == NULL)
    {
        return NULL;
    }
    else
    {
        struct node *temp = sll->head;
        sll->head = sll->head->next;
        // printf("%d ", *(int *)temp->data);
        return temp->data;
    }
}
/*
Linked list stores pointers to nodes. And can hence store any data type.
It will NOT work with for loops adding values to the list for testing if the pointer being passed remains the same.
*/

int main()
{
    struct sll *sll = create_sll();
    
}