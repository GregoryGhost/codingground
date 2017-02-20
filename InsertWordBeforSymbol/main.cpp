#include <string>
#include <iostream>
#include <cmath>
 using namespace std;
 
struct Output 
{
    string changed;
    int countInserting;
};

Output InsertWordBeforSymbol(string source, string insertStr, string searchSym);
void calcInStr(double y, double z, char* dst);

int main()
{
    /*locale loc("Russian");//нужно для вывода в консоль русских символов
	std::locale::global(loc);
	system("chcp 1251");*/
	
	char* dst = new char[1000];
	
    string sourceStr         = "abc&abca&bca";
    string insertStr   = "Вот он, этот символ, нашелся:";
    string symbol       = "&";
    int count = 0;
    Output info = InsertWordBeforSymbol(sourceStr, insertStr, symbol);
    cout << "Измененная строка:\n" << info.changed << endl;
    cout << "Количество вставок:" << info.countInserting<< endl;
    
    
    /*<<< Операции с данными >>>*/
	double y = 0;
	double z = 0;

	std::cout << "Введите y = ";
	std::cin >> y;
	std::cout << "Введите z = ";
	std::cin >> z;

	calcInStr(y, z, dst);//Вызываем функцию по преобразованию численного результата в строковый
	std::cout << "Вывод: " << "x = lg(y+3*z)" << std::endl;
	std::cout << dst << std::endl;
    
    return 0;
}

Output InsertWordBeforSymbol(string source, string insertStr, string searchSym)
{
    Output info;
    info.countInserting = 0;
    info.changed = source;
    
    for(int it = info.changed.find(searchSym);
        it != std::string::npos;
        it = info.changed.find(searchSym, it + insertStr.length() + 1))
        {
            info.changed.insert(it, insertStr);
            info.countInserting++;
        }
        
    return info;
}

void calcInStr(double y, double z, char* dst)//подпрограмма для работы с данными
{
	double x = log10(y+3*z);//задаем уравнение по заданию x = lg(y+3*z)
	sprintf(dst, "%4.5f=lg(%4.5f+3*%4.5f)\n", x, y, z);
}
