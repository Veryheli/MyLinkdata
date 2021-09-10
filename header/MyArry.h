#ifndef MYLINKLIST_H
#define MYLINKLIST_H
#include<iostream>
using namespace std;
template<class T>
class MyLinkList
{
public:
    int length;
    T *data;
    MyLinkList(int length)
    {
            this->data = new T[length];                         
            this->length = length;
    }
    MyLinkList()
    {
        this->data =new T[10];
        this->length = 0;
    }
    //TODO
    MyLinkList(int num,T data)
    {
        this->length = num;
        this->data = new T[num];
        for(int i = 0;i < num;i++)
        {
            this->data[i] = data;
        }
    }
    MyLinkList(const MyLinkList&M)
    {
        *this = M;
    }
    void push_back(T data)
    {
        if(this->length == 0)
        {
            this->data = new T[10];
            this->data[0] = data;
            this->length = 1;
        }
        else{
            T *temp = this->data;
            this->data = new T[this->length + 1];
            this->data = temp;
            this->data[length] = data;
            this->length++;
        }
    }
    void push_foward(T data)
    {
        if(this->length == 0)
        {
            this->data = new T[10]();
            this->length = 1;
            this->data[0] = data;
        }
        else{
            T *temp = this->data;
            this->data = new T[this->length + 1];
            this->data = temp;
            for(int i = this->length ;i > 0;i--)
            {
                this->data[i] = this->data[i-1];
            }
            this->data[0] = data;
            this->length ++;
        }
    }
    MyLinkList & operator=(const MyLinkList&M)
    {
        this->data = new T[M.length]();
        this->length = M.length;
        for(int i = 0;i < this->length ;i++)
        {
            this->data[i] = M.data[i];
        }
        return *this;
    }
    bool insert(int i,T data)
    {
       if(i > this->length + 1 || i < 0)
       {
           return false;
       }
       else if(i == 0)
       {
           this->push_foward(data);
           return true;
       }
       else if(i == this->length+1)
       {
           push_back(data);
           return true;
       }
       else
       { 
            T *temp = this->data;
            this->data = new T[this->length + 1]();
            this->data = temp;
            this->length++;
            for(int k = this->length+1;k > i;k--)
            {
                this->data[k+1] = this->data[k];
            }
            this->data[i] = data;
            return true;
       }
    }
    bool pop(int k)
    {
        if(k > this->length-1||k < 0)
            return false;
        for(int i = k;i < this->length-1;i++)
        {
            this->data[i] = this->data[i+1];
        }
        this->length--;
        return true;
    }
    T operator[](int i)
    {
        if(i > this->length||i < 0 )
        {
            return 0;
        }
        return data[i];
    }
    void erase()
    {
        delete(this->data);
        this->length =0;
        this->data =nullptr;
    }
};
#endif

