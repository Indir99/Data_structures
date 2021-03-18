#include<iostream>
#include"dna_storage.hpp"
#include<fstream>


DNAStorage::DNAStorage(){
  capacity_=100;
  size_=0;
  elements_=new char[capacity_];
  for(auto i=0;i<capacity_;i++){
    empty_.push_back(true);
  }
}

 DNAStorage::DNAStorage(const DNAStorage& second){
   capacity_=second.capacity_;
   empty_=second.empty_;
   size_=second.size_;
   elements_=new char [capacity_];
   std::copy(second.elements_,second.elements_+second.capacity_,elements_);
 }
 
DNAStorage::DNAStorage(DNAStorage&& second){
  capacity_=second.capacity_;
  empty_=second.empty_;
  size_=second.size_;
  elements_=second.elements_;
  second.capacity_=0;
  second.size_=0;
}

DNAStorage& DNAStorage::operator=(const DNAStorage& second){
  if(elements_!=second.elements_){
    delete [] elements_;
    capacity_=second.capacity_;
    empty_=second.empty_;
    size_=second.size_;
    elements_=new char [capacity_];
    std::copy(second.elements_,second.elements_+second.capacity_,elements_);
  }
  return *this;
}

 DNAStorage& DNAStorage::operator=(DNAStorage&& second){
  delete [] elements_;
  capacity_=second.capacity_;
  empty_=second.empty_;
  size_=second.size_;
  elements_=second.elements_;
  return *this;
}
DNAStorage::~DNAStorage(){
  delete [] elements_;
}

// Privatni metod reserve koristimo kada napunimo niz ili kada korisnik želi upisati element
// na poziciju koja je veća od kapaciteta našeg niza (elements_)
void DNAStorage::reserve(size_t new_cap){
  if(new_cap>capacity_){
    auto temp=new char[new_cap];
    std::copy(elements_,elements_+capacity_,temp);
    delete [] elements_;
    elements_=temp;
    for(auto i=capacity_;i<new_cap;i++){
      empty_[i]=false;
    }
    capacity_=new_cap;
  }
}

//U metodu insert pored dodavanja elemenata u niz provjeravamo da li je kapacitet zadovoljavajuci
//i da li dolazi do povećanja size_ (sa size uvijek znamo koja je pozicija posljednjeg elementa)
void DNAStorage::insert(int pos, std::string lanac){
  if(pos+lanac.size()>capacity_){
  reserve(2*(pos+lanac.size()));
  }
  if(pos+lanac.size()>size_)
    size_=pos+lanac.size();
  auto el=0;  //pomoćna varijabla koja pomaže pri prolasku kroz string
  for(auto i=pos;i<pos+lanac.size();i++){
    elements_[i]=lanac.at(el++);
    empty_[i]=false;
  }
}

void DNAStorage::print(std::ostream& izlaz) const{
  if(size_==0)
    izlaz<<"0-0: NULL"<<std::endl;
  auto i=0;               // pomocna varijabla koja figurira u petlji
  while (i<size_){
    std::string temp;     //privremeni string koji se nanovo puni u svakoj novoj iteraciji
    int counter=i;      //pomoćna varijabla koja prati na kojem indeksu se nalaze elementi
    if(empty_.at(i)==false){  //ovaj uslov je bitan u slučaju kada na prvom indeksu niza nemamo element
    while(empty_.at(i)==false){
      temp.push_back(elements_[i++]);
      counter++;
    }
    izlaz<<i-temp.size()<<'-'<<i-1<<": ";  //ispis ispred, npr: 0-5:
  for(auto x=0; x<temp.size();x++){
    izlaz<<temp.at(x);
  }
    }
  izlaz<<std::endl;
  while(empty_.at(i)==true && (i++)<size_){}  //u datoj petlji se provjerava da li se element nalazi na indeksu i 
  if(counter!=size_)                            // vodi se računa o tome da petlja ne postane beskočana (<size_)
    izlaz<<counter<<'-'<<i-1<<": NULL"<<std::endl;  
}
}

void DNAStorage::print(std::ostream& izlaz, int pos, int len) const{
  if(empty_.at(pos)==true){      //dati uslov se ispunjava ukoliko korisnik unese indeks na kojem nema elementa
    izlaz<<pos<<'-'<<pos<<": NULL"<<std::endl;
  }
  else{
  std::string temp;         
  for(auto i=pos;i<len+pos;i++){
    if(empty_.at(i)==false)
      temp.push_back(elements_[i]);
    else{
      izlaz<<std::endl;
      break;
    }
  }
  izlaz<<pos<<'-'<<pos+temp.size()-1<<": ";
  for(auto i=0; i<temp.size();i++){
    izlaz<<temp.at(i);
  }
  izlaz<<std::endl;
  }
}

int DNAStorage::remove(int pos, int len){
  auto counter=0;    //data pomoćna varijabla broji elemente koje smo izbrisali
  if(empty_.at(pos)==true)    //ukoliko se unose pozicija na kojoj nema poznatog elementa
    return 0;
  if(pos+len>size_){
    size_=pos;
  }
  for(auto i=pos;i<pos+len;i++){
    if(empty_.at(i)==false){
      empty_[i]=true;
      counter++;
    }
    else{
      break;
    }
  }
  return counter;
}

//privatni metod koji pozivamo kada želimo upisati niz u datetku 
void DNAStorage::print_priv(std::ostream& izlaz) const {
  auto i=0;               // pomoćna varijabla koja figurira u petlji
  while (i<size_){
    std::string temp;     //privremeni string koji se nanovo puni u svakoj novoj iteraciji
    while(empty_.at(i)==false){
      temp.push_back(elements_[i++]);
    }
    izlaz<<i-temp.size()<<' ';  //ispis početnog ispisa u datoteci
  for(auto x=0; x<temp.size();x++){   //petlja za ispis elementata u datoteku
    izlaz<<temp.at(x);
  }
  izlaz<<std::endl;
  while(empty_.at(i)==true && (i++)<size_-1){}
}
}

void DNAStorage::clear(){
  size_=0;
  for(auto i=0;i<capacity_;i++){
    empty_.at(i)=true;
  }
}

void DNAStorage::store(std::string filename){
  std::ofstream output{filename};
  print_priv(output);
  output.close();
}

void DNAStorage::load(std::string filename){
  std::ifstream input{filename};
  clear();
  if(input.is_open()){
  std::string temp;
  int n;
  while(input.eof()==false){
  input>>n>>temp;
  insert(n,temp);
  }
  input.close();
  }
  else{
    std::cout<<"File does not exist. Try again!"<<std::endl;
  }
}
