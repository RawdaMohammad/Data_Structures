#include <iostream>

using namespace std;
template< class T>
class matrix{
    T ** mat;
    T * m;
public:
    int rows, columns;

    matrix(int r ,int c){
        rows = r;
        columns = c;
        mat = new T* [rows] ;
        for(int i=0; i<rows; i++){
            mat[i] = new T[columns];
        }
//        m = new T;
//        m = mat[1][1];
    }
    template<class T2>
    friend istream& operator>> (istream &is, matrix<T2> &obj){

        cout << "Enter the matrix: " << endl;
        for(int i=0; i<obj.rows; i++){
            for(int j=0; j<obj.columns; j++){
                is >> obj.mat[i][j];
            }
        }
        return is;
    }
    template<class T2>
    friend ostream& operator<< (ostream &os, const matrix<T2> &obj){
        cout << "Matrix is: " << endl;
        for(int i=0; i<obj.rows; i++){
            for(int j=0; j<obj.columns; j++){
                os << obj.mat[i][j] << " ";
            }
            cout << endl;
        }
        return os;
    }
    matrix<T> operator+(const matrix<T> &obj1){
        matrix<T>obj2(obj1.rows, obj1.columns);
        for(int i=0; i<obj1.rows; i++){
            for(int j=0; j<obj1.columns; j++){
                obj2.mat[i][j] = obj1.mat[i][j] + mat[i][j];
            }
        }
        return obj2;
    }
    matrix<T> operator-(const matrix<T> &obj1){
        matrix obj2(obj1.rows, obj1.columns);
        for(int i=0; i<obj1.rows; i++){
            for(int j=0; j<obj1.columns; j++){
                obj2.mat[i][j] = mat[i][j] - obj1.mat[i][j];
            }
        }
        return obj2;
    }
    matrix<T> operator*(const matrix<T> &obj1){
        matrix obj2(rows, obj1.columns);
        for(int i=0; i< rows; i++){
            for(int j=0; j< obj1.columns; j++){
                    obj2.mat[i][j] = 0;
                for (int k = 0; k < obj1.rows; k++) {
                    obj2.mat[i][j] += mat[i][k] * (obj1.mat[k][j]);

                }
            }
        }
        return obj2;
    }
     void transpose(){
        cout << "transpose matrix is: " << endl;
        for(int i=0; i<columns; i++){
            for(int j=0; j<rows; j++){
                cout << mat[j][i] << " ";
            }
            cout << endl;
        }
    } 

    friend class MatrixCalculator;
    ~matrix(){
        for(int i=0; i<rows; i++){
            delete[] mat[i];
            mat[i] = 0;
        }
    }

};

class MatrixCalculator{

    public:
    MatrixCalculator() {}

    template<class T3>
    void menu(int r1, int c1, int r2, int c2 ){
        char c;
        matrix<T3>m1(r1, c1), m2(r2, c2);

        cout<<"(+) Perform Matrix Addition "<<endl;
        cout<<"(-) Perform Matrix Subtraction "<<endl;
        cout<<"(*) Perform Matrix Multiplication"<<endl;
        cout<<"(T) Matrix Transpose  "<<endl;
        cout<<"(E) Exit form this program  "<<endl;
        cout<<"Enter your choice: ";
        cin>>c;

        while (c!='E')
        {

            if (c=='+')
             {
                 cin>>m1;
                 cin>>m2;
                 if(m1.rows==m2.rows&&m1.columns==m2.columns){
                    cout<<m1+m2;
                 }
                 else {
                     cout<<"Invalid Addition!"<<endl;
                 }
                 
             }
            else if (c=='-')
             {
                 cin>>m1;
                 cin>>m2;
                 if(m1.rows==m2.rows&&m1.columns==m2.columns){
                    cout<<m1-m2;
                 }
                 else {
                     cout<<"Invalid Subtraction!"<<endl;
                 }
                 
             }
            else if (c=='*')
             {
                 cin>>m1;
                 cin>>m2;
                 if(m1.rows==m2.rows&&m1.columns==m2.columns){
                    cout<<m1*m2;
                 }
                 else {
                     cout<<"Invalid Multiplication !"<<endl;
                 }
                 
             }
            else if (c=='T')
             {
               cin>>m1;
               cin>>m2;
               cout<<" First Matrix :"<<endl;
               m1.transpose();
               cout<<" Seconde Matrix :"<<endl;
               m2.transpose();

             }
            cout<<"Enter your choice: ";
            cin>>c;


        }

    }


};

int main(){
    MatrixCalculator ob;
    int r1, c1, r2, c2;
    cout << "Enter 1st dimensions: ";
    cin >> r1 >> c1;
    cout << "Enter 2nd dimensions: ";
    cin >> r2 >> c2;
    ob.menu<int>(r1, c1, r2, c2);



    return 0;
}