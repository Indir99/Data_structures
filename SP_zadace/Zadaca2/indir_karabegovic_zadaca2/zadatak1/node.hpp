#pragma once

#include<iostream>


template<typename T>
class Node{
  public:
  T value_;
  Node* next_;
  Node* prev_;
  Node(const T& val) : value_(val), next_(nullptr), prev_(nullptr){}
  Node( T&& val) : value_(std::move(val)), next_(nullptr), prev_(nullptr){}
};
