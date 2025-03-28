#include "user.hpp"
#include "password.hpp"

User::User(int id, Password &password): id(id), password(password) {
  (*this).is_logged_in = false; 
}

std::string extract_id(std::string line) {
	int marker = -1;
	int i = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i]=='|') {
			marker = i;
			break;
		}
	}

	if (marker == -1) {
		return "";
	} else {
		return line.substr(0,marker);
	}
}


bool User::id_exists(std::string id_value) {
  std::ifstream file(PWD_LIST);
  
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
	  if (extract_id(line)==id_value) {
		  return true;
	  }
    }
    file.close();
  } else {
    std::cerr << "impossible douvrir le fichier" << std::endl;
  }

  return false;
}

bool User::id_exists(int id_value) {
	return id_exists(std::to_string(id_value));
}

void User::save() {


  if (!id_exists(this->id)) {
	  std::string content = std::to_string(this->id) + "|" + password.str() + "\n";
	  std::fstream file(PWD_LIST, file.out | file.app);
	  file << content;
	  std::cout << "Saved: " << content << std::endl;
  }
  printf("User deja enregistre");
}

std::string get_hashed_password(std::string raw_password) {
	return Password::encrypt(raw_password);
}

int User::login(std::string raw_password) {
  std::string encrypted = get_hashed_password(raw_password);
  if (encrypted==this->password.str()) {
	  is_logged_in = true; 
	  printf("User `%d` logged in!\n", this->id);
  }
  else {
  	printf("mot de passe incorrect \n");
  }
  return 0;
}

User* User::get(int id, Password pwd) {

	if (id_exists(id)) {
		std::string content = std::to_string(id) + "|" + pwd.str();

		std::ifstream file(PWD_LIST);
		if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			if (line==content) {
				return new User(id, pwd);
			}
		}
		file.close();
		} else {
			std::cerr << "impossible douvrir le fichier" << std::endl;
		}
	} 
	printf("user inexistant .\n");
	return nullptr;
	// Pour éviter d'avoir à gérer la mémoire allouée avec new, on préfère
	// souvent renvoyer un smart pointer. std::make_unique<User>(id, pwd);

	// En fonction des cas, on peut penser à un vecteur/map contenant des User ou des unique_ptr<User>
	// Cela permet d'avoir un conteneur qui gère la mémoire automatiquement
	// puis de renvoyer une référence ou un pointeur vers l'élément souhaité
	// et ainsi de ne pas avoir à se soucier de la libération de la mémoire
	// std::vector<std::unique_ptr<User>> users;
	// users.push_back(std::make_unique<User>(id, std::move(password)));
	// return users.back();

	// Regardez également du côté de std::move pour utiliser les mêmes blocs mémoire des 2 cotés du return
}

int User::getId() const {
	return this->id; 
}

bool User::getLoginStatus() const {
    return this->is_logged_in; 
}

std::string User::str() {
	return std::to_string(this->id);
}

std::ostream &operator<<(std::ostream &os, const User &user) {
    os << "id:"<< user.id << " est logge :" << user.is_logged_in;
    return os;
}

