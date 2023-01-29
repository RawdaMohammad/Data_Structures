//problem 1
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

// make a stack class to take a string and return a string
class stack {
private:
    string *str;
    int size;
    int top , index ;
public:
    stack(int size) {
        this->size = size;
        this->str = new string[size];
        this->top = -1;
    }
    ~stack() {
        delete[] this->str;
    }
    stack(string c) {
        this->size = 1;
        this->str = new string[1];
        this->str[0] = c;
        this->top = 0;
    }
    void push(string c) {
        if (this->top == this->size - 1) {
            cout << "stack is full" << endl;
        } else {
            this->top++;
            this->str[this->top] = c;
        }
    }
    string topElement() {
        if (this->top >= 0) {
            return this->str[this->top];
        }
        return "";
    }

    // print function to print the stack
    void print() {
        if (this->top >= 0) {
            for (int i = 0; i <= this->top ; i++) {
                for (int j = 0; j < this->str[i].length(); j++) {
                    // delete the last character of each string
                    if (j == this->str[i].length() - 1) {
                        continue;
                    }
                    // if the character is "/" and the next character is "/" delete just the next character
                    if(this->str[i][j] == '/' && this->str[i][j+1] == '/'){
                        continue;
                    }
                    // if the character is "." and the next character is "." delete both of them
                    if(this->str[i][j] == '.'){
                        continue;
                    }
                    cout << this->str[i][j];

                    }
                cout << endl;
                }

            }

    }
};
int main(){
    stack s(10);
    string str;
    str = "/home/" ;
    s.push(str);
    s.push("/../");
    s.push("/home//foo/");
    s.print();
    cout<<endl;
    return 0;

}

