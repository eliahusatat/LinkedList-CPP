//#pragma once
#include<iostream>
#include "LinkedList.hpp"

using namespace ll;
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
       // cout<<"l1.at(3)"<<l1.in(3)<<endl;
        //l1.removefirst();
       // l1.removefirst();
       // l1.removefirst();
        //l1.removefirst();
        l1.remove(6);
        l1.remove(1);
        cout<<l1.contains(1)<<endl;
        cout<<false<<endl;
        l1.remove(2);
        
        l1.print();
        //cout<<"size: "<<l1.getsize()<<endl;
        return 0 ;
    }
