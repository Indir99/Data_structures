#include<iostream>
#include"bin_tree.hpp"


int main(int argc, char *argv[])
{
  bin_tree<int> bin;
  bin.add(20);
  bin.add(40);
  bin.add(15);
  bin.add(17);
  bin.add(12);
  bin.add(21);
  std::cout<<"In order"<<std::endl;
  bin.printInOrder();
  std::cout<<std::endl;

  std::cout<<"Pre order"<<std::endl;
  bin.printPreOrder();
  std::cout<<std::endl;

  std::cout<<"Post order"<<std::endl;
  bin.printPostOrder();
  std::cout<<std::endl;


  std::cout<<"Find 20: "<<std::boolalpha<<bin.find(20)<<std::endl;
  std::cout<<"Find 17: "<<std::boolalpha<<bin.find(17)<<std::endl;
  std::cout<<"Find 12: "<<std::boolalpha<<bin.find(12)<<std::endl;
  return 0;
}
