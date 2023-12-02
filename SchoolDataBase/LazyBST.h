#ifndef LazyBST_H
#define LazyBST_H
#include "TreeNode.h"
#include "Student.h"
#include "Faculty.h"
template <typename T>
class LazyBST{
    public:
        LazyBST();
        virtual ~LazyBST();
        bool isEmpty();
        int getSize();
        void insert(T d);
        void remove(T d);
        bool contains(T d);
        T getMin();
        T getMax();
        void printTreeInOrder();
        TreeNode<T>* search(T key);
        void rebuildTree();
    private:
        TreeNode<T>* m_root;
        int m_size;
        void insertHelper(TreeNode<T>*& subTreeRoot,TreeNode<T>* newNode);
        bool containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* target);
        T getMinHelper(TreeNode<T>* subTreeRoot);
        T getMaxHelper(TreeNode<T>* subTreeRoot);
        void printTreeInOrderHelper(TreeNode<T>* subTreeRoot);
        void findTarget(T key, TreeNode<T>*& target,TreeNode<T>*& parent);
        TreeNode<T>* getSuccessor(TreeNode<T>* rightChild);
        void arrayHelper(TreeNode<T>*& subTreeRoot, T* arr, int& idx);
        void rebuildTreeHelper(T* arr, int start, int end);
};
// prints provided data
// @param data to be printed
template <typename T>
struct PrintTree {
    static void print(const T& data) {
        std::cout << data << std::endl;
    }
};
// templated specialization for type student
// @param student to be printed
template <>
struct PrintTree<Student> {
    static void print(const Student& student) {
        student.print();
    }
};
// templated specilization for type faculty
// @param faculty to be printed 
template <>
struct PrintTree<Faculty> {
    static void print(const Faculty& faculty) {
        faculty.print();
    }
};
// constructor for tree
template <typename T>
LazyBST<T>::LazyBST(){
    m_root = NULL;
    m_size = 0;
}
// destructor for tree
template <typename T>
LazyBST<T>::~LazyBST(){
    if(m_root != NULL){
        delete m_root;
    }
}
// gets the size of the tree
// @return integer representing size
// @param none
template <typename T>
int LazyBST<T>::getSize(){
    return m_size;
}
// inserts new data in to the tree 
// @return none
// @param T d representing the data to be inserted into the tree 
template <typename T>
void LazyBST<T>::insert(T d){
    TreeNode<T>* newNode = new TreeNode<T>(d);
    insertHelper(m_root,newNode);
    ++m_size;
}
// helper function for inserting a new node into the tree 
// @return none
// @param subTreeRoot reference to the root of the current subtree where the new node is to be inserted
// @param newNode pointer to the new node that is to be interested into the tree
template <typename T>
void LazyBST<T>::insertHelper(TreeNode<T>*& subTreeRoot,TreeNode<T>* newNode){
    if(subTreeRoot == nullptr){
        subTreeRoot = newNode;
    } else if(newNode->m_data < subTreeRoot->m_data){
        insertHelper(subTreeRoot->m_left,newNode);
    } else{
    insertHelper(subTreeRoot->m_right,newNode);
    }
}
// removes a node from the tree based on data
// @return none
// @param T d represeting the data to remove 
template <typename T>
void LazyBST<T>::remove(T d){
if(m_root != NULL){
    TreeNode<T>* target = NULL;
    TreeNode<T>* parent = NULL;
    target = m_root;
    findTarget(d,target,parent);
    if(target == NULL){ 
        return;
    }
    if(target->m_left==NULL && target->m_right==NULL){ 
        if(target == m_root){
            m_root = NULL;
        } else{
            if(target == parent->m_left){
                parent->m_left = NULL;
            } else {
                parent->m_right = NULL;
            }
        }
        } else if(target->m_left!=NULL && target->m_right!=NULL){
            TreeNode<T>* suc = getSuccessor(target->m_right);
            T value = suc->m_data;
            remove(value);
            target->m_data = value;
        } else {
            TreeNode<T>* child; 
            if(target->m_left != NULL){
                child = target->m_left;
            } else{
                child = target->m_right;
            }
            if(target == m_root){
                m_root = child;
            } else{ 
            if(target == parent->m_left){
                parent->m_left = child;
            } else {
                parent->m_right = child;
            }
        }
    }
}
    --m_size;
}
// checks to see if the tree contains apiece of data
// @return boolean indicating whether or not the tree contains a piece of data
// @param T d piece of data to compare whether the tree contains it or nit
template <typename T>
bool LazyBST<T>::contains(T d){
    TreeNode<T>* newNode = new TreeNode<T>(d);
    bool ret = containsHelper(m_root,newNode);
    delete newNode;
    return ret;
}
// helper for the contains method
// @return boolean indicating if the piece of data was found
// @param subTreeRoot pointer to the root of the current subtree
// @param target pointer to the target node
template <typename T>
bool LazyBST<T>::containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* target){
    if(subTreeRoot == NULL){
        return false;
    } else if(target->m_data < subTreeRoot->m_data){
        return containsHelper(subTreeRoot->m_left,target);
    } else if (target->m_data > subTreeRoot->m_data){
        return containsHelper(subTreeRoot->m_right,target);
    } else{
       return true;
    }
}
// returns minimum value of the tree
// @return T data representing minimum value
// @param none
template <typename T>
T LazyBST<T>::getMin(){
    if(m_root == NULL){
        return;
    }else{
        return getMinHelper(m_root);
    }
}
// helper function for the get min function
// @return T representing min value from subtree root
// @param pointer representing current subtreeroot
template <typename T>
T LazyBST<T>::getMinHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot->m_left == NULL){
        return subTreeRoot->m_data;
    } else{
        return getMinHelper(subTreeRoot->m_left);
    }
}
// returns maximum value from the tree
// @return T representing maximum value from the tree
// @param none
template <typename T>
T LazyBST<T>::getMax(){
    if(m_root == NULL){
        return;
    }else{
        return getMaxHelper(m_root);
    }
}
// helper function for the get max function
// @return T representing the max data from the current subtree 
// @param pointer representing current root of subtree
template <typename T>
T LazyBST<T>::getMaxHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot->m_right == NULL){
        return subTreeRoot->m_data;
    } else{
        return getMaxHelper(subTreeRoot->m_right);
    }
}
// prints the tree in order
// @return none
// @param none
template <typename T>
void LazyBST<T>::printTreeInOrder(){
    printTreeInOrderHelper(m_root);
}
// helper method for printTreeInOrder method
// @return none
// @param pointer representing current root of subtree 
template <typename T>
void LazyBST<T>::printTreeInOrderHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot == NULL){
        cout << "TREE IS NULL" << endl;
        return;
    }
    if(subTreeRoot->m_left != NULL){
        printTreeInOrderHelper(subTreeRoot->m_left);
    }
        PrintTree<T>::print(subTreeRoot->m_data);
    if(subTreeRoot->m_right != NULL){
        printTreeInOrderHelper(subTreeRoot->m_right);
    }
}
// searches for a node with the specified key in the binary search tree
// @return none
// @param key the target data to search for
// @param target reference to a pointer that will be updated to point to the target node
// @param parent reference to a pointe rthat will be updated to point to the parent of the target node
template <typename T>
void LazyBST<T>::findTarget(T key, TreeNode<T>*& target,TreeNode<T>*& parent){
    while(target != nullptr && target->m_data != key){
        parent = target;
        if(key < target->m_data){
            target = target->m_left;
        } else{
            target = target->m_right;
        }
    }
}
// finds and returns the leftmost node in the given subtree
// @return treenode pointer to the leftmost node in the subtree of rightchild
// @param rightchild pointer to the root of the right subtree
template <typename T>
TreeNode<T>* LazyBST<T>::getSuccessor(TreeNode<T>* rightChild){
    while(rightChild->m_left != NULL){
        rightChild = rightChild->m_left;
    }
    return rightChild;
}
// rebuilds tree when it gets unbalanced beyond depth of 1.5
// @return none
// @param none
template <typename T>
void LazyBST<T>::rebuildTree(){
    T* arr = new T[m_size];
    int idx = 0;
    if(m_root != NULL){
        arrayHelper(m_root, arr, idx);
        delete m_root;
        m_root = nullptr;
        rebuildTreeHelper(arr, 0, m_size-1);
    }
    delete[] arr;
}
// traverses the tree in order and populates array with its elements
// @param subtree root reference to the current root of the subtree being processed
// @param arr pointer to an array where the elements of the tree will be stored
// @param idx integer reference to the currrent index of an array
template <typename T>
void LazyBST<T>::arrayHelper(TreeNode<T>*& subTreeRoot, T* arr, int& idx){
    if(subTreeRoot->m_left != NULL){
        arrayHelper(subTreeRoot->m_left, arr, idx);
    }
    arr[idx++] = subTreeRoot->m_data;
    if(subTreeRoot->m_right != NULL){
        arrayHelper(subTreeRoot->m_right, arr, idx);
    }
}
// helper function for the rebuildtree function
// @return none
// @param T* arr pointer to the array containing the elements of the tree
// @param start integer reprenting the start of the current subarray
// @param end integer presenting the end of the current subarray
template <typename T>
void LazyBST<T>::rebuildTreeHelper(T* arr, int start, int end){
    if(start > end){
        return;
    }
    int mid = (start + end) / 2;
    insert(arr[mid]);
    rebuildTreeHelper(arr, start, mid-1);
    rebuildTreeHelper(arr, mid+1, end);
}
// searches the tree for a piece of data based on key
// @return pointer to tree node that contains target data
// @param T key representing piece of data to be searched for
template <typename T>
TreeNode<T>* LazyBST<T>::search(T key) {
    TreeNode<T>* target = m_root;
    TreeNode<T>* parent = nullptr;
    findTarget(key, target, parent);
    return target;
}
// inidcates whether or not the tree is empty 
// @return boolean representing whether or not the tree is empty 
// @param none
template<typename T>
bool LazyBST<T>::isEmpty() {
    return(m_root == NULL);
}

#endif