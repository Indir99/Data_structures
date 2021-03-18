#pragma once
#include <iostream>
#include <stdexcept>
#include <functional>

template <typename T>
class ArrayList {
  private:
  T* elements_;
  size_t size_;
  size_t capacity_;

  public:
  ArrayList(int size = 100); //implementirano
  ArrayList(const ArrayList<T>& other); //implementirano
  const ArrayList<T>& operator=(const ArrayList<T>&); //implementirano
  bool empty() const; //implementirano
  bool full() const; //implementirano
  int size() const { return size_; } //implementirano
  int capacity() const { return capacity_; } //implementirano
  void print() const; //implementirano 
  void reserve(int new_cap);
  T& at(int index); //implementirano 
  ~ArrayList(void) { delete[] elements_; } //implementirano
  //Dodatni metodi
   ArrayList<T>& push_back(const T& value); //slozenost O(1) osim u slucaju kada se poziva funkcija rserve()
   ArrayList<T>& pop_back(); //slozenost O(1)
   ArrayList<T>& push_front(const T& value); //slozenost O(n)
   ArrayList<T>& pop_front(); //slozenost O(n)
  // Zadatak: 
  class iterator; 
  class const_iterator;
  iterator begin() {return iterator(elements_);}
  iterator end() {return iterator(elements_+size_);}
  const_iterator cbegin() const { return const_iterator(elements_);}
  const_iterator cend() const { return const_iterator(elements_+size_);}

  //slozenost O(n)
   void insert(iterator it, const T& value); 
   //slozenost O(n)
   void remove(iterator it);
   //slozenost O(n)
   ArrayList<T>& invert(); 
   //slozenost O(n)
   iterator find(const T& value);
   // slozenost O(n)
   iterator find_if(std::function<bool(T)> expr);
   //slozenost O(n)
   void remove_if(std::function<bool(T)> expr); 
};

template <typename T>
ArrayList<T>::ArrayList(int n) {
  n < 0 ? capacity_ = 100 : capacity_ = n;
  size_ = 0;
  elements_ = new T[capacity_];
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& other) {
  capacity_ = other.capacity();
  size_ = other.size();
  elements_ = new T[capacity_];
  for (int i = 0; i < size_; i++) elements_[i] = other.elements_[i];
}

template <typename T>
const ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other) {
  if (this != &other) {
    delete[] elements_;
    capacity_ = other.capacity();
    size_ = other.size();
    elements_ = new T[capacity()];
    for (int i = 1; i < size_; i++) elements_[i] = other.elements_[i];
  }
  return *this;
}

template <typename T>
bool ArrayList<T>::empty() const {
  return (size_ == 0);
}

template <typename T>
bool ArrayList<T>::full() const {
  return (size_ == capacity_);
}

template <typename T>
void ArrayList<T>::print() const {
  for (int i = 0; i < size_; i++) std::cout << elements_[i] << " ";
  std::cout << std::endl;
}

template <typename T>
T& ArrayList<T>::at(int index) {
  if (index < 0 || index >= size_)
    throw std::out_of_range("Index is out of range.");
  else
    return elements_[index];
}

template<typename T>
void ArrayList<T>::reserve(int new_cap){
  if(new_cap>capacity_){
    auto temp = new T[new_cap];
    for (int i=0; i<size_;i++){
      temp[i]=std::move(elements_[i]);
    }
    delete [] elements_;
    elements_=temp;
    capacity_=new_cap;
  }
}

//Implementacija dodatnih metoda:
template<typename T>
ArrayList<T>& ArrayList<T>::push_back(const T& value){
  if(full()){
    reserve(2*capacity_);
  }
  elements_[size_++]=value;
  return *this;
}

template<typename T>
ArrayList<T>& ArrayList<T>::pop_back(){
  if(size_>0){
    size_--;
  }
  return *this;
}

template<typename T>
ArrayList<T>& ArrayList<T>::push_front(const T& value){
  if(full()){
    reserve(2*capacity_);
  }
  for(auto i=size_; i>0; i--){
    std::swap(elements_[i],elements_[i-1]);
  }
  size_++;
  elements_[0]=value;
  return *this;
}

template<typename T>
ArrayList<T>& ArrayList<T>::pop_front(){
  if(size_>0){
    for(auto i=0;i<size_-1;i++){
      std::swap(elements_[i],elements_[i+1]);
    }
    size_--;
  }
    return *this;
}

//Implementacija iteraotra:
template<typename T>
class ArrayList<T>::iterator :
public std::iterator<std::random_access_iterator_tag, T> {
  private:
    T* ptr_=nullptr;
  public:
    iterator(T* p) {ptr_=p;}
    T& operator*(){ return *ptr_;}
    const T& operator*() const {return *ptr_;}

    iterator& operator++(){ ++ptr_; return *this;}
    iterator operator++(int){ auto temp=*this; ++ptr_; return temp;}
    iterator& operator--(){ --ptr_; return *this;}
    iterator operator--(int){ auto temp=*this; --ptr_; return temp;}
    iterator operator+(const int& i){ return iterator(ptr_+i);}
    iterator operator-(const int& i){ return iterator(ptr_-i);}
    iterator& operator+=(const int& i){ ptr_+=i; return iterator(ptr_);}
    iterator& operator-=(const int& i){ ptr_-=i; return iterator(ptr_);}

    int operator-(const iterator& second){ return ptr_-second.ptr_;}
    int operator+(const iterator& second){ return ptr_+second.ptr_;}

    //Operatori poredjenja
    bool operator==(const iterator& second){ return ptr_==second.ptr_;} 
    bool operator!=(const iterator& second){ return ptr_!=second.ptr_;}
    bool operator> (const iterator& second){ return ptr_>second.ptr_;}
    bool operator< (const iterator& second){ return ptr_<second.ptr_;}
    bool operator>=(const iterator& second){ return ptr_>=second.ptr_;}
    bool operator<=(const iterator& second){ return ptr_<=second.ptr_;}

};

template<typename T>
class ArrayList<T>::const_iterator :
public std::iterator<std::random_access_iterator_tag, T> {
  private:
    T* ptr_=nullptr;
  public:
    const_iterator(T* p) {ptr_=p;}
    // T& operator*(){ return *ptr_;} - Kod const_iteratora ne mozemo mijenjati vrijednost elementa
    const T& operator*() const {return *ptr_;}

    const_iterator& operator++(){ ++ptr_; return *this;}
    const_iterator operator++(int){ auto temp=*this; ++ptr_; return temp;}
    const_iterator& operator--(){ --ptr_; return *this;}
    const_iterator operator--(int){ auto temp=*this; --ptr_; return temp;}
    const_iterator operator+(const int& i){ return const_iterator(ptr_+i);}
    const_iterator operator-(const int& i){ return const_iterator(ptr_-i);}
    const_iterator& operator+=(const int& i){ ptr_+=i; return const_iterator(ptr_);}
    const_iterator& operator-=(const int& i){ ptr_-=i; return const_iterator(ptr_);}

    int operator-(const const_iterator& second){ return ptr_-second.ptr_;}
    int operator+(const const_iterator& second){ return ptr_+second.ptr_;}

    //Operatori poredjenja
    bool operator==(const const_iterator& second){ return ptr_==second.ptr_;} 
    bool operator!=(const const_iterator& second){ return ptr_!=second.ptr_;}
    bool operator> (const const_iterator& second){ return ptr_>second.ptr_;}
    bool operator< (const const_iterator& second){ return ptr_<second.ptr_;}
    bool operator>=(const const_iterator& second){ return ptr_>=second.ptr_;}
    bool operator<=(const const_iterator& second){ return ptr_<=second.ptr_;}

};

template<typename T>
void ArrayList<T>::insert(iterator it, const T& value){
  if(it>=end() || it<begin())
    throw std::out_of_range("Indeksiranje van granica");
  if(full()){
    reserve(2*capacity_);
  }
  auto temp=end();
  *temp=value;
  for(auto iter=temp;iter>it;iter--){
    std::swap(*iter,*(iter-1));
  }
  size_++;
}

template<typename T> 
typename ArrayList<T>::iterator ArrayList<T>::find(const T& value){
  for(auto it=begin(); it<end();it++){
    if(*it==value){
      return it;
    }
  }
  return end();
}

template<typename T>
void ArrayList<T>::remove(iterator it){
  if(it>=end() || it<begin()){
    throw std::out_of_range("indeksiranje van granica");
  }
  for(auto iter=it; iter<end()-1;iter++){
    std::swap(*iter,*(iter+1)); 
  }
  size_--;
}

template<typename T>
ArrayList<T>& ArrayList<T>::invert(){
  auto first=begin();
  auto last=end()-1;
  while(first!=last && first!=(last+1)){
    std::swap(*first,*last);
    first++;
    last--;
  }
}

template<typename T>
typename ArrayList<T>::iterator ArrayList<T>::find_if(std::function<bool(T)> expr){
  for(auto it=begin();it<end();it++){
    if(expr(*it))
      return it;
  }
  return end();
}

template<typename T>
void ArrayList<T>::remove_if(std::function<bool(T)> expr){
  for(auto it=begin();it<end();it++){
    if(expr(*it))
      remove(it);
  }
}





