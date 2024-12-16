#include "password.hpp"
#include "user.hpp"

int main() {

  auto u2 = User::get(1,Password("mypassword"));
  if (u2) {
  	std::cout << *u2 << std::endl;
  }

  return 0;
};
