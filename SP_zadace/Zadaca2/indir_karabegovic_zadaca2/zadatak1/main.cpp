#include<iostream>

#include"sorted_list.hpp"

int main(int argc, char *argv[])
{
  /*
  sorted_list<int> s1,s2;
  for(auto i=0;i<5;i++){
    s1.add(i);
  }
  for(auto item : s1){
    std::cout<<item<<' ';
  }
  std::cout<<std::endl;
  s1.reverse2();
  for(auto item: s1){
    std::cout<<item<<' ';
  }
  std::cout<<std::endl;
  for(auto i=0;i<6;i++){
    s2.add(i);
  }
  for(auto item : s2){
    std::cout<<item<<' ';
  }
  std::cout<<std::endl;
  s2.reverse2();
  for(auto item: s2){
    std::cout<<item<<' ';
  }
  std::cout<<std::endl;
  std::cout<<std::endl;
  sorted_list<int> s3;
  s3=s2;
  for(auto item : s3){
    std::cout<<item<<' ';
  }
  std::cout<<std::endl;
  */
  sorted_list<int> s4;
  for(auto i=1;i<17;i++){
    s4.add(i);
  }
  for(auto item :s4){
    std::cout<<item<<' ';
  }
  std::cout<<std::endl;
  //s4.swap_elements(3);
  //for(auto item :s4){
  //  std::cout<<item<<' ';
  //}
 // std::cout<<std::endl;
 auto it=s4.begin();
 it++;
 it++;
 it++;
 auto it2=--s4.end();
 it2--;
 it2--;
 it2--;
 s4.revese_of(it,it2);
 for(auto item : s4){
   std::cout<<item<<' ';
 }
 std::cout<<std::endl;
 s4.push_front(0);
 s4.push_back(25);
 for(auto item : s4){
   std::cout<<item<<' ';
 }
 std::cout<<std::endl;
 auto new_it=s4.begin();
 new_it++;
 new_it++;
 s4.insert_before(new_it,20);
 for(auto item : s4){
   std::cout<<item<<' ';
 }
 std::cout<<std::endl;
 auto new_it2=s4.begin();
 new_it2++;
 s4.insert_after(new_it2,11);
 for(auto item : s4){
   std::cout<<item<<' ';
 }
 std::cout<<std::endl;
 s4.pop_back();
 s4.pop_front();
 for(auto item : s4){
   std::cout<<item<<' ';
 }
 std::cout<<std::endl;
 auto iter4=s4.begin();
 iter4++;
 iter4++;
 iter4++;
 iter4++;
 auto iter5=s4.end();
 iter5--;
 iter5--;
 iter5--;
 iter5--;
 s4.remove(s4.end(),iter4);
 for(auto item : s4){
   std::cout<<item<<' ';
 }
 std::cout<<std::endl;

  return 0;
}
