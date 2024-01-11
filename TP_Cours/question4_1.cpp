//
// Created by Groupe 24 on 09/01/2024.
//
#include <iostream>
#include <string>
#include <vector>

// Définition de la classe Personne
class Personne {
private:
    static int compteur;
protected:
    std::string nom;
    std::string prenom;
    int age;
    char sexe;
    std::string lieuNaissance;
    std::string numeroTelephone;
public:
    Personne() : nom(""), prenom(""), age(-1), sexe(' '), lieuNaissance(""), numeroTelephone("") {
        compteur++;
        std::cout << "Création d'une instance de Personne. Total: " << compteur << std::endl;
    }

    Personne(std::string n, std::string p, int a, char s, std::string lieu, std::string tel)
            : nom(n), prenom(p), age(a), sexe(s), lieuNaissance(lieu), numeroTelephone(tel) {
        compteur++;
        std::cout << "Création d'une instance de Personne. Total: " << compteur << std::endl;
    }

    virtual ~Personne() {
        compteur--;
        std::cout << "Destruction d'une instance de Personne. Restant: " << compteur << std::endl;
    }
    void toString(){
        std::cout << "Nom: " << nom << ", Prénom: " << prenom << ", Age: " << age << ", Sexe: " << sexe
                  << ", Lieu de Naissance: " << lieuNaissance << ", Numéro de Téléphone: " << numeroTelephone << std::endl;
    }
    void afficher() const {
        std::cout << "Nom: " << nom << ", Prénom: " << prenom << ", Age: " << age << ", Sexe: " << sexe
                  << ", Lieu de Naissance: " << lieuNaissance << ", Numéro de Téléphone: " << numeroTelephone << std::endl;
    }
};
int Personne::compteur = 0;

// Définition de la classe Etudiant
class Etudiant : virtual public Personne {
private:
    static int compteur;
    std::string universite;
    std::string faculte;
    std::string filiere;
    int anneeEtude;
    std::string numeroMatricule;
    std::string email;
public:
    Etudiant() : Personne(), universite(""), faculte(""), filiere(""), anneeEtude(0), numeroMatricule(""), email("") {
        compteur++;
        std::cout << "Création d'une instance d'Etudiant. Total: " << compteur << std::endl;
    }

    Etudiant(std::string n, std::string p, int a, char s, std::string lieu, std::string tel, std::string uni, std::string fac, std::string fil, int annee, std::string num, std::string mail)
            : Personne(n, p, a, s, lieu, tel), universite(uni), faculte(fac), filiere(fil), anneeEtude(annee), numeroMatricule(num), email(mail) {
        compteur++;
        std::cout << "Création d'une instance d'Etudiant. Total: " << compteur << std::endl;
    }

    ~Etudiant() {
        compteur--;
        std::cout << "Destruction d'une instance d'Etudiant. Restant: " << compteur << std::endl;
    }
    void etudier() {
        std::cout << prenom << " " << nom << " étudie en " << filiere << " à " << universite << std::endl;
    }
    void manger() {
        std::cout << nom << " est en train de manger." << std::endl;
    }

    void dormir() {
        std::cout << nom << " est en train de dormir." << std::endl;
    }

    void toString() {
        Personne::toString();
        std::cout << "Université: " << universite << ", Faculté: " << faculte << ", Filière: " << filiere
                  << ", Année d'étude: " << anneeEtude << ", Numéro matricule: " << numeroMatricule << ", Email: " << email << std::endl;
    }
    void afficher() {
        Personne::afficher();
        std::cout << "Université: " << universite << ", Faculté: " << faculte << ", Filière: " << filiere
                  << ", Année d'étude: " << anneeEtude << ", Numéro matricule: " << numeroMatricule << ", Email: " << email << std::endl;
    }
};
int Etudiant::compteur = 0;

// Définition de la classe Enseignant
class Enseignant : virtual public Personne {
private:
    std::vector<std::string> specialites;
    std::string emploiDuTemps;
    std::vector<std::string> matieresEnseignees;
public:
    Enseignant() : Personne(), emploiDuTemps("") {
        specialites.clear();
    }

    Enseignant(std::string n, std::string p, int a, char s, std::string lieu, std::string tel, std::vector<std::string> specs, std::vector<std::string> matieres, std::string emploi)
            : Personne(n, p, a, s, lieu, tel), specialites(specs), matieresEnseignees(matieres), emploiDuTemps(emploi) {}

    void enseigner() {
        std::cout << prenom << " " << nom << " est en train d'enseigner." << std::endl;
    }

    void conseiller() {
        std::cout << prenom << " " << nom << " est en train de conseiller des étudiants." << std::endl;
    }

    void orienter(){
        std::cout << prenom << " " << nom << " est en train d'orienter' des étudiants." << std::endl;
    }
    void evaluer(){
        std::cout << prenom << " " << nom << " est en train d'évaluer des étudiants." << std::endl;
    }
    void afficher()  {
        Personne::afficher();
        std::cout << "Specialités: ";
        for (size_t i = 0; i < specialites.size(); ++i) {
            std::cout << specialites[i] << " ";
        }
        std::cout << ", Emploi du temps: " << emploiDuTemps << std::endl;
    }
};

// Définition de la classe Administratif
class Administratif : public Personne {
private:
    std::string poste;
    std::vector<std::string> qualifications;
    std::string emploiDuTemps;
    std::vector<std::string> taches;
public:
    Administratif(std::string n, std::string p, int a, char s, std::string lieu, std::string tel, std::string post, std::vector<std::string> qualifs, std::vector<std::string> taches, std::string emploi)
            : Personne(n, p, a, s, lieu, tel), poste(post), qualifications(qualifs), taches(taches), emploiDuTemps(emploi) {}

    void realiserTaches() {
        std::cout << prenom << " " << nom << " est en train de réaliser ses tâches." << std::endl;
    }

    void conseiller() {
        std::cout << prenom << " " << nom << " est en train de conseiller des étudiants." << std::endl;
    }
};

// Définition de la classe Technicien
class Technicien : public Personne {
private:
    std::vector<std::string> qualifications;
    std::string emploiDuTemps;
public:
    Technicien(std::string n, std::string p, int a, char s, std::string lieu, std::string tel, std::vector<std::string> qualifs, std::string emploi)
            : Personne(n, p, a, s, lieu, tel), qualifications(qualifs), emploiDuTemps(emploi) {}

    void realiserTachesTechniques() {
        std::cout << prenom << " " << nom << " est en train de réaliser des tâches techniques." << std::endl;
    }
};

// Définition de la classe Moniteur
class Moniteur : public Etudiant, public Enseignant {
public:
    Moniteur(std::string n, std::string p, int a, char s, std::string lieu, std::string tel,
             std::string uni, std::string fac, std::string fil, int annee, std::string num, std::string mail,
             std::vector<std::string> specs, std::vector<std::string> matieres, std::string emploi)
            : Personne(n, p, a, s, lieu, tel),
              Etudiant(n, p, a, s, lieu, tel, uni, fac, fil, annee, num, mail),
              Enseignant(n, p, a, s, lieu, tel, specs, matieres, emploi) {}

    void afficher()  {
        Etudiant::afficher();
        Enseignant::afficher();
    }
};

int main() {
    // 1ere Methode
    //Etudiant *Etud1 = new Personne();

    //2eme Methode
    //Personne *etud1 = new Etudiant();


    // Création de quelques étudiants
    Etudiant etudiant1("HINVI", "Josué", 23, 'M', "Calavi", "0123456789", "UAC", "FAST", "MIA", 3, "E123456", "aaa@gmail.com");
    Etudiant etudiant2("ABDOULAYE", "Arafath", 23, 'M', "Parakou", "0987654321", "UAC", "FAST", "MIA", 3, "E654321", "bbbb@gmail.com");

    // Affiche les informations de l'étudiant
    etudiant1.afficher();
    etudiant2.afficher();


    // Utilisation de la méthode toString pour afficher l'étudiant
    Etudiant etudiant3("Baba", "Arafath", 20, 'F', "Parakou", "0987654321", "UAC", "FAST", "MIA", 3, "E654321", "Baba@gmail.com");
    etudiant3.toString();

    // Création du moniteur avec initialisation manuelle des vecteurs
    std::vector<std::string> specialites;
    specialites.push_back("Mathématiques");
    specialites.push_back("Informatique");

    std::vector<std::string> matieres;
    matieres.push_back("Mathématiques");
    // Ajouter des matières si nécessaire

    Moniteur moniteur("Durand", "Alice", 24, 'F', "Cotonou", "0123456789", "Université Z", "Mathématiques", "Maths", 4, "E987654", "alice.durand@gmail.com",
                      specialites, matieres, "Lundi, Mercredi, Vendredi");
    moniteur.afficher();
    moniteur.Etudiant::etudier();
    moniteur.enseigner();

    return 0;
}
