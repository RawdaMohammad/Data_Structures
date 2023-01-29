#include <iostream>
#include <vector>
#include <algorithm>
#include<chrono>
#include<cstdlib>
#include<ctime>
#include <iomanip>
using namespace std;
using namespace std::chrono;

class sorter{
public:
    sorter(){}
    virtual void Sort(int arr[], int Size){

    }
};
class QuickSorter: public sorter{
public:
    QuickSorter(){}
    int Partition(int A[], int left, int right){
        int pivot, i, j;
         pivot = A[left];
         i = left;
         for (j = left+1; j<right+1; j++){
            if (A[j] < pivot ){
                 i = i + 1;
                 swap(A[i], A[j]);
            }
         }
         swap(A[i], A[left]);
         return i;

    }
    void Quick_Sort(int A[], int left, int right){
        if (left < right){
            int middle = Partition(A, left, right);
            Quick_Sort(A, left, middle-1 );
            Quick_Sort(A, middle+1, right);
        }
    }
    virtual void Sort(int arr[], int Size){
        Quick_Sort(arr, 0, Size-1);
    }

};
class SelectionSorter: public sorter{
public:
    SelectionSorter(){}
    virtual void Sort(int arr[], int Size){
        for (int i = 0, j, least; i < Size-1; i++) {
            for (j = i+1, least = i; j < Size; j++){
                if (arr [j] < arr [least]){
                    least = j;
                }
            }
            swap (arr [least], arr [i]);
        }
    }
};
class Testbed{
    vector<int>arr;
public:
    Testbed(){}
    void GenerateRandomList(int Min, int Max, int Size){

        for(int i=0; i<Size; i++){
            arr.push_back(rand() % Max + Min);

        }


    }
    void GenerateReverseOrderedList(int Min, int Max, int Size){
        for(int i=0; i<Size; i++){
            arr.push_back(rand() % Max + Min);
        }
        reverse(arr.begin(), arr.end());

    }
    long long RunOnce(sorter* sort1, int array1[], int size1){
        auto startTime = high_resolution_clock:: now() ;
        sort1->Sort(array1,size1);
        auto endTime = high_resolution_clock:: now() ;
        auto duration = duration_cast<microseconds>(endTime-startTime);
        return (duration.count());

    }
    long long RunAndAverage(sorter* sort1, string type, int Min, int Max, int Size, int sets_num){
        int arr1[Size];
        for(int i=0; i<Size; i++){
            arr1[i] = 0;
        }
        int coun = 0;
        for(int i=0; i<sets_num; i++){
            if(type == "Random"){
                auto startTime = high_resolution_clock:: now() ;
                GenerateRandomList(Min, Max, Size);

                for(int i=0; i<Size; i++){
                    arr1[i] = arr[i];
                }

                sort1->Sort(arr1, Size);
                auto endTime = high_resolution_clock:: now() ;
                auto duration = duration_cast<microseconds>(endTime-startTime);
                coun += (duration.count());

            }else if(type == "Reverse"){
               auto startTime = high_resolution_clock:: now() ;
                GenerateReverseOrderedList(Min, Max, Size);

                for(int i=0; i<Size; i++){
                    arr1[i] = arr[i];
                }
                sort1->Sort(arr1, Size);
                auto endTime = high_resolution_clock:: now() ;
                auto duration = duration_cast<microseconds>(endTime-startTime);
                coun += (duration.count());
            }

        }
        return (coun/sets_num);

    }
    void RunExperient (sorter* s, string type, int Min, int Max, int min_val,
                  int max_val, int sets_num, int step){

        for(int i=0; i<sets_num-1; i++){
            GenerateRandomList(Min, Max, min_val);
            RunAndAverage(s, type, Min, Max, min_val, sets_num);
        }
        cout << left << setw(10) << "Set size" << setw(200) << "Average time" << endl;
        cout << left << setw(10) << min_val << setw(200) << RunAndAverage(s, type, Min, Max, min_val, sets_num) << endl;
        int s1=step;
        for(int i=0; i<sets_num; i++){
            s1 += step ;
            if(s1 < max_val){
                GenerateRandomList(Min, Max, s1 );
                cout << left <<setw(10) <<s1 << setw(200) <<
                RunAndAverage(s, type, Min, Max, s1, sets_num) << endl;

            }else
                break;

        }
    }

};


int main()
{
    int size1 = 5;
    int arr[size1] = {4, 10, 1, 8, 2};
    Testbed t;
    sorter *q;
    q = new QuickSorter;
    cout << "Random quick sort" << endl;
    cout << endl;
    t.RunExperient(q, "Random", 100, 100000, 5000, 100000, 4, 5000);
    cout << "------------------------------------" << endl;

    cout << "Reverse quick sort" << endl;
    cout << endl;
    t.RunExperient(q, "Reverse", 100, 100000, 5000, 100000, 4, 5000);
    cout << "------------------------------------" << endl;

    sorter *s;
    s = new SelectionSorter;
    cout << "Random selection sort" << endl;
    cout << endl;
    t.RunExperient(s, "Random", 100, 100000, 5000, 100000, 4, 5000);
    cout << "------------------------------------" << endl;

    cout << "Reverse selection sort" << endl;
    cout << endl;
    t.RunExperient(s, "Reverse", 100, 100000, 5000, 100000, 4, 5000);
    return 0;
}
