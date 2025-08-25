#include<stdio.h>
#define CAPACITY 10
int stack[CAPACITY];
int top = -1;

void push(int x){
    if(top < CAPACITY - 1){
        top = top + 1;
        stack[top]= x;
        printf("Successfully added item: %d\n", x);
    }else{
        printf("Exception! No spaces\n");
    }
}
void print(int top)
{
    for(int i=0;i<=top;i++)printf("%d ",stack[i]);
    printf("\n");
}

int pop(){
    if(top >= 0){
        int val = stack[top];
        top = top - 1;
        return val;
    }
    printf("Exception from Pop! Empty Stack\n");
    return -1;
}

int peek(){
    if(top >= 0){
        return stack[top];
    }
    printf("Exception from Peek! Empty Stack\n");
    return -1;
}
int main()
{

        printf("1.Push\n");
        printf("2. pop\n");
        printf("3. Top\n");
        printf("4. print\n");
        printf("5. Exit\n");


    while(1)
    {


        int i;
        printf("Press the number :");
        scanf("%d",&i);
        switch(i)
        {

        case 1:
        {

            int val;
            printf("enter push val :");
            scanf("%d",&val);
            push(val);
            break;
        }



        case 2:

        {
            printf("Pop item: %d\n", pop());
            break;

        }
        case 3:

        {
            printf("Top of Stack: %d\n",peek());

            break;
        }
        case 4:
            print(top);
            break;

        case 5:
            return 0;
          default:
        printf("Invalid choice\n");


        }


    }

}
