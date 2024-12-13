#include "password.hpp"
#include "user.hpp"
#include <iostream>
#include <string>
#include <fstream>

int main() {
    try {
        std::string raw_password = "Secure@123";
        Password password(raw_password);

        std::cout << "Mot de passe encrypté  " << password.str() << std::endl;

        User user(1, password);

        user.save();

        std::string login_password = "Secure@123";
        if (user.login(login_password.c_str())) {
            std::cout << "Connexion ok" << std::endl;
        } else {
            std::cout << "Echec " << std::endl;
        }

        // Récupération d'un utilisateur sauvegardé
        User &retrieved_user = User::get(1);
        std::cout << "Utilisateur récupéré " << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}
