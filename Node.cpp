#include "Node.h"
#include <iostream>
using namespace std;
Node::Node(){
    next=nullptr;
    data=0;

}
int Node::get_data(){
    return data;
}
void Node::set_data(int x){
   data=x;
}
Node*Node::get_next(){
    return next;
}
void Node::set_next(Node* x){
    next=x;
}