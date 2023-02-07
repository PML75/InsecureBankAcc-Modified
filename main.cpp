#include <iostream>
#include <map>
#include <vector>
#include <stdlib.h>

#include "bank.h"

using namespace std;

int main() {
  bool game_on = true;
  string user;
  string name;
  double amount;
  string bank;

  Bank chase("phuphu");
  chase.WelcomeMessage();

  while (game_on) 
  {
    cout << "\nWhat do you want to do? ";
    cin >> user;
    cout << "" << endl;
    system("clear");
    if (chase.UserActions(user) == false)
    {
      game_on = false;
    }
  }

  // int id = chase.CreateAccount("Tuffy", 121.00);
  // int is = chase.CreateAccount("Frank", 1234.56);
  // chase.CreateAccount("Oreo", 140.12);

  // chase.DeactivateAccount(is);

  // chase.DisplayBalances();
}