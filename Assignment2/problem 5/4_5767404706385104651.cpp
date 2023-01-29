//problem 5
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
     public: bool isSameTree(TreeNode* p, TreeNode* q) {
         // check if the two trees are the same
            if(p == nullptr && q == nullptr){
                return true;
            }
            if(p == nullptr || q == nullptr){
                return false;
            }
            // check if the value of every element in the 2 trees  are the same
            for(int i = 0; i < 2; i++){
                if(p->val != q->val){
                    return false;
                }
            }
            // check if the left subtree is the same
            if(isSameTree(p->left, q->left) == false){
                return false;
            }
            // check if the right subtree is the same
            if(isSameTree(p->right, q->right) == false){
                return false;
            }
            return true;
            if (isSameTree(nullptr, nullptr)) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }







     }

     };

int main(){
    Solution s;
    //first test case.
    int x[] = {1,2,3};
    int y[] = {1,2,3};
    TreeNode* x1 = new TreeNode(x[0]);
    TreeNode* y1 = new TreeNode(y[0]);
    TreeNode* x2 = new TreeNode(x[1]);
    TreeNode* y2 = new TreeNode(y[1]);
    TreeNode* x3 = new TreeNode(x[2]);
    TreeNode* y3 = new TreeNode(y[2]);
    x1->left = x2;
    x1->right = x3;
    y1->left = y2;
    y1->right = y3;
    s.isSameTree(x1, y1) ;
    if (s.isSameTree(x1, y1)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    //second test case.
    int null ;
    int a[] = {1,2};
    int b[] = {1,null,2};
    TreeNode* a1 = new TreeNode(a[0]);
    TreeNode* b1 = new TreeNode(b[0]);
    TreeNode* a2 = new TreeNode(a[1]);
    TreeNode* b2 = nullptr;
    TreeNode* a3 = nullptr;
    TreeNode* b3 = new TreeNode(b[2]);
    a1->left = a2;
    b1->left = b2;
    s.isSameTree(a1, b1) ;
    if (s.isSameTree(a1, b1)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    //third test case.
    int p[] = {1,2,1};
    int q[] = {1,1,2};
    TreeNode* p1 = new TreeNode(p[0]);
    TreeNode* q1 = new TreeNode(q[0]);
    TreeNode* p2 = new TreeNode(p[1]);
    TreeNode* q2 = new TreeNode(q[1]);
    TreeNode* p3 = new TreeNode(p[2]);
    TreeNode* q3 = new TreeNode(q[2]);
    p1->left = p2;
    p1->right = p3;
    q1->left = q2;
    q1->right = q3;
    s.isSameTree(p1, q1);
    // if the two trees are the same return "true" else return "false"
    if (s.isSameTree(p1, q1)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }



    return 0;








}
