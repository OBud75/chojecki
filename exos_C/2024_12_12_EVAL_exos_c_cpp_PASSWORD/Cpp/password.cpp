#include "password.hpp"

Password::Password(const std::string &password, bool is_encrypted) {
    if (!is_encrypted) {
        if (!is_valid(password)) {
		std::cout << "le mot de passe doit contenir au moins 6 caracteres, une majuscule et un caractere special" << std::endl;
        }
        raw_value = password;
        encrypt();
    } else {
        encrypted_value = password;
    }
}

bool Password::is_valid(const std::string &password) const {
    if (password.length() < 6) {
        return false;
    }
    if (!std::regex_search(password, std::regex("[A-Z]"))) {
        return false;
    }
    if (!std::regex_search(password, std::regex("[!@#$%^&*(),.?\":{}|<>]"))) {
        return false;
    }
    return true;
}

std::string Password::encrypt(std::string str) {
    return "ENC(" + str + ")";
}

void Password::encrypt() {
    encrypted_value = encrypt(raw_value);
}

std::string Password::str() const {
    return encrypted_value;
}

bool Password::operator==(const std::string &str) const {
    return str == encrypted_value;
}

bool Password::operator==(const Password &other) const {
    return encrypted_value == other.encrypted_value;
}

std::ostream &operator<<(std::ostream &os, const Password &p) {
    os << p.encrypted_value;
    return os;
}

