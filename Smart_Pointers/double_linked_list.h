#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <vector>
#include <memory>
#include <iostream>

template<typename T>
struct Node {
    explicit Node(T val)
            : value{val}
    {}
    ~Node() {
        std::cout << "Node " << value << " destroyed\n";
    }

    Node(const Node&) = default;
    Node(Node&&) = default;
    Node& operator=(const Node&) = default;
    Node& operator=(Node&&) = default;

    T value;
    std::shared_ptr<Node> next = nullptr;
    std::weak_ptr<Node> previous; // using a shared_ptr would introduce circular dependencies
};

template<typename T>
class DoubleLinkedList {
public:
    void push_front (T x);
    void push_back (T x);
    std::vector<T> get_nodes_forward() ;
    std::vector<T> get_nodes_reverse ();
private:
    std::shared_ptr<Node<T>> front = nullptr;
    std::shared_ptr<Node<T>> back = nullptr;
};

template<typename T>
void DoubleLinkedList<T>::push_front(T x)
{
    const auto n = std::make_shared<Node<T>>(x);
    if( not front) {
        front = n;
        back = n;
    } else {
        front->previous = n;
        n->next = front;
        front = n;
    }
}

template<typename T>
void DoubleLinkedList<T>::push_back(T x)
{
    const auto n = std::make_shared<Node<T>>(x);
    if( not back) {
        front = n;
        back = n;
    } else {
        back->next = n;
        n->previous = back;
        back = n;
    }
}

template<typename T>
std::vector<T> DoubleLinkedList<T>::get_nodes_forward()
{
    auto temp = front;
    std::vector<T> out;
    while(temp) {
        out.push_back(temp->value);
        temp = temp->next;
    }
    return out;
}

template<typename T>
std::vector<T> DoubleLinkedList<T>::get_nodes_reverse()
{
    auto temp = back;
    std::vector<T> out;
    while(temp) {
        out.push_back(temp->value);
        temp = temp->previous.lock();
    }
    return out;
}

#endif
