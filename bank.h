#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <memory>
#include <string>

#include "account.h"

class Bank {
public:
  Bank(const std::string &bName) : bank_name_(bName) {}
  std::string GetBankName() const;
  std::map<int, Account> GetAccounts() const;
  int CreateAccount(const std::string &nAccount, double balance);
  int TotalAccounts() const;
  void DisplayBalances() const;
  void DeactivateAccount(int id);
  void WelcomeMessage() const;
  bool UserActions(std::string action);

private:
  std::string bank_name_;
  std::map<int, Account> accounts_;

  int GenerateAccountId() const {
    return std::rand() % 9000 + 1000; // [1000, 9999]
  }
};