//problem 4
#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    bool isEqual(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr && root2 == nullptr)
        {
            return true;
        }
        else if (root1 == nullptr || root2 == nullptr)
        {
            return false;
        }
        else if (root1 != nullptr && root2 != nullptr)
        {
            if (root1->val == root2->val)
            {
                return isEqual(root1->left, root2->right) &&
                       isEqual(root1->right, root2->left);
            }
            else
            {
                return false;
            }
        }
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        return isEqual(root->left, root->right);


    }
};

int main()
{
    // Test case 1
    Solution S;
    TreeNode *root = new TreeNode(1);
    TreeNode *root2 = new TreeNode(2);
    TreeNode *root3 = new TreeNode(2);
    TreeNode *root4 = new TreeNode(4);
    TreeNode *root5 = new TreeNode(3);
    TreeNode *root6 = new TreeNode(3);
    TreeNode *root7 = new TreeNode(4);
    root->left = root2;
    root->right = root3;
    root->left->left = root5;
    root->left->right = root4;
    root->right->left = root7;
    root->right->right = root6;
    S.isSymmetric(root);
    if (S.isSymmetric(root))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    // Test case 2
    int null;
    TreeNode *rot = new TreeNode(1);
    TreeNode *rot2 = new TreeNode(2);
    TreeNode *rot3 = new TreeNode(2);
    TreeNode *rot4 = new TreeNode(null);
    TreeNode *rot5 = new TreeNode(3);
    TreeNode *rot6 = new TreeNode(null);
    TreeNode *rot7 = new TreeNode(3);
    rot->left = rot2;
    rot->right = rot3;
    rot->left->left = rot5;
    rot->left->right = rot4;
    rot->right->left = rot7;
    rot->right->right = root6;
    S.isSymmetric(rot);
    if (S.isSymmetric(rot))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    // Test case 3
    TreeNode *rot1 = new TreeNode(1);
    TreeNode *rot8 = new TreeNode(3);
    TreeNode *rot9 = new TreeNode(4);
    TreeNode *rot10 = new TreeNode(null);
    TreeNode *rot11 = new TreeNode(2);
    TreeNode *rot12 = new TreeNode(null);
    TreeNode *rot13 = new TreeNode(2);
    rot1->left = rot8;
    rot1->right = rot9;
    rot1->left->left = rot10;
    rot1->left->right = rot11;
    rot1->right->left = rot12;
    rot1->right->right = rot13;
    S.isSymmetric(rot1);
    if (S.isSymmetric(rot1))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    // Test case 4
    TreeNode *root1 = new TreeNode(1);
    TreeNode *root8 = new TreeNode(2);
    TreeNode *root9 = new TreeNode(2);
    TreeNode *root10 = new TreeNode(4);
    TreeNode *root11 = new TreeNode(4);
    root1->left = root8;
    root1->right = root9;
    root1->left->left = root10;
    root1->right->right = root11;
    S.isSymmetric(root1);
    if (S.isSymmetric(root1))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    // Test case 5
    TreeNode *r = new TreeNode(1);
    TreeNode *r2 = new TreeNode(2);
    TreeNode *r3 = new TreeNode(2);
    TreeNode *r4 = new TreeNode(4);
    TreeNode *r5 = new TreeNode(3);

    r->left = r2;
    r->right = r3;
    r->left->left = r5;
    r->left->right = r4;

    S.isSymmetric(r);
    if (S.isSymmetric(r))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
