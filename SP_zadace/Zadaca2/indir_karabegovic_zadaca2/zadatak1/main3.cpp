#include<iostream>

#include"sorted_list.hpp"

int main(int argc, char *argv[])
{
  sorted_list<int> s1;
  for(auto i=0;i<12;i++){
    s1.push_back(i);
  }
  s1.push_back(2);
  s1.push_back(2);
  s1.push_back(5);
  s1.push_back(7);
  s1.push_back(9);
  for(auto item: s1){
    std::cout<<item<<' ';
  }
  std::cout<<std::endl;
  s1.unique();
for(auto item: s1){
  std::cout<<item<<' ';
}
std::cout<<std::endl;
//s1.find_pairs(9);
s1.invert();
  for(auto item: s1){
    std::cout<<item<<' ';
  }
  std::cout<<std::endl;
  s1.sort_up();
  for(auto item: s1){
    std::cout<<item<<' ';
  }
  std::cout<<std::endl;
  return 0;
}
