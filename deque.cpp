#include <iostream>

using namespace std;

class Node{
public:
  int data;
  Node *next;
  Node *previous;
};

class Deck{
private:
    int count;
    Node *head;
    Node *back;

public:

  Deck(){
    count = 0;
    head = nullptr;
  }

  void push_front(){

    Node *node = new Node;
    cout << "Value to node: " << endl;
    cin >> node->data;

    if(head == nullptr){
      head = node;
      node->next = nullptr;
      node->previous = nullptr;
      count++;
    }
  }

  void push_back(){

    Node *node = new Node;
    cout << "Value to node:" << endl;
    cin >> node->data;

    if(head == nullptr){
      back = node;
      node->next = nullptr;
      node->previous = nullptr;
      head = node;
      count++;
    }
  }

  void pop_front(){

    if(head == nullptr){
      cout << "Empty list" << endl;
    }
    else
    {
      Node *node = head;
      head = node->next;
      delete node;
      count--;
    }
  }

  void pop_back(){

    if(head == nullptr){
      cout << "Empty list" << endl;
    }
    else
    {
      Node *node = back;
      back = node->previous;
      delete node;
      count--;
    }
  }

  void print_deck(){

    Node *node = head;
    cout << "--DECK--" << endl;

    while(node != nullptr){
      cout << "|" << node->data << "|" << endl;
      node = node->next;
    }
  }
};

int main(){

  Deck deck;

  int qtd = 0;
  cout << "Press a qtd to node:" << endl;
  cin >> qtd;

  for(int i = 0; i < qtd; i++){
    deck.push_front();
  }

  deck.print_deck();

  for(int i = 0; i < qtd; i++){
    deck.push_back();
  }

  deck.print_deck();

  return 0;
}