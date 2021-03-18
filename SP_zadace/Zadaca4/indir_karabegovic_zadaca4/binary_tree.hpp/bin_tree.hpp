#pragma once

#include<iostream>
#include<utility>
#include<cstddef>


template<typename T>
class bin_tree{
  public:
    bin_tree();
    bin_tree(const bin_tree&);
    bin_tree(bin_tree&&);
    bin_tree& operator=(const bin_tree&);
    bin_tree& operator=(bin_tree&&);
    ~bin_tree()=default;
    template<typename U>
      void add(U&&);
    void printInOrder() const;
    void printPreOrder() const;
    void printPostOrder() const;
    bool find(const T& value) const;



  private:
    struct Node{
      T value;
      Node* leftChild;
      Node* rightChild;

      Node(const T& v) : value{v}, leftChild{nullptr}, rightChild{nullptr} {}
    };
    template<typename U>
      void addIntoNode(Node*,U&&);
    void printNodeInOrder(Node* node) const;
    void printNodePreOrder(Node* node) const;
    void printNodePostOrder(Node* node) const;
    bool findValue(Node* node,const T& value) const ;
    Node* root_;
    size_t size_;

};

template<typename T>
bin_tree<T>::bin_tree() {
  root_=nullptr;
  size_=0;
}

template<typename T>
template<typename U>
void bin_tree<T>::add(U&& value){
  if(root_==nullptr){
    root_=new Node(std::forward<U>(value));
  }
  else{
  addIntoNode(root_,std::forward<U>(value));
  }
  size_++;
}

template<typename T>
template<typename U>
void bin_tree<T>::addIntoNode(Node* node,U&& value){
  if(node->value>value){
    if(node->leftChild!=nullptr)
    addIntoNode(node->leftChild,value);
    else{
      node->leftChild=new Node(value);
    }
  }
  else if(node->value<value){
    if(node->rightChild!=nullptr)
    addIntoNode(node->rightChild,value);
    else{
      node->rightChild=new Node(value);
    }
  }
}

template<typename T>
void bin_tree<T>::printInOrder() const {
  printNodeInOrder(root_);
}

template<typename T>
void bin_tree<T>::printNodeInOrder(Node* node) const {
  if(node->leftChild!=nullptr)
    printNodeInOrder(node->leftChild);
  std::cout<<node->value<<std::endl;
  if(node->rightChild!=nullptr)
    printNodeInOrder(node->rightChild);
}

template<typename T>
bool bin_tree<T>::find(const T& value) const{
  auto isfound=findValue(root_,value);
  return isfound;
}

template<typename T>
bool bin_tree<T>::findValue(Node* node, const T& value) const {
  if (node->value==value){
    return true;
  }
  if(node->value>value && node->leftChild!=nullptr){
    findValue(node->leftChild, value);
  }
  else if(node->value<value && node->rightChild!=nullptr){
    findValue(node->rightChild, value);
  }
  else
  return false;
}


template<typename T>
void bin_tree<T>::printPreOrder() const {
  printNodePreOrder(root_);
}

template<typename T>
void bin_tree<T>::printNodePreOrder(Node* node) const {
  std::cout<<node->value<<std::endl;
  if(node->leftChild!=nullptr)
    printNodePreOrder(node->leftChild);
  if(node->rightChild!=nullptr)
    printNodePreOrder(node->rightChild);
}

template<typename T>
void bin_tree<T>::printPostOrder() const {
  printNodePostOrder(root_);
}

template<typename T>
void bin_tree<T>::printNodePostOrder(Node* node) const {
  if(node->leftChild!=nullptr)
    printNodePostOrder(node->leftChild);
  if(node->rightChild!=nullptr)
    printNodePostOrder(node->rightChild);
std::cout<<node->value<<std::endl;
}


