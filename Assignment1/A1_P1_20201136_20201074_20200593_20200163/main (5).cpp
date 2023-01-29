#include <iostream>
#include<string>
#include<cmath>
#include<sstream>
#include <vector>
#include <algorithm>
using namespace std;

class BigInt{
    int number ;
    string num=" ";
    vector<int> arr;
    //vector<int>v;
    public:
    BigInt(string decStr){
        num=decStr;
    };
    BigInt (int decInt){
//        number=decInt;
//        while (number!=0) {
//        arr.insert(arr.begin(), number%10);
//        number /= 10;
//        }
        number= decInt;
        stringstream ss;
        ss << number;
        ss >> num;
    }
    BigInt operator+( BigInt &obj1){

        if (num.length() > (obj1.num).length()){
            string temp;
            temp=num;
            num=obj1.num;
            obj1.num=temp;
        }
        string result = "";
        int length1 = num.length(), length2 = (obj1.num).length();
        int difference = length2 - length1;
        int carry = 0;
        for (int i=length1-1; i>=0; i--)
        {
            int sum = ((num[i]-'0') +
                    ((obj1.num)[i+difference]-'0') + carry);
                    result.push_back(sum%10 + '0');
                    carry = sum/10;
        }
        for (int i=length2-length1-1; i>=0; i--)
        {
            int sum = (((obj1.num)[i]-'0')+carry);
            result.push_back(sum%10 + '0');
            carry = sum/10;
        }
        if (carry){
            result.push_back(carry+'0');
        }
        reverse(result.begin(), result.end());

        return result;
}


//bool Smaller(string str1, string str2){
//        int length1 = str1.length(), length2 = str2.length();
//
//        if (length1 < length2)
//            return true;
//        if (length2 < length1)
//            return false;
//
//        for (int i = 0; i < length1; i++)
//            if (str1[i] < str2[i])
//                return true;
//            else if (str1[i] > str2[i])
//                return false;
//
//        return false;
//    }

 BigInt operator-(BigInt &obj1){
//    if (Smaller(num, (obj1.num)))
//        swap(num, (obj1.num));

    string result = "";


    int length1 = num.length(), length2 = (obj1.num).length();
    reverse(num.begin(), num.end());
    reverse((obj1.num).begin(), (obj1.num).end());

    int carry = 0;

    for (int i = 0; i < length2; i++) {

        int sub = ((num[i] - '0') - ((obj1.num)[i] - '0') - carry);

        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }else
            carry = 0;

        result.push_back(sub + '0');
    }

    for (int i = length2; i < length1; i++) {
        int sub = ((num[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        result.push_back(sub + '0');
    }
    reverse(result.begin(), result.end());

    return result;

}
    void operator=(const BigInt &obj1){
        num=obj1.num ;
   }
    bool operator== (const BigInt &obj1){
        bool status;
        if(num==obj1.num){
            status=true;
        }
        else {
            status=false;
        }
        return status;
    }

    friend ostream& operator << (ostream& os, const BigInt& obj1){
//        for(int i=0;i<(obj1.arr).size();i++){
//            os<<obj1.arr[i];
//        }
        os << obj1.num;
        return os;
    }
    int size(){
        if(num!=" "){
            return num.length();
        }
        else {
            return sizeof(number);
        }
    }
};
void test1(){
    BigInt num1(800);
    BigInt num2(200);
    BigInt num3=num1+num2;
    BigInt result(1000);
     if(num3==result)
     {
         cout<<"the result is true"<<endl;
     }
     else
         cout<<"the result is false"<<endl;
}

void test2(){
    BigInt num1("200");
    BigInt num2("700");
    BigInt num3=num1-num2;
    cout << num3 << endl;
    BigInt result("500");
    if(num3==result)
    {
        cout<<"the result is true"<<endl;
    }
    else
    cout<<"the result is false"<<endl;
}
void test3(){
    BigInt num1("2000");
    BigInt num2("-500");
    BigInt num3=num1+num2;
    BigInt result("1500");
    if(num3==result)
    {
        cout<<"the result is true"<<endl;
    }
    else
    cout<<"the result is false"<<endl;
}
void test4(){
    BigInt num1("500");
    BigInt num2("8000");
    BigInt num3=num1+num2;
    BigInt result("8500");
    if(num3==result)
    {
        cout<<"the result is true"<<endl;
    }
    else
    cout<<"the result is false"<<endl;
}
void test5(){
    BigInt num1("3000");
    BigInt num2("300");
    BigInt num3=num1+num2;
    BigInt result("3300");
    if(num3==result)
    {
        cout<<"the result is true"<<endl;
    }
    else
    cout<<"the result is false"<<endl;
}
int main(){
    test2();
}
