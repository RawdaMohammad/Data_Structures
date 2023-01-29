//problem 8
#include <iostream>
using namespace std;


char searchIndex(string in, int startIn,int endIn, char data)
{
    int i = 0;
    for (i = startIn; i < endIn; i++)
    {
        if (in[i] == data)
        {
            return i;
        }
    }
    return i;
}
void printPost(string IN, string pre,int Start, int End)
{
    int preIndex = 0;
    if (Start > End)
    {
        return;
    }


    char I = searchIndex(IN, Start, End,pre[preIndex++]);


    printPost(IN, pre, Start, I - 1);


    printPost(IN, pre, I + 1, End);


    cout <<IN[I] << " ";
}

//postOrder= L R N
//preOrder= N L R
//inOrder= L N R

int main()
{
    string in1 = "ABFGC";
    string pre1 = "FBGAC" ;
    int len1 = in1.length()-1;
    cout<<"The postfix print of test case 1 ----> " ;
    printPost(pre1, in1, 0, len1);
        cout<<endl ;
        cout<<endl ;


    string pre = "42175836" ;
    string in = "12435786" ;
    int len = in.length()-1;
    cout<<"The postfix print of test case 2 ----> " ;
    printPost(pre,in , 0, len);
    cout<<endl ;
    cout<<endl ;


    string pre3 = "ZXWDY" ;
    string in3 = "DXZWY" ;
    int len3 = in3.length()-1;
    cout<<"The postfix print of test case 3 ----> " ;
    printPost(pre3,in3, 0, len3);
    cout<<endl ;
    cout<<endl ;

    string in4 = "LMNPQ";
    string pre4= "NMPLQ" ;
    int len4 = in4.length()-1;
    cout<<"The postfix print of test case 4 ----> " ;
    printPost(pre4, in4, 0, len4);
        cout<<endl ;
        cout<<endl ;

    string in5 = "RSVUQ";
    string pre5= "VSURT" ;
    int len5 = in5.length()-1;
    cout<<"The postfix print of test case 5 ----> " ;
    printPost(pre5, in5, 0, len5);
        cout<<endl ;
        cout<<endl ;


}
