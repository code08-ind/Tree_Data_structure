/*
  ARYAN GARG
  19124018
  INFORMATION TECHNOLOGY(IT)
  G-1
*/

//MENU DRIVEN PROGRAM OF BST AND IT'S OPERATIONS.

# include <stdio.h>
# include <malloc.h>

struct node
{
    int info;//root node info
    struct node *lchild;//left child
    struct node *rchild;//right child
}*root;

void find(int item,struct node **par,struct node **loc)//function for finding of the node and the position and
//pointers for accessing of the *par and *loc pointers taken here.
{
    struct node *ptr,*ptrsave;

    if(root==NULL) //tree is empty
    {
        *loc=NULL;//location of the node or the element
        *par=NULL;
        return;
    }
    if(item==root->info) //item is at root position
    {
        *loc=root;
        *par=NULL;
        return;
    }

    //Initialize ptr and ptrsave to a new case
    if(item<root->info)
        ptr=root->lchild;
    else
        ptr=root->rchild;
    ptrsave=root;

    while(ptr!=NULL)
    {
        if(item==ptr->info)
        {
            *loc=ptr;
            *par=ptrsave;
            return;
        }
        ptrsave=ptr;
        if(item<ptr->info)
            ptr=ptr->lchild;
        else
            ptr=ptr->rchild;
    }//End of while loop
    *loc=NULL;  //item not found inside the tree
    *par=ptrsave;
}//End of find() function

void insert(int item)
{
    struct node *tmp,*parent,*location;
    find(item,&parent,&location);
    if(location!=NULL)
    {
        printf("Item already present");//item already present inside the tree
        return;
    }

    tmp=(struct node *)malloc(sizeof(struct node));//allocating the memory to the new element  to be inserted
    tmp->info=item;
    tmp->lchild=NULL;
    tmp->rchild=NULL;

    if(parent==NULL)
        root=tmp;
    else if(item<parent->info)
        parent->lchild=tmp;
    else
        parent->rchild=tmp;
}//End of insert() function


void case_a(struct node *par,struct node *loc )
{
    if(par==NULL)//item to be deleted is root node when the process of deletion needs to be carried.
        root=NULL;
    else if(loc==par->lchild)
        par->lchild=NULL;
    else
        par->rchild=NULL;
}//End of case_a()

void case_b(struct node *par,struct node *loc)
{
    struct node *child;

    //Initializing the child elements
    if(loc->lchild!=NULL) //item to be deleted has lchild inside it
        child=loc->lchild;
    else                //item to be deleted has rchild inside it
        child=loc->rchild;

    if(par==NULL )  //Item to be deleted is root node
        root=child;
    else if( loc==par->lchild)   //Item is lchild of its parent node inside it
        par->lchild=child;
    else                  //item is rchild of its parent node present inside it.
        par->rchild=child;
}//End of case_b() function

void case_c(struct node *par,struct node *loc)
{
    struct node *ptr,*ptrsave,*suc,*parsuc;

    //Find inorder successor and its parent node element
    ptrsave=loc;
    ptr=loc->rchild;
    while(ptr->lchild!=NULL)
    {
        ptrsave=ptr;
        ptr=ptr->lchild;
    }
    suc=ptr;
    parsuc=ptrsave;

    if(suc->lchild==NULL && suc->rchild==NULL)
        case_a(parsuc,suc);
    else
        case_b(parsuc,suc);

    if(par==NULL) //if item to be deleted is root node then what we will have to take in the node.
        root=suc;
    else if(loc==par->lchild)
        par->lchild=suc;
    else
        par->rchild=suc;

    suc->lchild=loc->lchild;
    suc->rchild=loc->rchild;
}//End of case_c() function
int del(int item)
{
    struct node *parent,*location;
    if(root==NULL)
    {
        printf("Tree empty");//tree is empty
        return 0;
    }

    find(item,&parent,&location);
    if(location==NULL)
    {
        printf("Item not present in tree");//if the item is not present inside the tree
        return 0;
    }

    //deleting the node if we are preparing for it's deletion
    if(location->lchild==NULL && location->rchild==NULL)
        case_a(parent,location);
    if(location->lchild!=NULL && location->rchild==NULL)
        case_b(parent,location);
    if(location->lchild==NULL && location->rchild!=NULL)
        case_b(parent,location);
    if(location->lchild!=NULL && location->rchild!=NULL)
        case_c(parent,location);
    free(location);
}//End of del() function

int preorder(struct node *ptr)
{
    if(root==NULL)
    {
        printf("Tree is empty");//tree has no element
        return 0;
    }
    if(ptr!=NULL)
    {
        //preorder traversal of the form of searching of the element
        printf("%d  ",ptr->info);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}//End of preorder() function

void inorder(struct node *ptr)
{
    if(root==NULL)
    {
        printf("Tree is empty");//tree is empty
        return;
    }
    if(ptr!=NULL)
    {
        //inorder traversal of the element inside the tree
        inorder(ptr->lchild);
        printf("%d  ",ptr->info);
        inorder(ptr->rchild);
    }
}//End of inorder() function

void postorder(struct node *ptr)
{
    if(root==NULL)
    {
        printf("Tree is empty");//tree is empty
        return;
    }
    if(ptr!=NULL)
    {
        //preorder traversal of the tree form of the element of the tree
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%d  ",ptr->info);
    }
}//End of postorder() function

int main()
{
    int choice,num;
    root=NULL;
    while(1)
    {
        printf("BINARY SEARCH TREE AND IT'S VARIOUS OPERATIONS.")
        printf("\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Inorder Traversal oF BST\n");
        printf("4.Preorder Traversal OF BST\n");
        printf("5.Postorder Traversal OF BST\n");
        printf("6.Quit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Enter the number to be inserted : ");
            scanf("%d",&num);
            insert(num);
            break;
        case 2:
            printf("Enter the number to be deleted : ");
            scanf("%d",&num);
            del(num);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            break;
        default:
            printf("Wrong choice\n");
        }//End of switch statement
    }//End of while loop
}//End of main() function

