#include <iostream>
using namespace std;

template<class T>
class Stack {
private:
    template<class T>
    class Node {
    public:
        T datas;
        Node* next;

        Node(T datas = T(), Node* next = nullptr) : datas{ datas }, next{ next } {}
    };

    int size;
    Node<T>* top_node;

public:
    Stack() : size(0), top_node(nullptr) {}

    ~Stack() {
        while (!Empty()) {
            pop();
        }
    }

    int getSize() {
        return size;
    }

    bool Empty() {
        return size == 0;
    }

    void push(const T& datas) {
        Node<T>* newNode = new Node<T>(datas, top_node);
        top_node = newNode;
        size++;
    }

    T pop() {
        if (Empty()) {
            cout << "Stack is empty" << endl;
            return T();
        }

        Node<T>* tmp = top_node;
        T popped_data = tmp->datas;
        top_node = top_node->next;
        delete tmp;
        size--;
        return popped_data;
    }

    T& top() {
        if (Empty()) {
            cout << "Stack is empty" << endl;
            return top_node->datas;
        }
        return top_node->datas;
    }
    
    void Swap(Stack<T>& first, Stack<T>& second) {
        swap(first.size, second.size);
        swap(first.top_node, second.top_node);
    }
};

int main() {
    Stack<int> stk;

    stk.push(5);
    stk.push(10);
    stk.push(15);
    cout << "Size: " << stk.getSize() << endl;


}
