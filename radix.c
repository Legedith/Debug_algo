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
    struct sll[10] *sll;
    int i = 0;
    for(i = 0; i < 10; i++)
    {
        sll[i] = create_sll();
    }
    int n, num;
    // printf("Enter the number of elements: ");
    scanf("%d", &n);
    // if n<0, invalid input
    if (n <= 0)
    {
        printf("INVALID INPUT");
        return 0;
    }
    // Declare the elements and take input into array
    int arr[n];
    // printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        // if the inserted element is -ve, return and print INVALID INPUT
        if (arr[i] < 0)
        {
            printf("INVALID INPUT");
            return 0;
        }
    }
    // Find the maximum number in the array
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    // Find the number of digits in the maximum number
    int digits = 0;
    while (max != 0)
    {
        max /= 10;
        digits++;
    }
   // -- debug -- print the max and number of digits
    // printf(Digits: %d", max, digits);
    // Radix sort
    for (int i = 0; i < digits; i++)
    {
        // Add the elements to the list based on the digit
        for (int j = 0; j < n; j++)
        {
            int digit = (arr[j] / (int)pow(10, i)) % 10;
            // add(&head[digit], arr[j], -1);
            insert_sll(sll[digit], &arr[j]);
            // -- debug -- print arr[j] and digit, i 
            // printf("arr[%d]: %d, digit: %d, i: %d \n", j, arr[j], digit, i);
        }
        // Remove the elements from the list and add them to the array
        int index = 0;
        for (int j = 0; j < 10; j++)
        {
            while (!isEmpty(head[j]))
            {
                // arr[index] = Remove(&head[j], 0);
                arr[index] = *(int *)delete_sll(sll[j]);
                // printf("inserted arr[%d]: %d \n", index, arr[index]);
                index++;
            }
        }
        // printf("After iteration %d: ", i);
        // for (int j = 0; j < n; j++)
        // {
        //     printf("%d ", arr[j]);
        // }
        // printf("\n");
    }
    // Print the sorted array
    // printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    
}