#include "LinkedList.h"
#include"Node.h"
#include <string>
#include <limits>
using namespace std;
#include<string>
#include<iostream>
LinkedList::LinkedList(){
    head=nullptr;
}
LinkedList::LinkedList(int array[], int size){
    for (int i=0;i<size;i++){
        addEnd(array[i]);
    }

}
void LinkedList::addFront(int newItem){ 
    //head is address of first node;
     Node* first_node=head;
   Node* added_node=new Node();
   
    added_node->set_data(newItem);
    //make the new added node point to the head node
     if(first_node!=NULL){
        //added_node->set_next(first_node) also work;
        added_node->next=first_node;
     }
    //make the head as the address of the new created node
    head=added_node;
    
}
void LinkedList::addEnd(int newItem){
    if (head==NULL){
        addFront(newItem);
        return;}
    Node* added_node=new Node();
    added_node->set_data(newItem);
    added_node->set_next(nullptr);
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=added_node;
}
void LinkedList::addAtPosition(int position, int newItem){
    int size=0;
    Node*temp=head;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    if(position<1||position==1){
        addFront(newItem);
    }
    if(position>size){
        addEnd(newItem);
    }
    else{
        Node* added_node=new Node();
        Node* prev=head;
        Node* curr=head;
        for (int i=1;i<position;i++){
            prev=curr;
            curr=curr->next;
        }
        added_node->set_data(newItem);
        //Point the next pointer of the new added node to the original node at position x
        
        added_node->next=curr;//added_node->set_next(curr); also work
        //Point the previous node below position x to the new added node.
        prev->next=added_node;

    }
}

int LinkedList::search(int item){
    Node*new_node=head;
    int size=0;
    while(new_node!=NULL){
        size++;
        new_node=new_node->next;
    }
    for (int i=0;i<size;i++){
        if(new_node->get_data()==item){
            cout<<new_node->get_data()<<" ";
            return new_node->get_data();
        }
        else{
            cout<<"0"<<" ";
            return 0;
        }
    }
}
void LinkedList::deleteFront(){
    if(head==NULL){
        return;
    }
        Node* temp = head;
        head = head->next;
        delete temp;
        

}
void LinkedList::deleteEnd(){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        head=nullptr;
    }
     Node* temp = head;
     //search for second last node
     while(temp->next->next!=NULL){
        temp=temp->next;
    }
    //delete last node
    delete temp->next;
    //what is after second last node is value null
    temp->next=NULL;
}


void LinkedList::deletePosition(int position){
    int size=0;
    Node*temp=head;
    while(temp!=NULL){
        size=size+1;
        temp=temp->next;
    }
    if(position<1 || position>size){
        cout << "outside range";
    }
    if (position==size){
        deleteEnd();
    }
    if (position==1){
        deleteFront();
    }
    else{
        Node* prev=head;
        Node* curr=head;
        for (int i=1;i<position-1;i++){
            prev=prev->next;
        }
       // for (int i=1;i<position;i++){
            //curr=curr->next;
       // }
        prev->next=prev->next->next;
        //delete curr;
    }
}
int LinkedList::getItem(int position){
    int size=0;
    Node*temp=head;
    while(temp!=NULL){
        size=size+1;
        temp=temp->next;
    }
    if(position>size){
        cout<< numeric_limits <int>::max() <<" ";
        return numeric_limits <int>::max();
    }
    else{
        temp=head;
        for (int i=1;i<position;i++){
            temp=temp->next;
        }
        cout << temp->get_data() <<" ";
        return temp->get_data();
    }
}

void LinkedList::printItems(){
    int size=0;
    Node*temp=head;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    temp=head;
    for (int i=0;i<size;i++){
        cout <<temp->get_data() << " ";
        temp=temp->next;
    }
}
LinkedList::~LinkedList(){
    Node* temp=head;
	Node* prev;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
        delete prev;
    }
	delete temp;
}



