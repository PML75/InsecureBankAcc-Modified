#include "bank.h"
#include <map>

using namespace std;

std::string Bank::GetBankName() const { return bank_name_; }
std::map<int, Account> Bank::GetAccounts() const { return accounts_; }
int Bank::CreateAccount(const std::string &nAccount, double balance) {
  Account c1(nAccount, balance);
  int newId = GenerateAccountId();
  accounts_.insert({newId, c1});
  return newId;
}
int Bank::TotalAccounts() const { return accounts_.size(); }
void Bank::DisplayBalances() const {
  for (auto it = accounts_.begin(); it != accounts_.end(); it++) {
    int user_id = it->first;
    Account curr_acc = it->second;
    cout << "=========================" << endl;
    cout << curr_acc.GetAccountHolder() << "(" << user_id << ")"
         << ": $" << curr_acc.GetBalance() << endl;
  }
}
void Bank::DeactivateAccount(int id) {
  auto deactivate = accounts_.find(id);
  accounts_.erase(deactivate);
}
void Bank::WelcomeMessage() const {
  string user;
  cout << "Welcome to Insecure Bank Account" << endl;
  cout << "====================================" << endl;
  cout << "Type c for commands: ";
  cin >> user;

  if (user == "c") {
    cout << "1. ca - create account" << endl;
    cout << "2. da - deactivate account" << endl;
    cout << "3. di - display info" << endl;
    cout << "4. x  - to exit" << endl;
  }
}
bool Bank::UserActions(std::string action) {
  string tName;
  double tAmount;
  if (action == "ca") {
    cout << "Enter account name: ";
    cin >> tName;
    cout << "Enter account amount: ";
    cin >> tAmount;
    CreateAccount(tName, tAmount);
    return true;
  } else if (action == "da") {
    int daAcc;
    cout << "Enter ID: ";
    cin >> daAcc;
    DeactivateAccount(daAcc);
    cout << "Account deleted." << endl;
    return true;
  } else if (action == "di") {

    DisplayBalances();
    return true;
  } else {
    return false;
  }
}
