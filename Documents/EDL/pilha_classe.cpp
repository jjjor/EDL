#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class Stack{
private:
    int count;
    Node *head;

public:

    Stack(){
        count = 0;
        head = nullptr;
    }

    void push() {
    Node *node = new Node;
    cout << "Value to node: ";
    cin >> node->data;

    if (head == nullptr) {
        head = node;
        node->next = nullptr;
        count++;
    } else {
        node->next = head;
        head = node;
        count++;
    }
}


    void print_stack(){

        Node *node = head;
        cout << "--STACK--" << endl;

        while (node != nullptr){
            cout << "|" << node->data << "|" << endl;
            node = node->next;
        }

    }

    void reverse_stack()
    {
        Node *node = head;
        Node *prev = nullptr;
        Node *next = nullptr;
        while (node != nullptr)
        {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
            head = prev;
        }
    }
};


int main(){

    Stack stack1;
    Stack stack2;

    int qtd = 0;
    cout << "Press a qtd to value: " << endl;
    cin >> qtd;

    for (int i = 0; i < qtd; i++)
    {
        stack1.push();
    }

    //for (int i = 0; i < qtd; i++)
    //{
    //    stack2.push();
    //}


    stack1.print_stack();
    stack1.reverse_stack();
    stack1.print_stack();
}