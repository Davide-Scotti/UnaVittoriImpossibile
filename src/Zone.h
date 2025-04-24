// Zone.h
#ifndef ZONE_H
#define ZONE_H

#include "Oggetti.h"
#include <string>

struct Zone {
  std::string name; // nome della zona
  int number;       // numero della zona
  Oggetti oggetti;  // livello corrente di barricata

  // Costruttore di comodo
  Zone(const std::string &name, int number)
      : name(name), number(number), oggetti() {}

  Zone(const Zone& other) noexcept
      : name(std::move(other.name)), number(other.number),
        oggetti(std::move(other.oggetti)) {}

  void mostraZona() {
    std::cout << "Zona: " << name << " (Numero: " << number << ")" << std::endl;

    std::cout << "Barricate: " << oggetti.nBarricate << "/3" << std::endl;

    oggetti.get_Oggetti();
   
  }
};

#endif // ZONE_H
