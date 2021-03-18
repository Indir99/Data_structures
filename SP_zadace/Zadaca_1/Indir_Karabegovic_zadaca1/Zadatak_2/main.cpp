#include<iostream>
#include"dna_storage.hpp"
#include<fstream>
#include<string>



int main(int argc, char *argv[])
{
  DNAStorage spec;
  std::cout<<"Welcome to DNA Stroage. Please enter one of following options:"<<std::endl;
  while(true){
  std::cout<<std::endl;
  std::cout<<"  1. Print "<<std::endl;
  std::cout<<"  2. Print <pos> <len> "<<std::endl;
  std::cout<<"  3. Inset <pos> <lanac> "<<std::endl;
  std::cout<<"  4. Remove <pos> <len> "<<std::endl;
  std::cout<<"  5. Store <file> "<<std::endl;
  std::cout<<"  6. Load <file> "<<std::endl;
  std::cout<<std::endl;
  std::cout<<"     Your choice: ";
  short i;
  std::cin>>i;
  if(i==1){
    spec.print(std::cout);
  }
  else if(i==2){
    int i,len;
    std::cout<<"Postion: ";
    std::cin>>i;
    std::cout<<"Length: ";
    std::cin>>len;
    spec.print(std::cout,i,len);
  }
  else if(i==3){
    int i;
    std::string lanac;
    std::cout<<"Position: ";
    std::cin>>i;
    std::cout<<"Value: ";
    std::cin>>lanac;
    spec.insert(i,lanac);
  }
  else if(i==4){
    int i, len;
    std::cout<<"Position: ";
    std::cin>>i;
    std::cout<<"Length: ";
    std::cin>>len;
    spec.remove(i,len);
  }
  else if(i==5){
    std::string filename;
    std::cout<<"File: ";
    std::cin>>filename;
    spec.store(filename);
  }
  else if(i==6){
    std::string filename;
    std::cout<<"File: ";
    std::cin>>filename;
    spec.load(filename);
  }
  }
  return 0;
}


