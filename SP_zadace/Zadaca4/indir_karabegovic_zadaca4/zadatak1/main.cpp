#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<fstream>


typedef std::map<std::string,std::vector<int>> par;

void ispisi(const par& rijeci);
void ucitaj(std::ifstream& filename,par& rijeci);


int main(int argc, char *argv[])
{
  par rijeci;
  std::ifstream filename{"story.txt"};
  if(filename.is_open()){
    std::cout<<"Uspjesno otvaranje"<<std::endl;
    std::cout<<std::endl;
  ucitaj(filename,rijeci);
  ispisi(rijeci);
  }
  else{
    std::cout<<"Neuspjesno otvaranje"<<std::endl;
  }
  return 0;
}

void ispisi(const par& rijeci){
  for(auto item : rijeci){
    std::cout<<"Rijec je: '"<<item.first<<"' i nalazi se na sljedećim pozicijama: "<<std::endl;
    for(auto i=0;i<item.second.size();i++){
      std::cout<<item.second.at(i)<<' ';
  }
    std::cout<<std::endl;
    std::cout<<std::endl;
  }
}

void ucitaj(std::ifstream& filename,par& rijeci){
  int brojac=0;
  while(!filename.eof()){
      std::string nova_rijec;
      filename>>nova_rijec;
        if(nova_rijec!=" " && nova_rijec!="")
        rijeci[nova_rijec].push_back(brojac);
	brojac++;
      }
}


