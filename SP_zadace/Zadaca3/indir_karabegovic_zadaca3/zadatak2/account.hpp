#pragma once

#include<iostream>
#include<string>
#include<queue>

class account{
  public:
  class transaction;
  void add(const transaction&);
  void apply();
  void pending();
  void remove();
  void balance();
  private:
  double ballance=0;
  std::queue<transaction> trans;
};


class account::transaction{
  public:
  double value;
  std::string svrha;
  transaction(){
    double d;
    int i;
    std::cout<<"New transaction: "<<std::endl;
    std::cout<<"1. Add money to your balance"<<std::endl;
    std::cout<<"2. Take money"<<std::endl;
    std::cout<<"Your choice: ";
    std::cin>>i;
    if(i==1){
      std::cout<<"Enter amount: "<<std::endl;
      std::cin>>d;
      if(d<0){
        throw std::invalid_argument("Invalid argument");
      }
      value=d;
      svrha="add";
    }
    else if(i==2){
      std::cout<<"Enter amount: "<<std::endl;
      std::cin>>d;
      if(d<0){
        throw std::invalid_argument("Invalid argument");
      }
      value=d;
      svrha="take";
    }
    else{
      std::cout<<"Invalid argument"<<std::endl;
    }
  }
  friend class account;
};

void account::add(const transaction& transaction){
  if(transaction.svrha=="add" || transaction.svrha=="take"){
  trans.push(transaction);
  std::cout<<"Transaction added successfully"<<std::endl;
  }
}

void account::apply(){
  if(trans.size()!=0){
    auto transaction=trans.front();
    if(transaction.svrha=="add"){
      ballance+=transaction.value;
      std::cout<<"Money order: "<<transaction.svrha<<std::endl;
      std::cout<<"Amount: "<<transaction.value<<std::endl;
      trans.pop();
      std::cout<<"Transaction successfully apllied"<<std::endl;
    }
    else{
      if(ballance-transaction.value>=0){
      ballance-=transaction.value;
      std::cout<<"Money order: "<<transaction.svrha<<std::endl;
      std::cout<<"Amount: "<<transaction.value<<std::endl;
      trans.pop();
      std::cout<<"Transaction successfully apllied"<<std::endl;
      }
      else{
        std::cout<<"Transaction can not be applied. Low balance level."<<std::endl;
        std::cout<<"Transaction deleted!"<<std::endl;
        trans.pop();
      }
    }
  }
    else{
      std::cout<<"No transaction to apply"<<std::endl;
  }
}

void account::pending(){
  if(trans.size()>0){
    std::cout<<"Pending transaction"<<std::endl;
  std::cout<<"Money order: "<<trans.front().svrha<<std::endl;
  std::cout<<"Amount: "<<trans.front().value<<std::endl;
  }
  else{
    std::cout<<"List of transaction is empty"<<std::endl;
  }
}

void account::remove(){
  if(trans.size()==0){
    std::cout<<"List of transaction is empty"<<std::endl;
  }
  else{
    std::cout<<"Deleting transaction...:"<<std::endl;
    std::cout<<"Money order: "<<trans.front().svrha<<std::endl;
    std::cout<<"Amount: "<<trans.front().value<<std::endl;
    trans.pop();
    std::cout<<"Transaction successfully deleted"<<std::endl;
  }
}

void account::balance(){
  std::cout<<"Balance: "<<ballance<<std::endl;
}

