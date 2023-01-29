#include <iostream>
#include<algorithm>
#include<chrono>
#include<vector>
using namespace std;
using namespace std::chrono;



int binarySearch(int arr[], int value , int low, int high) {
   if (high <= low)
     if (value > arr[low])
      return(low + 1) ;
          else
          return  low;
      int mid = (low + high)/2;
   if(value == arr[mid])
      return mid+1;
   if( value > arr[mid])
      return binarySearch(arr, value , mid+1, high);

      return binarySearch(arr,value , low, mid-1);
}

void BinaryInsertion(int arr[], int n) {
   int i;
   int loc ;
   int j ;
   int  selected;
   for (i = 1; i < n; ++i) {
      j = i - 1;
      selected = arr[i];
      loc = binarySearch(arr, selected, 0, j);
      while (j >= loc) {

         arr[j+1] = arr[j];
         j--;
      }
      arr[j+1] = selected;
   }
}

void insertionSort(int arr[], int n)
{
    int i ;
    int key ;
    int j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}



int main() {
//   int arr[10] = {12, 56, 1, 67, 45, 8, 82, 16, 63, 23};
//   BinaryInsertion(arr, 10);
//   insertionSort(arr, 10) ;
//      cout<<"Sorted array is : \n";
//   for ( int i = 0; i < 10; i++)
//      cout<<arr[i]<<"\t";
cout << endl << " binary selection "<<endl;
for(int i = 0 ; i<5 ; i++)
{
int * it ;
int size1 ;
auto f= []()-> int {return rand()% 10000;};
cout<< "enter size " ;
cin>> size1 ;
it = new int [size1] ;
generate(it , it +size1 , f);
auto startTime = high_resolution_clock:: now() ;
BinaryInsertion(it , size1);
auto endTime = high_resolution_clock:: now() ;
auto duration = duration_cast<microseconds>(endTime-startTime);
cout << duration.count()<< endl ;
}
cout << endl << "selection "<<endl;
for(int i = 0 ; i<5 ; i++)
{
int * it ;
int size1 ;
auto f= []()-> int {return rand()% 10000;};
cout<< "enter size " ;
cin>> size1 ;
it = new int [size1] ;
generate(it , it +size1 , f);
auto startTime = high_resolution_clock:: now() ;
BinaryInsertion(it , size1);
auto endTime = high_resolution_clock:: now() ;
auto duration = duration_cast<microseconds>(endTime-startTime);
cout << duration.count()<< endl ;
}







   return 0;
}
