#ifndef LIST_NODE_H
#define LIST_NODE_H
#include <cstdlib>
#include <iostream>
using namespace std;

template <typename T>
class ListNode{
    public:
    ListNode(T data);
    virtual ~ListNode();
    template<typename U>
    friend class DblList;

    private:
    T m_data;
    ListNode<T>* m_next;
    ListNode<T>* m_prev;
};
// constructor for list node
// @param T data representing data the node will contain
template <typename T>
ListNode<T>::ListNode(T data){
    m_data = data;
    m_next = nullptr;
    m_prev = nullptr;
}
// destructor for listnode
template <typename T>
ListNode<T>::~ListNode(){

}

#endif