#ifndef TREE_NODE_H
#define TREE_NODE_H
#include <cstdlib>
#include <iostream>
using namespace std;
template <typename T>
class TreeNode{
    public:
        TreeNode(T d);
        virtual ~TreeNode();
        T getData();
        template <typename S>
        friend class LazyBST;
    private:
        TreeNode<T>* m_left;
        TreeNode<T>* m_right;
        T m_data;
};
// constructor for treenode
// @param T d data to be contained by node
template <typename T>
TreeNode<T>::TreeNode(T d){
    m_left = NULL;
    m_right = NULL;
    m_data = d;
}
// destructor for treenode
// @param none
template <typename T>
TreeNode<T>::~TreeNode(){
    if(m_left != NULL){
        delete m_left;
    }   
    if(m_right != NULL){
        delete m_right;
    }
}
// returns the data stored in the node
// @return the data stored in the node
// @param none
template <typename T>
T TreeNode<T>::getData(){
    return m_data;
}
#endif
