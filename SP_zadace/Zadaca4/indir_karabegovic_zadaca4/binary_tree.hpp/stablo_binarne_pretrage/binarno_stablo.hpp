#pragma once

#include<iostream>
#include<utility>


template<typename T>
class binarno_stablo{
  public:
    binarno_stablo();
    binarno_stablo(const binarno_stablo&);
    binarno_stablo(binarno_stablo&&);

    binarno_stablo& operator=(const binarno_stablo&);
    binarno_stablo& operator=(binarno_stablo&&);

    ~binarno_stablo()=default;
    template<typename U>
      void add(U&&);
    void print() const;
    inline size_t size() const { return size_;}
    bool find(const T& value);

  private:
    struct Node{
      T value;
      Node* leftChild;
      Node* rightChild;

      Node(const T& v) : value{v}, leftChild{nullptr}, rightChild{nullptr} {};
    };
    inline bool empty() const {return size_==0;}
    template<typename U>
      void addIntoNode(Node*,U&&);
    void printNode(Node* node) const;
    Node* root_;
    size_t size_;
    bool findNode(Node* node,const T& value);

};

template<typename T>
binarno_stablo<T>::binarno_stablo(){
  root_=nullptr;
  size_=0;
}

template<typename T>
template<typename U>
void binarno_stablo<T>::add(U&& value){
  if(empty()){
    root_=new Node{std::forward<U>(value)};
  }
  else{
    addIntoNode(root_,value);
  }
  size_++;
}

template<typename T>
template<typename U>
void binarno_stablo<T>::addIntoNode(Node* node,U&& value){
  if(value<node->value){
    if(node->leftChild!=nullptr){
      addIntoNode(node->leftChild,value);
    } else {
      node->leftChild=new Node{std::forward<U>(value)};
    }
  }
  else{
    if(node->rightChild!=nullptr){
      addIntoNode(node->rightChild,value);
    } else {
      node->rightChild=new Node{std::forward<U>(value)};
    }
  }
}

template<typename T>
void binarno_stablo<T>::print() const {
  printNode(root_);
}


template<typename T>
void binarno_stablo<T>::printNode(Node* node) const {
  //std::cout<<node->value<<std::endl; //za pre-order
  if(node->leftChild!=nullptr){
    printNode(node->leftChild);
  }
  //std::cout<<node->value<<std::endl; // za in-order
  if(node->rightChild!=nullptr){
    printNode(node->rightChild);
  } 
   std::cout<<node->value<<std::endl; // za post-order
};


template<typename T>
bool binarno_stablo<T>::find(const T& value){
  auto temp=findNode(root_,value);
  return temp;
}

template<typename T>
bool binarno_stablo<T>::findNode(Node* node, const T& value){
  if(node==nullptr){
    return false;
  }
  if(value==node->value){
    return true;
  }
  else if(value<node->value){
    findNode(node->leftChild,value);
  }
  else if(value>node->value){
    findNode(node->rightChild,value);
  }
}
