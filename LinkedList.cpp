//#pragma once
#include<iostream>
#include "LinkedList.hpp"

using std::cout;
using std::endl;
using namespace ll;



/////////////////////////////// Node//////////////////////////
    Node::Node()
    :next(nullptr),data(0)
    {

    }
    Node::Node(int value)
    :next(nullptr),data(value)
    {

    }
    Node* Node::getnext(){
       return this->next;
    }
    void Node::setnext(Node * n){
        this->next = n;
    }

    int Node::getdata(){
        return this->data;
    }
    ///////////////////////////////end Node//////////////////////////

    LinkedList::LinkedList():head(nullptr),_size(0)
    {

    }
    LinkedList::~LinkedList()
    {
         this->clear(head);
    }

   void  LinkedList::clear(Node * root){
         if(root->getnext()!=nullptr){
             clear(root->getnext());
             delete(root);
              _size=0;
         }
         
        
    }


    void LinkedList::add(int value){
         if(head == nullptr){
             head = new Node(value);
             _size++;
         }
         else{
         Node * current = head;
         while(current->getnext()!=nullptr){
             current = current->getnext();
         }
         current->setnext(new Node(value));
         _size++;
         }

    }
    void LinkedList::removefirst(){
        if(head==nullptr){
            throw std::invalid_argument("try to remove from empty list!");
        }
        else{
            Node * current = head;
            if(current->getnext()==nullptr){ 
    /////////////////////// dump core//////////////////////////////////////////////////////////////////
                head = nullptr;
                delete current;
            }
            else
            {
            head = current->getnext();
            delete current;
            _size--; 
            }
        }
    }

    void LinkedList::remove(int value){
          if(!(this->contains(value))){
              throw std::invalid_argument("the value is not in the list");
          }
          else
          {
              Node * current = head;
              if(current->getdata()==value){
                  head = current->getnext();
                  delete current;
                  _size--;
              }
              else{
                  while (current->getnext()->getdata()!=value)
                  {
                      current = current->getnext();
                  }
                  Node * temp = current->getnext();
                  if(temp->getnext()==nullptr){
                      delete temp;
                      current->setnext(nullptr);
                      _size--;
                  }
                  else
                  {
                      current->setnext(temp->getnext());
                      delete temp;
                      _size--;
                  }
                  
                  
              }
          }
          
    }

    bool LinkedList::contains(int value){
         if(head == nullptr)return false;
         if(head->getdata()==value) return true;
             Node * current = head;
             while (current->getnext()!=nullptr)
             {
                 if(current->getdata()==value){
                     return true;
                 }
                 current = current->getnext();
             }
             return false;
    }

    int LinkedList::in(int index){
        if(this->_size-1 < index){
           throw std::invalid_argument("list out of bound"); 
        }
        else{
            Node * current = head;
            for (size_t i = 0; i < index; i++)
            {
                current = current->getnext();
            }
            return current->getdata();
        }
    }


    int LinkedList::getsize(){
        return this->_size;
    }
    void LinkedList::print(){
      
      cout<<"the list is : ";
      help_print(head);
      cout<<endl;
    }
    void LinkedList::help_print(Node *root){
        if(root!=nullptr){
            cout<<","<<root->getdata();
            help_print(root->getnext());
        }
    }


/*
    int main(){
        LinkedList l1;
        l1.add(1);
        cout<<l1.contains(1)<<endl;
        cout<<true<<endl;
        cout<<l1.contains(2)<<endl;
        cout<<"size: "<<l1.getsize()<<endl;
        l1.add(2);
        l1.add(6);
        l1.add(1);
        l1.print();
        cout<<"size: "<<l1.getsize()<<endl;
        cout<<"l1.at(0)"<<l1.in(0)<<endl;
        cout<<"l1.at(1)"<<l1.in(1)<<endl;
        cout<<"l1.at(2)"<<l1.in(2)<<endl;
        cout<<"l1.at(3)"<<l1.in(3)<<endl;
        l1.removefirst();
        l1.removefirst();
        l1.removefirst();
        l1.removefirst();
        l1.print();
        //cout<<"size: "<<l1.getsize()<<endl;
        return 0 ;
    }
    */

