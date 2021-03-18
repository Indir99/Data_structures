#include<iostream>
#include<string>

#include"Queue.hpp"


int main(int argc, char *argv[])
{
  Queue<int> q(10);
  for(auto i=0;i<10;i++){
    q.push(i);
  }
  std::cout<<"Front: "<<q.front()<<std::endl;
  std::cout<<"Back: "<<q.back()<<std::endl;
  std::cout<<"Size: "<<q.size()<<std::endl;
  std::cout<<"Capacity: "<<q.capacity()<<std::endl;
  q.push(10);
  q.push(11);
  std::cout<<"Front: "<<q.front()<<std::endl;
  std::cout<<"Back: "<<q.back()<<std::endl;
  std::cout<<"Size: "<<q.size()<<std::endl;
  std::cout<<"Capacity: "<<q.capacity()<<std::endl;
  std::cout<<"Reverse test: "<<std::endl;
  q.reverse();
  std::cout<<"Front: "<<q.front()<<std::endl;
  std::cout<<"Back: "<<q.back()<<std::endl;
  std::cout<<"Size: "<<q.size()<<std::endl;
  std::cout<<"Capacity: "<<q.capacity()<<std::endl;

  std::cout<<"Testing swap"<<std::endl;
  Queue<int> q2;
  for(auto i=15;i<27;i++){
    q2.push(i);
  }
  std::cout<<"Queue 1"<<std::endl;
  std::cout<<"Front: "<<q.front()<<std::endl;
  std::cout<<"Back: "<<q.back()<<std::endl;
  std::cout<<"Size: "<<q.size()<<std::endl;
  std::cout<<"Capacity: "<<q.capacity()<<std::endl;
  std::cout<<"queue 2"<<std::endl;
  std::cout<<"Front: "<<q2.front()<<std::endl;
  std::cout<<"Back: "<<q2.back()<<std::endl;
  std::cout<<"Size: "<<q2.size()<<std::endl;
  std::cout<<"Capacity: "<<q2.capacity()<<std::endl;
  q.swap(q2);
  std::cout<<std::endl;
  std::cout<<"After swap"<<std::endl;
std::cout<<"Queue 1"<<std::endl;
std::cout<<"Front: "<<q.front()<<std::endl;
std::cout<<"Back: "<<q.back()<<std::endl;
std::cout<<"Size: "<<q.size()<<std::endl;
std::cout<<"Capacity: "<<q.capacity()<<std::endl;
std::cout<<"queue 2"<<std::endl;
std::cout<<"Front: "<<q2.front()<<std::endl;
std::cout<<"Back: "<<q2.back()<<std::endl;
std::cout<<"Size: "<<q2.size()<<std::endl;
std::cout<<"Capacity: "<<q2.capacity()<<std::endl;

 /* 
  std::cout<<std::string(10,'-')<<std::endl;

  auto x=q.pop();
 x=q.pop();
 x=q.pop();
 x=q.pop();
  std::cout<<"Front: "<<q.front()<<std::endl;
  std::cout<<"Back: "<<q.back()<<std::endl;
  std::cout<<"Size: "<<q.size()<<std::endl;
  std::cout<<"Capacity: "<<q.capacity()<<std::endl;
  std::cout<<std::string(10,'-')<<std::endl;

  for(auto i=10;i<14;i++){
    q.push(i);
  }
  std::cout<<"Front: "<<q.front()<<std::endl;
std::cout<<"Back: "<<q.back()<<std::endl;
std::cout<<"Size: "<<q.size()<<std::endl;
std::cout<<"Capacity: "<<q.capacity()<<std::endl;
  std::cout<<std::string(10,'-')<<std::endl;

  for(auto i=14;i<17;i++){
    q.push(i);
  }
  std::cout<<"Front: "<<q.front()<<std::endl;
std::cout<<"Back: "<<q.back()<<std::endl;
std::cout<<"Size: "<<q.size()<<std::endl;
std::cout<<"Capacity: "<<q.capacity()<<std::endl;
*/
 return 0;

}
