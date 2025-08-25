#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;


void  QueueTraversal(struct Node *ptr)
{

    printf("Printing the elements of this linked list :");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void enqueue(int val)
{
    struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
    if(temp==NULL)
    {
        printf("Queue is Full");
    }
    else
    {
        //4 5 6
        temp->data = val;
        temp->next = NULL;
        if(front==NULL)
        {
            front=rear=temp;
        }
        else
        {
            rear->next = temp;
            rear=temp;
        }
    }
}

int dequeue()
{
    int val = -1;
    struct Node *ptr = front;
    if(front==NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        front = front->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

void peek()
{
    if(front==NULL)
    {
        printf("NO element in Queue\n");
    }
    else
    {
        printf("peek element %d\n",front->data);
    }
}
//int main()
//{
//    linkedListTraversal(f);
//    printf("Dequeuing element %d\n", dequeue());
//    enqueue(34);
//    enqueue(4);
//    enqueue(7);
//    enqueue(17);
//    printf("Dequeuing element %d\n", dequeue());
//    printf("Dequeuing element %d\n", dequeue());
//    printf("Dequeuing element %d\n", dequeue());
//    printf("Dequeuing element %d\n", dequeue());
//    linkedListTraversal(f);
//    return 0;
//}


int main()
{

    while (1)
    {
         printf("\n1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. peek element\n");
    printf("5. Quit\n");

        int i;
        printf("Enter your choice: ");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("Enter the element to Queue: ");
            int value;
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            printf("Dequeuing element %d\n", dequeue());
            break;
        case 3:
            QueueTraversal(front);
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}







