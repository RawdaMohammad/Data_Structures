//problem 7
#include <iostream>

using namespace std;

/* new node */
struct Node
{
    int data;
    Node* right;
    Node* left;
};

// allocates a new node


struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

//swap right and left pointer at each node

void flip(Node* node)
{
    if (node == NULL)
        return;
    else
    {
        struct Node* temp;
        /* call the subtrees */
        flip(node->left);
        flip(node->right);
        // swap right and left pointers in the node
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

/* function to print Inorder traversal */
void inOrder(struct Node* node)
{
    if (node == NULL)
        return;
        else
        {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
}

void testcase1()
{
    cout<<"The test case1:"<<endl;
    struct Node *root = newNode(5);

    /* Print inorder traversal the original tree */
    cout << "Inorder traversal of the origial tree is:" << endl;
    inOrder(root);

    /* Convert the original tree to its mirror image */
    flip(root);
    cout<<endl;

    /* Print inorder traversal of the mirror image of the original tree */
    cout << "Inorder traversal of the mirror image of the original tree is:"<<endl;
    inOrder(root);
    cout<<endl;
    cout<<endl;

}

void testcase2()
{
    cout<<"The test case2:"<<endl;
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    /* Print inorder traversal the original tree */
    cout << "Inorder traversal of the origial tree is:" << endl;
    inOrder(root);

    /* Convert the original tree to its mirror image */
    flip(root);
    cout<<endl;

    /* Print inorder traversal of the mirror image of the original tree */
    cout << "Inorder traversal of the mirror image of the original tree is:"<<endl;
    inOrder(root);
    cout<<endl;
    cout<<endl;

}

void testcase3()
{
    cout<<"The test case3:"<<endl;
    struct Node *root = newNode(13);
    root->left = newNode(10);
    root->right = newNode(25);
    root->left->left = newNode(2);
    root->left->right = newNode(12);
    root->right->left = newNode(20);
    root->right->right = newNode(31);
    root->right->right->left = newNode(29);

    /* Print inorder traversal the original tree */
    cout << "Inorder traversal of the origial tree is:" << endl;
    inOrder(root);

    /* Convert the original tree to its mirror image */
    flip(root);
    cout<<endl;

    /* Print inorder traversal of the mirror image of the original tree */
    cout << "Inorder traversal of the mirror image of the original tree is:"<<endl;
    inOrder(root);
    cout<<endl;
    cout<<endl;

}

void testcase4()
{
    cout<<"The test case4:"<<endl;
    struct Node *root = newNode(15);
    root->left = newNode(4);
    root->right = newNode(20);
    root->left->left = newNode(1);
    root->right->left = newNode(16);
    root->right->right = newNode(25);

    /* Print inorder traversal the original tree */
    cout << "Inorder traversal of the origial tree is:" << endl;
    inOrder(root);

    /* Convert the original tree to its mirror image */
    flip(root);
    cout<<endl;

    /* Print inorder traversal of the mirror image of the original tree */
    cout << "Inorder traversal of the mirror image of the original tree is:"<<endl;
    inOrder(root);
    cout<<endl;
    cout<<endl;

}

void testcase5()
{
    cout<<"The test case5:"<<endl;
    struct Node *root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(18);
    root->left->left = newNode(-4);
    root->left->right = newNode(3);
    root->right->right = newNode(21);
    root->right->right->left = newNode(19);
    root->right->right->right = newNode(25);

    /* Print inorder traversal the original tree */
    cout << "Inorder traversal of the origial tree is:" << endl;
    inOrder(root);

    /* Convert the original tree to its mirror image */
    flip(root);
    cout<<endl;

    /* Print inorder traversal of the mirror image of the original tree */
    cout << "Inorder traversal of the mirror image of the original tree is:"<<endl;
    inOrder(root);
    cout<<endl;
    cout<<endl;

}




int main()
{
    testcase1();
    cout<<"**********************************************************"<<endl;
    testcase2();
    cout<<"**********************************************************"<<endl;
    testcase3();
    cout<<"**********************************************************"<<endl;
    testcase4();
    cout<<"**********************************************************"<<endl;
    testcase5();


    return 0;
}
