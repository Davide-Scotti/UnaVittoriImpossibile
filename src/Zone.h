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
};

#endif // ZONE_H
