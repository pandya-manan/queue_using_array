#include<stdio.h>
#include<stdlib.h>

void enqueue(int arr[], int value, int *rear, int size)
{
    if(*rear == (size - 1))
    {
        printf("The queue is full, hence no more elements can be added\n");
        return;
    }
    (*rear)++;
    arr[*rear] = value;
}

void dequeue(int arr[], int *front, int *rear)
{
    if(*front == *rear)
    {
        printf("The queue is empty, hence there is nothing left to delete\n");
        return;
    }
    (*front)++;
    arr[*front] = -1;  // Use -1 to indicate empty slot
}

void printElements(int arr[], int front, int rear)
{
    if(front == rear)
    {
        printf("The queue is empty, hence there is nothing to print\n");
        return;
    }
    printf("Current elements: ");
    for(int i = front + 1; i <= rear; i++)  // Print starts from front + 1
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void peek(int arr[], int front, int rear)
{
    if(front == rear)
    {
        printf("The queue is empty, hence there is nothing to peek\n");
        return;
    }
    printf("Next element to be removed: %d\n", arr[front + 1]);
}

int main()
{
    int size;
    printf("Enter the number of elements to be stored in the queue\n");
    scanf("%d", &size);
    int arr[size];
    int front = -1, rear = -1;  // Initialize front and rear as -1
    int choice, value;

    while(1)
    {
        printf("Menu for operating on queue\n");
        printf("1. Insert element into the queue\n");
        printf("2. Delete element from the queue\n");
        printf("3. List the elements of the queue\n");
        printf("4. Peek\n");
        printf("5. Exit the program\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
                printf("Enter a value which needs to be inserted into the queue\n");
                scanf("%d", &value);
                enqueue(arr, value, &rear, size);  // Pass rear by reference
                break;
            case 2: 
                dequeue(arr, &front, &rear);  // Pass front and rear by reference
                break;
            case 3: 
                printElements(arr, front, rear);
                break;
            case 4: 
                peek(arr, front, rear);
                break;
            case 5: 
                exit(0);
            default:
                printf("Please enter the correct choice from the given options\n");
        }
    }
}
