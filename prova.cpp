#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class list {
private:
    int count;
    Node *head;

public:
    list(){
        count = 0;
        head = nullptr;
    }

    bool empty_yn(){
        return count == 0;
    }

    int size(){
        return count;
    }

    void push(int data) {
        Node *new_node = new Node();
        new_node->data = data;
        new_node->next = nullptr;

        if (empty_yn()) {
            head = new_node;
        } else {
            new_node->next = head;
            head = new_node;

        }

        count++;
    }

    void remove_repeated(){
        if (head == nullptr) {
            return;
        }   

        Node *current = head;

        while (current != nullptr) {
            Node *runner = current;

            while (runner->next != nullptr) {
                if (runner->next->data == current->data) {
                    Node *repeated = runner->next;
                    runner->next = runner->next->next;
                    delete repeated;
                    count--;

                } else {
                    runner = runner->next;
                }
            }

            current = current->next;
        }
    }

    void invert(){
        if (head == nullptr) {
            return;
        }

        //aponta pro topo
        Node *current = head;

        Node *previous = nullptr;
        Node *next = nullptr;

        while (current != nullptr) {
            //guarda o proximo nó
            next = current->next;

            //inverte o ponteiro do nó atual
            current->next = previous;

            //atualiza o valor dos ponteiros
            previous = current;

            //atualiza o nó
            current = next;
        }

        //atualiza o topo da lista
        head = previous;
    }

    void print() {
        Node *current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;   
    }
};

int main() {

    list list;

    list.push(1);
    list.push(2);
    list.push(3);
    list.push(3);
    list.push(4);

    cout << "tamanho da lista: " << list.size() << endl;
    cout << "lista antes de ser filtrada:" << endl;
    list.print();

    list.remove_repeated();

    cout << endl;

    cout << "tamanho da lista: " << list.size() << endl;
    cout << "lista depois de ser filtrada:" << endl;
    list.print();

    list.invert();

    cout << endl;

    cout << "lista depois de ser invertida" << endl;
    list.print();

    return 0;

};

