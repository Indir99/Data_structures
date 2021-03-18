#pragma once

#include<cstddef>
#include<utility>
#include<iostream>


template<typename T>
class binary_tree{
  public:
    binary_tree();
    binary_tree(const binary_tree&);
    binary_tree(binary_tree&&);

    binary_tree& operator=(const binary_tree&);
    binary_tree& operator=(binary_tree&&);

    ~binary_tree();

    template<typename U>
      void add(U&& value);
    void print() const;
    bool find(const T& value);

    inline size_t size() const {
      return size_;
    }
    inline bool empty() const {
      return size_==0;
    }

    bool find(const T& value) const;
    bool erase(const T&);

  private:
    struct Node{
      T value;
      Node* leftChild;
      Node* rightChild;

      Node(const T& value) : value{value}, leftChild{nullptr},
        rightChild{nullptr} {}
    };
    template<typename U>
    void addIntoNode(Node* node, U&& value);
    void printNode(Node* node) const;
    void deleteNode(Node* node){
      if(node->leftChild){
    deleteNode(node->leftChild);
      }
      if(node->rightChild)
      {
    deleteNode(node->rightChild);
      }
    delete node;
};
    Node* root_;
    size_t size_;
};

template<typename T>
binary_tree<T>::binary_tree(){
  root_=nullptr;
  size_=0;
}

template<typename T>
template<typename U>
void binary_tree<T>::add(U&& value){
  if(empty()){
    root_=new Node(std::forward<U>(value));
  }
  else{
    addIntoNode(root_,value);
  }
  size_++;
}

template<typename T>
template<typename U>
void binary_tree<T>::addIntoNode(Node* node, U&& value){
  if(value<node->value){
    if(node->leftChild==nullptr){
      node->leftChild = new Node{std::forward<U>(value)};
    }else {
    addIntoNode(node->leftChild, value);
        }
  }else{
    if(node->rightChild==nullptr){
      node->rightChild = new Node{std::forward<U>(value)};
    }else {
    addIntoNode(node->rightChild, value);
        }
  }
}

template<typename T>
void binary_tree<T>::print() const {
  if(!empty()){
    printNode(root_);
  }
}

template<typename T>
void binary_tree<T>::printNode(Node* node) const{
  if(node->leftChild) print(node->leftChild);
  std::cout<<node->value<<std::endl;
  if(node->rightChild) print(node->rightChild);
  std::cout<<node->value<<std::endl;
}

template<typename T>
binary_tree<T>::~binary_tree() {
  if(!empty())
    deleteNode(root_);
}

// probati copy i operator jednako

//probati s rekurzijom
template<typename T>
bool binary_tree<T>::find(const T& value) const{
  auto current=root_;
  while(current!=nullptr){
    if(current->value==value){
      return true;
    }
    else if(value < current->value){
      current=current->leftChild;
    }
    else{
      current=current->rightChild;
    }
  }
  return false;
}

template<typename T>
bool binary_tree<T>::erase(const T& value){
  Node* parent = root_;
  Node* current = root_;
  while(current){
    if(current->value==value)
      break;
    if(value<current->value)
      current=current->leftChild;
    else
      current=current->rightChild;
  }
  if(!current) 
    return false;
  if(current->leftChild && current->rightChild){
    Node* temp=current;
    parent=current->leftChild;
    while(current->rightChild){
      parent=current;
      current=current->rightChild;
    }
    temp->value=std::move(current->value);
  }

  if(!current->leftChild && !current->rightChild){
//    std::cout<<"Node does not have any children"<<std::endl;
      if(parent->leftChild==current)
        parent->leftChild=nullptr;
      else
        parent->rightChild==nullptr;
      delete current;
  }
  else if(!current->rightChild){
    //slucaj kada samo imamo leftchild
    if(parent->leftChild==current)
      parent->leftChild=current->leftChild;
    else
      parent->rightChild=current->leftChild;
    delete current;
  }
  else if(!current->rightChild){
    //slucaj kada samo imamo rightChild
    if(parent->leftChild==current)
      parent->rightChild=current->leftChild;
    else
      parent->rightChild=current->rightChild;
  }

}
