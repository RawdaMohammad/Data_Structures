#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;
vector <string> str;
class StudentName{
    string name;

public:

    StudentName(string n){

        int numspaces=0, position;
        for(int i=0; i<n.length(); i++){
            if(n[i] == ' '){
                numspaces++;
                position = i;
            }
        }
        if(numspaces == 1){
            cout << n << ' ' ;
            for(int j=position+1; j<n.length(); j++){
                cout << n[j] ;
            }
            cout << endl;
        }else if(numspaces >= 2){
            cout << n << endl;

        }else if(numspaces == 0){
            cout << n <<' '<< n << ' '<< n << endl;
        }
        name = n;
    }
    bool Replace(int i,int j){
        int numspace=0, pos;
        for(int i=0; i<name.length(); i++){
            if(name[i] == ' '){
                numspace++;
                pos = i;
            }
        }

        string space = " " ;
        int start = 0;
        int end = name.find(space);
        int coun = 1;
        while (end != -1) {
            str.push_back(name.substr(start, end - start));
            coun++;
            start = end + 1;
            end = name.find(space, start);

        }
        str.push_back(name.substr(start, end - start));
        if(i==j || i > numspace+1 || j > numspace+1){
            cout << "Error" << endl;
            return false;
        }else if(numspace == 1 && j <= 2 && i <= 2){
            swap(str[i-1], str[j-1]);

            return true;
        }else if(numspace > 1 && i <= numspace+1 && j <= numspace+1){
            swap(str[i-1], str[j-1]);

            return true;
        }


    }

    void print()
    {
        for(int l=0; l<str.size(); l++){
            cout << l+1 << ") " <<str[l] << endl ;
        }
        str.clear();
    }
    ~StudentName(){
        str.clear();
    }
};
int main()
{
    StudentName n1("ahmed Mohamed sayed");
    StudentName n2("sara ahmed");
    StudentName n3("Khaled");
    StudentName n4("aya ali ahmed sayed");
    StudentName n5("ahmed Mohamed sayed Khaled");
    cout << endl;
    if(n1.Replace(1,5)){
        n1.print();
    }else
        n1.print();
    cout << endl;
    if(n2.Replace(1,2)){
        n2.print();
    }else
        n2.print();
    cout << endl;
    if(n3.Replace(1,1)){
        n3.print();
    }else
        n3.print();
    cout << endl;
    if(n4.Replace(2,4)){
        n4.print();
    }else
        n4.print();
    cout << endl;
    if(n5.Replace(3,5)){
        n5.print();
    }else
        n5.print();

    return 0;
}
