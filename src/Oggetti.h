// Oggetti.h

#ifndef OGGETTI_H
#define OGGETTI_H

#include <string>
#include <iostream>

struct Oggetti {
  int nBarricate;    // numero corrente di barricata
  int nMaxBarricate; // numero massimo possibile
  int nFascisti;     // numero corrente di fascisti
  int nMunizioni;    // numero corrente di munizioni
  int nPozioni;      // numero corrente di pozioni
  int nCivili;       // numero corrente di civili

  Oggetti()
      : nBarricate(0), nMaxBarricate(3), nFascisti(0), nMunizioni(0),
        nPozioni(0), nCivili(0) {}

  void Reset() {
    nBarricate = 0;
    nFascisti = 0;
    nMunizioni = 0;
    nPozioni = 0;
    nCivili = 0;
  }

  void Add_Barricata() {
    if (nBarricate < nMaxBarricate)
      nBarricate++;
  }

  void Add_Fascisti() { nFascisti++; }

  void Add_Munizioni() { nMunizioni++; }

  void Add_Pozioni() { nPozioni++; }

  void Add_Civili() { nCivili++; }

  void Remove_Fascisti() {
    if (nFascisti > 0)
      nFascisti--;
  }

  void Remove_Munizioni() {
    if (nMunizioni > 0)
      nMunizioni--;
  }

  void Remove_Pozioni() {
    if (nPozioni > 0)
      nPozioni--;
  }

  void Remove_Civili() {
    if (nCivili > 0)
      nCivili--;
  }

  void get_Oggetti(){
    std::cout << "Fascisti: " << nFascisti
              << ", Munizioni: " << nMunizioni
              << ", Pozioni: " << nPozioni
              << ", Civili: " << nCivili << std::endl;
  }
};

#endif // OGGETTI_H