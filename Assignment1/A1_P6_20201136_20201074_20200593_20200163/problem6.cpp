#include <iostream>
#include <vector>
#include <cmath>      
using namespace std;
 class  PhoneDirectory {
     private:
      string first_name ;
      string last_name;
      int phone_number;
      public:
      PhoneDirectory(){
           first_name="" ;
           last_name="" ;
           phone_number=0  ;
      }
      vector<string>Fname;
      vector<string>Lname;
      vector<int>Phone;


      
      void AddEntery(string name1,string name2,int number){
          first_name=name1;
          last_name=name2;
          phone_number=number;
          Fname.push_back(first_name);
          Lname.push_back(last_name);
          Phone.push_back(phone_number);  
      }
      void list(){
          for(int i=0; i<Fname.size();i++){
              cout<<Fname[i]<<" "<<Lname[i]<<" "<<Phone[i]<<endl;
          }
      }
     void Look_UP_First_name(string FirstName){
         for(int i=0; i<Fname.size();i++){
             if(FirstName==Fname[i]){
                 cout<<Fname[i]<<" "<<Lname[i]<<" "<<Phone[i]<<endl;
            }   
          }  
     }
     void Look_UP_Phone(int num){
         for(int i=0; i<Phone.size();i++){
             if(num==Phone[i]){
                 cout<<Fname[i]<<" "<<Lname[i]<<" "<<Phone[i]<<endl;
            }   
          }  
     }
    void Delete_BY_First_name(string FName){
         for(int i=0; i<Fname.size();i++){
             if(FName==Fname[i]){
               Fname.erase(Fname.begin() + i);
                Lname.erase(Lname.begin() + i);
              Phone.erase(Phone.begin() + i);

            }
          }
     }
     void selection_sort()
    {

       int smallest =0 ;
        for (int l = 0 ; l < Fname.size(); l++) {
              smallest= l ;
           for(int j = l ; j<Fname.size();j++)
           {
               if (Fname[j].compare(Fname[smallest])<0)
               {
                   smallest=j ;

               }

           }
           if(smallest!=l)
           {
               swap(Fname[l],Fname[smallest]);
               swap(Lname[l],Lname[smallest]);
               swap(Phone[l],Phone[smallest]);
           }
        }
    }
    void insertion_sort() {
        for (int i = 1; i < Fname.size(); ++i) {
        string x = Fname[i];
        string y = Lname[i];
        int z = Phone[i];
        int j = i;
        while (j > 0 and Fname[j - 1] > x) {
        Fname[j] = Fname[j - 1];
        Lname[j] = Lname[j - 1];
        Phone[j] = Phone[j - 1];
        --j;
        }
        Fname[j] = x;
        Lname[j]=y;
        Phone[j]=z;

        }
    }
    void Bubble_sort() {
        for (int i = 0; i < Fname.size()- 1; i++) {
            for (int j = Fname.size() - 1; j > i; --j){
                if (Fname [j] < Fname [j-1]){
                    swap (Fname [j], Fname [j - 1]);
                    swap (Lname [j], Lname [j - 1]);
                    swap (Phone [j], Phone [j - 1]);

                }
            }    
        
        }

        
    }


   
 };
int main()
{
    PhoneDirectory p;
    int number;
    string first ,last;
    int phone ;
    cout<<"1. Add an entry to the directory "<<endl;
    cout<<"2. Look up a phone number "<<endl;
    cout<<"3. Look up by first name "<<endl;
    cout<<"4. Delete an entry from the directory "<<endl;
    cout<<"5. List All entries in phone directory "<<endl;
    cout<<"6. Exit form this program "<<endl;
    cout<<"Enter your choice: ";
    cin>>number;
      
while (number!=6)
    {
         
            if (number==1)
         {
             cout<<"Enter First Name:" ;
             cin>>first;
             cout<<"Enter last Name:" ;
             cin>>last;
             cout<<"Enter phone Number Name:" ;
             cin>>phone;
             p.AddEntery(first,last,phone);

         }
         else if (number==2){
            int phonenumber;
            cout<<"Enter Phone Number: "; 
            cin>>phonenumber;
            p.Look_UP_Phone(phonenumber);
        }
         
        else if (number==3){
           string firstname;
           cout<<"Enter First Name: "; 
           cin>>firstname;
           p.Look_UP_First_name(firstname);
        }
         
        else if (number==4){
           string Firstname;
           cout<<"Enter First Name: "; 
           cin>>Firstname;
           p.Delete_BY_First_name(Firstname);
        }
        else if (number==5){
            cout<<"1.selction sotr"<<endl;
            cout<<"2. Insertion "<<endl;
            cout<<"3. Bubble sort "<<endl;
            cout<<"choose sorting type:"<<endl;
            int S_num;
            cin>>S_num;
            if (S_num==1){
              p.selection_sort();
            }
            else if ((S_num==2)){
                p.insertion_sort();
            }  
            else if ((S_num==3)){
                p.Bubble_sort();
            }  

           p.list();
        }
          cout<<"Enter your choice: ";
          cin>>number;
    }
   
  
    return 0 ;
}
