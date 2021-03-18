#include<iostream>

#include"sorted_list.hpp"

int main(int argc, char *argv[])
{
  sorted_list<int> s1;
  s1.push_back(1);
  s1.push_back(10);
  s1.push_back(7);
  s1.push_back(12);
  s1.push_back(6);
  s1.push_back(2);
  for(auto item : s1){
    std::cout<<item<<' ';
  }
  std::cout<<std::endl;
  s1.sort_up();
  for(auto item : s1){
    std::cout<<item<<' ';
  }
  std::cout<<std::endl;
  s1.sort_down();
  for(auto item : s1){
    std::cout<<item<<' ';
  }
  std::cout<<std::endl;
  s1.swap_elements(0,3);
  for(auto item : s1){
    std::cout<<item<<' ';
  }
  std::cout<<std::endl;
  s1.remove_if([](int i){ return i>3;});
  for(auto item : s1){
    std::cout<<item<<' ';
  }
  std::cout<<std::endl;
  return 0;
}
