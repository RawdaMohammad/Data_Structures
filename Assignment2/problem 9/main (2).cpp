//problem 9
#include <iostream>


using namespace std;
class node{
public:
    int data;
    node * left;
    node * right;
    node(int Data)
    {
        data = Data;
        left = NULL;
        right = NULL;
    }
};

bool foldable(node* first, node* second)
{
	if (first == NULL && second == NULL) {
		return true;
	}
	else if (first == NULL || second == NULL){
        return false;
	}

    if(foldable(first->left, second->right) && foldable(first->right, second->left))
        return true;
    return false;
}
bool isfoldable(node*root){
    if(root == NULL)
        return true;
    return (foldable(root->left, root->right));
}
void test1(){
    //Expected output is => Tree is foldable
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->right = new node(3);
    root->right->right = new node(5);

    if(isfoldable(root)){
        cout << "Tree is foldable\n" ;
    }else
        cout << "Tree is not foldable\n" ;
}
void test2(){
    //Expected output is => Tree is not foldable
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(7);
    root->right = new node(3);
    root->right->right = new node(5);

    if(isfoldable(root)){
        cout << "Tree is foldable\n" ;
    }else
        cout << "Tree is not foldable\n" ;
}
void test3(){
    //Expected output is => Tree is foldable
    node* root = new node(1);
    root->left = new node(2);
    root->left->right = new node(4);
    root->right = new node(3);
    root->right->left = new node(5);

    if(isfoldable(root)){
        cout << "Tree is foldable\n" ;
    }else
        cout << "Tree is not foldable\n" ;
}
void test4(){
    //Expected output is => Tree is foldable
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(7);
    root->right = new node(3);
    root->right->right = new node(5);
    root->right->left = new node(10);

    if(isfoldable(root)){
        cout << "Tree is foldable\n" ;
    }else
        cout << "Tree is not foldable\n" ;
}
void test5(){
    //Expected output is => Tree is not foldable
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(7);
    root->right = new node(3);

    if(isfoldable(root)){
        cout << "Tree is foldable\n" ;
    }else
        cout << "Tree is not foldable\n" ;
}
int main()
{
    cout << "Test case 1 \n";
    test1();
    cout << endl;

    cout << "Test case 2 \n";
    test2();
    cout << endl;

    cout << "Test case 3 \n";
    test3();
    cout << endl;

    cout << "Test case 4 \n";
    test4();
    cout << endl;

    cout << "Test case 5 \n";
    test5();
    cout << endl;

    return 0;
}
