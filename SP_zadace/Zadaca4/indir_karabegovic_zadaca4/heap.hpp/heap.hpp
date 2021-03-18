#pragma once


#include<iostream>
#include<utility>
#include<cstddef>
#include<algorithm>

template<typename T>
class heap{
  public:
    heap(int cap=20);
    //copy ctr
    //move ctr
    //move =
    //copy =
    ~heap();
    inline size_t size() const { return size_-1;}
    inline bool empty() const { return size_==1; }
    inline bool full() const { return size_==capacity_;}
    template<typename U>
      void insert(U&& value);
    void print() const;
    T extractMax();

  private:
    void expand();
    void fixheap(int);
    size_t size_;
    size_t capacity_;
    T* heap_;
};

template<typename T>
heap<T>::heap(int cap){
  size_=1;
  capacity_=cap+1;
  heap_ = new T[capacity_];
}

template<typename T>
heap<T>::~heap(){
  delete [] heap_;
  size_=0;
  capacity_=0;
}

template<typename T>
template<typename U>
void heap<T>::insert(U&& value){
  if(size_==capacity_){
    expand();
  }
  int index=size_;
  heap_[index]=std::forward<U>(value);
  while(index!=1){
  int parentIndex=index/2;
  if(heap_[index]>heap_[parentIndex]){
    std::swap(heap_[index],heap_[parentIndex]);
    index=parentIndex;
  }else{
    break;
  }
  }
  size_++;
}

template<typename T>
void heap<T>::expand() {
  capacity_*=2;
  auto newHeap=new T[capacity_];
  std::copy(heap_,heap_+size_,newHeap);
  delete [] heap_;
  heap_=newHeap;
}


template<typename T>
void heap<T>::print() const {
  for(auto i=1;i<size_;i++){
    std::cout<<heap_[i]<<' ';
  }
  std::cout<<std::endl;
}

template<typename T>
T heap<T>::extractMax(){
  auto result=std::move(heap_[1]);
  heap_[1]=heap_[size_-1];
  fixheap(1);
  size_--;
  return result;
}

template<typename T>
void heap<T>::fixheap(int index){
 // heap_[1]=std::move(heap_[size_-1]);
  int leftChildindex=index*2;
  int rightChildindex=index*2+1;
  int maxValueindex=index;
  if(leftChildindex<size_ && heap_[leftChildindex]>heap_[maxValueindex]){
    maxValueindex=leftChildindex;
  }
  if(rightChildindex<size_ && heap_[rightChildindex]>heap_[maxValueindex]){
    maxValueindex=rightChildindex;
  }
  if(index!=maxValueindex){
    std::swap(heap_[index],heap_[maxValueindex]);
    fixheap(maxValueindex);
  }
}









