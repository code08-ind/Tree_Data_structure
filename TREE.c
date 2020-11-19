/*
ARYAN GARG
19124018
INFORMATION TECHNOLOGY(IT)
G-1
*/

//PROGRAM OF IMPLEMENTATION OF BINARY TREE WITH VARIOUS OPERATIONS OPERATED ON IT.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node node;//using struct node as node as well in some of the places

// Defining the Tree's node here for the info as it's value and with left and the right child nodes
struct node
{
    // data
    int data;
    // left and right children of the root node
    node* lchild, *rchild;
};

node* createTree(int value)
{
    // Creates the tree and returns the
    // root node
    node* root = (node*) malloc (sizeof(node));//creating the node and it's element
    root->lchild = root->rchild = NULL;
    root->data = value;
    return root;
}

node* create_node(int value)//creates the nodes in the tree
{
    // Creates a new node in the tree respectively
    node* Node = (node*) malloc (sizeof(node));
    Node->data = value;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

int height_Of_Tree(node* root)
{
    // Get back the height of the tree
    if (!root)
        return 0;
    else
    {
        // Find the height of both subtrees os the regular initial tree
        // and use the larger one

        int left_node_height = height_Of_Tree(root->lchild);
        int right_node_height = height_Of_Tree(root->rchild);
        if (left_node_height >= right_node_height)
            return left_node_height + 1;
        else
            return right_node_height + 1;
    }
}

void print_at_each_level(node* root, int level_no)
{
    // Prints the nodes in the tree
    // having a level = level_no

// An auxiliary root or the extra root node node
    // for printing the root of every
    // subtree
    if (!root)
        return;
    if (level_no == 0)
    {
        // We are at the top of a subtree
        // So print the auxiliary or the extra root node
        printf("%d >>> ", root->data);
    }
    else
    {
        // Make the auxiliary or the extra root node to
        // be the left and right nodes for
        // the subtrees and decrease level by 1, since
        // you are moving from top to bottom of the tree or the binary tree.
        print_at_each_level(root->lchild, level_no - 1);
        print_at_each_level(root->rchild, level_no - 1);
    }

}

void print_tree_full_level_order(node* root)//printing the node or the element at each level
{
    if (!root)
        return;
    int height = height_Of_Tree(root);
    for (int i=0; i<height; i++)
    {
        printf("Level Of : %d: ", i);//level of the tree and it's nodes
        print_at_each_level(root, i);//printing the elements at the specific node levels
        printf("\n");
    }
    printf("\n\n======= LEVEL ORDER TRAVERSAL OF THE BINARY TREE IS : ========\n");
    for (int i=0; i<height; i++)
    {
        print_at_each_level(root, i);
    }
    printf("\n");
}

int main()
{
    // Create the root node with it's value
    node* root = createTree(20);

    // Insert the nodes and with the left and the right child's specifically
    root->lchild = create_node(12);
    root->rchild = create_node(30);
    root->lchild->lchild = create_node(11);
    root->lchild->rchild = create_node(18);

    // Level Order Traversal of the Binary tree we have formed in it.
    print_tree_full_level_order(root);

    return 0;
}
