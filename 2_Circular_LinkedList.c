
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void  print(struct Node *head)
{
    if(head==NULL)
    {
        printf("NULL !\n");

    }
    else
    {
        struct Node *ptr=head;
        do
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        while(ptr!=head);
        printf("\n");

    }
}
struct Node* insertAtBeginning(struct Node *head,int val)
{
    //3 4 5 6
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));

    if(head==NULL)
    {
        ptr->data=val;
        ptr->next=ptr;
        head=ptr;
        return head;

    }
    struct Node *p=head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    // At this point p points to the last node of this circular linked list
    ptr->data=val;
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;

}
struct Node *insertAtEnd(struct Node *head,int val)
{
    // 3 4 5-6-
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    if(head==NULL)
    {
        ptr->data=val;
        ptr->next=ptr;
        head=ptr;
        return head;
    }
    struct Node *p=head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    ptr->data=val;
    ptr->next=p->next;
    p->next=ptr;
    return head;

}
struct Node* insertAtAnyPos(struct Node* head, int pos, int val)
{
    //3 4 5
    int cnt=1;
    struct Node *p=head->next;
    while(cnt!=pos-1)
    {
        p=p->next;
        cnt++;
    }
    struct Node *tmp=(struct Node*)malloc(sizeof(struct Node));
    tmp->data=val;
    tmp->next=p->next;
    p->next=tmp;
    return head;
}
struct Node *DeleteFirst(struct Node *head)
{
    //3 4 5 6

    if(head==NULL)
    {
        printf("Empty List !\n");
        return head;
    }
    else
    {
        struct Node *p=head;
        while(p->next!=head)
        {
            p=p->next;
        }
        printf("%d \n",head->data);
        p->next=head->next;
        struct Node *h=head;
        head=head->next;
        free(h);
        return head;

    }

}
struct Node *DeleteLast(struct Node *head)
{
    //3 4 5

    if(head==NULL)
    {
        printf("Empty List !\n");
        return head;
    }
    else
    {
        struct Node *p=head->next;
        struct Node *q=head;

        while(p->next!=head)
        {
            p=p->next;
            q=q->next;
        }
        q->next=head;
        printf("%d \n",p->data);
        free(p);
        return head;


    }
}
struct Node *DeleteIndexValue(struct Node *head,int pos)
{
    //3 4 5
    struct Node *p=head->next;
    int cnt=2;
    while(cnt!=pos-1)
    {
        p=p->next;
        cnt++;
    }
    struct Node *del=p->next;
     p->next=p->next->next;
     printf("%d \n",del->data);
     free(del);
     return head;

}
struct Node *sort(struct Node *head)
{
    int temp;
    struct Node *t=head;
    struct Node *i,*j;
    for(i=t;; i=i->next)
    {
        for(j=t;; j=j->next)
        {
            if(j->next!=head)
            {
                // printf("%d %d\n ",i->data,j->data);
                if(i->data<j->data)
                {
                    temp=i->data;
                    i->data=j->data;
                    j->data=temp;
                }
            }
            else break;

        }
        if(i->next==head) break;

    }
}

int  searchNode(struct Node *head,int val)
{

//    int idx=-1;
//    struct Node *ptr=head;
//    while(ptr->next!=head)
//    {
//
//        if(ptr->data==val)
//        {
//            return idx;
//        }
//        idx++;
//        ptr=ptr->next;
//    }
//    return -1;

int idx=-1;
        struct Node *ptr=head;
        do
        {
          if(ptr->data==val) return idx;
          idx++;
            ptr=ptr->next;
        }
        while(ptr!=head);

}



int main()
{
    struct Node* head = NULL;

    printf("\n--------Press a key to operate any operation------\n");
    printf("1 Insert at Beginning.\n");
    printf("2 Insert at End.\n");
    printf("3 Insert a node After a node.\n");
    printf("4 Delete First Node\n");
    printf("5 Delete Last Node.\n");
    printf("6 Delete the specific index.\n");
    printf("7 Search a Node.\n");
    printf("8 Sort the list.\n");
    printf("9 Traverse Linked List\n");
    printf("10 Exit the linked list.\n");

    while(1)
    {
        int i;

        int val;
        printf("Press the number :");
        scanf("%d",&i);
        switch(i)
        {

        case 1:
            printf("Enter Value :");
            scanf("%d",&val);
            head=insertAtBeginning(head,val);
            break;
        case 2:
            printf("Enter value :");
            scanf("%d",&val);
            head=insertAtEnd(head,val);
            break;
        case 3:
            int pos;
            printf("Enter position and value :");
            scanf("%d %d",&pos,&val);
            head=insertAtAnyPos(head,pos,val);
            break;
        case 4:
            head=DeleteFirst(head);
            break;
        case 5:
            int idx;
            printf("Enter index :");
            scanf("%d",&idx);
            head=DeleteIndexValue(head,idx);
            break;
        case 6:
            head=DeleteLast(head);
            break;

        case 7:
            int num;
            printf("Enter search value :");
            scanf("%d",&num);
            printf("%d\n",searchNode(head,num));
            break;
        case 8:
            sort(head);
            break;
        case 9:
            print(head);
            break;
        case 10:
            return 0;



        }

        //system("cls");

    }

}

/* 
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *F(struct node *tail,int data)
{
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=data;
//3 4 5 6
    if(tail==NULL)
    {

        tail=p;
        tail->next=p;
        return tail;
    }
    p->next=tail->next;
    tail->next=p;
    return tail;

}
void print(struct node *tail)
{
    //3 4 5
    struct node *t=tail->next;
    do
    {
        printf("%d ",t->data);
        t=t->next;
    }
    while(t!=tail->next);
    printf("\n");
}
struct node *E(struct node *tail,int data)
{
    struct node *p=(struct node*)malloc(sizeof(struct node));
//3 4 5 ..6
    p->data=data;

    p->next=tail->next;
    tail->next=p;
    tail=p;
    return tail;

}
struct node *df(struct node *tail)
{
//3 4 5
    if(tail==NULL)
    {
        printf("NULL..!\n");
        return tail;
    }
    if(tail->next==tail)
    {
        free(tail);
        tail=NULL;
        return tail;

    }
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p=tail->next;
    tail->next=p->next;
    free(p);
    return tail;
}
struct node *dl(struct node *tail)
{
//3 4 5
    if(tail==NULL)
    {
        printf("NULL !\n");
        return tail;
    }
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p->next=tail->next;
    while(p->next!=tail)
    {
        p=p->next;
    }
    //free(tail);
    tail=p;
    p->next=tail->next;

    return tail;

}
struct node *at(struct node *tail,int data,int pos)
{
//3 4 5 6
    int cnt=0;
    struct node *p=tail->next;
    struct node *q=p->next;
    while(cnt!=pos-1)
    {
        cnt++;
        p=p->next;
        q=q->next;
    }
    struct node *tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->next=q;
    p->next=tmp;
    return tail;

}
struct node *AT(struct node *tail,int pos)
{
    int cnt=0;
//3 4 5 6

    struct node *p=tail->next;
    struct node *q=p->next;
    while(cnt!=pos-1)
    {
        cnt++;
        p=p->next;
        q=q->next;
    }

    p->next=q->next;
    printf("%d\n",q->data);
    free(q);
    return tail;
}
void *sort(struct node *tail)
{
    struct node *i,*j,*t;
    for(i=tail->next;i!=tail;i=i->next){
        for(j=tail->next;j!=tail;j=j->next)
        {
            t=j->next;
            if(t->data<j->data)
            {
                int tmp=j->data;
                j->data=t->data;
                t->data=tmp;
            }
        }
    }
}

int main()
{
    struct node *tail=NULL;
    int ch,val,pos;
    while(1)
    {
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("enter val:");
            scanf("%d",&val);
            tail=F(tail,val);
            break;
        case 2:
            print(tail);
            break;
        case 3:
            printf("enter val:");
            scanf("%d",&val);
            tail=E(tail,val);
            break;
        case 4:
            tail=df(tail);
            break;
        case 5:
            tail=dl(tail);
            break;
        case 6:
            printf("enter val &pos:");
            scanf("%d %d",&val,&pos);
            tail=at(tail,val,pos);
            break;
        case 7:
            printf("enter pos:");
            scanf("%d",&pos);
            tail=AT(tail,pos);
            break;
        case 8:
            sort(tail);
            break;

        }
    }
}











 */
/*
#include<stdio.h>
#include<stdlib.h>
//#include<bits/stdc++.h>
struct node{
    int data;
    struct node *next;
};
struct node* addToBegin(struct node* tail, int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data= data;
    if(tail==NULL)
    {

      tail=temp;
      tail->next=tail;

     // printf("%d\n",tail->data);
      return tail;
    }
    temp->next=tail->next;
    tail->next=temp;
    return tail;
}


struct node* addAfterpos(struct node* tail,int data,int pos)
{
  struct node* p=tail->next;
  struct node* newp=(struct node*)malloc(sizeof(struct node));
  newp-> data=data;
  newp->next= NULL;
  while(pos>1)
  {
      p=p->next;
      pos--;
  }
  newp->next=p->next;
  p->next=newp;
  if(p==tail)
  {
      tail=tail->next;
  }
  return tail;

}
struct node * deleteAtFirst(struct node* tail)
{
    if(tail==NULL)
    {
        printf("Here nothing have to delete.\n");
        return tail;
    }
    if(tail->next==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }
  struct node* p=(struct node*)malloc(sizeof(struct node));
  p=tail->next;
  tail->next=p->next;
  free(p);
  return tail;
}
void print(struct node* tail)
{

    if(tail==NULL)
    {
        printf("List is empty.\n");
        return ;
    }
     struct node * p=tail->next;
    do
    {
        printf("%d ",p->data);
        p=p->next;
    }
    while(p!=tail->next);
    printf("\n");

}

struct node* delAtlast(struct node* tail)
{
    if(tail==NULL)
    {
        printf("Empty linked list.\n");
        return tail;
    }
   struct node* p=(struct node*)malloc(sizeof(struct node));
   p->next=tail->next;
   while(p->next!=tail)
   {
       p=p->next;
   }
   p->next=tail->next;

   //free(tail);
   tail=p;
   //free(p);
   return tail;
}
struct node* delAtpos(struct node* tail,int pos)
{
    if(tail==NULL)
    {
        return tail;
    }
    if(tail->next==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }
    struct node* temp=tail->next;
    while(pos>2)
    {
        temp=temp->next;
        pos--;
    }
    struct node* temp2=temp->next;
    temp->next=temp2->next;
    if(temp2==tail)
    {
        tail=temp;
    }
    free(temp2);
    return tail;
}
int searchelement(struct node* tail,int val)
{
    if(tail==NULL)
    {
        return -1;
    }
    struct node* p=tail->next;
    int ind=1;
    do
    {
        if(p->data==val)
        {
            return ind;
        }
        p=p->next;
        ind++;

    }while(p!=tail->next);
    return -1;
}
void sort_list(struct node* tail)
{

    if(tail==NULL)
    {
        return ;
    }
    struct node* i=(struct node*)malloc(sizeof(struct node));
    struct node* j=(struct node*)malloc(sizeof(struct node));
    struct node* t=(struct node*)malloc(sizeof(struct node));
    int temp=78;
   //printf("%d\n",temp);

    for(i=tail->next;i!=tail;i=i->next)
    {
        //printf("%d\n",temp);
        for(j=tail->next;j!=tail;j=j->next)
        {
            t=j->next;
            if(j->data>t->data)
            {
                temp=j->data;
               j->data= t->data;
               t->data=temp;
            }
           // printf("%d\n",temp);
        }

    }
    print(tail);
}

int main()
{
     struct node* tail=(struct node*)malloc(sizeof(struct node));

     tail=NULL;
     while(1)
     {
         printf("Enter a number in below to operate any operation:\n");
         printf("Enter 1 to add any element at first of the circular linked list.\n");
         printf("Enter 2 to add any element at the end of the circular linked list.\n");
         printf("Enter 3 to add any element at after any specific position of the circular linked list.\n");
         printf("Enter 4 to delete any element at first of the circular linked list.\n");
         printf("Enter 5 to delete any element at the end of the circular linked list.\n");
         printf("Enter 6 to delete any element at after any specific position of the circular linked list.\n");
         printf("Enter 7 to search any element .\n");
         printf("Enter 8 to sort the list.\n");
         printf("Enter 9 for printing the list.\n");
         printf("Enter 10 to exit from the list.\n");
         int c;
         scanf("%d",&c);
         switch (c)
         {
         case 1:
             int d;
            printf("Give the number:");
            scanf("%d",&d);
            tail=addToBegin(tail,d);
            break;
         case 2:
            int k;
            printf("Give the number:");
            scanf("%d",&k);
            tail=addAtEnd(tail,k);
            break;
         case 3:
            int m,p;
            printf("Give the number and the position:");
            scanf("%d %d",&m,&p);
             tail=addAfterpos(tail,m,p);
            break;
         case 4:
            tail=deleteAtFirst(tail);
            break;
         case 5:
            tail=delAtlast(tail);
            break;
         case 6:
             int pos;
            printf("Give the position:");
            scanf("%d",&pos);
            tail=delAfterpos(tail,pos);
            break;
         case 7:{
             int data;
             printf("Give the number:");
             scanf("%d",&data);
            int n=searchelement(tail,data);
            if(n!=-1)
            {
                printf("The number is found at %d position.\n",n);

            }
            else
            {
                printf("Not found.\n");
            }
          break;}

          case 8:
            sort_list(tail);
            break;
          case 9:
            print(tail);
            break;
         case 10:
            printf("Exiting  the programming......\n");
            exit(0);
         default:
             printf("Invalid choice.\n");
            break;

         }
     }


    return 0;
}

*/



























