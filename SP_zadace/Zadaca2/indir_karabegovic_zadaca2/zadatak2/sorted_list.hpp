#pragma once


#include<iostream>
#include<iterator>

#include"node.hpp"


template<typename T>
class sorted_list{
  private:
    Node<T>* first_=nullptr;
    Node<T>* last_=nullptr;
    size_t size_;
  public:
    sorted_list();   //implementirano
    sorted_list(const sorted_list& other);  //implementirano
    sorted_list(sorted_list&& other);   //implementirano
    sorted_list& operator=(const sorted_list& other);  //implementirano
    sorted_list& operator=(sorted_list&& other); //implementirano
    ~sorted_list();  //implementirano
    class iterator; //implementirano 
    iterator begin() {return iterator(nullptr,first_);}  //implementirano 
    iterator end() {return iterator(last_,nullptr);}  //implementirano
    template<typename U>
    void add(U&&);  //implementirano
    iterator find(const T&); //implementirano

    template<typename U> 
    iterator find_if(U predicate); //implementirano 
    void remove(iterator it);  //implementirano 
    size_t size() const { return size_;}  //implementirano
    bool empty() const { return size_==0;}  //implementirano
    void clear();  //implementirano

};

template<typename T>
sorted_list<T>::sorted_list(){
  size_=0;
  first_=nullptr;
  last_=nullptr;
}

template<typename T>
sorted_list<T>::sorted_list(const sorted_list<T>& other){
  auto temp=other.first_;
  for(auto i=0;i<other.size_;i++){
    add(temp->value_);
    temp=temp->next_;
  }
}

template<typename T>
sorted_list<T>::sorted_list(sorted_list<T>&& other){
  size_=other.size_;
  first_=other.first_;
  last_=other.last_;
  other.size_=0;
  other.first_=other.last_=nullptr;
  delete other.first_;
  delete other.last_;
}

template<typename T>
sorted_list<T>& sorted_list<T>::operator=(const sorted_list& other){
  if(first_!=other.first_){
    clear();
    auto temp=other.first_;
    for(auto i=0;i<other.size_;i++){
      add(temp->value_);
     temp=temp->next_;
    }
  }
  return *this;
}

template<typename T>
sorted_list<T>& sorted_list<T>::operator=(sorted_list&& other){
  clear();
  size_=other.size_;
  first_=other.first_;
  last_=other.last_;
  other.size_=0;
  other.first_=other.last_=nullptr;
  delete other.first_;
  delete other.last_;
}

template<typename T>
sorted_list<T>::~sorted_list(){
clear();
}

template<typename T>
class sorted_list<T>::iterator : 
public std::iterator<std::bidirectional_iterator_tag, T>{
  private:
    Node<T>* myNode_=nullptr;
    Node<T>* prevNode_=nullptr;
  public:
    iterator( Node<T>* prevn,Node<T>* curr){
      myNode_=curr;
      prevNode_=prevn;
    }
    T& operator*() {return myNode_->value_;}
    const T& operator*() const {return myNode_->value_;}
    
    iterator& operator++() { prevNode_=myNode_; myNode_=myNode_->next_; return *this;}
    iterator& operator--() { myNode_=prevNode_; prevNode_=prevNode_->prev_; return *this;}
    iterator operator++(int) { auto temp=*this; prevNode_=myNode_; myNode_=myNode_->next_; return temp;}
    iterator operator--(int) {auto temp=*this; myNode_=prevNode_; prevNode_=prevNode_->prev_; return temp;}

    bool operator==(const iterator& other) {return myNode_==other.myNode_;}
    bool operator!=(const iterator& other) {return myNode_!=other.myNode_;}

    friend class sorted_list;
};


template<typename T>
template<typename U>
void sorted_list<T>::add(U&& value){
  auto new_node=new Node<T>(std::forward<U>(value));
  if(empty()){
    first_=new_node;
    last_=new_node;
    size_++;
  }
  else{
    if(new_node->value_<=first_->value_){
      first_->prev_=new_node;
      new_node->next_=first_;
      first_=new_node;
      size_++;
    }
    else if(new_node->value_>=last_->value_){
      last_->next_=new_node;
      new_node->prev_=last_;
      last_=new_node;
      size_++;
    }
    else{
      auto temp=first_;
      while(new_node->value_>temp->value_){
        temp=temp->next_;
      }
      new_node->next_=temp;
      new_node->prev_=temp->prev_;
      temp->prev_->next_=new_node;
      temp->prev_=new_node;
      size_++;
    }
  }
}


template<typename T>
void sorted_list<T>::clear(){
  auto temp=first_;
  while(first_){
    temp=first_;
    first_=first_->next_;
    delete temp;
  }
  first_=last_=nullptr;
  size_=0;
}


template<typename T>
typename sorted_list<T>::iterator sorted_list<T>::find(const T& value){
  for(auto iter=begin();iter!=end();iter++){
    if((*iter)==value){
      return iter;
    }
  }
  return end();
}

template<typename T>
template<typename U>
typename sorted_list<T>::iterator sorted_list<T>::find_if(U predicate){
  for(auto iter=begin();iter!=end();iter++){
    if(predicate(*iter)){
        return iter;
        }
  }
}

template<typename T>
void sorted_list<T>::remove(iterator it){
  if(empty()){
    return;
  }
  if(size_==1){
    first_=nullptr;
    last_=nullptr;
    delete it.myNode_;
    size_--;
    return;
  }
  if(it==begin()){
    first_=it.myNode_->next_;
    first_->prev_=nullptr;
      delete it.myNode_;
  }
  else if(it==--end()){
    last_=it.myNode_->prev_;
    last_->next_=nullptr;
    delete it.myNode_;
  }
  else{
  it.myNode_->next_->prev_=it.myNode_->prev_;
  it.myNode_->prev_->next_=it.myNode_->next_;
  delete it.myNode_;
  }
  size_--;
}


