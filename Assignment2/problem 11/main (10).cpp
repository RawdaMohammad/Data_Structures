//problem 11
#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <cmath>


using namespace std;
template <class T>
class BSTFCI{
    public :
    class BSTNode{
    public:
        T data;
        BSTNode *left;
        BSTNode *right;
    };
    public:
    BSTNode *root=NULL;
    BSTFCI(){};
    BSTFCI(BSTNode *r){root = r;}
    BSTNode *getRoot(){return root;}
    void setRoot(BSTNode *r){root = r;}
    void insert(T data){
        BSTNode *newNode = new BSTNode();
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        if(root == NULL){
            root = newNode;
        }
        else{
            BSTNode *cur = root;
            BSTNode *parent = NULL;
            while(cur != NULL){
                parent = cur;
                if(cur->data > data){
                    cur = cur->left;
                }
                else{
                    cur = cur->right;
                }
            }
            if(parent->data > data){
                parent->left = newNode;
            }
            else{
                parent->right = newNode;
            }
        }
    }


    // write a function to get the height of the tree
    int getHeight(BSTNode *root){
        if(root == NULL){
            return 0;
        }
        else{
            int leftHeight = getHeight(root->left);
            int rightHeight = getHeight(root->right);
            return max(leftHeight, rightHeight) + 1;
        }
    }


bool isBalanced(BSTNode *root){
        if(root == NULL){
            return true;
        }
        else{
            int leftHeight = getHeight(root->left);
            int rightHeight = getHeight(root->right);
            if(abs(leftHeight - rightHeight) > 1){
                return false;
            }
            else{
                return (isBalanced(root->left) && isBalanced(root->right));
            }
        }
    }

bool IdenticalTree(BSTNode * root1, BSTNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    else if (root1 != NULL && root2 == NULL)
        return false;
    else if (root1 == NULL && root2 != NULL)
        return false;
    else {
        if (root1->data == root2->data && IdenticalTree(root1->left, root2->left)
            && IdenticalTree(root1->right, root2->right))
            return true;
        else
            return false;
    }
}


 bool isSubtree(BSTNode *Tree1,BSTNode *Tree2){
    if (Tree2 == NULL)
        return true;

    if (Tree1 == NULL)
        return false;
if(IdenticalTree(Tree1,Tree2)){
    return true;
}
else{
return (isSubtree(Tree1->left,Tree2) ||isSubtree(Tree1->right,Tree2));}
}

 void printRange(BSTNode* r, T l_key, T h_key){
        if (r == NULL){
            return;
        }

        if (r->data > l_key)
            printRange(r->left, l_key, h_key);

        if (r->data >= l_key && r->data <= h_key && l_key != h_key)
            cout <<r->data<<" ";
        if(l_key == h_key){
            cout << "[ ]";
            return;
        }
        printRange(r->right, l_key, h_key);

    }




};


//------------------------------>Is Balanced Test Cases <------------------------------------------------//

void TestCase1isBalanced(){
     BSTFCI<int> bst;
// create the first node of the tree using root
    BSTFCI<int>::BSTNode *root = new BSTFCI<int>::BSTNode();
    root->data = 5;
    root->left = new BSTFCI<int>::BSTNode();
    root->left->data = 3;
    root->right = new BSTFCI<int>::BSTNode();
    root->right->data = 6;
    root->left->left = new BSTFCI<int>::BSTNode();
    root->left->left->data = 1;
    root->left->right = new BSTFCI<int>::BSTNode();
    root->left->right->data = 4;

    bst.setRoot(root);
    if (bst.isBalanced(root))
        cout << "Tree is Balanced"<<endl;
    else
        cout << "Tree is not Balanced"<<endl;

}

void TestCase2isBalanced(){
    BSTFCI<int> bst;
        // enter the values of the tree
    BSTFCI<int>::BSTNode *root = new BSTFCI<int>::BSTNode();
    root->data = 15;
    root->left = new BSTFCI<int>::BSTNode();
    root->left->data = 10;
    root->right = new BSTFCI<int>::BSTNode();
    root->right->data = 25;
    root->left->left = new BSTFCI<int>::BSTNode();
    root->left->left->data = 8;
    root->left->left->right = new BSTFCI<int>::BSTNode();
    root->left->left->right->data = 30;
    root->right->right = new BSTFCI<int>::BSTNode();
    root->right->right->data = 30;
    root->left->right = new BSTFCI<int>::BSTNode();
    root->left->right->data = 12;
    root->right->left = new BSTFCI<int>::BSTNode();
    root->right->left->data = 20;
    root->left->left->left = new BSTFCI<int>::BSTNode();
    root->left->left->left->data = 6;
    root->left->left->right = new BSTFCI<int>::BSTNode();
    root->left->left->right->data = 9;
    root->right->left->left = new BSTFCI<int>::BSTNode();
    root->right->left->left->data = 19;
    root->right->left->right = new BSTFCI<int>::BSTNode();
    root->right->left->right->data = 22;

    bst.setRoot(root);
        if (bst.isBalanced(root))
        cout << "Tree is Balanced"<<endl;
    else
        cout << "Tree is not Balanced"<<endl;

}

void TestCase3isBalanced(){
        // test case 3
        BSTFCI<int> bst;
    BSTFCI<int>::BSTNode *root = new BSTFCI<int>::BSTNode();
    root->data = 15;
    root->left = new BSTFCI<int>::BSTNode();
    root->left->data = 10;
    root->right = new BSTFCI<int>::BSTNode();
    root->right->data = 25;
    root->left->left = new BSTFCI<int>::BSTNode();
    root->left->left->data = 8;
    root->left->left->right = new BSTFCI<int>::BSTNode();
    root->left->left->right->data = 30;
    root->right->right = new BSTFCI<int>::BSTNode();
    root->right->right->data = 30;
    root->left->right = new BSTFCI<int>::BSTNode();
    root->left->right->data = 12;
    root->right->left = new BSTFCI<int>::BSTNode();
    root->right->left->data = 20;
    root->left->left->left = new BSTFCI<int>::BSTNode();
    root->left->left->left->data = 6;
    root->left->left->right = new BSTFCI<int>::BSTNode();
    root->left->left->right->data = 9;
    root->right->left->left = new BSTFCI<int>::BSTNode();
    root->right->left->left->data = 19;
    root->right->left->right = new BSTFCI<int>::BSTNode();
    root->right->left->right->data = 22;
    root->left->left->left->left = new BSTFCI<int>::BSTNode();
    root->left->left->left->left->data = 5;


    bst.setRoot(root);
    if (bst.isBalanced(root))
        cout << "Tree is Balanced"<<endl;
    else
        cout << "Tree is not Balanced"<<endl;
}

void TestCase4isBalanced(){
        // test case 3
        BSTFCI<int> bst;
       BSTFCI<int>::BSTNode *root = new BSTFCI<int>::BSTNode();
    root->data = 5;
    root->left = new BSTFCI<int>::BSTNode();
    root->left->data = 3;
    root->right = new BSTFCI<int>::BSTNode();
    root->right->data = 6;
    root->left->left = new BSTFCI<int>::BSTNode();
    root->left->left->data = 1;
    root->left->right = new BSTFCI<int>::BSTNode();
    root->left->right->data = 4;
    root->left->left->right = new BSTFCI<int>::BSTNode();
    root->left->left->right->data = 2;




    bst.setRoot(root);
    if (bst.isBalanced(root))
        cout << "Tree is Balanced"<<endl;
    else
        cout << "Tree is not Balanced"<<endl;
}

void TestCase5isBalanced(){
        // test case 3
        BSTFCI<int> bst;
       BSTFCI<int>::BSTNode *root = new BSTFCI<int>::BSTNode();
    root->data = 5;
    root->left = new BSTFCI<int>::BSTNode();
    root->left->data = 3;
    root->right = new BSTFCI<int>::BSTNode();
    root->right->data = 6;
    root->left->left = new BSTFCI<int>::BSTNode();
    root->left->left->data = 1;
    root->left->right = new BSTFCI<int>::BSTNode();
    root->left->right->data = 4;
    root->left->left->right = new BSTFCI<int>::BSTNode();
    root->left->left->right->data = 2;
    root->right->right = new BSTFCI<int>::BSTNode();
    root->right->right->data = 7;





    bst.setRoot(root);
    if (bst.isBalanced(root))
        cout << "Tree is Balanced"<<endl;
    else
        cout << "Tree is not Balanced"<<endl;
}

//---------------------------------->Sub Tree Test Cases <--------------------------------------------------//

void TestCase1SubTree (){
    BSTFCI<int> bst;

    BSTFCI<int>::BSTNode *root = new BSTFCI<int>::BSTNode();
    root->data = 15;
    root->left = new BSTFCI<int>::BSTNode();
    root->left->data = 10;
    root->right = new BSTFCI<int>::BSTNode();
    root->right->data = 25;
    root->left->left = new BSTFCI<int>::BSTNode();
    root->left->left->data = 8;
    root->left->left->right = new BSTFCI<int>::BSTNode();
    root->left->left->right->data = 30;
    root->right->right = new BSTFCI<int>::BSTNode();
    root->right->right->data = 30;
    root->left->right = new BSTFCI<int>::BSTNode();
    root->left->right->data = 12;
    root->right->left = new BSTFCI<int>::BSTNode();
    root->right->left->data = 20;
    root->left->left->left = new BSTFCI<int>::BSTNode();
    root->left->left->left->data = 6;
    root->left->left->right = new BSTFCI<int>::BSTNode();
    root->left->left->right->data = 9;
    root->right->left->left = new BSTFCI<int>::BSTNode();
    root->right->left->left->data = 19;
    root->right->left->right = new BSTFCI<int>::BSTNode();
    root->right->left->right->data = 22;


    // enter the values of the tree
    BSTFCI<int>::BSTNode *root2 = new BSTFCI<int>::BSTNode();
    root2->data = 10;
    root2->left = new BSTFCI<int>::BSTNode();
    root2->left->data = 8;
    root2->right = new BSTFCI<int>::BSTNode();
    root2->right->data = 12;
    root2->left->right = new BSTFCI<int>::BSTNode();
    root2->left->right->data = 9;
    root2->left->left = new BSTFCI<int>::BSTNode();
    root2->left->left->data = 6;


    if (bst.isSubtree(root, root2))
        cout << "Tree 2 is subtree of Tree 1"<<endl;
    else
        cout << "Tree 2 is not a subtree of Tree 1"<<endl;
}

void TestCase2SubTree (){
    BSTFCI<int> bst;

    BSTFCI<int>::BSTNode *root = new BSTFCI<int>::BSTNode();
    root->data = 15;
    root->left = new BSTFCI<int>::BSTNode();
    root->left->data = 10;
    root->right = new BSTFCI<int>::BSTNode();
    root->right->data = 25;
    root->left->left = new BSTFCI<int>::BSTNode();
    root->left->left->data = 8;
    root->left->left->right = new BSTFCI<int>::BSTNode();
    root->left->left->right->data = 30;
    root->right->right = new BSTFCI<int>::BSTNode();
    root->right->right->data = 30;
    root->left->right = new BSTFCI<int>::BSTNode();
    root->left->right->data = 12;
    root->right->left = new BSTFCI<int>::BSTNode();
    root->right->left->data = 20;
    root->left->left->left = new BSTFCI<int>::BSTNode();
    root->left->left->left->data = 6;
    root->left->left->right = new BSTFCI<int>::BSTNode();
    root->left->left->right->data = 9;
    root->right->left->left = new BSTFCI<int>::BSTNode();
    root->right->left->left->data = 19;
    root->right->left->right = new BSTFCI<int>::BSTNode();
    root->right->left->right->data = 22;


    // enter the values of the tree
    BSTFCI<int>::BSTNode *root2 = new BSTFCI<int>::BSTNode();
    root2->data = 10;
    root2->left = new BSTFCI<int>::BSTNode();
    root2->left->data = 8;
    root2->right = new BSTFCI<int>::BSTNode();
    root2->right->data = 12;
    root2->left->right = new BSTFCI<int>::BSTNode();
    root2->left->right->data = 9;
    root2->left->left = new BSTFCI<int>::BSTNode();
    root2->left->left->data = 6;
    root2->left->left->left = new BSTFCI<int>::BSTNode();
    root2->left->left->left->data = 5;

    if (bst.isSubtree(root, root2))
        cout << "Tree 2 is subtree of Tree 1"<<endl;
    else
        cout << "Tree 2 is not a subtree of Tree 1"<<endl;
}

void TestCase3SubTree (){


    BSTFCI<int> bst;

    BSTFCI<int>::BSTNode *root = new BSTFCI<int>::BSTNode();
    root->data = 15;
    root->left = new BSTFCI<int>::BSTNode();
    root->left->data = 10;
    root->right = new BSTFCI<int>::BSTNode();
    root->right->data = 25;
    root->left->left = new BSTFCI<int>::BSTNode();
    root->left->left->data = 8;
    root->left->left->right = new BSTFCI<int>::BSTNode();
    root->left->left->right->data = 30;
    root->right->right = new BSTFCI<int>::BSTNode();
    root->right->right->data = 30;
    root->left->right = new BSTFCI<int>::BSTNode();
    root->left->right->data = 12;
    root->right->left = new BSTFCI<int>::BSTNode();
    root->right->left->data = 20;
    root->left->left->left = new BSTFCI<int>::BSTNode();
    root->left->left->left->data = 6;
    root->left->left->right = new BSTFCI<int>::BSTNode();
    root->left->left->right->data = 9;
    root->right->left->left = new BSTFCI<int>::BSTNode();
    root->right->left->left->data = 18;
    root->right->left->right = new BSTFCI<int>::BSTNode();
    root->right->left->right->data = 22;

    // enter the values of the tree
    BSTFCI<int>::BSTNode *root2 = new BSTFCI<int>::BSTNode();
    root2->data = 25;
    root2->left = new BSTFCI<int>::BSTNode();
    root2->left->data = 20;
    root2->right = new BSTFCI<int>::BSTNode();
    root2->right->data = 30;
    root2->left->right = new BSTFCI<int>::BSTNode();
    root2->left->right->data = 22;
    root2->left->left = new BSTFCI<int>::BSTNode();
    root2->left->left->data = 18;


    if (bst.isSubtree(root, root2))
        cout << "Tree 2 is subtree of Tree 1"<<endl;
    else
        cout << "Tree 2 is not a subtree of Tree 1"<<endl;
}

void TestCase4SubTree (){

BSTFCI<int> bst;

    BSTFCI<int>::BSTNode *root = new BSTFCI<int>::BSTNode();
    root->data = 8;
    root->left = new BSTFCI<int>::BSTNode();
    root->left->data = 3;
    root->right = new BSTFCI<int>::BSTNode();
    root->right->data = 10;
    root->left->left = new BSTFCI<int>::BSTNode();
    root->left->left->data = 1;
    root->left->right = new BSTFCI<int>::BSTNode();
    root->left->right->data = 6;
    root->left->right->left = new BSTFCI<int>::BSTNode();
    root->left->right->left->data = 4;
    root->left->right->right = new BSTFCI<int>::BSTNode();
    root->left->right->right->data = 7;
    root->right->right = new BSTFCI<int>::BSTNode();
    root->right->right->data = 14;



    // enter the values of the tree
    BSTFCI<int>::BSTNode *root2 = new BSTFCI<int>::BSTNode();
    root2->data = 25;
    root2->right = new BSTFCI<int>::BSTNode();
    root2->right->data = 10;



    if (bst.isSubtree(root, root2))
        cout << "Tree 2 is subtree of Tree 1"<<endl;
    else
        cout << "Tree 2 is not a subtree of Tree 1"<<endl;
}

void TestCase5SubTree (){
BSTFCI<int> bst;

    BSTFCI<int>::BSTNode *root = new BSTFCI<int>::BSTNode();
    root->data = 8;
    root->left = new BSTFCI<int>::BSTNode();
    root->left->data = 3;
    root->right = new BSTFCI<int>::BSTNode();
    root->right->data = 10;
    root->left->left = new BSTFCI<int>::BSTNode();
    root->left->left->data = 1;
    root->left->right = new BSTFCI<int>::BSTNode();
    root->left->right->data = 6;
    root->left->right->left = new BSTFCI<int>::BSTNode();
    root->left->right->left->data = 4;
    root->left->right->right = new BSTFCI<int>::BSTNode();
    root->left->right->right->data = 7;
    root->right->right = new BSTFCI<int>::BSTNode();
    root->right->right->data = 14;



    // enter the values of the tree
    BSTFCI<int>::BSTNode *root2 = new BSTFCI<int>::BSTNode();
    root2->data = 10;
    root2->right = new BSTFCI<int>::BSTNode();
    root2->right->data = 14;



    if (bst.isSubtree(root, root2))
        cout << "Tree 2 is subtree of Tree 1"<<endl;
    else
        cout << "Tree 2 is not a subtree of Tree 1"<<endl;
}

//----------------------------------> Print in range Test Cases <--------------------------------------------------//

void TestCase1_printRange(){
    cout << "Test case 1: ";
    BSTFCI<int> bst;
// create the first node of the tree using root
    BSTFCI<int>::BSTNode *root = new BSTFCI<int>::BSTNode();
    root->data = 5;
    root->left = new BSTFCI<int>::BSTNode();
    root->left->data = 3;
    root->right = new BSTFCI<int>::BSTNode();
    root->right->data = 7;
    root->left->left = new BSTFCI<int>::BSTNode();
    root->left->left->data = 2;
    root->left->right = new BSTFCI<int>::BSTNode();
    root->left->right->data = 4;
    root->right->right = new BSTFCI<int>::BSTNode();
    root->right->right->data = 9;
    root->left->left->left = new BSTFCI<int>::BSTNode();
    root->left->left->left->data = 1;
    root->right->right->right = new BSTFCI<int>::BSTNode();
    root->right->right->right->data = 10;
    root->right->right->left = new BSTFCI<int>::BSTNode();
    root->right->right->left->data = 8;
    bst.setRoot(root);

    cout<<"[ " ;
    bst.printRange(root, 8, 15);
    cout<<"]" ;
    cout<<endl ;
    cout<<endl ;

}

void TestCase2_printRange(){
    cout << "Test case 2: ";
    BSTFCI<int> bst;
    BSTFCI<int>::BSTNode *root = new BSTFCI<int>::BSTNode();
    root->data = 5;
    root->left = new BSTFCI<int>::BSTNode();
    root->left->data = 3;
    root->right = new BSTFCI<int>::BSTNode();
    root->right->data = 7;
    root->left->left = new BSTFCI<int>::BSTNode();
    root->left->left->data = 2;
    root->left->right = new BSTFCI<int>::BSTNode();
    root->left->right->data = 4;
    root->right->right = new BSTFCI<int>::BSTNode();
    root->right->right->data = 9;
    root->left->left->left = new BSTFCI<int>::BSTNode();
    root->left->left->left->data = 1;
    root->right->right->right = new BSTFCI<int>::BSTNode();
    root->right->right->right->data = 10;
    root->right->right->left = new BSTFCI<int>::BSTNode();
    root->right->right->left->data = 8;
    bst.setRoot(root);


    bst.printRange(root, 6, 6);
    cout<<endl ;
    cout<<endl ;

}

void TestCase3_printRange(){
    cout << "Test case 3: ";
    BSTFCI<int> bst;
    BSTFCI<int>::BSTNode *root3 = new BSTFCI<int>::BSTNode();
    root3->data = 10;
    root3->left = new BSTFCI<int>::BSTNode();
    root3->left->data = 8;
    root3->right = new BSTFCI<int>::BSTNode();
    root3->right->data = 14;
    root3->left->left = new BSTFCI<int>::BSTNode();
    root3->left->left->data = 5;
    root3->left->right = new BSTFCI<int>::BSTNode();
    root3->left->right->data = 9;
    root3->right->right = new BSTFCI<int>::BSTNode();
    root3->right->right->data = 20;
    root3->left->left->left = new BSTFCI<int>::BSTNode();
    root3->left->left->left->data = 3;
    root3->right->right->right = new BSTFCI<int>::BSTNode();
    root3->right->right->right->data = 22;
    root3->right->right->left = new BSTFCI<int>::BSTNode();
    root3->right->right->left->data = 19;
    bst.setRoot(root3);
    cout<<"[ " ;
    bst.printRange(root3, 3, 10);
    cout<<"]" ;
    cout<<endl ;
    cout<<endl ;
}

void TestCase4_printRange(){
    cout << "Test case 4: ";

    BSTFCI<int> bst;
    BSTFCI<int>::BSTNode *root4 = new BSTFCI<int>::BSTNode();
    root4->data = 10;
    root4->left = new BSTFCI<int>::BSTNode();
    root4->left->data = 8;
    root4->right = new BSTFCI<int>::BSTNode();
    root4->right->data = 14;
    root4->left->left = new BSTFCI<int>::BSTNode();
    root4->left->left->data = 5;
    root4->left->right = new BSTFCI<int>::BSTNode();
    root4->left->right->data = 9;
    root4->right->right = new BSTFCI<int>::BSTNode();
    root4->right->right->data = 20;
    root4->left->left->left = new BSTFCI<int>::BSTNode();
    root4->left->left->left->data = 3;
    root4->right->right->right = new BSTFCI<int>::BSTNode();
    root4->right->right->right->data = 22;
    root4->right->right->left = new BSTFCI<int>::BSTNode();
    root4->right->right->left->data = 19;
    bst.setRoot(root4);

    cout<<"[ " ;
    bst.printRange(root4, 10, 20) ;
    cout<<"]" ;
    cout<<endl ;
    cout<<endl ;
}

void TestCase5_printRange(){
    cout << "Test case 5: ";

    BSTFCI<int> bst;
    BSTFCI<int>::BSTNode *root5 = new BSTFCI<int>::BSTNode();
    root5->data = 10;
    root5->left = new BSTFCI<int>::BSTNode();
    root5->left->data = 8;
    root5->right = new BSTFCI<int>::BSTNode();
    root5->right->data = 14;
    root5->left->left = new BSTFCI<int>::BSTNode();
    root5->left->left->data = 5;
    root5->left->right = new BSTFCI<int>::BSTNode();
    root5->left->right->data = 9;
    root5->right->right = new BSTFCI<int>::BSTNode();
    root5->right->right->data = 20;
    root5->left->left->left = new BSTFCI<int>::BSTNode();
    root5->left->left->left->data = 3;
    root5->right->right->right = new BSTFCI<int>::BSTNode();
    root5->right->right->right->data = 22;
    root5->right->right->left = new BSTFCI<int>::BSTNode();
    root5->right->right->left->data = 19;
    bst.setRoot(root5);

    cout<<"[ " ;
    bst.printRange(root5, 7, 8);
    cout<<"]" ;
    cout<<endl ;
    cout<<endl ;
}




int main(){

BSTFCI<int> bst;
cout<<"//----------> Is Balanced Test Cases <------------------------//" <<endl<<endl;
    TestCase1isBalanced();
    TestCase2isBalanced();
    TestCase3isBalanced();
    TestCase4isBalanced();
    TestCase5isBalanced();

    cout<<endl ;


cout<<"//----------> Sub Tree Test Cases <------------------------//" <<endl<<endl;
    TestCase1SubTree();
    TestCase2SubTree();
    TestCase3SubTree();
    TestCase4SubTree();
    TestCase5SubTree();

    cout<<endl ;

cout<<"//----------> Print in range Test Cases <------------------------//" <<endl<<endl;
    TestCase1_printRange();
    TestCase2_printRange();
    TestCase3_printRange();
    TestCase4_printRange();
    TestCase5_printRange();

    cout<<endl ;

    return 0;





}
