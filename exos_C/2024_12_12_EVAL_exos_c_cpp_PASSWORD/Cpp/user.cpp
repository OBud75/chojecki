#include "user.hpp"


void User::save() {
    std::ofstream file("users.db", std::ios::app);
    if (!file.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier ");
    }
    file << id << "|" << password->str() << "\n";
    file.close();
}

User& User::get(int id) {
    static User retrieved_user(0, *(new Password("", true)));
    std::ifstream file("users.db");
    if (!file.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier .");
    }
    std::string line;
    while (std::getline(file, line)) {
        size_t delim_pos = line.find('|');
        int stored_id = std::stoi(line.substr(0, delim_pos));
        if (stored_id == id) {
            std::string encrypted_password = line.substr(delim_pos + 1);
            Password password(encrypted_password, true);
            retrieved_user = User(stored_id, password);
            break;
        }
    }
    file.close();
    return retrieved_user;
}

int User::login(const char *raw_password) {
    Password input_password(std::string(raw_password));
    if (*password == input_password) {
        is_logged_in = true;
        return 1;
    }
    return 0;
}
