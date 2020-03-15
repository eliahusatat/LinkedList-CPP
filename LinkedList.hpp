#include<iostream>
using std::cout;
using std::endl;

namespace ll{

    class Node
    {
    private:
       int data;
       Node *next;
    public:
       Node* getnext();
       int getdata();
       void setnext(Node * n);
       Node();
       Node(int value);
    };
    
    
    

class LinkedList
{
private:
    Node *head;
    int _size;
    void help_print(Node* root);
public:
    LinkedList();
    ~LinkedList();
    void clear(Node * root);
    void add(int value);
    void remove(int value);
    void removefirst();
    bool contains(int value);
    int getsize();
    void print();
    int in(int index);

};


}