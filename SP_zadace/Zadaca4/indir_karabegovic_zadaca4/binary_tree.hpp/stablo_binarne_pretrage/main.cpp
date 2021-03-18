#include<iostream>
#include"binarno_stablo.hpp"

int main(int argc, char *argv[])
{
  binarno_stablo<int> bin;
  bin.add(15);
  bin.add(20);
  bin.add(10);
  bin.add(7);
  bin.add(12);
  bin.add(18);
  std::cout<<bin.size()<<std::endl;
  bin.print();
  std::cout<<std::endl;
  std::cout<<"Find 15: "<<std::boolalpha<<bin.find(15)<<std::endl;
  std::cout<<"Find 7: "<<std::boolalpha<<bin.find(7)<<std::endl;
  std::cout<<"Find 20: "<<std::boolalpha<<bin.find(20)<<std::endl;
  std::cout<<"Find 40: "<<std::boolalpha<<bin.find(40)<<std::endl;

  return 0;
}
