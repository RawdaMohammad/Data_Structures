#include <bits/stdc++.h>
#include <vector>
using namespace std;

set<string> str;
void RecPermute(string soFar, string rest)
{

    if (rest == ""){
        str.insert(soFar);
}

    else{
        for (int i = 0; i < rest.length(); i++) {
        string next = soFar + rest[i]; // Glue next char
        string remaining = rest.substr(0, i)+ rest.substr(i+1);
        RecPermute(next, remaining);
        }
    }
}

void ListPermutations(string s) {
    RecPermute("", s);

}
void print(){
    set<string> :: iterator it;
    for(it=str.begin(); it!=str.end(); it++){
        cout << *it << endl;
    }
}
int main()
{
    string str;
    cout << "Enter a word" << endl;
    cin >> str;
    ListPermutations(str);
    print();
    return 0;
}
