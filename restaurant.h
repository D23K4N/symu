//definicja klasy Restaurant - gromadzącej pozostałe elementy systemu
#pragma once
#include <vector>
#include <queue>
#include "employe.h"
#include "group.h"
#include "table.h"

using namespace std;

class Restaurant
{
public:
  Restaurant() : manager_(new Employe)
  {
    for (auto i = 0; i <= this->w_i_; i++) this->waiter_.push_back(new Employe); //Tworzenie określonej ilości stanowisk obsługi przez kelnerów
    for (auto i = 0; i <= this->c_i_; i++) this->cashiers_.push_back(new Employe); //Tworzenie określonej ilości stanowisk obsługi przez kasjerów
    for (auto i = 0; i <= this->b_i_; i++) this->buffet_.push_back(new Employe); //Tworzenie określonej ilości stanowisk obsługi w bufecie
    for (auto i = 0; i <= this->t2_i_; i++) this->table_2_.push_back(new Table(2)); //Tworzenie określonej ilości stolików 2-osobowych
    for (auto i = 0; i <= this->t3_i_; i++) this->table_3_.push_back(new Table(3)); //Tworzenie określonej ilości stolików 3-osobowych
    for (auto i = 0; i <= this->t4_i_; i++) this->table_4_.push_back(new Table(4)); //Tworzenie określonej ilości stolików 4-osobowych
  }

  void AddToQueue(Group* group, const char select) // getery i settery do kolejek
  {
    if (select == 'm') this->to_manager_.push(group);
    if (select == 'w') this->to_waiter_.push(group);
    if (select == 'c') this->to_cashier_.push(group);
    if (select == 'b') this->to_buffet_.push(group);
  }

  Group* GetFromQueue(const char select)
  {
    Group* temporary_ptr = nullptr;
    if (select == 'm') 
    { 
      temporary_ptr = this->to_manager_.front();
      this->to_manager_.front() = nullptr;
    };
    if (select == 'w') 
    {
      temporary_ptr = this->to_waiter_.front();
      this->to_waiter_.pop();
    }
    if (select == 'c')
    {
      temporary_ptr = this->to_cashier_.front(); 
      this->to_cashier_.pop();
    }
    if (select == 'b')
    {
      temporary_ptr = this->to_buffet_.front();
      this->to_buffet_.pop();
    }
    return temporary_ptr; //nie zabezpieczam przed błędem, ponieważ nikt prócz programisty nie ma dostępu do wywoływanie metody
  }

  void use_employe(Group* group, const char select, const int number) // przypisywanie grup do stanowisk obsługi
  {
    if (select == 'm') this->manager_->change_status(group);
    if (select == 'w')
    {
      auto temp = this->waiter_.at(number);
      temp->change_status(group);
    }

    if (select == 'c')
    {
      auto temp = this->cashiers_.at(number);
      temp->change_status(group);
    }
    if (select == 'b')
    {
      auto temp = this->buffet_.at(number);
      temp->change_status(group);
    }
  }

  void add_to_queue(Group* group, const char select)
  {
    if (select == 'm') this->to_manager_.push(group);
    if (select == 'w') this->to_waiter_.push(group);
    if (select == 'c') this->to_cashier_.push(group);
    if (select == 'b') this->to_buffet_.push(group);
  }

  Group* free_employe(const char select, const int number = 0)
  {
    if (select == 'm')
    {
      const auto temp = manager_->is_busy();
      manager_->change_status(nullptr);
      return temp;
    }

    if (select == 'w')
    {
      const auto temp = waiter_.at(number)->is_busy();
      waiter_.at(number)->change_status(nullptr);
      return temp;
    }

    if (select == 'c')
    {
      const auto temp = cashiers_.at(number)->is_busy();
      cashiers_.at(number)->change_status(nullptr);
      return temp;
    }

    if (select == 'b')
    {
      const auto temp = buffet_.at(number)->is_busy();
      buffet_.at(number)->change_status(nullptr);
      return temp;
    }

    return nullptr;
  }

private:
  const int b_i_ = 10; //Ilość stanowisk w bufecie
  const int c_i_ = 10; //Ilość stanowisk kasjerów
  const int w_i_ = 10; //Ilość stanowisk kelnerów
  const int t2_i_ = 10; //Ilość stolików 2-osobowych
  const int t3_i_ = 10; //Ilość stolików 3-osobowych
  const int t4_i_ = 10; //Ilość stolików 4-osobowych
  vector<Employe*> waiter_; //Wektory kolejno kelnerów, kasjerów, miejsc w bufecie i stołów
  vector<Employe*> cashiers_;
  vector<Employe*> buffet_;
  vector<Table*> table_2_;
  vector<Table*> table_3_;
  vector<Table*> table_4_;
  Employe* manager_; //Wskaźnik na pojedynczego kierownika restauracji
  queue<Group*> to_manager_; //Kolejki wskaźników na obiekty klasy Group - kolejno do kierownika, bufetu, kelnerów i kasjerów
  queue<Group*> to_buffet_;
  queue<Group*> to_waiter_;
  queue<Group*> to_cashier_;
};
