#include <iostream>
#include <vector>

//using namespace std;

class Stooge {
public:
    virtual Stooge* clone() = 0;
    virtual void slap_stick() = 0;
};

class Factory {
public:
    static Stooge* make_stooge( int choice );
private:
    static Stooge* s_prototypes[4];
};

Stooge* Factory::s_prototypes[] = {0, new Larry, new Moe, new Curly};

Stooge* Factory::make_stooge( int choice ) {
    return s_prototypes[choice]->clone();
}

class Larry : public Stooge {
public:
    Stooge*   clone() { return new Larry; }
    void slap_stick() {
        std::cout << "Larry: poke eyes\n"; }
};


class Moe : public Stooge {
public:
    Stooge*   clone() { return new Moe; }
    void slap_stick() {
        std::cout << "Moe: slap head\n"; }
};


class Curly : public Stooge {
public:
    Stooge*   clone() { return new Curly; }
    void slap_stick() {
        std::cout << "Curly: suffer abuse\n"; }
};

int main() {
    std::vector<Stooge*> roles;
    int choice;

    while (true) {
        std::cout << "Larry(1) Moe(2) Curly(3) Go(0): ";
        std::cin >> choice;
        if (choice == 0)
            break;
        roles.push_back(
                Factory::make_stooge( choice ) );
    }

    for (int i=0; i < roles.size(); ++i)
        roles[i]->slap_stick();
    for (int i=0; i < roles.size(); ++i)
        delete roles[i];
}