#include<iostream>
#include"sorted_list.hpp"
#include"ToDoTask.hpp"


void print( const ToDoTask& item){
      std::cout<<"Title: "<<item.getTitile()<<std::endl;
      std::cout<<"Description: "<<item.getDesc()<<std::endl;
      std::cout<<"Id: "<<item.getId()<<std::endl;
}


int main(int argc, char *argv[])
{
  int i;
  sorted_list<ToDoTask> lista;
  while(true){
  std::cout<<"---------------notes--------------"<<std::endl;
  std::cout<<"1. New Task"<<std::endl;
  std::cout<<"2. Show Tasks"<<std::endl;
  std::cout<<"3. Mark task as completed"<<std::endl;
  std::cout<<"4. Higher priority tasks"<<std::endl;
  std::cout<<"5. Lower priority tasks"<<std::endl;
  std::cout<<"6. Swap task priotiy"<<std::endl;
  std::cout<<"Your choice: ";
  std::cin>>i;
    if(i==1){
      ToDoTask new_task;
      lista.add(new_task);
    }
  else if(i==2){
    if(lista.empty()){
      std::cout<<"Task list is empty!"<<std::endl;
    }
    else{
    std::cout<<"Your tasks:"<<std::endl;
    for(auto item : lista){
      print(item);
    }
    }
  }
  else if(i==3){
    int id;
  std::cout<<"Enter Id: "<<std::endl;
  std::cin>>id;
  auto it=lista.find_if([=](ToDoTask i){return i==id;});
  if(it!=lista.end()){
  lista.remove(it);
  }
  else{
  std::cout<<"Wrong Id"<<std::endl;
  }
  }
  else if(i==4){
    if(!lista.empty()){
    auto i=0;
    auto it=lista.begin();
    std::cout<<"Tasks with higher priority: "<<std::endl;
    while(i<3 && it!=lista.end()){
        auto temp=*it;
        print(temp);
        it++;
        i++;
        }
      }
      else{
      std::cout<<"Task list is empty"<<std::endl;
      }

  }
  else if(i==5){
    if(!lista.empty()){
    auto it=lista.end();
    it--;
    std::cout<<"Tasks with lower priority: "<<std::endl;
    for(auto i=0;i<3;i++){
      auto temp=*it;
      if(it!=lista.begin()){
      print(temp);
      }
      else{
        print(temp);
        break;
      }
      it--;
    }
    }
    else{
      std::cout<<"Task list is empty"<<std::endl;
    }
  }
  else if(i==6){
    int id1,id2;
    std::cout<<"First id: "<<std::endl;
    std::cin>>id1;
    std::cout<<"Second id: "<<std::endl;
    std::cin>>id2;
    auto it1=lista.find_if([=](ToDoTask i){ return i==id1; });
    auto it2=lista.find_if([=](ToDoTask i){ return i==id2;});
    if(it1!=lista.end() && it2!=lista.end()){
      std::swap((*it1).title_,(*it2).title_);
      std::swap((*it1).description_,(*it2).description_);
      std::swap((*it1).Id_,(*it2).Id_);
    }
    else{
      std::cout<<"Wrong id "<<std::endl;
    }
  }

  std::cout<<std::endl;
}

  return 0;
}

