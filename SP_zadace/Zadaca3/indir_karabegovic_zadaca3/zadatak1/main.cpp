#include<iostream>
#include<string>

#include"PostfixCalc.hpp"

int main(int argc, char *argv[])
{
  PostfixCalc calculator;
  std::string str;
  std::cout<<"RPN Calculator"<<std::endl;
  std::cout<<"Type q for quit or c for clear"<<std::endl;
  std::cout<<"Oerations: +, -, *, /"<<std::endl;
  std::cout<<"After every operator/operand press Enter"<<std::endl;
  std::cout<<"Enter operands and operators: "<<std::endl;
  while(true){
  std::cin>>str;
  if(str=="q"){
    break;
  }
  if(str=="c"){
    calculator.clear();
  }
  else{
  calculator.isOperand(str);
  calculator.calculate();
  }
}

  return 0;
}

