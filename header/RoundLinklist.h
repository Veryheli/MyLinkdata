#pragma once
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class RoundLinklist
{
public:
    Node *head;
    Node *tail;
    Node *index;
    int length;
    RoundLinklist()
    { 
        this->length = 0;
        this->head = nullptr;
        this->tail= nullptr;

    }
    void showMyRoundlist()
    {
        if(this->head == nullptr)
        {
            cout<<"this is a void RoundLinklist.."<<endl;
        }
        else
        {
            Node *target;
            target= this->head;
            do
            {
                cout<<target->data<<" ";
                target= target->next;
            }while(target!= this->tail->next);
            cout<<endl;
            cout<<"this RoundLinklist's length is "<<this->length;
            cout<<endl;
        }
    }
    void push_back(int data)
    {
        Node *temp = new Node;
        temp->data = data;
        if(this->head == nullptr)
        {
            this->head = temp;
            this->tail = temp;
            temp->next = temp;
        }
        else
        {
            this->tail->next =temp;
            this->tail = temp;
            this->tail->next = this->head;
        }
        this->length++;

    }
    void push_head(int data)
    {
        if(this->head == nullptr)
        {
            this->push_back(data);
        }
        else
        {
            Node *temp = new Node;
            temp->data = data;
            temp->next = this->head;
            this->tail->next= temp;
            this->head = temp;
        }
        this->length++;
    }
    bool insert(int pos,int data)
    {
        if(pos <0 || pos >this->length )
        {
            cout<<"the position you want to insert data is wrong..."<<endl;
            return false;
        }
        else if(pos ==0)
        {
            this->push_head(data);
        }
        else if(pos == this->length)
        {
            this->push_back(data);
        }
        else
        {
            Node *temp = new Node;
            Node *target;
            target= this->head;
            temp->data = data;
            for(int i = 0;i < pos - 1 ;i++)
            {
                target = target->next;
            }
            temp->next=target->next;
            target->next = temp;
            this->length++;
        }
        return true;
    }
    Node*& getNode(int pos)
    {
        if(pos == 0)
        {
            return this->head;
        }
        else if (pos == this->length)
        {
            return this->tail;
        }
        else
        {
            this->index= this->head;
            for(int i = 0;i < pos;i++)
            {
                this->index = this->index->next;
            }
            return this->index;
        }
    }
    int getIndexWithData(int data)
    {
        int count = 0;
        for(this->index = this->head;this->index->data != data;this->index = this->index ->next )
        {
            count++;
            if(count > this->length )
            {
                cout<<endl<<"there is not a data equals the data you provided.."<<endl;
                return -1;
            }
        }
        return count;
    }
    bool remove(int pos)
    {
        if(pos < 0||pos > this->length-1)
        {
            return false;
        }
        else if(pos == 0) 
        {
            Node *temp;
            temp = this->head;
            this->head =this->head->next;
            this->tail->next =this->head;
            delete (temp);
            this->length--;
        }
        else if(pos == this->length-1)
        {
            Node *target = this->head;
            for(int i = 0;i < this->length - 2;i++)
            {
                target = target->next;
            }
            delete(this->tail);
            this->tail = target;
            target->next = this->head;
            this->length--;
        }
        else
        {
            Node *target = this->head;
            for(int i=0;i < pos-1 ;i++)
            {
                target = target->next;
            }
            Node *temp;
            temp = target->next;
            target->next = target->next->next;
            delete (temp);
            this->length--;
        }
        return true;
    }
    ~RoundLinklist()
    {
        Node *temp;
        while(this->length != 0)
        {
            temp = this->head;
            this->head = this->head->next;
            delete (temp);
            this->length--;
        }
        this->head = nullptr;
        this->tail = nullptr;
    }

private:

};

