#include "pch.h"
#include "restaurant.h"
#include <queue>

using namespace std;

int main()
{
  // ReSharper disable once CppNonReclaimedResourceAcquisition
  auto* restaurant = new Restaurant();
  auto* test_group = new Group(0, 4);
  delete restaurant;
  delete test_group;

  return 0;
}
