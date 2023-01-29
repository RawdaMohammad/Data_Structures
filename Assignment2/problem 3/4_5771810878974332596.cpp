//problem 3
#include <iostream>

using namespace std;

template <class T>
class Queue{
    public :
    class q_node{
    public:
        T data;
        q_node* next;
        q_node* previous;

        q_node(T d)
        {
            data = d;
            next = NULL;
            previous =NULL;

        }

        };
    public:
        q_node *Front, *rear;
        int s=0;
        Queue()
        {
            Front = rear = NULL;
        }

        //add new element

       void enQueue(int x)
       {
           // Create a new Linked List node

           q_node* temp = new q_node(x);


           // new node is front and rear both
           if (rear == NULL)
            {
                Front = rear = temp;
                return;
            }

           // Add the new node at the end of queue

        rear->next = temp;
        rear = temp;
        s++;
    }

    // remove the element

    void deQueue()
    {
        if (Front == NULL)
            return;

        q_node* temp = Front;
        Front = Front->next;

        if (Front == NULL)
            rear = NULL;

        delete (temp);
    }

    bool empty1()
    {
        if(Front == NULL)
        {
            return true ;
        }
        else
            return false;
    }

    int size()
        {
            return s;
        }

};

class Stack
{
     Queue<int> q;
     public:
     //push-->add new item to the top of the stack
    void push(int val)
    {
        int q_size = q.size();

        q.enQueue(val);

        for (int i=0; i<q_size; i++)
            {

                //add front element to the back of queue

                q.enQueue((q.Front)->data);


               //remove the front element
               q.deQueue();

            }


    }

    //pop-->remove the top element

    void pop()
    {
        if( q.empty1())
        {
            cout << "Error , No elements to be popped , can't delete from an empty stack"<<endl;
        }


        q.deQueue();

    }

    //top-->returns the top element of the stack
    int top()
    {
        if(q.empty1())
        {
            cout<<"NO existing elements, The stack is empty"<<endl;
        }
        else
        {
            cout<<"The top element is: "<< (q.Front)->data <<endl;
        }

    }

    bool empty()
    {
        return (q.empty1());
    }


};

int main()
{
    Stack s;

    s.push(1); // add 1
    s.push(2); // add 2
    s.push(3); // add 3
    s.push(4); // add 4
    s.top();   //return the top element(4)
    cout<<endl;
    s.pop();     //remove the top element(4)
    s.pop();    //remove the top element(3)
    s.pop();     //remove the top element(2)
    s.top();   //return the top element(1)
    cout<<endl;

    s.pop();     //remove the top element(1)
    s.top();    //return the top element-->empty


    return 0;
}
