//definicja klasy Employe - pracownicy (kelnerzy, kasjerzy itd). Do pracowników nakeży również bufet, ponieważ ma również tylko wskaźnik na grupę aktualnie obsługiwaną
#pragma once
#include "group.h"

class Employe
{
public:
  Employe() : busy_(nullptr)
  {
  }

  void change_status(Group* group)
  {
    busy_ = group;
  }

  Group* is_busy() const
  {
    return busy_;
  }

private:
  Group* busy_; // Wskaźnik na grupę zajmującą stanowisko
};

