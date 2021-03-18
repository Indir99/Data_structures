#include <iostream>
#include "sorted_list.hpp"

// zadatak1.cpp sluzi kao primjer koristenja klase koju trebate implementirati u
// okviru prvog zadatka. Ovaj file se mora moci kompajlirati bez ikakvih izmjena
// unutar njega. Fajl mozete mijenjati u svrhu testiranja (nije potrebno
// predavati ovaj file).
//
// Napomena:
// Funkcija main testira u potpunosti ispravnost vaseg koda. Funkcija main sluzi
// samo kao kratki primjer

int main(void) {
  sorted_list<int> s;

  s.add(20);
  s.add(10);
  s.add(30);
  s.add(15);
  // Sadrzaj liste bi trebao da bude: 10 15 20 30

  // Testiramo ispis sa druge pozicije, ocekujemo 15
  auto it = s.begin();
  ++it;
  std::cout << "Expected 15, actual: " << *it << std::endl;

  // Testiramo ispis sa predzadnje pozicije, ocekujemo 20
  it = s.end();
  --it;
  --it;
  std::cout << "Expected 20, actual: " << *it << std::endl;

  // Testiramo pronalazak po vrijednosti te brisanje tog clana, ocekujemo da se
  // na pocetku liste nakon brisanja nalazi vrijednost 15
  it = s.find(10);
  std::cout << "Found: " << *it << std::endl;
  s.remove(it);
  std::cout << "Expected 15, actual " << *(s.begin()) << std::endl;

  // Testiramo pronalazak po kriteriju te brisanje tog clana.
  // Ispis sadrzaja liste bi trebao rezultirati sa:
  // 15
  // 20
  s.remove(s.find_if([](int item) { return item == 30; }));
  for (int item : s) {
    std::cout << item << std::endl;
  }
  return 0;
}
