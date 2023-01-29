#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


vector<string> biasedsort(vector<string> & vec)
{

       int smallest =0 ;
        for (int l = 0 ; l < vec.size(); l++) {
              smallest= l ;
           for(int j = l ; j<vec.size();j++)
           {
               if (vec[j].compare(vec[smallest])<0)
               {
                   smallest=j ;

               }

           }
           if(smallest!=l)
           {
               swap(vec[l],vec[smallest]);
           }
        }
        if(vec[0]=="untitled"){
            return vec ;}
        else {
        for(int i = 1 ; i<vec.size();i++)
        {


            if(vec[i]=="untitled")
            {
                string temp = vec[i];
                for (int j=i ; j>0 ;j--){

                     vec[j]=vec[j-1];
                     vec[j-1]=temp ;}

            }

        }
        return vec ;
        }



}

int main()
{
    int vec_size;
    cout << "please enter size of vector :" << endl;
    cin >> vec_size;
     string x;
    vector<string> vec;
    cout << "please enter your playlist:" << endl;
    for(int i=0;i<vec_size;i++)
    {
        cin>>x;
        vec.push_back(x);
    }

    biasedsort(vec);
        for(int i=0;i<vec_size;i++)
    {
        cout << vec[i] << endl;
    }

    return 0;
}
