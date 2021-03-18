#include <iostream>
#include "ArrayList.hpp"

int main(void)
{
  //Test push_back:
   std::cout << "Push back:" << std::endl;
   ArrayList<int> list1;
   for(auto i=0;i<10;i++){
     list1.push_back(i);
   }
   list1.print();

   //Test pop_back:
   std::cout << "Pop back:" << std::endl;
   list1.pop_back().pop_back();
   list1.print();

  //Test push_front:
   std::cout << "Push front:" << std::endl;
   list1.push_front(100).push_front(200).push_front(300);
   list1.print();

  // Test pop_front:
   std::cout << "Pop front:" << std::endl;
   list1.pop_front();
   list1.print();

  // Test insert:
   std::cout << "Insert:" << std::endl;
   ArrayList<int>::iterator it=list1.begin()+5;
   list1.insert(it, 25);
   list1.print();
   //list1.insert(it+100, 12);   // Bacanje iznimke std::out_of_range
   //list1.print();
   
   //Test find:
   std::cout<<"Find: "<<std::endl;
   auto it2=list1.find(25);  
   std::cout<<"Result 1: "<<*it2<<std::endl;
   //auto it3=list1.find(14754);
   //std::cout<<"Result 1: "<<*it3<<std::endl; //neodređeno ponašanje programa zbog deref. end() 

   //Test remove:
   std::cout<<"Remove: "<<std::endl;
   list1.remove(it);
   list1.print();
   // list1.remove(it+100);
   // list1.print();

   //Test invert:
   std::cout << "Invert:" << std::endl;
   list1.invert();
   list1.print();

   //Test find_if:
  std::cout << "Find if: "<< std::endl;
   auto result1 = list1.find_if([](int i){ return i==7;}); 
   std::cout << "Result1: "<< *result1<< std::endl;
   
   //Test remove_if:
   std::cout<<"Remove if: "<<std::endl;
   list1.remove_if([](int i){ return i==100;});
   list1.print();
  //
  //
  return 0;
}
