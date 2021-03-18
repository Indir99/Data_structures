#include<iostream>

struct Radnik{
int godisnji=0;
std::string ime;
bool operator<=(const Radnik& other);
bool operator>=(const Randni& other);
}

//operator poredjenja implementiramo kako bi mogli porediti radnike i sortirati ih listi
// treba dati operator dodati u struktru
bool Radnik::operator<=(const Radnik& other){ return godisnji<other.godisnji; }
bool Radnik::operator>=(const Radnik& other){ return godisnji>other.godisnji; }

int main(){
Radnik radnik1;
radnik1.ime="Prvi";
radnik1.godisnji=5;
Radnik radnik2;
ranik2.ime="Drugi";
radnik2.godisnji=7;
Radnik radnik3;
radnik3.ime="Treci";
radnik3.godisnji=9;
sorted_list<Radnik> lista;
lista.add(radnik1);
lista.add(radnik2);
lista.add(radnik3);
//posto je lista koja je implementirana za zadacu bila sortirana od najmanjeg ka najvecem //elementu potrebno je vrsiti ispis od zadnjeg ka prvom clanu
std::cout<<"Radnici su: "<<std::endl;
auto it=--lista.end();
for(auto i=0;i<3;i++){
auto temp=*it;
std::cout<<temp.ime<<std::endl;
std::cout<<temp.godisnji<<std::endl;
it--;
}
}
