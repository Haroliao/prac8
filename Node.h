#ifndef NODE_H
#define NODE_H
class Node{
    public:
    Node* next;
    Node();
    int data;
    int get_data();
    void set_data(int x);
    Node* get_next();
    void set_next(Node* x);

};
#endif