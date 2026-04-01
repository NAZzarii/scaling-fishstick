#include <iostream>
#include <string>

using namespace std;

class Plant {
public:
    string name;
};

class Animal {
public:
    string habitat;
    int age;

    Animal(string place) {
        habitat = place;
        age = 0;
    }
};

class Grass : public Plant {
public:
    Grass() {
        name = "Зелена трава";
    }
};

class Fox : public Animal {
public:
    Fox() : Animal("Ліс") {}
};

class Rabbit : public Animal {
public:
    Rabbit() : Animal("Поле") {}
};

class Life {
public:
    int grass_count;
    int rabbit_count;
    int fox_count;
    
    int fox_age;
    int rabbit_age;

    Life(int g, int r, int f) {
        grass_count = g;
        rabbit_count = r;
        fox_count = f;
        fox_age = 8;
        rabbit_age = 4;
    }

    void dayPasses() {
        cout << "\n--- Новий день у природі ---" << endl;
        
        if (grass_count > rabbit_count) {
            cout << "Трави більше ніж кроликів. Трава залишається." << endl;
        } else {
            cout << "Кроликів забагато! Вони з'їли всю траву." << endl;
            grass_count = 0;
        }

        fox_age += 2;
        rabbit_age += 2;

        if (fox_age >= 10 && fox_count > 0) {
            cout << "Лисиця занадто стара і вмирає." << endl;
            fox_count--;
            fox_age = 0;
        }

        if (rabbit_age >= 6 && rabbit_count > 0) {
            cout << "Кролик помер від старості." << endl;
            rabbit_count--;
            rabbit_age = 0;
        }

        if (fox_count > 5) {
            cout << "Лисиць занадто багато (більше 5). Нові не з'являються." << endl;
        } else {
            cout << "В околиці з'являється нова лисиця." << endl;
            fox_count++;
        }

        if (rabbit_count < fox_count && rabbit_count > 0) {
            cout << "Кроликів менше ніж лисиць. Лисиця зловила і з'їла кролика." << endl;
            rabbit_count--;
        }

        cout << ">>> Стан околиці: Трави = " << grass_count 
             << " | Кроликів = " << rabbit_count 
             << " | Лисиць = " << fox_count << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Ukrainian");

    Fox myFox;
    Rabbit myRabbit;
    Grass myGrass;

    cout << "Створено Лисицю. Місце проживання: " << myFox.habitat << endl;
    cout << "Створено Кролика. Місце проживання: " << myRabbit.habitat << endl;
    cout << "Створено Рослину: " << myGrass.name << endl;

    Life ecosystem(10, 3, 4);

    ecosystem.dayPasses();
    ecosystem.dayPasses();

    return 0;
}#include <iostream>
#include <string>

using namespace std;

class Plant {
public:
    string name;
};

class Animal {
public:
    string habitat;
    int age;

    Animal(string place) {
        habitat = place;
        age = 0;
    }
};

class Grass : public Plant {
public:
    Grass() {
        name = "Зелена трава";
    }
};

class Fox : public Animal {
public:
    Fox() : Animal("Ліс") {}
};

class Rabbit : public Animal {
public:
    Rabbit() : Animal("Поле") {}
};

class Life {
public:
    int grass_count;
    int rabbit_count;
    int fox_count;
    
    int fox_age;
    int rabbit_age;

    Life(int g, int r, int f) {
        grass_count = g;
        rabbit_count = r;
        fox_count = f;
        fox_age = 8;
        rabbit_age = 4;
    }

    void dayPasses() {
        cout << "\n--- Новий день у природі ---" << endl;
        
        if (grass_count > rabbit_count) {
            cout << "Трави більше ніж кроликів. Трава залишається." << endl;
        } else {
            cout << "Кроликів забагато! Вони з'їли всю траву." << endl;
            grass_count = 0;
        }

        fox_age += 2;
        rabbit_age += 2;

        if (fox_age >= 10 && fox_count > 0) {
            cout << "Лисиця занадто стара і вмирає." << endl;
            fox_count--;
            fox_age = 0;
        }

        if (rabbit_age >= 6 && rabbit_count > 0) {
            cout << "Кролик помер від старості." << endl;
            rabbit_count--;
            rabbit_age = 0;
        }

        if (fox_count > 5) {
            cout << "Лисиць занадто багато (більше 5). Нові не з'являються." << endl;
        } else {
            cout << "В околиці з'являється нова лисиця." << endl;
            fox_count++;
        }

        if (rabbit_count < fox_count && rabbit_count > 0) {
            cout << "Кроликів менше ніж лисиць. Лисиця зловила і з'їла кролика." << endl;
            rabbit_count--;
        }

        cout << ">>> Стан околиці: Трави = " << grass_count 
             << " | Кроликів = " << rabbit_count 
             << " | Лисиць = " << fox_count << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Ukrainian");

    Fox myFox;
    Rabbit myRabbit;
    Grass myGrass;

    cout << "Створено Лисицю. Місце проживання: " << myFox.habitat << endl;
    cout << "Створено Кролика. Місце проживання: " << myRabbit.habitat << endl;
    cout << "Створено Рослину: " << myGrass.name << endl;

    Life ecosystem(10, 3, 4);

    ecosystem.dayPasses();
    ecosystem.dayPasses();

    return 0;
}
