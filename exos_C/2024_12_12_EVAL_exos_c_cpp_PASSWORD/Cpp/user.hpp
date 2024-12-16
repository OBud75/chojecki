#include <memory>
#include <iostream>
#include <fstream>
#include <string>

#define PWD_LIST "pwd_list.data"

class Password; 

class User {
    private:
        int id;
        Password &password;
        bool is_logged_in;
	static bool id_exists(int id_value);
	static bool id_exists(std::string id_value);

    public:
        explicit User(int id, Password &password);

	std::string str();
	int getId() const;
	bool getLoginStatus() const;
	
        void save();
        int login(std::string raw_password);
        static User* get(int id, Password pwd);
        friend std::ostream &operator<<(std::ostream &os, const User &user);
};
