#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <vector>
/*
* A simple double linked list implementation taken from
* http://www.cprogramming.com/snippets/source-code/double-linked-list-cplusplus
*/
template<typename T>
struct Node
{
  T value;
  Node *N,*P;
  Node(T y)
  {
      value = y;
      N = P = 0;
  }
};

template<typename T>
class DoubleLinkedList
{
  Node<T> *front;
  Node<T> *back;
  public:
  DoubleLinkedList()
  {  front = 0; back = 0; }
  ~DoubleLinkedList(){ destroy_list();}
  void push_front(T x);
  void push_back(T x);
  std::vector<T> get_nodes_forward();
  std::vector<T> get_nodes_reverse();
  void destroy_list();
};

template<typename T>
void DoubleLinkedList<T>::push_front(T x)
{
      Node<T> *n = new Node<T>(x);
      if( front == 0)
      {
          front = n;
          back = n;
      }
      else
      {
          front->P = n;
          n->N = front;
          front = n;
      }
}

template<typename T>
void DoubleLinkedList<T>::push_back(T x)
{
      Node<T> *n = new Node<T>(x);
      if( back == 0)
      {
          front = n;
          back = n;
      }
      else
      {
          back->N = n;
          n->P = back;
          back = n;
      }

}

template<typename T>
std::vector<T> DoubleLinkedList<T>::get_nodes_forward()
{
    Node<T> *temp = front;
    std::vector<T> out;
    while(temp != 0)
    {
       out.push_back(temp->value);
       temp = temp->N;
    }
    return out;
}

template<typename T>
std::vector<T> DoubleLinkedList<T>::get_nodes_reverse()
{
    Node<T> *temp = back;
    std::vector<T> out;
    while(temp != 0)
    {
       out.push_back(temp->value);
       temp = temp->P;
    }
    return out;
}

template<typename T>
void DoubleLinkedList<T>::destroy_list()
{
    Node<T> *temp = back;
    while(temp != 0)
    {
        Node<T> *temp2 = temp;
        temp = temp->P;
        delete temp2;
    }
    front = 0;
    back = 0;
}

#endif
