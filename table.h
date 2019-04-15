//definicja klasy Table - stoły
#pragma once
#include "group.h"

class Table
{
public:
  explicit Table(const int number) : busy_(nullptr) // zabezpieczony konstruktor przed rzutowaniem niejawnym
  {
    seats_i_ = number;
  }

  Group* who_seat() const
  {
    return this->busy_;
  }

private:
  __readonly int seats_i_; //Zmienna określająca ilość miejsc przy stole, __readonly, ponieważ miejsce przy stoliku ma być tylko dostępne do odczytu
  Group* busy_; // wskaźnik grupę klientów zajmującą stolik
};