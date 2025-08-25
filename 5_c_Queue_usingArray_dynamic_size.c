#include <stdio.h>
#include <stdlib.h>
#define N 100

struct Queue{
    int *arr;
    int front;
    int back;
};

void push(struct Queue *q, int val) {
    if(q->back == N-1){
        printf("Queue overflow\n");
        return;
    }
    q->back++;
    q->arr[q->back]=val;
    if (q->front==-1) {
        q->front=0;
    }
}

void pop(struct Queue *q) {
    if (q->front==-1 || q->front > q->back) {
        printf("No element for Pop\n");
        return;
    }
    q->front++;
}

int peek(struct Queue *q) {
    if (q->front==-1 || q->front > q->back) {
        printf("No element in queue\n");
        return -1;
    }
    return q->arr[q->front];
}

int empty(struct Queue *q) {
    if (q->front==-1 || q->front > q->back) {
        return 1;
    }
    return 0;
    //Shortcut
    //return q->front==-1 || q->front > q->back;
}
void display(struct Queue *q) {
    if (empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->back; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}
int main() {
    struct Queue q;
    q.arr =(int*)malloc(N*sizeof(int));
    q.front = -1;
    q.back = -1;

    printf("Enter Total element No: ");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter Element: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        push(&q, a[i]);
    }
    display(&q);
    printf("Top = %d\n", peek(&q));
    pop(&q);
    printf("After pop, Top = %d\n", peek(&q));
    printf("%d\n", empty(&q));

    free(q.arr);
    return 0;
}
