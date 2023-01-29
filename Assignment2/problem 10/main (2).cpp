//problem 10
#include <iostream>
#include <vector>

using namespace std;
class node{
public:
    int data;
    node * left, * right;

};

node* Insert(int data)
{
    node* temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
vector<int>v;

void storeTree(node * root){
    if(root == NULL){
        return;
    }

    storeTree(root->left);

    v.push_back(root->data) ;

    storeTree(root->right);


}
int sum(int k){
    int result = 0;
    if(k > v.size()){
        cout << "Error\n";
        return 0;
    }

    for(int j=0; j<k; j++){
        result += v[j];
    }
    v.clear();
    return result;
}
void test1(){
    //Expected output is => 152
    cout << "Test case 1 \n";
    int k = 3;
    node * root = Insert(54);
    root->left = Insert(51);
    root->left->left = Insert(49);
    root->left->right = Insert(52);

    root->right = Insert(75);
    root->right->left = Insert(74);
    root->right->right = Insert(85);
    storeTree(root);

    cout << "the sum of all the elements which is less or equal to the " << k <<
     "th smallest "<< sum(k) << endl;

}
void test2(){
    //Expected output is => 22
    cout << "Test case 2 \n";
    int k = 3;
    node * root = Insert(10);
    root->left = Insert(8);
    root->left->left = Insert(5);
    root->left->right = Insert(9);

    root->right = Insert(15);
    root->right->left = Insert(12);
    root->right->right = Insert(20);
    storeTree(root);

    cout << "the sum of all the elements which is less or equal to the " << k <<
     "th smallest "<< sum(k) << endl;

}
void test3(){
    //Expected output is => 280
    cout << "Test case 3 \n";
    int k = 5;
    node * root = Insert(54);
    root->left = Insert(51);
    root->left->left = Insert(49);
    root->left->right = Insert(52);

    root->right = Insert(75);
    root->right->left = Insert(74);
    root->right->right = Insert(85);
    storeTree(root);

    cout << "the sum of all the elements which is less or equal to the " << k <<
     "th smallest "<< sum(k) << endl;

}
void test4(){
    //Expected output is => 32
    cout << "Test case 4 \n";
    int k = 4;
    node * root = Insert(10);
    root->left = Insert(8);
    root->left->left = Insert(5);
    root->left->right = Insert(9);

    root->right = Insert(15);
    root->right->left = Insert(12);
    root->right->right = Insert(20);
    storeTree(root);

    cout << "the sum of all the elements which is less or equal to the " << k <<
     "th smallest "<< sum(k) << endl;

}
void test5(){
    //Expected output is => 29
    cout << "Test case 5 \n";
    int k = 2;
    node * root = Insert(50);
    root->left = Insert(19);
    root->left->left = Insert(10);
    root->left->right = Insert(30);

    root->right = Insert(70);
    root->right->left = Insert(60);
    root->right->right = Insert(85);
    storeTree(root);

    cout << "the sum of all the elements which is less or equal to the " << k <<
     "th smallest "<< sum(k) << endl;

}
int main()
{

    test1();
    cout<<endl ;
    test2();
    cout<<endl ;
    test3();
    cout<<endl ;
    test4();
    cout<<endl ;
    test5();



    return 0;
}
