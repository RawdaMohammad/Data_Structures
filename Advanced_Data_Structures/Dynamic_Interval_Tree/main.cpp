#include <iostream>
using namespace std;
int numOfNodes = 0; //number of nodes in interval tree
//class node for interval tree
class Node
{
public:
    Node * left; //pointer to left child of node
    Node* right; //pointer to right child of node
    int highInterval; //high Interval for each node
    int lowInterval; //low Interval for each node
    int maximum; //maximum number for each node
    // parametrize constructor to set values of high and low interval and to set maximum initially equals high interval
    Node(int lowInterval, int highInterval)
    {
        left = NULL; //set left child equals null
        right = NULL; //set right child equals null
        this->highInterval = highInterval; //set high Interval
        this->lowInterval = lowInterval; //set low Interval
        maximum = highInterval;          //set maximum initially equals high interval
    }
    //default constructor
    Node()
    {
        left = NULL; //set left child equals null
        right = NULL; //set right child equals null
        highInterval = 0; //set high Interval equal zero
        lowInterval = 0;  //set high Interval equal zero
        maximum = highInterval; //set maximum initially equals high interval
    }
    //insert function to insert interval in our tree
    Node* InsertInterval(Node * root, int lowInterval, int highInterval)
    {
        if(root == NULL) //base case for recursion no childerns
        {
            Node* newNode = new Node(lowInterval, highInterval); //create new node sets the high and low interval
            numOfNodes++; //count number of inserted node
            return newNode; //return the node
        }
        if(lowInterval < root->lowInterval) //if low of inserted node less than low of the root
        {
            root->left = InsertInterval(root->left, lowInterval, highInterval); //make the new node the left child of the root
            if(root->maximum > root->left->maximum) //if maximum of root greater than maximum of the left
            {
                root->maximum= root->maximum;            //so the maximum of the root will be the same
            }
            else
            {
                root->maximum = root->left->maximum ; //the maximum of the root will be the maximum of the left child
            }
        }
        else if(lowInterval > root->lowInterval) //if low of inserted node greater than low of the root
        {
            root->right = InsertInterval(root->right, lowInterval, highInterval); //make the new node the right child of the root
            if(root->maximum > root->right->maximum) //if maximum of root greater than maximum of the right
            {
                root->maximum= root->maximum;         //so the maximum of the root will be the same
            }
            else
            {
                root->maximum = root->right->maximum ; // the maximum of the root will be the maximum of the right child
            }
        }
        return root; //return root of our interval tree
    }
    //function to check if the query interval overlaps with any interval in our interval tree
    bool overlaps(int qLow, int qHigh, int NodeLow, int NodeHigh)
    {
        if(qLow <= NodeHigh && NodeLow <= qHigh) //overlapping condition
            return true; //if overlaps
        return false; //if not overlaps
    }
    //function to getPredecessor
    Node* getPredecessor (Node* root)
    {
        while(root->right != NULL) //if not leave node go right so on
        {
            root = root->right;
        }
        return root; //return most right(in left subtree) in our tree interval
    }
    //function to travels in our tree
    Node* traverseTree(Node* root, int lowInterval, int highInterval)
    {
        if(root == NULL) //base case if arrive leaf node
            return root; //return root of the tree
        if(lowInterval < root->lowInterval) //if low of inserted node less than low of the root
        {
            root->left = traverseTree(root->left, lowInterval, highInterval); //make the new node the left child of the root
            if(root->maximum > root->left->maximum) //if maximum of root greater than maximum of the left
            {
                root->maximum= root->maximum; //so the maximum of the root will be the same
            }
            else
            {
                root->maximum = root->left->maximum ; //the maximum of the root will be the maximum of the left child
            }
        }
        else if(lowInterval > root->lowInterval) //if low of inserted node greater than low of the root
        {
            root->right = traverseTree(root->right, lowInterval, highInterval); //make the new node the right child of the root
            if(root->maximum > root->right->maximum) //if maximum of root greater than maximum of the right
            {
                root->maximum = root->maximum;       //so the maximum of the root will be the same
            }
            else
            {
                root->maximum = root->right->maximum ; // the maximum of the root will be the maximum of the right child
            }
        }
        return root; //return root of our interval tree
    }
    //function to delete overlapping interval
    Node* DeleteInterval(Node * root, int low)
    {
        if(root == NULL) //base case if arrive leaf node
        {
            root = root->traverseTree(root, root->lowInterval, root->highInterval);
            return root;
        }
        else if(low < root->lowInterval) //if low less low of root
            root->left = DeleteInterval (root->left, low); //call function again(recursion) to left subtree
        else if (low > root->lowInterval) //if low greater low of root
            root->right = DeleteInterval (root->right, low); //call function again(recursion) to right subtree
        else
        {
            if(root->left == NULL && root->right == NULL) //case if root has no children
            {
                delete root; //so delete node
                root = NULL; //set location of root points to null
            }
            else if(root->left == NULL) //case if root has one children(right children)
            {
                Node* temp = root; //make temp equals root
                root = root->right; //make root equals to the right child
                delete temp; //delete temp
                temp = NULL; //set location of temp points to null
            }
            else if(root->right == NULL) //case if root has one children(left children)
            {
                Node* temp = root; //make temp equals root
                root = root->left; //make root equals to the left child
                delete temp; //delete temp
                temp = NULL; //set location of temp points to null
            }
            else  //case if root has two children
            {
                Node* temp = getPredecessor(root->left); //temp equals Predecessor of the root
                root->lowInterval = temp->lowInterval; //set low interval of root equals to low interval of temp
                root->highInterval = temp->highInterval; //set high interval of root equals to high interval of temp
                root->maximum = temp->maximum; //set maximum of root equals to maximum of temp
                root->left = DeleteInterval(root->left, temp->lowInterval); //call function again to left subtree
            }
        }
        return root; //return root of our interval tree
    }
    //function to search if the interval overlapping or not
    Node* SearchInterval(Node * root, int low, int high)
    {
        if (root == NULL) //base case if arrive leaf node
            return NULL;
        Node* result; //to initialize overlapping result
        if (low <= root->maximum) //if the low of the queryInterval less than maximum of root
        {
            result = SearchInterval(root->left, low, high); //call function again to left subtree
            if (result != NULL) //if found overlapping interval in left subtree
                return result;   //so return this overlapping interval

            else if (overlaps(low, high, root->lowInterval, root->highInterval))//check if the query interval overlaps with any interval in our interval tree
                return root; //return the root
            else
               return NULL; //else return null
        }
        else //if the low of the queryInterval greater than maximum of root
        {
            if (overlaps(low, high, root->lowInterval, root->highInterval)) //check if the query interval overlaps with any interval in our interval tree
                return root; //return the root
            else
                return SearchInterval(root->right, low, high); //call function again to right subtree
        }
    }
    //function to insert overlapping nodes which deleted again
    Node * ION(Node* root , Node* arr,int size1)
    {
        for(int j=0; j<size1; j++) //for loop to iterate to the number of overlapping nodes
            root = root->InsertInterval(root, arr[j].lowInterval, arr[j].highInterval); //insert overlapping nodes
        return root ;
    }
};

int main()
{
    Node* root = NULL;
    Node* newNode;
    root = root->InsertInterval(root, 5, 10);
    root->InsertInterval(root, 3, 8);
    root->InsertInterval(root, 10, 15);
    root->InsertInterval(root, 16, 18);
    root->InsertInterval(root, 9, 11);
    root->InsertInterval(root, 1, 1);
    Node* arr = new Node[numOfNodes];
    newNode = root->SearchInterval(root, 6, 20); //[3,8][5,10][9,11][10,15][16,18]
//    newNode = root->SearchInterval(root, 1, 1); //[1,1]
//    newNode = root->SearchInterval(root, 3, 8);//[3,8][5,10]
//    newNode = root->SearchInterval(root, 1, 2);//[1,1]
//    newNode = root->SearchInterval(root, 5 ,15 );//[5,10][3,8][10,15][9,11]
//    newNode = root->SearchInterval(root, 10, 14);//[5,10][10,15][9,11]
//    newNode = root->SearchInterval(root, 4, 6);//[5,10][3,8]
//    newNode = root->SearchInterval(root, 3, 9);//[3,8][5,10][9,11]
//    newNode = root->SearchInterval(root, 9, 12);//[5,10][10,15][9,11]
//    newNode = root->SearchInterval(root, 8,9); //[3,8][9,11][5,10]
    int i = 0;
    cout << "Overlapping intervals\n\n";
    while(newNode != NULL)
    {
        arr[i++] = Node(newNode->lowInterval, newNode->highInterval);
        cout << "[ " << newNode->lowInterval << " , " << newNode->highInterval << " ]"<< " ";
        root = root->DeleteInterval(root, newNode->lowInterval);
        newNode = root->SearchInterval(root, 6, 20); //[3,8][5,10][9,11][10,15][16,18]
//        newNode = root->SearchInterval(root, 1, 1); //[1,1]
//        newNode = root->SearchInterval(root, 3, 8);//[3,8][5,10]
//        newNode = root->SearchInterval(root, 1, 2);//[1,1]
//        newNode = root->SearchInterval(root, 5 ,15 );//[5,10][3,8][10,15][9,11]
//        newNode = root->SearchInterval(root, 10, 14);//[5,10][10,15][9,11]
//        newNode = root->SearchInterval(root, 4, 6);//[5,10][3,8]
//        newNode = root->SearchInterval(root, 3, 9);//[3,8][5,10][9,11]
//        newNode = root->SearchInterval(root, 9, 12);//[5,10][10,15][9,11]
//        newNode = root->SearchInterval(root, 8,9); //[3,8][9,11][5,10]
    }
    root = root->ION(root , arr,i);
    numOfNodes = 0;
    cout << endl;

//    Node* root = NULL;
//    Node* newNode;
//    root = root->InsertInterval(root, 13, 20);
//    root->InsertInterval(root, 10, 30);
//    root->InsertInterval(root, 17, 19);
//    root->InsertInterval(root, 5, 20);
//    root->InsertInterval(root, 12, 15);
//    root->InsertInterval(root, 30, 40);
//    Node* arr = new Node[numOfNodes];
//    newNode = root->SearchInterval(root, 5, 20); //[10,30][13,20][5,20][12,15][17,19]
//    //newNode = root->SearchInterval(root, 10, 18); //[10,30][13,20][5,20][12,15][17,19]
//    //newNode = root->SearchInterval(root, 13, 15);//[13,20][10,30][5,20][12,15]
//    //newNode = root->SearchInterval(root, 30, 40);//[10,30]
//    //newNode = root->SearchInterval(root, 5 ,7 );//[5,20]
//    //newNode = root->SearchInterval(root, 11, 15);//[5,20][12,15][10,30][13,20]
//    //newNode = root->SearchInterval(root, 19, 29);//[13,20][10,30][5,20]
//    //newNode = root->SearchInterval(root, 3, 6);//[5,20]
//    //newNode = root->SearchInterval(root, 12, 13);//[13,20][12,15][10,30][5,20]
//    //newNode = root->SearchInterval(root, 1,9); //[5,20]
//    int i = 0;
//    cout << "Overlapping intervals\n\n";
//    while(newNode != NULL)
//    {
//        arr[i++] = Node(newNode->lowInterval, newNode->highInterval);
//        cout << "[ " << newNode->lowInterval << " , " << newNode->highInterval << " ]"<< " ";
//        root = root->DeleteInterval(root, newNode->lowInterval);
//        newNode = root->SearchInterval(root, 5, 20); //[10,30][13,20][5,20][12,15][17,19]
//    }
//    root = root->ION(root , arr,i);
//    numOfNodes = 0;
//    cout << endl;

//    Node* root = NULL;
//    Node* newNode;
//    root = root->InsertInterval(root, 15, 20);
//    root->InsertInterval(root, 14, 30);
//    root->InsertInterval(root, 18, 19);
//    root->InsertInterval(root, 5, 20);
//    root->InsertInterval(root, 22, 25);
//    root->InsertInterval(root, 33, 90);
//    Node* arr = new Node[numOfNodes];
//    newNode = root->SearchInterval(root, 14, 15); // [15,20][14,30][5,20]
//    //newNode = root->SearchInterval(root, 18, 19); //[18,19][5,20][15,20][14,30]
//    //newNode = root->SearchInterval(root, 30, 31);//[14,30]
//    //newNode = root->SearchInterval(root, 16, 18);//[5,20][18,19][15,20][14,30]
//    //newNode = root->SearchInterval(root, 26 ,28);//[14,30]
//    //newNode = root->SearchInterval(root, 9, 12);//[5,20]
//    //newNode = root->SearchInterval(root, 14, 22);//[15,20][14,30][18,19][5,20][22,25]
//    //newNode = root->SearchInterval(root, 4, 9);//[5,20]
//    //newNode = root->SearchInterval(root, 6,14);//[5,20][14,30]
//    //newNode = root->SearchInterval(root, 11,24); //[15,20][14,30][18,19][5,20][22,25]
//    int i = 0;
//    cout << "Overlapping intervals\n\n";
//    while(newNode != NULL)
//    {
//        arr[i++] = Node(newNode->lowInterval, newNode->highInterval);
//        cout << "[ " << newNode->lowInterval << " , " << newNode->highInterval << " ]"<< " ";
//        root = root->DeleteInterval(root, newNode->lowInterval);
//        newNode = root->SearchInterval(root, 14, 15); // [15,20][14,30][5,20]
//    }
//    root = root->ION(root , arr,i);
//    numOfNodes = 0;
//    cout << endl;
    return 0;
}

