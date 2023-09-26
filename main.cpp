#include <iostream>
using namespace std;


class Node {
public:
  int data;
  Node* next;

  Node(int value) : data(value), next(nullptr) {}
};

class lista {
private:
  Node* head;

public:
  lista() : head(nullptr) {}

//função pra inserir elemento
  void inserir(int value) {
    Node* newNode = new Node(value);
    newNode -> next = head;
    head = newNode;
  }

//imprimir elementos da lista
  void display() {
    Node* current = head;
    while(current != nullptr) {
      cout << current -> data << " ";
      current = current -> next;
    }
    cout << endl;
  }
};


int main(){

  lista milista;
  
  milista.inserir(3);
  milista.inserir(2);
  milista.inserir(2);
  milista.inserir(1);
  
  cout << "Lista: " << endl;
  milista.display();

  return 0;
}
