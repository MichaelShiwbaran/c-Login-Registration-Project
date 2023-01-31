#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool userLogin()
{
    std::string username, password, correct_user, correct_pass;
    std::cout << "To login, enter your username and password: " << std::endl;
    std::cout << "Enter username: " << std::endl;
    std::cin >> username;
    std::cout << "Enter password: " << std::endl;
    std::cin >> password;
    std::ifstream read(username + ".txt");
    getline (read, correct_user);
    getline (read, correct_pass);
    if(correct_user == username && correct_pass == password)
    {
      return true;
    }
    else
    {
      return false;
    }
}

int main() {
  int user_input;
  std::cout << "Select a choice: " << std::endl;
  std::cout << "(1) Register\n" << "(2) Login\n" << std::endl;
  std::cin >> user_input;
  if(user_input == 1)
  {
    std::string username, password;
    std::cout << "Enter a username: " << std::endl;
    std::cin >> username;
    std::cout << "Enter a password: " << std::endl;
    std::cin >> password;
    std::ofstream user_registered_file;
    user_registered_file.open(username + ".txt");
    user_registered_file << username << std::endl;
    user_registered_file << password << std::endl;
    user_registered_file.close();
    main();
  }
  else if (user_input == 2){
      bool check = userLogin();
      if(!check){
        std::cout << "You have entered your username or password incorrectly, please try again." << std::endl;
        system("PAUSE");
        return 0;
      }
      else {
        std::cout << "You are now logged in!" << std::endl;
        system("PAUSE");
        return 1;
      }
  }
  else {
    std::cout << "Wrong choice selected. Please choose again." << std::endl;
    main();
  }
}
