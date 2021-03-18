#pragma once

#include<iostream>
#include<string>

int generateId(){
  static int counter=0;
  return ++counter;
}

class ToDoTask{
  //private:
  public:
  int Id_;
  std::string title_;
  std::string description_;
  int priority_;
 // public:
  ToDoTask();
  bool operator>(const ToDoTask& other){ return priority_>other.priority_;}
  bool operator>=(const ToDoTask& other){ return priority_>=other.priority_;}
  bool operator<=(const ToDoTask& other){ return priority_<=other.priority_;}
  bool operator<(const ToDoTask& other){ return priority_<other.priority_;}
  bool operator==(int i){ return Id_==i;}
  std::string getTitile() const { return title_;}
  std::string getDesc() const { return description_;}
  int getPriority() const {return priority_;}
  int getId() const { return Id_;}
  //void swap();
  //bool operator!=(const ToDoTask& other){ return priority_!=other.priority_;}
};

ToDoTask::ToDoTask(){
  std::cout<<"Title: ";
  std::cin.ignore();
  std::getline(std::cin,title_);
  std::cout<<"Description: ";
  std::getline(std::cin,description_);
  std::cin.clear();
  std::cout<<"Smaller number - higher priority!"<<std::endl;
  std::cout<<"Enter number: ";
  std::cin>>priority_;
  Id_=generateId();
  std::cout<<"Id: "<<Id_<<std::endl;
}

