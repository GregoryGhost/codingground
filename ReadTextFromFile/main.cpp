#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

void ReadTextFromFileAndSortToFiles(string filename);

int main()
{
    string filename;
    cout << "Введите имя файла для чтения:" << endl;
    cin >> filename ;;
    
    setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
    ReadTextFromFileAndSortToFiles(filename);
    
   return 0;
}

void ReadTextFromFileAndSortToFiles(string filename)
{
    ifstream fin(filename, ios_base::in); // открыли файл для чтения
    
    if (!fin.is_open()) // если файл не открыт
        cout << "Файл не может быть открыт!\n"; // сообщить об этом
    else{
        char ch;
        
        ofstream foutNumbers("number.txt",ios_base::trunc);
        ofstream foutLetters("letters.txt", ios_base::trunc);
        ofstream foutOther("other.txt", ios_base::trunc);
    
        while (!fin.eof()) // пока не конец файла
        {
            ch = fin.get();
             if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')
                || (ch >= 'а' && ch <= 'я') || (ch >= 'А' && ch <= 'Я'))
                    foutLetters << ch;
                else if(ch >= '0' && ch <= '9')
                    foutNumbers << ch;
                else
                    foutOther << ch;
        }
        fin.close();
        foutLetters.close();
        foutNumbers.close();
        foutOther.close();
    }
}

