#include<iostream>
#include<string>
#include"account.hpp"



int main(int argc, char *argv[])
{
  account new_acc;
  int i;
  while(true){
std::cout<<std::string(70,'*')<<std::endl;
std::cout<<"Actions: "<<std::endl;
std::cout<<std::string(8,' ')<<"1. New transaction"<<std::endl;
std::cout<<std::string(8,' ')<<"2. Apply transaction"<<std::endl;
std::cout<<std::string(8,' ')<<"3. Pending transaction"<<std::endl;
std::cout<<std::string(8,' ')<<"4. Discard pending transaction"<<std::endl;
std::cout<<std::string(8,' ')<<"5. Balance"<<std::endl;
std::cout<<std::string(8,' ')<<"6. Exit"<<std::endl;
std::cout<<"Your choice?  ";
std::cin>>i;
if(i==1){
  account::transaction new_trans;
  new_acc.add(new_trans);
}
else if(i==2){
  new_acc.apply();
}
else if(i==3){
  new_acc.pending();
}
else if(i==4){
  new_acc.remove();
}
else if(i==5){
  new_acc.balance();
}
else if(i==6){
  break;
}
}
  return 0;
}
