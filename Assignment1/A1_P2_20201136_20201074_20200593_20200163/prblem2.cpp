#include <iostream>
using namespace std;

class fraction {
private:
    int numi ;
    char c1;
    int demi ;
public :
    fraction(){}
    fraction(int num1 , char c, int num2 )
    {
        numi=num1 ;
        c1 = c;
        demi = num2 ;
    }
    bool operator<(const fraction & obj)
    {
        if (numi <obj.numi&& demi <obj.demi)
           return true ;
        else
        return false ;
    }
    bool operator>(const fraction & obj)
    {
        if (numi >obj.numi&& demi >obj.demi)
           return true ;
        else
        return false ;
    }
     bool operator==(const fraction & obj)
    {
        if (numi==obj.numi&& demi ==obj.demi)
           return true ;
        else
        return false ;
    }
    bool operator>=(const fraction & obj)
    {
        if (numi >=obj.numi&& demi >=obj.demi)
           return true ;
        else
        return false ;
    }
    bool operator<=(const fraction & obj)
    {
        if (numi <=obj.numi&& demi <=obj.demi)
           return true ;
        else
        return false ;
    }
     friend ostream & operator<<(ostream & os , const fraction & obj1)
    {
        os<<obj1.numi ;
        os<< '/';
        os<<obj1.demi ;
        return os ;
    }
     friend istream & operator>>(istream & is , fraction & obj)
    {
        is>> obj.numi >>obj.c1>>obj.demi;
        if(obj.demi == 0){
            cout << "Invalid number!! Enter another number" << endl;
            is>> obj.numi >>obj.c1>>obj.demi;
        }
        return is ;
    }
    fraction operator+ (const fraction & obj)
    {
        fraction obj3 ;
        obj3.numi= (numi *obj.demi)+(demi *obj.numi);
        obj3.demi = demi*obj.demi ;
        reduce_fraction(obj3) ;
        return obj3 ;
    }
    fraction operator- (const fraction & obj)
    {
        fraction obj3 ;
        obj3.numi= (numi *obj.demi)-(demi *obj.numi);
        obj3.demi = demi*obj.demi ;
        reduce_fraction(obj3) ;
        return obj3 ;
    }
    fraction operator* (const fraction & obj)
    {
        fraction obj3 ;
        obj3.numi= numi * obj.numi;
        obj3.demi = demi * obj.demi ;
        reduce_fraction(obj3) ;
        return obj3 ;
    }
    fraction operator/ (const fraction & obj)
    {
        fraction obj3 ;
        if(obj.numi == 0){
            cout << "Invalid division" << endl;
            exit(1);
        }
        else{
            obj3.demi= demi *obj.numi;
            obj3.numi = numi *obj.demi ;
            reduce_fraction(obj3) ;
            return obj3 ;
        }


    }

    void reduce_fraction (fraction & obj )
{
        for (int i = obj.demi* obj.numi; i > 1; i--) {
                if ((obj.demi % i == 0) && (obj.numi% i == 0)) {
                         obj.demi /= i;
                         obj.numi /= i;
        }

         }
}
friend class FractionCalculator;

};

class FractionCalculator
{

    fraction f1 , f2 , f3, *f4 ;

    public :
    FractionCalculator()
    {
        f4 = new fraction;
        cout << "Enter two fractions" << endl;
        cin>>f1>>f2;

    }
    void calculator(char C1){
        int i = 0;

        while(C1 != 'E'){
            switch (C1)
            {
                 case '+' :
                    f3 = f1 + f2;
                    cout << f3 ;
                    break ;
                case '-' :
                    f3 = f1 - f2;
                    cout << f3 ;
                    break ;
                case '*' :
                    f3 = f1 * f2;
                    cout << f3 ;
                    break ;
                case '/' :
                    f3 = f1 / f2;
                    cout << f3 ;
                    break ;
                case 'r' :
                    for(int j=0;j<i; j++){
                        cout << f4[j] << endl;
                    }
                    break ;
            }
            while(i<10){
                f4[i++] = f3;
                break;
            }
            cout << endl;
            cout << "Enter operation ";
            cin >> C1;
        }
        cout << "Exit successfully" << endl;
    }



};

int main()
{
    char operation;
    FractionCalculator f5 ;
    cout<<"(+) Adding Operation "<<endl;
    cout<<"(-) Subtracting Operation "<<endl;
    cout<<"(*) Multiplying Operation "<<endl;
    cout<<"(/) Dividing Operation "<<endl;
    cout<<"(r) Reduce Fraction "<<endl;
    cout<<"(E) Exit form this program "<<endl;
    cout << "Enter operation ";
    cin >> operation;
    f5.calculator(operation);

    return 0;
}
