#include <iostream>
#include <string>
#include <fstream>
int seeekSubStr(std::string mainS, std::string subS) {
	using namespace std;
	int mainLength{ (int)mainS.length() };
	int subLength{ (int)subS.length() };
	//Построение таблицы сдвигов
	int table[256]{ 0 }; //256 символов ASCII
	for (int i{ 0 }; i < 256; ++i) { //все по длине строке
		table[i] = subLength; //Если символа нет - сдвиг на длину подстроки
	}
	for (int i{ 0 }; i < subLength - 1; ++i) { //Последний символ не рассматриваем
		table[(unsigned char)subS[i]] = subLength - i - 1; //вычисление сдвигов
	}
	//Поиск
	int point{ 0 }; // положение начала подстроки относительно начала строки
	//Смещение по строке
	int mainOffset{ 0 };
	//Смещение по подстроке
	int subOffset{ 0 };
	int shift{ 0 };
	while (point + subLength - 1 < mainLength) {
		mainOffset = point;
		subOffset = 0;
		while (subOffset < subLength && mainS[mainOffset] == subS[subOffset]) { //Проверка символов строк на совпадение 
			++mainOffset; //Если совпали, сравниваем дальше
			++subOffset; 
		}
		if (subOffset == subLength) { //Дошли до конца подстроки
			if (point == 0) {
				cout << "No need for shift"; //Нет нужды в сдвиге
			}
			return point; //Вернуть позицию строки в подстроке
		}
		shift = table[(unsigned)mainS[point + subLength - 1]];
		cout << shift << " "; //Выводим значение сдвига;
		point += shift; //Делаем сдвиг согласно таблице
	}
	cout << "\tNot found";
	return -1; //Не найдена
}

int main() {
	using namespace std;
	string mainString{""};
	string subStr{ "" };
	ifstream fin("input.txt");
	string readString{""};
	while (!fin.eof()) {
		getline(fin, readString);
		mainString += "\n" + readString;
	}
	for (int i{ 0 }; i < mainString.length(); ++i) {
		if (mainString[i + 1] == '\n') {
			if (mainString[i] == '-') {
				mainString.erase(i, 2);
			}
			else {
				mainString[i + 1] = ' ';
			}
		}
	}
	fin.close();
	cout << mainString << "\n\nEnter the string you want to search: ";
	getline(cin, subStr);
	seeekSubStr(mainString, subStr);
	return 0;
}
