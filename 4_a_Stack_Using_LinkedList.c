#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};


struct node *top = NULL;



void push(int x)
{


  // 5 4 3
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}
void pop()
{
    struct node *temp;
    if (top == NULL)
        printf("Stack is empty\n");
    else
    {
        temp = top;
        printf("Pop item:%d\n",temp->data);
        top = top->next;
       // temp->next = NULL;
        free(temp);
    }
}
void Top()
{
    if(top==NULL)
    {
        printf("No element found\n");
    }
    else
    {
        printf("%d\n",top->data);
    }
}
//3 4 5 6 7
void display()
{
    struct node *temp;
    if (top == NULL)
        printf("Stack is empty\n");
    else
    {
        printf("Stack contents: ");
        temp = top;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. top element\n");
    printf("5. Quit\n");

    while (1)
    {
        int i;
        printf("Enter your choice: ");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("Enter the element to be pushed: ");
            int value;
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            Top();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}

































