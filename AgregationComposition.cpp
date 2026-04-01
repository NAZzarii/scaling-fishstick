#include <iostream>
#include <string>

using namespace std;

class Engine {
public:
    int power;
    
    Engine(int p = 100) {
        power = p;
    }
};

class Body {
public:
    string color;
    
    Body(string c = "Білий") {
        color = c;
    }
};

class Wheels {
public:
    int size;
    
    Wheels(int s = 15) {
        size = s;
    }
};

class Driver {
public:
    string name;
    string surname;
    int age;
    int experience;

    Driver(string n, string s, int a, int e) {
        name = n;
        surname = s;
        age = a;
        experience = e;
    }

    void Show() {
        cout << "Водій: " << name << " " << surname 
             << " | Вік: " << age 
             << " | Стаж: " << experience << " років" << endl;
    }
};

class Car {
public:
    Engine engine;
    Body body;
    Wheels wheels;
    Driver* driver;

    Car(int p, string c, int s) : engine(p), body(c), wheels(s) {
        driver = nullptr;
    }

    Car(int p, string c, int s, Driver* d) : engine(p), body(c), wheels(s) {
        driver = d;
    }

    void AddDriver(Driver* d) {
        driver = d;
    }

    void Show() {
        cout << "\nХарактеристики авто:" << endl;
        cout << "Колір кузова: " << body.color << endl;
        cout << "Потужність двигуна: " << engine.power << " к.с." << endl;
        cout << "Розмір коліс: R" << wheels.size << endl;
        
        if (driver != nullptr) {
            driver->Show();
        } else {
            cout << "Водій: ВІДСУТНІЙ" << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Ukrainian");

    Driver myDriver("Олександр", "Петренко", 35, 10);

    Car car1(150, "Чорний", 17);
    car1.Show();

    car1.AddDriver(&myDriver);
    car1.Show();

    Driver secondDriver("Марія", "Коваленко", 28, 5);
    Car car2(200, "Червоний", 18, &secondDriver);
    car2.Show();

    return 0;
}
