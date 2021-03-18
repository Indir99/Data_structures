#include<iostream>
#include<string>
#include<map>

#include"student.hpp"

void dodaj_studenta(std::map<int,student>& baza_studenata);
void izbrisi_studenta(std::map<int,student>& baza_studenata);
void print(const std::map<int,student>& baza_studenata);
void pronadji(const std::map<int,student>& baza_studenata);



int main(int argc, char *argv[])
{
  int i;
  std::map<int,student> baza_studenata;
  while(true){
  std::cout<<std::string('*',30)<<"Dobro došli u bazu podataka o studentima!"<<std::string('*',30)<<std::endl;
  std::cout<<"1. Unesi sutdenta"<<std::endl;
  std::cout<<"2. Izbrisi studenta"<<std::endl;
  std::cout<<"3. Prikazi sve studente"<<std::endl;
  std::cout<<"4. Prikazi odredjenog studenta"<<std::endl;
  std::cout<<"5. Napusti bazu"<<std::endl;
  std::cout<<"Vas izbor je: ";
  std::cin>>i;
  if(i==1){
    dodaj_studenta(baza_studenata);
  }
  else if(i==2){
    izbrisi_studenta(baza_studenata);
  }
  else if(i==3){
    print(baza_studenata);
  }
  else if(i==4){
    pronadji(baza_studenata);
  }
  else if(i==5){
    break;
  }
  }

  return 0;
}


void dodaj_studenta(std::map<int,student>& baza_studenata){
  int index;
  std::cout<<"Unesite broj indeksa: "<<std::endl;
  std::cin>>index;
  student novi_student(index);
  if(novi_student.getpr()<6 || novi_student.getpr()>10){
    std::cout<<"Nevalidan prosjek"<<std::endl;
    return;
  }
  bool uslov=true;
  for(auto item : baza_studenata){
    if(item.first==novi_student.getindex()){
      std::cout<<"Student sa datim brojem indeksa vec postoji u bazi. Dva studenta ne mogu imati isti broj indeksa!"<<std::endl;
      uslov=false;
      break;
    }
  }
  if(uslov)
    baza_studenata[novi_student.getindex()]=std::move(novi_student);
}

void izbrisi_studenta(std::map<int,student>& baza_studenata){
  if(baza_studenata.size()==0){
    std::cout<<"Baza je prazna"<<std::endl;
    return;
  }
  int index;
  std::cout<<"Unesite broj indeksa: ";
  std::cin>>index;
  auto it=baza_studenata.find(index);
  if(it!=baza_studenata.end()){
    std::cout<<"Broj indeksa: "<<it->first<<std::endl;
    std::cout<<"Ime: "<<it->second.getname()<<std::endl;
    std::cout<<"Prezime: "<<it->second.getlastName()<<std::endl;
    std::cout<<"Prosjek: "<<it->second.getpr()<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Jeste li sigurni da zelite izbrisati studenta? "<<std::endl;
    std::cout<<"1. Da!"<<std::endl;
    std::cout<<"2. Ne!"<<std::endl;
    int izbor;
    std::cout<<"Vas izbor: ";
    std::cin>>izbor;
      if(izbor==1){
        baza_studenata.erase(it);
        std::cout<<"Student je izbrisan"<<std::endl;
      }
      else if(izbor==2){
        std::cout<<"Student nije izbrisan i ostao je u bazi."<<std::endl;
        return;
      }
      else{
        std::cout<<"Pogresan unos"<<std::endl;
      }
  }
  else{
    std::cout<<"Student sa navedenim brojem indeksa ne postoji u bazi"<<std::endl;
  }
}

void print(const std::map<int,student>& baza_studenata){
  if(baza_studenata.size()==0){
    std::cout<<"Baza je prazna!"<<std::endl;
  }
  std::cout<<std::endl;
  for(auto item : baza_studenata){
    std::cout<<"Broj indeksa: "<<item.first<<std::endl;
    std::cout<<"Ime: "<<item.second.getname()<<std::endl;
    std::cout<<"Prezime: "<<item.second.getlastName()<<std::endl;
    std::cout<<"Prosjek: "<<item.second.getpr()<<std::endl;
    std::cout<<std::endl;
  }
}

void pronadji(const std::map<int,student>& baza_studenata){
  if(baza_studenata.size()==0){
    std::cout<<"Baza je prazna"<<std::endl;
    return;
  }
  int izbor;
  std::cout<<"Da li zelite unijeti broj indeksa ili ime i prezime?"<<std::endl;
  std::cout<<"1. Broj indeksa"<<std::endl;
  std::cout<<"2. Ime i prezime"<<std::endl;
  std::cout<<"Vas izbor: ";
  std::cin>>izbor;
  if(izbor==1){
    int index;
    std::cout<<"Unesite broj indeksa: ";
    std::cin>>index;
    std::cout<<std::endl;
  auto it=baza_studenata.find(index);
  if(it!=baza_studenata.end()){
    std::cout<<"Broj indeksa:"<<it->first<<std::endl;
    std::cout<<"Ime: "<<it->second.getname()<<std::endl;
    std::cout<<"Prezime: "<<it->second.getlastName()<<std::endl;
    std::cout<<"Prosjek: "<<it->second.getpr()<<std::endl;
    std::cout<<std::endl;
  }
  else{
      std::cout<<"Pogresan unos"<<std::endl;
    }
  }
  else if(izbor==2){
    std::string ime, prezime;
    std::cout<<"Unesite ime studenta: ";
    std::cin>>ime;
    std::cout<<"Unesite prezime studenta: ";
    std::cin>>prezime;
    std::cout<<std::endl;
    bool uslov=true;
    for(auto item : baza_studenata){
      if(item.second.getname()==ime && item.second.getlastName()==prezime){
    std::cout<<"Broj indeksa:"<<item.first<<std::endl;
    std::cout<<"Ime: "<<item.second.getname()<<std::endl;
    std::cout<<"Prezime: "<<item.second.getlastName()<<std::endl;
    std::cout<<"Prosjek: "<<item.second.getpr()<<std::endl;
    std::cout<<std::endl;
    uslov=false;
      }
    }
    if(uslov){
      std::cout<<"U Bazi ne postoji student sa navedenim imenom i prezimenom"<<std::endl;
    }
  }
  else{
    std::cout<<"Pogresan unos"<<std::endl;
  }
}

