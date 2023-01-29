//problem 6
#include <iostream>
#include <string>
using namespace std;


class BST{
public:
    string data;
    BST *left = NULL;
    BST *right = NULL;

    BST(string s){
        data = s;
    }
};


int stringTointeger(string str)
{
    int temp = 0;
    for (int i = 0; i < str.length(); i++) {
        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}


int expreEvaluation(BST* root)
{

    if (!root)
        return 0;


    if (!root->left && !root->right)
        return stringTointeger(root->data);


    else{
    int leftValue = expreEvaluation(root->left);

    int rightValue = expreEvaluation(root->right);

    if (root->data=="+")
        return leftValue+rightValue;

    if (root->data=="*")
        return leftValue*rightValue;

    if (root->data=="-")
        return leftValue-rightValue;

    return leftValue/rightValue;}
}


int main()
{
    BST *root = new BST("+");
    root->right = new BST("*");
    root->left= new BST("3");
    root->right->right = new BST("/");
    root->right->left = new BST("4");
    root->right->right->right = new BST("2");
    root->right->right->left= new BST("8");
    cout<<"The evaluation for the expression of test case 1 ----> " ;
    cout << expreEvaluation(root) << endl;
    cout<<endl ;

    delete(root);


    root = new BST("+");
    root->left = new BST("*");
    root->left->left = new BST("5");
    root->left->right = new BST("4");
    root->right = new BST("-");
    root->right->left = new BST("100");
    root->right->right = new BST("/");
    root->right->right->left = new BST("20");
    root->right->right->right = new BST("2");
    cout<<"The evaluation for the expression of test case 2 ----> " ;
    cout << expreEvaluation(root) << endl;
    cout<<endl ;


    root = new BST("+");
    root->left = new BST("*");
    root->right = new BST("/");
    root->left->left = new BST("-");
    root->left->right = new BST("5");
    root->right->left = new BST("21");
    root->right->right = new BST("7");
    root->left->left->left = new BST("10");
    root->left->left->right = new BST("5");
    cout<<"The evaluation for the expression of test case 3 ----> " ;
    cout << expreEvaluation(root) << endl;
    cout<<endl ;


    root = new BST("+");
    root->left = new BST("*");
    root->left->left = new BST("5");
    root->left->right = new BST("4");
    root->right = new BST("-");
    root->right->left = new BST("100");
    root->right->right = new BST("20");
    cout<<"The evaluation for the expression of test case 4 ----> " ;
    cout << expreEvaluation(root) << endl;
    cout<<endl ;


    root = new BST("+");
    root->left = new BST("*");
    root->left->left = new BST("5");
    root->left->right = new BST("4");
    root->right = new BST("/");
    root->right->left = new BST("100");
    root->right->right = new BST("20");
    cout<<"The evaluation for the expression of test case 5 ----> " ;
    cout << expreEvaluation(root) << endl;
    cout<<endl ;





    return 0;
}
