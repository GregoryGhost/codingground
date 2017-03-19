#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

const string _foutLetters = "letters.txt";
const string _foutNumbers = "numbers.txt";
const string _foutOther = "other.txt";

int ReadTextFromFileAndSortToFiles(string filename);
void ReadOutputFile(string filename);

int main()
{
    string filename;
    cout << "Введите имя файла для чтения:" << endl;
    cin >> filename ;;
    
    setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
    if(ReadTextFromFileAndSortToFiles(filename) == 0){
		ReadOutputFile(_foutLetters);
		ReadOutputFile(_foutNumbers);
		ReadOutputFile(_foutOther);
    };
   return 0;
}

void ReadOutputFile(string filename)
{
    ifstream fout(filename, ios_base::in);
	if(!fout.is_open()){
		cout << "Файл не может быть открыт!\n";
	}
	else{
	    cout << "Считываем данные из файла: " << filename << endl; 
		char ch;
		while (!fout.eof()) // пока не конец файла
        {
            ch = fout.get();
			cout << ch;
        }
        cout << endl;
		fout.close();
	}
}

int ReadTextFromFileAndSortToFiles(string filename)
{
	int result = 0;
    ifstream fin(filename, ios_base::in); // открыли файл для чтения
    
    if (!fin.is_open()) {// если файл не открыт
        cout << "Файл не может быть открыт!\n"; // сообщить об это
		result = 1;     }
    else{
        char ch;
        
        ofstream foutNumbers(_foutNumbers,ios_base::trunc);
        ofstream foutLetters(_foutLetters, ios_base::trunc);
        ofstream foutOther(_foutOther, ios_base::trunc);
    
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
		result = 0;
    }
	return result;
}