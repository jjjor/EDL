#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

struct Stack
{
    Node *head;
    int size;
};

Stack *init_stack()
{
    Stack *stack = new Stack;
    if (stack != nullptr)
    {
        stack->head = nullptr;
        stack->size = 0;
    }
    return stack;
}

void push_stack(Stack *stack)
{
    Node *node = new Node;
    cout << "Press a value to node: " << endl;
    cin >> node->value;
    if (stack->head == nullptr)
    {
        stack->head = node;
        node->next = nullptr;
        stack->size++;
    }
    else
    {
        node->next = stack->head;
        stack->head = node;
        stack->size++;
    }
}

void print_stack(Stack *stack)
{
    Node *node = stack->head;
    cout << "--STACK--" << endl;
    while (node != nullptr)
    {
        cout << "|" << node->value << "|" << endl;
        node = node->next;
    }
}
void reverse_stack(Stack *stack)
{
    Node *node = stack->head;
    Node *prev = nullptr;
    Node *next = nullptr;
    while (node != nullptr)
    {
        next = node->next;
        node->next = prev;
        prev = node;
        node = next;
        stack->head = prev;
    }
}

Stack *split_stack(Stack *stack)
{
    int half_size = stack->size / 2;
    Stack *new_stack = init_stack();
    Node *node = stack->head;
    if (half_size % 2 == 0)
    {
        for (int i = 0; i < half_size - 1; i++)
        {
            node = node->next;
        }
    }
    else
    {
        for (int i = 0; i < half_size; i++)
        {
            node = node->next;
        }
    }
    new_stack->head = node->next;
    node->next = nullptr;
    new_stack->size = stack->size - half_size;
    stack->size = half_size;
    return new_stack;
}

void remove_Duplicates(Stack *stack) {
        if (stack->head == nullptr) {
            return;
        }

        Node *current = stack->head;

        while (current != nullptr) {
            Node *runner = current;

            while (runner->next != nullptr) {
                if (runner->next->value == current->value) {
                    Node *duplicate = runner->next;
                    runner->next = runner->next->next;
                    delete duplicate;
                    stack->size--;
                } else {
                    runner = runner->next;
                }
            }

            current = current->next;
        }
    }

int main()
{
    Stack *stack = init_stack();
    int qtd = 0;
    cout << "Press a qtd to value: " << endl;
    cin >> qtd;
    for (int i = 0; i < qtd; i++)
    {
        push_stack(stack);
    }
    print_stack(stack);
    remove_Duplicates(stack);
    print_stack(stack);
    return 0;
}
