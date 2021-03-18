#pragma once

#include<iostream>
#include<stack>
#include<string>
#include<sstream>
#include<list>

class PostfixCalc{
  private: 
    std::stack<double> numbers_;
    std::string symbol_;
  public:
    PostfixCalc()=default;
    void isOperand(std::string);
    void isOperator(std::string);
    void calculate();
    void sum();
    void subs();
    void multip();
    void div();
    void clear();
    void print();
};

void PostfixCalc::isOperand(std::string str){
  double number;
  if(std::istringstream(str)>>number){
    numbers_.push(number);
  }
  else{
   isOperator(str);
  }
}

void PostfixCalc::isOperator(std::string str){
  if(str=="+" || str=="-" || str=="*" || str=="/"){
    symbol_=str;
  }
  else{
    std::cout<<"Invalid argument"<<std::endl;
    symbol_.clear();
    clear();
  }
}

void PostfixCalc::calculate(){
  if(symbol_.size()==0){
    return;
  }
  if(numbers_.size()<2 && symbol_.size()!=0){
    std::cout<<"Too much operators"<<std::endl;
    symbol_.clear();
    if(numbers_.size()>0)
    numbers_.pop();
    return;
  }
  if(symbol_=="+"){
    sum();
  }
  else if(symbol_=="-"){
    subs();
  }
  else if(symbol_=="*"){
    multip();
  }
  else if(symbol_=="/"){
    div();
  }

}

void PostfixCalc::sum(){
  double b=numbers_.top();
  numbers_.pop();
  double a=numbers_.top();
  numbers_.pop();
  double sum=a+b;
  numbers_.push(sum);
  print();
  symbol_.clear();
}

void PostfixCalc::subs(){
  double b=numbers_.top();
  numbers_.pop();
  double a=numbers_.top();
  numbers_.pop();
  double subs=a-b;
  numbers_.push(subs);
  //std::cout<<subs<<std::endl;
  print();
  symbol_.clear();
}

void PostfixCalc::multip(){
  double b=numbers_.top();
  numbers_.pop();
  double a=numbers_.top();
  numbers_.pop();
  double multip=a*b;
  numbers_.push(multip);
  //std::cout<<multip<<std::endl;
  print();
  symbol_.clear();
}

void PostfixCalc::div(){
  double b=numbers_.top();
  numbers_.pop();
  double a=numbers_.top();
  numbers_.pop();
  if(b==0){
    std::cout<<"You can not divide with 0!"<<std::endl;
    clear();
    symbol_.clear();
  }
  else{
  double div=a/b;
  numbers_.push(div);
  //std::cout<<div<<std::endl;
  print();
  symbol_.clear();
  }
}

void PostfixCalc::clear(){
  symbol_.clear();
  for(auto i=0;i<numbers_.size();i++){
    numbers_.pop();
  }
}


void PostfixCalc::print(){
  auto temp=numbers_;
  std::list<double> lista;
  for(auto i=0;i<=temp.size();i++){
    lista.push_front(temp.top());
    temp.pop();
  }
  for(auto it=lista.begin();it!=lista.end();it++){
    std::cout<<*it<<std::endl;
  }
}

