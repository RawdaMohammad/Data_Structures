//problem 2

#include <iostream>
using namespace std;
class QeuueTikits
{
private:
    int head, end, count, ArraySize, Time;
    int *arr;

public:
    QeuueTikits(int size)
    {
        head = 0;
        end = 0;
        Time = 0;
        count = 0;
        ArraySize = size;
        arr = new int[ArraySize];
    }
    int isEmpty()
    {
        return count == 0;
    }
    int isFull()
    {
        return count == ArraySize;
    }
    void addqueue(int num)
    {

        if (isFull())
        {
            cout << "Array is full";
        }
        else
        {
            arr[end] = num;
            end += 1;
            count++;
        }
    }
    void change(int num)
    {
        int number = arr[num];
        while (number != 0)
        {
            for (int i = head; i < count; i++)
            {

                if(arr[i]<=0){
                    continue;
                }
                else{
                arr[0] -= 1 ;}

                int temp = arr[0];
                for (int j = head; j < (count - 1); j++)
                {
                    arr[j] = arr[j + 1];
                }
                arr[count - 1] = temp;
                Time += 1;
            }
            number--;
        }

         cout << "time:" << Time << endl;
    }
    ~QeuueTikits()
    {
        delete arr;
    }
};
int main()
{
    cout<<"test case 1 ---->" <<endl;
    QeuueTikits Q(4);
    Q.addqueue(5);
    Q.addqueue(1);
    Q.addqueue(1);
    Q.addqueue(1);
    Q.change(0);

    cout<<"test case 2 ---->" <<endl;
    QeuueTikits Q2(3);
    Q2.addqueue(2);
    Q2.addqueue(3);
    Q2.addqueue(2);
    Q2.change(2);

    cout<<"test case 3 ---->" <<endl;
    QeuueTikits Q3(3);
    Q3.addqueue(2);
    Q3.addqueue(1);
    Q3.addqueue(4);
    Q3.change(1);

    cout<<"test case 4 ---->" <<endl;
    QeuueTikits Q4(4);
    Q4.addqueue(1);
    Q4.addqueue(5);
    Q4.addqueue(2);
    Q4.addqueue(3);
    Q4.change(2);




    return 0;
}
