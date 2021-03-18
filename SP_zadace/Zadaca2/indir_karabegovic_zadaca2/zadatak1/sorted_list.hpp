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
    void add(const T&);  //implementirano
    void add(T&&);
    iterator find(const T&); //implementirano

    template<typename U> 
    iterator find_if(U predicate); //implementirano 
    void remove(iterator it);  //implementirano 
    size_t size() const { return size_;}  //implementirano
    bool empty() const { return size_==0;}  //implementirano
    void clear();  //implementirano

    //neki dodatni metodi
    void invert();  //obrce redoslijed elemenata u listi
    void swap_elements(int pos1,int pos2); //mijenja vrijednost elemenata na pozicijama
    void revese_of(iterator it1,iterator it2); //obrce listu izmedju dva iteratora
    template<typename U>
    void push_back(U&&);  //dodavanje na kraj
    template<typename U>
    void push_front(U&&); //dodavanje na pocetak
    template<typename U>
    void insert_before(iterator it,U&&); //dodaje element ispred iteratora
    template<typename U>
    void insert_after(iterator it,U&&); //dodaje element iza iteratora
    void remove(iterator, iterator);   // brise listu izmedju dva iteratora
    void pop_back();   //brise zadnji
    void pop_front();  //brise prvi
    void sort_up();  //sortira u rastucem redoslijedu
    void sort_down(); //sortira u opadajucem redoslijedu
    template<typename U>
    void remove_if(U predicate); //brise ukoliko je ispunjen odg uslov
    void unique();  //brise duplirane elemente
    void find_pairs(const T& elem); // pronalazi par

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
void sorted_list<T>::add(const T& value){
  auto new_node=new Node<T>(value);
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
void sorted_list<T>::add(T&& value){
  auto new_node=new Node<T>(std::move(value));
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
  if(it==end()){
    throw std::invalid_argument("Invalid argument");
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





//Neki dodatni metodi koji mogu doci na provjeri

template<typename T>
void sorted_list<T>::invert(){
  auto prvi=begin();
  auto zadnji=--end();
  auto temp=zadnji;
  while(prvi!=zadnji && prvi!=temp){
    std::swap(*prvi,*zadnji);
    temp=zadnji;
    prvi++;
    zadnji--;
  }
 /* if(size_%2){
  while(prvi!=zadnji){
    std::swap(*prvi,*zadnji);
    prvi++;
    zadnji--;
  }
  }
  else{
    for(auto i=0;i<size();i+=2){
      std::swap(*prvi,*zadnji);
      prvi++;
      zadnji--;
    }
  }*/
}

template<typename T>
void sorted_list<T>::swap_elements(int pos1,int pos2){
  if(pos1>size_-1 || pos2>size_-1)
    throw std::invalid_argument("Invalid argument");
  auto it1=begin();
  for(auto i=0;i<pos1;i++){
    it1++;
  }
  auto it2=begin();
  for(auto i=0;i<pos2;i++){
    it2++;
  }
  std::swap(*it1,*it2);
}

template<typename T>
void sorted_list<T>::revese_of(iterator it1,iterator it2){
  auto prvi=it1;
  auto zadnji=it2;
  auto temp=zadnji;
  while(prvi!=zadnji && prvi!=temp){
    std::swap(*prvi,*zadnji);
    temp=zadnji;
    prvi++;
    zadnji--;
  }
}


template<typename T>
template<typename U>
void sorted_list<T>::push_back(U&& new_elem){
  auto new_node=new Node<T>(std::forward<U>(new_elem));
  if(size_==0){
    first_=new_node;
    last_=new_node;
    size_++;
  }
  else{
    new_node->prev_=last_;
    last_->next_=new_node;
    last_=new_node;
    size_++;
  }
}

template<typename T>
template<typename U>
void sorted_list<T>::push_front(U&& new_elem){
  auto new_node=new Node<T>(std::forward<U>(new_elem));
  if(size_==0){
    first_=last_=new_node;
    size_++;
  }
  else{
    first_->prev_=new_node;
    new_node->next_=first_;
    first_=new_node;
    size_++;
  }
}

template<typename T>
template<typename U>
void sorted_list<T>::insert_before(iterator it,U&& value){
  if(it==end()){
    throw std::invalid_argument("Invalid argument");
  }
  if(it==begin()){
    push_front(value);
  }
  else{
    auto new_node=new Node<T>(std::forward<U>(value));
    new_node->prev_=it.myNode_->prev_;
    new_node->next_=it.myNode_;
    it.myNode_->prev_->next_=new_node;
    it.myNode_->prev_=new_node;
    size_++;
  }
}

template<typename T>
template<typename U>
void sorted_list<T>::insert_after(iterator it,U&& value){
  if(it==end()){
    throw std::invalid_argument("Invalid arguement");
  }
  if(it==--end()){
    push_back(value);
  }
  else{
    auto new_node=new Node<T>(std::forward<U>(value));
    new_node->next_=it.myNode_->next_;
    new_node->prev_=it.myNode_;
    it.myNode_->next_->prev_=new_node;
    it.myNode_->next_=new_node;
    size_++;
  }
}

template<typename T>
void sorted_list<T>::pop_back(){
  if(size_==0)
    return;
  if(size_==1){
    delete first_;
    first_=last_=nullptr;
    size_=0;
  }
  else{
    auto temp=last_;
    last_=last_->prev_;
    last_->next_=nullptr;
    delete temp;
    size_--;
  }
}

template<typename T>
void sorted_list<T>::pop_front(){
  if(size_==0)
    return;
  if(size_==1){
    delete first_;
    first_=last_=nullptr;
  }
  else{
    auto temp=first_;
    first_=first_->next_;
    first_->prev_=nullptr;
    delete temp;
    size_--;
  }
}

template<typename T>
void sorted_list<T>::remove(iterator it1,iterator it2){
  for(auto iter=it1;iter!=it2;iter++){
    if(iter==end()){
      auto temp=it1;
      it1=it2;
      it2=temp;
      break;
    }
  }
  for(auto iter=it1;iter!=it2;iter++){
    remove(iter);
  }
}

template<typename T>
void sorted_list<T>::sort_up(){
  auto prvi=begin();
  auto zadnji=end();
  for(auto it=prvi;it!=zadnji;it++){
    for(auto it2=prvi;it2!=zadnji;it2++){
      if((*it)<(*it2)){
          std::swap(*it,*it2);
          
      }
    }
  }
}

template<typename T>
void sorted_list<T>::sort_down(){
  auto prvi=begin();
  auto zadnji=end();
  for(auto it=prvi;it!=zadnji;it++){
    for(auto it2=prvi;it2!=zadnji;it2++){
      if((*it)>(*it2)){
          std::swap(*it,*it2);
          
      }
    }
  }
}

template<typename T>
template<typename U>
void sorted_list<T>::remove_if(U predicate){
  for(auto it=begin();it!=end();it++){
    if(predicate(*it)){
      remove(it);
    }
  }
}

template<typename T>
void sorted_list<T>::unique(){
  for(auto it1=begin();it1!=end();it1++){
    for(auto it2=it1;it2!=end();it2++){
      if(it2!=it1){
        if(*it1==*it2){
          remove(it2);
        }
      }
    }
  }
}

template<typename T>
void sorted_list<T>::find_pairs(const T& elem){
  for(auto it1=begin();it1!=end();it1++){
    for(auto it2=begin();it2!=end();it2++){
      if((*it1)+*(it2)==elem){
        std::cout<<"("<<*it1<<","<<*it2<<")"<<std::endl;
      }
    }
  }
}
