#include<iostream>

#include"Queue.hpp"


int main(int argc, char *argv[])
{
  std::cout<<"Testiramo default konstruktor koji ima kapacitet 20"<<std::endl;
  Queue<int> q1;
  std::cout<<"Kapacitet: "<<q1.capacity()<<std::endl;
  std::cout<<"Velicina: "<<q1.size()<<std::endl;
  std::cout<<std::endl;

 std::cout<<"Testiramo dodavanje jednog clana (push)"<<std::endl;
 q1.push(0);
 // u redu se nalazi 0
 std::cout<<"Dodali smo: "<<q1.front()<<std::endl;
 std::cout<<"Velicina je: "<<q1.size()<<std::endl;
 std::cout<<"Testiramo brisanje tog clana (pop): "<<std::endl;
 auto item5=q1.pop();
 // red je prazan
 std::cout<<"Izbrisali smo: "<<item5<<std::endl;
 std::cout<<"Velicina je: "<<q1.size()<<std::endl;
 std::cout<<std::endl;
  // Bacanje iznimke u naredne dvije linije
   try{
  std::cout<<"Front: "<<q1.front()<<std::endl;
   }
  catch(std::out_of_range e1){
    std::cout<< e1.what()<<std::endl;
  }
  try{
  std::cout<<"Back: "<<q1.back()<<std::endl;
  }
  catch(std::out_of_range e1){
    std::cout<<e1.what()<<std::endl;
  }
 // try{
 //Bacanje iznimke kada pozovemo pop nad praznim redom
  //auto itemx=q1.pop();
 // }
 // catch(std::out_of_range e1){
 //   std::cout<<e1.what()<<std::endl;
 // }
  
  std::cout<<"Testiramo konstruktor koji prima maksimalan broj elemenata"<<std::endl;
  Queue<int> q2(10);
  std::cout<<"Kapacitet: "<<q2.capacity()<<std::endl;
  std::cout<<"Velicina: "<<q2.size()<<std::endl;
  // Bacanje iznimke u naredne dvije linije
  try{
  std::cout<<"Front: "<<q2.front()<<std::endl;
  }
  catch(std::out_of_range e1){
    std::cout<<e1.what()<<std::endl;
  }
 // std::cout<<"Back: "<<q2.back()<<std::endl;
  std::cout<<std::endl;
  
  std::cout<<"Testiramo dodavanje 8 elemenata: "<<std::endl;
 for(auto i=0;i<8;i++){
   q2.push(i);
 }
 //Elementi u redu su: 0, 1, 2, 3, 4, 5, 6, 7
 //Prvi element na indeksu 0 a posljednji na indexu 7
 //
 std::cout<<"Kapacitet: "<<q2.capacity()<<std::endl;
 std::cout<<"Velicina: "<<q2.size()<<std::endl;
 std::cout<<"Prvi element je: "<<q2.front()<<std::endl;
 std::cout<<"Posljednji element je: "<<q2.back()<<std::endl;
 std::cout<<std::endl;

 std::cout<<"Testiramo brisanje cetiri elementa"<<std::endl;
 auto item1=q2.pop();
 std::cout<<"Izbrisali smo: "<<item1<<std::endl;
 auto item2=q2.pop();
 std::cout<<"Izbrisali smo: "<<item2<<std::endl;
 auto item3=q2.pop();
 std::cout<<"Izbrisali smo: "<<item3<<std::endl;
 auto item4=q2.pop();
 std::cout<<"Izbrisali smo: "<<item4<<std::endl;
 std::cout<<std::endl;
 //Elementi u redu su: 4,5,6,7
 //Prvi element na indexu 4 a posljednji na indexu 7

 std::cout<<"Nakon brisanja: "<<std::endl;
 std::cout<<"Kapacitet: "<<q2.capacity()<<std::endl;
 std::cout<<"Velicina: "<<q2.size()<<std::endl;
 std::cout<<"Prvi element je: "<<q2.front()<<std::endl;
 std::cout<<"Posljednji element je: "<<q2.back()<<std::endl;
 std::cout<<std::endl;


 std::cout<<"Dodajemo jos 4 elementa pri cemu testiramo cirkularni buffer "<<std::endl;
 q2.push(25);
 q2.push(24);
 q2.push(15);
 int test1=27;
 q2.push(test1); 
 // sada su elementi reda: 4, 5, 6, 7, 25, 24, 15, 27;
 std::cout<<"Kapacitet: "<<q2.capacity()<<std::endl;
 std::cout<<"Velicina: "<<q2.size()<<std::endl;
 std::cout<<"Prvi element je: "<<q2.front()<<std::endl;
 std::cout<<"Posljednji element je: "<<q2.back()<<std::endl;
 std::cout<<std::endl;

//Prvi element na indexu 4 a posljednji na indexu 1 
//Ako dodamo jos 3 elementa doci ce do bacanje iznimke (Queue is full)
//q2.push(11);
//q2.push(12);
//q2.push(13);

 //q1.push(1);
 std::cout<<"Testiramo copy konstruktor"<<std::endl;
 Queue<int> q3(q2);
 std::cout<<"Kapacitet: "<<q3.capacity()<<std::endl;
 std::cout<<"Velicina: "<<q3.size()<<std::endl;
 std::cout<<"Prvi element je: "<<q3.front()<<std::endl;
 std::cout<<"Posljednji element je: "<<q3.back()<<std::endl;
 std::cout<<std::endl;

 std::cout<<"Testiramo move konstruktor"<<std::endl;
 Queue<int> q4(std::move(q3));
 std::cout<<"Kapacitet: "<<q4.capacity()<<std::endl;
 std::cout<<"Velicina: "<<q4.size()<<std::endl;
 std::cout<<"Prvi element je: "<<q4.front()<<std::endl;
 std::cout<<"Posljednji element je: "<<q4.back()<<std::endl;
 std::cout<<std::endl;

 Queue<int> q5;
 q5.push(1);
 std::cout<<"Testiramo copy operator="<<std::endl;
 q4=q5;
 std::cout<<"Kapacitet: "<<q4.capacity()<<std::endl;
 std::cout<<"Velicina: "<<q4.size()<<std::endl;
 std::cout<<"Prvi element je: "<<q4.front()<<std::endl;
 std::cout<<"Posljednji element je: "<<q4.back()<<std::endl;
 std::cout<<std::endl;

 std::cout<<"Testiramo move operator="<<std::endl;
 q5=std::move(q2);
 std::cout<<"Kapacitet: "<<q5.capacity()<<std::endl;
std::cout<<"Velicina: "<<q5.size()<<std::endl;
std::cout<<"Prvi element je: "<<q5.front()<<std::endl;
std::cout<<"Posljednji element je: "<<q5.back()<<std::endl;
std::cout<<std::endl;

  return 0;
}
