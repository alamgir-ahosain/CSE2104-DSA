#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};


int isEmpty(struct queue *q)
{
    if(q->r==q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if(q->r==q->size-1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if(isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if(isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void dis(struct queue *q)
{
    if(isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        printf("queue element :");
        printf("%d ",q->arr[q->f+1]);//first element
        for(int i=q->f+2; i<=q->r; i++) printf("%d ",q->arr[i]);
        printf("\n");
    }
}
int main()
{
//    struct queue q;
//    q.size = 4;
//    q.f = q.r = 0;
//    q.arr = (int*) malloc(q.size*sizeof(int));
//
//    // Enqueue few elements
//    enqueue(&q, 12);
//    enqueue(&q, 15);
//    enqueue(&q, 1);
//    printf("Dequeuing element %d\n", dequeue(&q));
//    printf("Dequeuing element %d\n", dequeue(&q));
//    printf("Dequeuing element %d\n", dequeue(&q));
//    enqueue(&q, 45);
//    enqueue(&q, 45);
//    enqueue(&q, 45);
//
//    if(isEmpty(&q)){
//        printf("Queue is empty\n");
//    }
//    if(isFull(&q)){
//        printf("Queue is full\n");
//    }

    struct queue q;
    int siz;
    printf("Enter size :");
    scanf("%d",&siz);
    q.size=siz;
    q.f=q.r=0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    int ch;
    while(1)
    {
        printf("enter choice :");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("enqueu element :");
            int val;
            scanf("%d",&val);
            enqueue(&q, val);
            break;
        case 2:
            printf("Dequeuing element %d\n", dequeue(&q));
            break;
        case 3:
            dis(&q);
            break;



        }
    }



    return 0;
}

