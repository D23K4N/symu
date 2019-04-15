//definicja klasy Group - obiekty tej klasy to grupy pojawiające się w systemie

#pragma once
using namespace std;

class Group
{
public:
  explicit Group(const int id, const int number) : client_(number), id_(id)
  {
  }

  void SetClient(const int number)
  {
    this->client_ = number;
  }

  int GetClient() const
  {
    return this->client_;
  }

  void SetTime(const int number)
  {
    this->time_ = number;
  }

  int GetTime() const
  {
    return this->time_;
  }

private:
  int client_; //Ilu klientów zawiera grupa
  int time_ = 0; //Czas zakończenia obsługi na stanowisku
  __readonly int id_; //Identyfikator grupy
};