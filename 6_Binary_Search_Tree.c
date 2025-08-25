#include<stdio.h>
#include<stdlib.h>
//struct node *serach(struct node *root,int x);
struct node
{
    int data;
    struct node *left;
    struct node *right;

};
struct node *search(struct node *root,int x)
{
    if(root==NULL ||root->data==x)return root;
    else if(x>root->data) return search(root->right,x);//search right subtree
    else return search(root->left,x);
}
struct node *mini(struct node *root)
{
    if(root==NULL) return NULL;
    else if(root->left!=NULL) return mini(root->left);//left most will be always be minimum
    return root;
}
struct node *new_node(int x)
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
struct nodde *insert(struct node *root,int x)
{
    //searching for the place to insert
    if(root==NULL) return new_node(x);
    //x is greater ,should be inserted to right
    else if(x>root->data) root->right=insert(root->right,x);
    else root->left=insert(root->left,x);//should be  inserted left
    return root;
    }


struct node *del(struct node *root,int x)
{
    //searching for item
    if(root==NULL) return NULL;
    if(x>root->data) root->right=del(root->right,x);
    else if(x<root->data) root->left=del(root->left,x);
    else
    {
        //no children
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        //one child
        else if(root->left==NULL || root->right==NULL)
        {
            struct node *tmp;
            if(root->left==NULL) tmp=root->right;
            else tmp=root->left;
            free(root);
            return tmp;
        }
        //two children
        else
        {
            struct node *tmp=mini(root->right);
            root->data=tmp->data;
            root->right=del(root->right,tmp->data);
        }

    }
    return root;
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }

}
int main()
{
    struct node *root;
    root=new_node(20);
    insert(root,5);
    insert(root,1);
    insert(root,15);
    insert(root,9);
    insert(root,7);
    insert(root,12);
    insert(root,30);
    insert(root,25);
    insert(root,40);
    insert(root,45);
    insert(root,42);
    inorder(root);
    printf("\n");
    root=del(root,1);
    root=del(root,40);
    root=del(root,9);
    inorder(root);
    printf("\n");
    return 0;






}












