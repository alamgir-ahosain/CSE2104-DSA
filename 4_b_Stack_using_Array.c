#include<stdio.h>
#include<stdlib.h>
#define N 100

struct Stack{
	int *arr;
	int top;
};
void push(struct Stack *st ,int val){
	if(st->top==N-1){
		printf("Stack Overflow\n");
		return;
	}
	st->top++;
	st->arr[st->top]=val;
}
void pop(struct Stack *st){
	if(st->top==-1){
		printf("No element to pop\n");
		return;
	}
	st->top--;
}
int top(struct Stack *st){
	if(st->top==-1){
		printf("No element in stack\n");
		return -1;
	}
	return st->arr[st->top];
}
int empty(struct Stack *st){
	return st->top==-1;
}
void display(struct Stack *st){
    if(st->top==-1){
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack Elements: ");
    for(int i=st->top;i>=0;i--){
        printf("%d ",st->arr[i]);
    }
    printf("\n");
}
int main(){
	struct Stack st;
	st.arr=(int *)malloc(N*sizeof(int));
	st.top=-1;

	printf("Enter Total element No:");
	int n;
	scanf("%d",&n);
	int a[n];
	printf("Enter element: ");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		push(&st,a[i]);
	}

    display(&st);
	printf("Top = %d\n",top(&st));
	pop(&st);
	printf("After Pop, Top = %d\n",top(&st));
	printf("%d\n",empty(&st));
	free(st.arr);
	return 0;
}
