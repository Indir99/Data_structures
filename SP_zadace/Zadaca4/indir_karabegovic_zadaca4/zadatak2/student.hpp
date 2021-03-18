#pragma once

#include<iostream>
#include<string>




class student{
  private:
    std::string ime_;
    std::string prezime_;
    int br_indeksa_=0;
    double prosjek_=0;
  public:
    student()=default;
    student(int index);
    student(const student& other);
    student(student&& other);
    student& operator=(const student&);
    student& operator=(student&&);
    int getindex() const;
    std::string getname() const;
    std::string getlastName() const;
    double getpr() const;
    bool operator<(const student& other) const;
    bool operator>(const student& other) const;
    bool operator<=(const student& other) const;
    bool operator>=(const student& other) const;
    bool operator==(const student& other) const;
    bool operator!=(const student& other) const;
};


student::student(int index){
  br_indeksa_=index;
  std::cout<<"Unesite ime studenta: ";
  std::cin.ignore();
  std::getline(std::cin,ime_);
  std::cout<<"Unesite prezime studenta: ";
  std::getline(std::cin,prezime_);
  std::cin.clear();
  std::cout<<"Unesite prosjek ocjena: ";
  std::cin>>prosjek_;
}

student::student(const student& other){
  ime_=other.ime_;
  prezime_=other.prezime_;
  br_indeksa_=other.br_indeksa_;
  prosjek_=other.prosjek_;
}

student::student(student&& other){
  ime_=std::move(other.ime_);
  prezime_=std::move(other.prezime_);
  br_indeksa_=other.br_indeksa_;
  prosjek_=other.prosjek_;
}
student& student::operator=(const student& other){
  ime_=other.ime_;
  prezime_=other.prezime_;
  br_indeksa_=other.br_indeksa_;
  prosjek_=other.prosjek_;
  return *this;
}

student& student::operator=(student&& other){
  std::swap(ime_,other.ime_);
  std::swap(prezime_,other.prezime_);
  std::swap(br_indeksa_,other.br_indeksa_);
  std::swap(prosjek_,other.prosjek_);
  return *this;
}



int student::getindex() const {
  return br_indeksa_;
}

std::string student::getname() const{
  return ime_;
}

std::string student::getlastName() const{
  return prezime_;
}

double student::getpr() const {
  return prosjek_;
}

bool student::operator<(const student& other) const {
  return br_indeksa_<other.br_indeksa_;
}

bool student::operator>(const student& other) const {
  return br_indeksa_>other.br_indeksa_;
}

bool student::operator<=(const student& other) const {
  return br_indeksa_<=other.br_indeksa_;
}

bool student::operator>=(const student& other) const {
  return br_indeksa_>=other.br_indeksa_;
}

bool student::operator==(const student& other) const {
  return br_indeksa_==other.br_indeksa_;
}
bool student::operator!=(const student& other) const {
  return br_indeksa_!=other.br_indeksa_;
}



