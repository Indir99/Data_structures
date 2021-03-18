#include<iostream>
#include<map>


int main(int argc, char *argv[])
{
  std::map<int,std::string> mapa;
  mapa[1]="indir";
  mapa[2]="naki";
  mapa[3]="Fuad";
  for(auto item : mapa){
    std::cout<<item.first<<"   "<<item.second<<std::endl;
  }
  auto it=mapa.find(1);
  std::cout<<std::endl;
  std::cout<<it->first<<"   "<<it->second<<std::endl;


  return 0;
}
