#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
void Tree(struct tree *ptr)
{
    struct tree *L, *R;
    int ch;
    if (ptr != NULL)
    {

        printf("\nEnter data:");
        scanf("%d", &ptr->data);
        ptr->left = NULL;
        ptr->right = NULL;
        printf("\n if create a left child for %d(1/0) :", ptr->data);
        scanf("%d", &ch);
        if (ch == 1)
        {
            L = (struct tree *)malloc(sizeof(struct tree));
            ptr->left = L;
            Tree(L);
        }
        printf("\nif create a rightchild for %d(1/0) :", ptr->data);

        scanf("%d", &ch);
        if (ch == 1)
        {
            R = (struct tree *)malloc(sizeof(struct tree));
            ptr->right = R;
            Tree(R);
        }
    }
}
void in(struct tree *ptr)
{
    if (ptr != NULL)
    {
        in(ptr->left);
        printf("%d ", ptr->data);
        in(ptr->right);
    }
}
void preorderTraversal(struct tree *root)
{
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void post(struct tree *root)
{
    if (root == NULL)
        return;
    post(root->left);
    post(root->right);
    printf("%d ", root->data);
}

// int main()
//{
//
//     struct tree *root;
//     root=(struct tree*)malloc(sizeof(struct tree));
//     Tree(root);
//     printf("in order :");
//     in(root);
//     printf("\n");
//     printf("Pre :");
//     preorderTraversal(root);
//     printf("\n");
//     printf("post: ");
//     post(root);
//     printf("\n");
//
// }

int main()
{

    printf("1.create a Root Node.\n");
    printf("2.in order Traversal.\n");
    printf("3.pre order Traversal.\n");
    printf("4.post order Traversal.\n");
    struct tree *root;
    root = (struct tree *)malloc(sizeof(struct tree));
    while (1)
    {
        int i;
        int val;
        printf("Press the number :");
        scanf("%d", &i);
        switch (i)
        {

        case 1:
            Tree(root);
            break;
        case 2:
            in(root);
            break;
        case 3:
            preorderTraversal(root);
            break;
        case 4:
            post(root);
            break;
        }
    }
}
