#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void print(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

struct node *insertAtBeginning(struct node *head,int val)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->next=head;
    head=ptr;
    return head;


}
struct node *insertAtEnd(struct node *head,int val)
{
    if(head==NULL)
    {
        struct node *NewNode=(struct node*)malloc(sizeof(struct node));

        NewNode->data=val;
        NewNode->next=NULL;
        head=NewNode;
        return head;
    }

    struct node *current=head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    current->next=temp;
    temp->next=NULL;

    return head;

}

//struct node *insertAtAnyPos(struct node *head,int pos,int val)
//{
//    struct node *temp,*current;
//    int cnt=0;
//    current=head;
//    while(current!=NULL)
//    {
//
//        cnt++;
//        if(cnt==pos-1)
//        {
//
//            //3 4 -6- 5
//
//            temp=(struct node*)malloc(sizeof(struct node));
//            temp->data=val;
//            temp->next=current->next;
//            current->next=temp;
//        }
//        current=current->next;
//    }
//    return head;
//}
struct node *insertAtAnyPos(struct node *head,int pos,int val)
{
 int cnt=0;
 struct node *p=head;
 while(cnt!=pos-1)
 {
     p=p->next;
     cnt++;
 }
 struct node *tmp=(struct node*)malloc(sizeof(struct node));
 tmp->data=val;
 tmp->next=p->next;
 p->next=tmp;
 return head;
}
struct node *del(struct node *head,int val)
{
    struct node *dele=(struct node*)malloc(sizeof(struct node));
    dele->next=head;
    struct node *temp=dele;
    while(temp->next!=NULL)
    {
        if(temp->next->data==val)
        {
            temp->next=temp->next->next;
        }
        temp=temp->next;
    }
    return dele->next;

}
struct node *DeleteFirst(struct node *head)
{
    struct node *ptr=head;
    head=head->next;
    int val=ptr->data;
    printf("%d\n",val);
    free(ptr);
    return head;

}
struct node *DeleteIndexValue(struct node *head,int idx)
{
    struct node *p=head;
    struct node *q=head->next;
    for(int i=0; i<idx-1; i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    printf("%d\n",q->data);
    free(q);
    return head;



}
struct node *DeleteLast(struct node *head)
{
    struct node *temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    struct node *last=temp->next;
    temp->next=NULL;
    printf("%d\n",last->data);
    free(last);
    return head;
}
int  searchNode(struct node *head,int val)
{
    int idx=1;
    while(head!=NULL)
    {
        if(head->data==val)
        {
            return idx;
        }
        idx++;
        head=head->next;
    }
    return -1;
}



struct node *sort(struct node *head)
{
    struct node *i,*j;
    int temp;
    for(i=head; i->next!=NULL; i=i->next)
    {
        for(j=i->next; j!=NULL; j=j->next)
        {
            if(i->data>j->data)
            {
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }

}

int main()
{
    struct Node* head = NULL;

    //printf("\n--------Press a key to operate any operation------\n");
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

struct node *Createlinklist(int a[],int size)
{
    struct node *head=NULL,*temp=NULL,*current=NULL;
    for(int i=0; i<size; i++)
    {

        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=a[i];
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            current=temp;
        }
        else
        {
            current->next=temp;
            current=current->next;
        }


    }
    return head;




}
void print(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

struct node *insertAtBeginning(struct node *head,int val)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=val;
    head=ptr;
    return ptr;

}
struct node *end(struct node *head,int val)
{

    struct node *current=head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    current->next=temp;

}

struct node *any(struct node *head,int pos,int val)
{
    struct node *temp,*current;
    int cnt=0;
    current=head;
    while(current!=NULL)
    {

        cnt++;
        if(cnt==pos-1)
        {

            temp=(struct node*)malloc(sizeof(struct node));
            temp->data=val;
            temp->next=current->next;
            current->next=temp;
        }
        current=current->next;
    }
}
//struct node *del(struct node *head,int val)
//{
//    struct node *dele=(struct node*)malloc(sizeof(struct node));
//    dele->next=head;
//    struct node *temp=dele;
//    while(temp->next!=NULL)
//    {
//        if(temp->next->data==val)
//        {
//            temp->next=temp->next->next;
//        }
//        temp=temp->next;
//    }
//    return dele->next;
//
//}
int  searchNode(struct node *head,int val)
{
    int idx=1;
    while(head!=NULL)
    {
        if(head->data==val)
        {
            return idx;
        }
        idx++;
        head=head->next;
    }
    return -1;
}

struct node *sort(struct node *head)
{
    struct node *i,*j;
    int temp;
    for(i=head; i->next!=NULL; i=i->next)
    {
        for(j=i->next; j!=NULL; j=j->next)
        {
            if(i->data>j->data)
            {
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }

}

int main()
{

    int n;
    printf("How many number :");
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    struct node *head;

    head=Createlinklist(a,n);

    struct node *one=head;
    //printf("%d\n",head->data);
    printf("Print Whole List :");
    print(head);
    printf("Enter value for insert at beginning :");
    int val;
    scanf("%d",&val);

    head=insertAtBeginning(one,val);
    printf("After Insert At Beginning : ");
    print(head);

    printf("Enter value for insert at end :");
    int num;
    scanf("%d",&num);
    printf("After Insert At End : ");
    end(head,num);
    print(head);

    printf("Enter position and value for insert at any");
    int pos,va;
    scanf("%d %d",&pos,&va);
    printf("After Insert At any : ");
    any(head,pos,va);
    print(head);

    printf("Enter search value :");
    int sv;
    scanf("%d",&sv);
    printf("search Node :");
    printf("%d\n",searchNode(head,sv));

    sort(head);
    printf("Sorting Linked List:");
    print(head);

//    printf("delete Node :");
//    del(head,500);
//    print(head);

}

*/




















/*

#include <stdio.h>
#include <stdlib.h>

// Create a node
struct Node
{
    int data;
    struct Node* next;
};

// Insert at the beginning
struct Node* insertAtBeginning(struct Node** head_ref, int new_data)
{
    // Allocate memory to a node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // insert the data
    new_node->data = new_data;

    new_node->next = (*head_ref);

    // Move head to new node
    (*head_ref) = new_node;
    return *head_ref;
}
//insert a node between linkedlist
struct Node * insertAfterIndex(struct Node* head,int data,int index)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p=head;
    int i=0;
    while(i!=index-1)
    {

        p=p->next;
        i++;
    }
    new_node->data=data;
    new_node->next=p->next;
    p->next=new_node;
    return head;
};
// Insert a node after a node
void insertAfter(struct Node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Insert the the end
void insertAtEnd(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) last = last->next;

    last->next = new_node;
    return;
}
//deleting nide
struct Node* deletefirst(struct Node *head)
{

    struct Node *ptr=head;
    head=head->next;
    free(ptr);
    return head;

};

// Print the linked list
void printList(struct Node* node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
    printf("\n\n");
}

// Driver program
int main()
{
    struct Node* head = NULL;
    printf("--------Press a key to operate any operation------\n");
    printf("Press 1 if you want to insert an element at the beginning of the linkedlist.\n ");
    printf("Press 2 if you want to insert an element at the end of the linkedlist.\n ");
    printf("Press 3 if you want to insert an element to  after a specific node  of the linkedlist.\n ");

    printf("Press 4 to print the linkedlist.\n");
    printf("Press 5  to exit from the operation of the linkedlist.\n");
    while(1)
    {
        int i;
        printf("Press the number:");
        scanf("%d",&i);
        if(i==1)
        {
            int a;
            printf("Enter the data do you want to insert at beginning:");
            scanf("%d",&a);
            head=insertAtBeginning(&head, a);
        }
        else if(i==2)
        {
            int a;
            printf("Enter the data do you want to insert at the end:");
            scanf("%d",&a);
            insertAtEnd(&head, a);
        }

        else if(i==3)
        {

            int a,index;
            printf("Enter the data do you want to insert:");
            scanf("%d",&a);
            printf("Enter the node's index after that the new element will be inserted:");
            scanf("%d",&index);
            head=insertAfterIndex(head,a,index);
        }
        else if(i==4)
        {

            printf("Linked list: ");
            printList(head);
        }
        else if(i==5)
        {
            break;
        }
        else
        {
            printf("You give an invalid number.Please Try again.\n");
            continue;
        }
    }




}



/*
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
};

void print(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->val);
        head=head->next;


    }
}

struct node *insert(struct node *head,int val)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->val=val;
    head=ptr;
    return ptr;

}

int main()
{
    //// Initialize nodes

    struct node *head;
    struct node *one=NULL;
    struct node *two=NULL;
    struct node *three=NULL;

    // // Allocate memory
    one=(struct node*)malloc(sizeof(struct node));
    two=(struct node*)malloc(sizeof(struct node));
    three=(struct node*)malloc(sizeof(struct node));

    //  // Assign value values
    one->val=4;
    two->val=69;
    three->val=8;

     // Connect nodes
    one->next=two;
    two->next=three;
    three->next=NULL;
    head=one;
    //printing node-value
    print(head);
    printf("\n");
    head=insert(head,56);
    print(head);


}




*/


