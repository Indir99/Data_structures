#include<iostream>
#include<set>
#include"student.hpp"


int main(int argc, char *argv[])
{
 // student marko(19001);
 // student naki(18023);
  student indir(12000);
  student indir2(12000);
  std::set<student> novi_set;
  novi_set.insert(indir);
  novi_set.insert(indir2);
  std::cout<<std::endl;

  for(auto item : novi_set){
    std::cout<<item.getindex()<<std::endl;
    std::cout<<item.getname()<<std::endl;
    std::cout<<item.getlastName()<<std::endl;
    std::cout<<item.getpr()<<std::endl;
    std::cout<<std::endl;
  }

  auto it=novi_set.find(indir);
  if(it!=novi_set.end()){
    std::cout<<it->getname()<<std::endl;
    std::cout<<it->getlastName()<<std::endl;
    std::cout<<it->getindex()<<std::endl;
    std::cout<<it->getpr()<<std::endl;
  }
  else{
    std::cout<<"Nije pronadjen"<<std::endl;
  }

auto number=novi_set.count(indir);
std::cout<<number<<std::endl;



  return 0;
}
