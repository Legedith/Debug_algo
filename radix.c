// Create singly linked list using structures
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

// Function to take a list and add element to it
void add(struct node **head, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Function to remove from the list
void remove(struct node **head, int data)
{
    struct node *temp = *head, *prev;
    if (temp != NULL && temp->data == data)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}
// Function to print the list
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
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
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    // Declare the elements and take input into array
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
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
    // Radix sort
    for (int i = 0; i < digits; i++)
    {
        // Add elements to the linked list according to the digit
        for (int j = 0; j < n; j++)
        {
            num = arr[j] % 10;
            add(&head[num], arr[j]);
            arr[j] /= 10;
        }
        // Remove elements from the linked list and add to the array
        int k = 0;
        for (int j = 0; j < 10; j++)
        {
            while (!isEmpty(head[j]))
            {
                arr[k] = head[j]->data;
                remove(&head[j], head[j]->data);
                k++;
            }
        }
    }
    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}