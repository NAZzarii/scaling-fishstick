#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Train {
private:
    string name;
    int* wagons;
    int wagonCount;

public:
    Train() {
        name = "Невідомий";
        wagonCount = 0;
        wagons = nullptr;
    }

    Train(string trainName, int count) {
        name = trainName;
        wagonCount = count;
        wagons = new int[wagonCount];
        
        for (int i = 0; i < wagonCount; i++) {
            wagons[i] = 0;
        }
    }

    ~Train() {
        delete[] wagons;
    }

    void setPassengers(int wagonIndex, int passengers) {
        if (wagonIndex >= 0 && wagonIndex < wagonCount) {
            wagons[wagonIndex] = passengers;
        }
    }

    friend ostream& operator<<(ostream& os, const Train& t) {
        os << t.name << endl;
        os << t.wagonCount << endl;
        
        for (int i = 0; i < t.wagonCount; i++) {
            os << t.wagons[i] << " ";
        }
        os << endl;
        
        return os;
    }

    friend istream& operator>>(istream& is, Train& t) {
        getline(is, t.name);
        
        if (t.name.empty()) return is;

        is >> t.wagonCount;

        delete[] t.wagons;
        
        t.wagons = new int[t.wagonCount];

        for (int i = 0; i < t.wagonCount; i++) {
            is >> t.wagons[i];
        }

        is.ignore();

        return is;
    }
};

int main() {
    setlocale(LC_ALL, "Ukrainian");

    string filename = "train_data.txt";

    Train express("Інтерсіті+", 3);
    express.setPassengers(0, 45);
    express.setPassengers(1, 50);
    express.setPassengers(2, 38);

    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << express;
        outFile.close();
    }

    Train loadedTrain;

    ifstream inFile(filename);
    if (inFile.is_open()) {
        inFile >> loadedTrain;
        inFile.close();
    }

    return 0;
}
