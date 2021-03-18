#include<iostream>
#include"heap.hpp"

int main(int argc, char *argv[])
{
  heap<int> hip;
  hip.insert(10);
  hip.insert(15);
  hip.insert(20);
  hip.insert(7);
  hip.insert(9);
  hip.insert(50);

  hip.print();
  std::cout<<"Extracted: "<<hip.extractMax()<<std::endl;
  std::cout<<"Extracted: "<<hip.extractMax()<<std::endl;
  hip.print();

  return 0;
}
