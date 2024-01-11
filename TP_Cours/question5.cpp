#include <iostream>

// Classe de base Mere
class Mere {
public:
    int attrPubMere;
    // Variable statique pour le comptage des instances
    static int nombreInstances;

    Mere() {
        std::cout << "Utilisation du constructeur par défaut de Mère." << std::endl;
        nombreInstances++;
    }

    Mere(int a, int b, int c) : attrPubMere(a), attrPrivMere(b), attrProtMere(c) {
        std::cout << "Utilisation du constructeur de trois arguments de Mère." << std::endl;
        nombreInstances++;
    }

    virtual ~Mere() {
        std::cout << "Destruction d'une instance de Mère." << std::endl;
        nombreInstances--;
    }

    void afficherAttributs() {
        std::cout << "Attributs de Mere - Public: " << attrPubMere << ", Protected: " << attrProtMere << ", Private: " << attrPrivMere  << std::endl;
    }

    void modifierAttributs(int a, int b, int c){
        attrPubMere = a;
        attrProtMere = c;
        attrPrivMere = b;
    }

    // Méthode virtuelle pour démonstration de polymorphisme
    virtual void checkPolyMorphisme() {
        std::cout << "Fonction checkPolyMorphisme 'checkant' de la classe Mere" << std::endl;
    }

    static void afficherNombreInstances() {
        std::cout << "Nombre total d'instances de Mere: " << nombreInstances << std::endl;
    }

protected:
    int attrProtMere;

private:
    int attrPrivMere;
};
// Initialisation de la variable statique
int Mere::nombreInstances = 0;

// Classe dérivée FillePub
class FillePub : public Mere {
public:
    int attrPubFillePub;

    FillePub() {
        std::cout << "Utilisation du constructeur par défaut de FillePub." << std::endl;
    }

    FillePub(int a, int b, int c, int d, int e, int f) : Mere(a, b, c), attrPubFillePub(d), attrPrivFillePub(e), attrProtFillePub(f) {
        std::cout << "Utilisation du constructeur de six arguments de FillePub." << std::endl;
    }

    ~FillePub() {
        std::cout << "Destruction d'une instance de FillePub." << std::endl;
    }

    // Redéfinition de la méthode pour afficher les attributs
    void afficherAttributs() {
        Mere::afficherAttributs();
        std::cout << "Attributs de FillePub - Public: " << attrPubFillePub << ", Protected: " << attrProtFillePub << ", Private: " << attrPrivFillePub  << std::endl;
    }

    // Méthode pour modifier les attributs de FillePub
    void modifierAttributs(int a, int b, int c, int d, int e, int f) {
        Mere::modifierAttributs(a, b, c);
        attrPubFillePub = d;
        attrPrivFillePub = e;
        attrProtFillePub = f;
    }
    // Redéfinition de la méthode checkPolyMorphisme
    void checkPolyMorphisme()  {
        std::cout << "Fonction checkPolyMorphisme 'checkant' de la classe FillePub" << std::endl;
    }


private:
    int attrPrivFillePub;
protected:
    int attrProtFillePub;
};

// Classe dérivée FillePriv
class FillePriv : private Mere {
public:
    int attrPubFillePriv;

    FillePriv() {
        std::cout << "Utilisation du constructeur par défaut de FillePriv." << std::endl;
    }

    FillePriv(int a, int b, int c, int d, int e, int f) : Mere(a, b, c), attrPubFillePriv(d), attrPrivFillePriv(e), attrProtFillePriv(f) {
        std::cout << "Utilisation du constructeur de six arguments de FillePriv." << std::endl;
    }

    ~FillePriv() {
        std::cout << "Destruction d'une instance de FillePriv." << std::endl;
    }

    // Redéfinition de la méthode pour afficher les attributs
    void afficherAttributs() {
        Mere::afficherAttributs();
        std::cout << "Attributs de FillePriv - Public: " << attrPubFillePriv << ", Protected: " << attrProtFillePriv << ", Private: " << attrPrivFillePriv  << std::endl;
    }

    // Méthode pour modifier les attributs de FillePub
    void modifierAttributs(int a, int b, int c, int d, int e, int f) {
        Mere::modifierAttributs(a, b, c);
        attrPubFillePriv = d;
        attrPrivFillePriv = e;
        attrProtFillePriv = f;
    }
    void checkPolyMorphisme() {
        std::cout << "Fonction checkPolyMorphisme 'checkant' de la classe FillePriv" << std::endl;
    }

private:
    int attrPrivFillePriv;
protected:
    int attrProtFillePriv;
};

// Classe dérivée FilleProt
class FilleProt : protected Mere {
public:
    int attrPubFilleProt;

    FilleProt() {
        std::cout << "Utilisation du constructeur par défaut de FilleProt." << std::endl;
    }

    FilleProt(int a, int b, int c, int d, int e, int f) : Mere(a, b, c), attrPubFilleProt(d), attrPrivFilleProt(e), attrProtFilleProt(f) {
        std::cout << "Utilisation du constructeur de six arguments de FilleProt." << std::endl;
    }

    ~FilleProt() {
        std::cout << "Destruction d'une instance de FilleProt." << std::endl;
    }

    // Redéfinition de la méthode pour afficher les attributs
    void afficherAttributs() {
        Mere::afficherAttributs();
        std::cout << "Attributs de FillePriv - Public: " << attrPubFilleProt << ", Protected: " << attrProtFilleProt << ", Private: " << attrPrivFilleProt  << std::endl;
    }

    // Méthode pour modifier les attributs de FillePub
    void modifierAttributs(int a, int b, int c, int d, int e, int f) {
        Mere::modifierAttributs(a, b, c);
        attrPubFilleProt = d;
        attrPrivFilleProt = e;
        attrProtFilleProt = f;
    }
    // Redéfinition de la méthode checkPolyMorphisme
    void checkPolyMorphisme() {
        std::cout << "Fonction checkPolyMorphisme 'checkant' de la classe FilleProt" << std::endl;
    }

private:
    int attrPrivFilleProt;
protected:
    int attrProtFilleProt;
};
// Classe FillePubPub (Hérite de FillePub)
class FillePubPub : public FillePub {
public:
    FillePubPub() {
        std::cout << "Utilisation du constructeur par défaut de FillePubPub." << std::endl;
    }

    FillePubPub(int a, int b, int c, int d, int e, int f) : FillePub(a, b, c, d, e, f) {
        std::cout << "Utilisation du constructeur de six arguments de FillePubPub." << std::endl;
    }

    void checkPolyMorphisme()  {
        std::cout << "Fonction checkPolyMorphisme 'checkant' de la classe FillePubPub" << std::endl;
    }
};

// Classe FilleProtProt (Hérite de FilleProt)
class FilleProtProt : public FilleProt {
public:
    FilleProtProt() {
        std::cout << "Utilisation du constructeur par défaut de FilleProtProt." << std::endl;
    }

    FilleProtProt(int a, int b, int c, int d, int e, int f) : FilleProt(a, b, c, d, e, f) {
        std::cout << "Utilisation du constructeur de six arguments de FilleProtProt." << std::endl;
    }

    void checkPolyMorphisme() {
        std::cout << "Fonction checkPolyMorphisme 'checkant' de la classe FilleProtProt" << std::endl;
    }
};

// Fonction principale pour tester les classes
int main() {

    Mere::afficherNombreInstances();
    Mere mere1;
    Mere::afficherNombreInstances();

    {
        Mere mere2;
        Mere::afficherNombreInstances();
    }

    Mere::afficherNombreInstances();

    FillePub objFillePub;
    objFillePub.afficherAttributs();
    objFillePub.modifierAttributs(1, 2, 3, 4, 5, 6);
    objFillePub.afficherAttributs();
    objFillePub.checkPolyMorphisme();

    return 0;
}
