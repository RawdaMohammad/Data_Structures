#include <iostream>
#include<list>
#include<iterator>
using namespace std;

template <class T>
class list1 {
    int size1 ;
    T value ;
    list<T>l;
    public :
    class iterator1 {
        private:
        T * head ;
        T * tail ;
        T * it ;
        T * dummy ;
         public:
        iterator1()
        {
            it = new T ;
            head = new T ;
            tail = new T ;
            dummy = new T ;
            it = l[0] ;
            head = l[0] ;
            dummy = l[((l.size())+1)];
            tail = l[l.size()];


        }
        void setid (T * it2)
        {
            it = it2 ;
        }
         T* getit()
        {
            return it;
        }
        iterator1 begin1ist()
        {
            return head ;
        }
        iterator1 end1ist()
        {
            return dummy ;
        }
        void operator++()
        {
            it++ ;
            try{
            if(it == dummy)
            {
                throw "invalid position" ;
            }
            }
            catch(const char * message)
            {
                cout<< message << endl ;
            }
        }
        void operator--()
        {
            it-- ;
            try{
            if(it == head)
            {
                throw "invalid position" ;
            }
            }
            catch(const char * message)
            {
                cout<< message << endl ;
            }
        }
        T & operator*()
        {
            return (*it);

        }
        bool operator ==(const iterator1 & obj)
        {
            if (it == obj.it)
                return true ;
            return false ;
        }

        ~iterator1()
        {
            delete it ;
            delete head;
            delete tail ;
            delete dummy ;

        }



    };

    list1(){
      for(int i = 0 ; i<l.size(); i++)
      {
          l[i]=0 ;
      }
    }
    list1(T v , int s)
    {
        size1 = s ;
        l.push_back(v);

    }
    int Size()
    {
        return (l.size());
    }
    void insertPos (T val ,iterator1 pos )
    {
       // while (it != NULL && it->next->l )


    }
    iterator1 eraseElement(iterator1 position)
    {
       position.setid(position.getit()) ;
        T * temp = new T ;
        temp = position.getit() ;
        position++ ;
        l.remove(temp);


    }
    list1<T>& operator = (list1<T> another_list)
    {
        l.clear();
        for (int i =0 ;i<l.size();i++)
        {

        }


    }


    ~list1(){
        l.clear();
    }


};



int main()
{
//    list1 obj (5 , 5)

    return 0;
}
