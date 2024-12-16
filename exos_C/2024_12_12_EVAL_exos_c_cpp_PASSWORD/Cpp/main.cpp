#include "password.hpp"
#include "user.hpp"

int main() {
  
  Password pwd = Password("mypassword"); 

  User u = User(1, pwd);
  u.save();
  u.login("mypassword");
  u.save();

  std::cout << "user: " << u.str() << std::endl;
  std::cout << u << std::endl;
  

  User* u2 = User::get(1,Password("mypassword"));
  (*u2).login("mypassword");
  if (u2) {
  	std::cout << "autre instance pour le meme user"<< *u2 << std::endl;
    delete u2;
  }

  return 0;
};
