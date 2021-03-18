#pragma once

#include<iostream>


template<typename T>
class Queue{
  private:
    T* elements_;
    int front_;
    int rear_;
    int size_;
    int capacity_;
    void realocate(int); //dodatni metod
  public:
    Queue();
    Queue(int);
    Queue(const Queue&);
    Queue(Queue&&);
    Queue& operator=(const Queue&);
    Queue& operator=(Queue&&);
    ~Queue();
    template<typename U>
    void push(U&&);
    T pop();
    T& front();
    T& back();
    const T& front() const;
    const T& back() const;
    int size() { return size_;}
    int capacity() {return capacity_;}
    bool empty() { return size_==0;}
    //dodatni metodi
    void reverse();
    void swap(Queue& other);
};

template<typename T>
Queue<T>::Queue(){
  capacity_=20;
  elements_=new T[20];
  front_=-1;
  rear_=-1;
  size_=0;
}

template<typename T>
Queue<T>::Queue(int max_cap){
  capacity_=max_cap;
  elements_=new T[max_cap];
  front_=-1;
  rear_=-1;
  size_=0;
}

template<typename T>
Queue<T>::Queue(const Queue& other){
   capacity_=other.capacity_;
   size_=other.size_;
   front_=other.front_;
   rear_=other.rear_;
   elements_=new T[capacity_];
   std::copy(other.elements_,other.elements_+capacity_,elements_);
 // std::cout<<"Okida copy"<<std::endl;
}

template<typename T>
Queue<T>::Queue(Queue&& other){
  elements_=other.elements_;
  capacity_=other.capacity_;
  front_=other.front_;
  rear_=other.rear_;
  size_=other.size_;
  other.elements_=nullptr;
 // std::cout<<"Okida move"<<std::endl;
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue& other){
  if(elements_!=other.elements_){
    delete [] elements_;
   capacity_=other.capacity_;
   size_=other.size_;
   front_=other.front_;
   rear_=other.rear_;
   elements_=new T[capacity_];
   std::copy(other.elements_,other.elements_+capacity_,elements_);
  }
  //std::cout<<"Okida kopi jednako"<<std::endl;
  return *this;
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue&& other){
  std::swap(elements_,other.elements_);
  std::swap(capacity_,other.capacity_);
  std::swap(size_,other.size_);
  std::swap(front_,other.front_);
  std::swap(rear_,other.rear_);
  //std::cout<<"Okida move jednako"<<std::endl;
  return *this;
}

template<typename T>
Queue<T>::~Queue(){
  delete [] elements_;
}

template<typename T>
template<typename U>
void Queue<T>::push(U&& new_elem){
  if(size_==capacity_){
    //throw std::out_of_range("Queue is full");
    realocate(2*capacity_);
  }
  if(size_==0){
    elements_[0]=std::forward<U>(new_elem);
    front_=0;
    rear_=0;
  }
  else{
    rear_=(rear_+1) % capacity_;
    elements_[rear_]=std::forward<U>(new_elem);
  }
  size_++;
}

template<typename T>
T Queue<T>::pop(){
  if(empty()){
    throw std::out_of_range("Queue is empty");
  }
  if(empty()){
    auto temp=front_;
    front_=-1;
    rear_=-1;
    size_=0;
    return std::move(elements_[temp]);
  }
  else{
    auto temp=front_;
    front_=(front_+1) % capacity_;
    size_--;
    return std::move(elements_[temp]);
  }
}

template<typename T>
T& Queue<T>::front(){
  if(empty()){
    throw std::out_of_range("Queue is empty");
  }
  else{
    return elements_[front_];
  }
}

//template<typename T>
template<typename T>
const T& Queue<T>::front() const {
  if(empty()){
    throw std::out_of_range("Queue is empty");
  }
  else{
    return elements_[front_];
  }
}

template<typename T>
T& Queue<T>::back(){
  if(empty()){
    throw std::out_of_range("Queue is empty");
  }
  else{
    return elements_[rear_];
  }
}

template<typename T>
const T& Queue<T>::back() const {
  if(empty()){
    throw std::out_of_range("Queue is empty");
  }
  else{
    return elements_[rear_];
  }
}

template<typename T>
void Queue<T>::realocate(int new_cap){
  auto temp=new T[new_cap];
  if(rear_>front_){
    std::copy(elements_,elements_+capacity_,temp);
    capacity_=new_cap;
    delete [] elements_;
    elements_=temp;
  }
  else{
    std::copy(elements_+front_,elements_+capacity_-1,temp);
    int i=capacity_-front_;
    std::copy(elements_,elements_+rear_,temp+i);
    capacity_=new_cap;
    delete [] elements_;
    elements_=temp;
    front_=0;
    rear_=size_-1;
  }
}

template<typename T>
void Queue<T>::reverse(){
  auto first=front_;
  auto last=rear_;
  while( first!=last && first!=last+1){
    std::swap(elements_[first],elements_[last]);
    first++;
    last--;
  }
}

template<typename T>
void Queue<T>::swap(Queue& other){
  std::swap(elements_,other.elements_);
  std::swap(capacity_,other.capacity_);
  std::swap(size_,other.size_);
  std::swap(front_,other.front_);
  std::swap(rear_,other.rear_);
}

