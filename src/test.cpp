/*************************************************************************
    > File Name: test.cpp
# Author: chen
# mail: 1771391789@qq.com
    > Created Time: 2021年08月04日 星期三 22时32分11秒
 ************************************************************************/
#include<iostream>
using namespace std;
#include"MyArry.h"
#include "RoundLinklist.h"
void test1()
{
    cout<<"----------------------test1-----------------------"<<endl;
    MyLinkList<int> m;
    m.push_back(1);
    m.push_back(5);
    m.push_back(4);
    m.push_back(7);
    m.push_back(2);
    m.push_back(9);
    m.push_back(3);
    cout<<"m:"<<endl;
    for(int i = 0;i < m.length;i++)
    {
        cout<<m[i]<<" ";
    }
    cout<<endl;
    m.push_foward(10);
    m.push_foward(30);
    m.push_foward(50);
    m.push_foward(70);
    for(int i = 0;i < m.length;i++)
    {
        cout<<m[i]<<" ";
    }
    cout<<endl;
    cout<<"m length:"<<m.length<<endl;
    cout<<"m pop(3)h :  "<<endl;
    m.pop(3);
    for(int i = 0;i < m.length;i++)
    {
        cout<<m[i]<<" ";
    }
    cout<<endl;
    cout<<"m length:"<<m.length<<endl;

    MyLinkList<int> n(m);
    cout<<"n:"<<endl;
    for(int i = 0;i < m.length;i++)
    {
        cout<<n[i]<<" ";
    }
    cout<<endl;
    cout<<"n length:"<<n.length<<endl;
    n.insert(1,999);
    for(int i = 0;i < n.length;i++)
    {
        cout<<n[i]<<" ";
    }
    cout<<endl;
    cout<<"n length:"<<n.length<<endl;
    cout<<"y:"<<endl;
    MyLinkList<int> y(10,9);
     for(int i = 0;i < y.length;i++)
    {
        cout<<y[i]<<" ";
    }
    cout<<endl;
    cout<<"y length:"<<y.length<<endl;
    MyLinkList<int> u(11);
    cout<<"u:"<<endl;
    for(int i = 0;i < u.length;i++)
    {
        cout<<u[i]<<" ";
    }
    cout<<endl;
    cout<<"u length"<<u.length<<endl;
    cout<<"erase后"<<endl;
    m.erase();
    n.erase();
    y.erase();
    u.erase();
    cout<<"m length: "<<m.length<<endl;
    cout<<"n length: "<<n.length<<endl;
    cout<<"y length: "<<y.length<<endl;
    cout<<"u length: "<<u.length<<endl;
}
void test2()
{
    cout<<"----------------------test2-----------------------"<<endl;
    RoundLinklist a;
    cout<<"before push_back ..."<<endl;
    a.showMyRoundlist();
    a.push_back(2);
    a.push_back(3);
    a.push_back(5);
    a.push_back(1);
    cout<<"after push_back ..."<<endl;
    a.showMyRoundlist();
    cout<<"head data:"<<a.head->data<<endl;
    cout<<"tail data:"<<a.tail->data<<endl;
    cout<<"after push_head ..."<<endl;
    a.push_head(87);
    a.push_head(32);
    a.push_head(432);
    a.showMyRoundlist();
    cout<<"head data:"<<a.head->data<<endl;
    cout<<"tail data:"<<a.tail->data<<endl;
    cout<<"after insert(0,999)..."<<endl;
    a.insert(0,999);
    a.showMyRoundlist();
    cout<<"head data:"<<a.head->data<<endl;
    cout<<"tail data:"<<a.tail->data<<endl;
    cout<<"after insert(8,55)..."<<endl;
    a.insert(8,55);
    a.showMyRoundlist();
    cout<<"head data:"<<a.head->data<<endl;
    cout<<"tail data:"<<a.tail->data<<endl;
    cout<<"after insert(4,445)..."<<endl;
    a.insert(4,445);
    a.showMyRoundlist();
    cout<<"head data:"<<a.head->data<<endl;
    cout<<"tail data:"<<a.tail->data<<endl;
    cout<<"getNode(0) and print it's data....."<<endl;
    cout<<a.getNode(0)->data<<endl;
    cout<<"getNode(2) and print it's data....."<<endl;
    cout<<a.getNode(2)->data<<endl;
    cout<<"after remove(0)...."<<endl;
    a.remove(0);
    a.showMyRoundlist();
    cout<<"head data:"<<a.head->data<<endl;
    cout<<"tail data:"<<a.tail->data<<endl;
    cout<<"after remove(8)...."<<endl;
    a.remove(8);
    a.showMyRoundlist();
    cout<<"head data:"<<a.head->data<<endl;
    cout<<"tail data:"<<a.tail->data<<endl;
    cout<<"after remove(2)...."<<endl;
    a.remove(2);
    a.showMyRoundlist();
    cout<<"head data:"<<a.head->data<<endl;
    cout<<"tail data:"<<a.tail->data<<endl;
    cout<<"after remove(3)...."<<endl;
    a.remove(3);
    a.showMyRoundlist();
    cout<<"head data:"<<a.head->data<<endl;
    cout<<"tail data:"<<a.tail->data<<endl;
    cout<<"getIndexWithData(4) = "<<a.getIndexWithData(4)<<endl;
    cout<<"getNode(4)->data = "<<a.getNode(4)->data <<endl;
}
void test3()
{
    cout<<"----------------------test3-----------------------"<<endl;
    RoundLinklist l;
    for(int i = 1;i <= 41;i++)
    {
        l.push_back(i);
    }
    l.showMyRoundlist();
    int count = 1;
    Node *it = l.head;
    while(l.length > 0)
    {
        it = it->next;
        count++;
        if(count == 3)
        {
            count = 1;
            cout<<"->"<<it->data; 
            int data = it->data;
            it = it->next;
            l.remove(l.getIndexWithData(data));
        }
    }
    cout<<endl;
}
int main()
{
    test1();
    test2();
    test3();
    return 0;
}
