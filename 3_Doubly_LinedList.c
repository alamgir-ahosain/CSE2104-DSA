/* Doubly Linked List implementation */
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head; // global variable - pointer to head node.

//Creates a new Node and returns pointer to it.
struct Node* GetNewNode(int x)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

//Inserts a Node at head of doubly linked list
void InsertAtHead(int x)
{
    struct Node* newNode = GetNewNode(x);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

//Inserts a Node at tail of Doubly linked list
void InsertAtTail(int x)
{
    struct Node* temp = head;
    struct Node* newNode = GetNewNode(x);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    while(temp->next != NULL) temp = temp->next; // Go To last Node
    temp->next = newNode;
    newNode->prev = temp;
}

//Prints all the elements in linked list in forward traversal order
void Print()
{
    struct Node* temp = head;
    printf("Forward: ");
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Prints all elements in linked list in reverse traversal order.
void ReversePrint()
{
    struct Node* temp = head;
    if(temp == NULL) return; // empty list, exit
    // Going to last Node
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    // Traversing backward using prev pointer
    printf("Reverse: ");
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
struct Node* after(struct NOde *head,int data,int pos)
{

    struct Node *newP,*temp,*temp2;
    newP=NULL;
    temp=head;
    temp2=NULL;
    newP= GetNewNode(data);
    while(pos!=1)
    {
        temp=temp->next;
        pos--;
    }
    temp2=temp->next;
    temp->next=newP;
    temp2->prev=newP;
    newP->next=temp2;
    newP->prev=temp;
    return head;

}
void bubbleSort(struct Node *start)
{
    int swapped, i;
    int temp;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    /* Checking for empty list */
    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                //   swap(ptr1->data, ptr1->next->data);
                temp=ptr1->data;
                ptr1->data=ptr1->next->data;
                ptr1->next->data=temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}


int search(struct Node** head_ref, int x)
{

    // Stores head Node
    struct  Node* temp = *head_ref;

    // Stores position of the integer
    // in the doubly linked list
    int pos = 0;

    // Traverse the doubly linked list
    while (temp->data != x
            && temp->next != NULL)
    {

        // Update pos
        pos++;

        // Update temp
        temp = temp->next;
    }

    // If the integer not present
    // in the doubly linked list
    if (temp->data != x)
        return -1;

    // If the integer present in
    // the doubly linked list
    return (pos + 1);
}







void deleteNode(struct Node** head_ref, struct Node* del)
{
    /* base case */
    if (*head_ref == NULL || del == NULL)
        return;

    /* If node to be deleted is head node */
    if (*head_ref == del)
        *head_ref = del->next;

    /* Change next only if node to be deleted is NOT the last node */
    if (del->next != NULL)
        del->next->prev = del->prev;

    /* Change prev only if node to be deleted is NOT the first node */
    if (del->prev != NULL)
        del->prev->next = del->next;

    /* Finally, free the memory occupied by del*/
    free(del);
    return;
}
int main()
{

    /*Driver code to test the implementation*/
    head = NULL; // empty list. set head as NULL.

    // Calling an Insert and printing list both in forward as well as reverse direction.
    InsertAtTail(2);
    Print();
    ReversePrint();
    InsertAtTail(4);

    Print();
    ReversePrint();

    InsertAtHead(6);
    Print();
    ReversePrint();

    InsertAtTail(8);
    Print();
    ReversePrint();

    after(head,66666,2);
    Print();
    ReversePrint();

    bubbleSort(head);
    Print();
    ReversePrint();

    printf("%d\n",search(&head,60000000000000));




     /* delete nodes from the doubly linked list */
    deleteNode(&head, head); /*delete first node*/
    deleteNode(&head, head->next); /*delete middle node*/
    deleteNode(&head, head->next); /*delete last node*/
      Print();
}

