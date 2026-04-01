#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Dictionary {
private:
    map<string, vector<string>> dict;

public:
    void addWord(const string& word, const vector<string>& translations) {
        dict[word] = translations;
    }

    void findWord(const string& word) const {
        auto it = dict.find(word);
        if (it != dict.end()) {
            cout << word << " - ";
            for (size_t i = 0; i < it->second.size(); ++i) {
                cout << it->second[i] << (i + 1 == it->second.size() ? "" : ", ");
            }
            cout << endl;
        } else {
            cout << "Слово не знайдено." << endl;
        }
    }

    void addTranslation(const string& word, const string& translation) {
        dict[word].push_back(translation);
        cout << "Переклад додано." << endl;
    }

    void deleteWord(const string& word) {
        if (dict.erase(word)) {
            cout << "Слово видалено." << endl;
        } else {
            cout << "Слово не знайдено." << endl;
        }
    }

    void showAll() const {
        if (dict.empty()) {
            cout << "Словник порожній." << endl;
            return;
        }
        for (const auto& pair : dict) {
            cout << pair.first << " - ";
            for (size_t i = 0; i < pair.second.size(); ++i) {
                cout << pair.second[i] << (i + 1 == pair.second.size() ? "" : ", ");
            }
            cout << endl;
        }
    }

    void saveToFile(const string& filename) const {
        ofstream out(filename);
        if (out.is_open()) {
            for (const auto& pair : dict) {
                out << pair.first;
                for (const auto& tr : pair.second) {
                    out << "|" << tr;
                }
                out << "\n";
            }
            out.close();
            cout << "Словник збережено у файл " << filename << endl;
        } else {
            cout << "Помилка відкриття файлу для збереження." << endl;
        }
    }

    void loadFromFile(const string& filename) {
        ifstream in(filename);
        if (in.is_open()) {
            dict.clear();
            string line;
            while (getline(in, line)) {
                stringstream ss(line);
                string word, tr;
                getline(ss, word, '|');
                while (getline(ss, tr, '|')) {
                    dict[word].push_back(tr);
                }
            }
            in.close();
            cout << "Словник завантажено з файлу " << filename << endl;
        } else {
            cout << "Помилка відкриття файлу для завантаження." << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Ukrainian");
    
    Dictionary myDict;
    int choice;
    string filename = "dictionary.txt";

    do {
        cout << "\n--- МЕНЮ ---" << endl;
        cout << "1. Додати слово з перекладами" << endl;
        cout << "2. Знайти переклади слова" << endl;
        cout << "3. Додати переклад до існуючого слова" << endl;
        cout << "4. Видалити слово разом з перекладами" << endl;
        cout << "5. Показати всі слова" << endl;
        cout << "6. Зберегти словник у файл" << endl;
        cout << "7. Завантажити словник з файлу" << endl;
        cout << "0. Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1) {
            string word, tr;
            vector<string> translations;
            int count;
            
            cout << "Введіть слово: ";
            cin >> word;
            cout << "Скільки перекладів додати? ";
            cin >> count;
            cin.ignore();
            
            for (int i = 0; i < count; ++i) {
                cout << "Введіть переклад " << i + 1 << ": ";
                getline(cin, tr);
                translations.push_back(tr);
            }
            myDict.addWord(word, translations);
            cout << "Слово успішно додано!" << endl;
            
        } else if (choice == 2) {
            string word;
            cout << "Введіть слово для пошуку: ";
            cin >> word;
            myDict.findWord(word);
            
        } else if (choice == 3) {
            string word, tr;
            cout << "Введіть слово: ";
            cin >> word;
            cin.ignore();
            cout << "Введіть новий переклад: ";
            getline(cin, tr);
            myDict.addTranslation(word, tr);
            
        } else if (choice == 4) {
            string word;
            cout << "Введіть слово для видалення: ";
            cin >> word;
            myDict.deleteWord(word);
            
        } else if (choice == 5) {
            myDict.showAll();
            
        } else if (choice == 6) {
            myDict.saveToFile(filename);
            
        } else if (choice == 7) {
            myDict.loadFromFile(filename);
        }
        
    } while (choice != 0);

    return 0;
}
