#pragma once

#include <iosfwd>
#include<vector>

class DNAStorage {
  public:
  DNAStorage();
  DNAStorage(const DNAStorage&);
  DNAStorage(DNAStorage&&);
  DNAStorage& operator=(const DNAStorage&);
  DNAStorage& operator=(DNAStorage&&);
  ~DNAStorage();

  void print(std::ostream&) const;
  void print(std::ostream&, int pos, int len) const;
  void insert(int pos, std::string lanac);
  // remove vraca broj elemenata koji su obrisani
  int remove(int pos, int len);
  void store(std::string filename);
  // load baca iznimku tipa std::runtime_error ukoliko ne postoji 
  // file sa imenom filename
  void load(std::string filename);

  private:
  size_t capacity_;
  char* elements_;
  std::vector<bool> empty_;
  void reserve(size_t new_cap);
  size_t size_;
  void clear();
  void print_priv(std::ostream&) const;
};

/* U datom zadatku je korišten dinamički alociran niz sa pomoćnim vektorom.
 * Uloga vektora je da prati popunjenost određenog indeksa niza.
 * Naime, pri alociranju niza kreira se vektor čiji je size jednak kapacitetu niza 
 * te je na svakoj poziciji vektora vrijednost true.
 * Kada se na neku poziciju u nizu upiše element,
 * vektor na istoj poziciji mijenja vrijednost sa true na false. 
 * Pomoću ovog vektora u svakom trenutku znamo
 * na kojoj poziciji se nalazi element a na kojoj ne.
 */

