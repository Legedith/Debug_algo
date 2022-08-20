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
    int data;
    struct node *next;
};

// Function to take a list and add element to it
void add(struct node **head, int data, int index)
{
    // Insert at index, if index is -1 insert at end
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (index == -1)
    {
        if (*head == NULL)
        {
            *head = new_node;
            return;
        }
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        return;
    }
    if (index == 0)
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    struct node *temp = *head;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;

}

// Function to Remove from the list the element at the given index and return it
int Remove(struct node **head, int index)
{
    struct node *temp = *head;
    struct node *prev = NULL;
    int i = 0;
    while (i < index)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }
    if (prev == NULL)
    {
        *head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    int data = temp->data;
    free(temp);
    return data;
}
// Function to print the list
void printList(struct node *node)
{
    while (node != NULL)
    {
        // printf(" %d ", node->data);
        node = node->next;
    }
}
// Function to check if list is empty
int isEmpty(struct node *head)
{
    return head == NULL;
}

int main()
{

    // Creating radix sort using linked lists for each digit
    struct node *head[10];
    for (int i = 0; i < 10; i++)
        head[i] = NULL;
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
            add(&head[digit], arr[j], -1);
            // -- debug -- print arr[j] and digit, i 
            // printf("arr[%d]: %d, digit: %d, i: %d \n", j, arr[j], digit, i);
        }
        // Remove the elements from the list and add them to the array
        int index = 0;
        for (int j = 0; j < 10; j++)
        {
            while (!isEmpty(head[j]))
            {
                arr[index] = Remove(&head[j], 0);
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