#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;

void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	fstream file("hm_1559230117.txt");
	if (!file) cout << "File not found!";

	cout << "\n-----------------------Исходный текст-------------------------------\n\n";
	string str;
	getline(file, str, '\0');
	cout << str;
	cout << "\n--------------------------------------------------------------------\n\n";

	cout << " -= Поиск/Замена слова по вышеприведенному тексту =- \n\n";

	cout << "Введите искомое слово    -> ";
	string searchWord;
	cin >> searchWord;

	cout << "Введите слово для замены -> ";
	string replaceWord;
	cin >> replaceWord;

	int cnt = 0;
	int fpos = 0;
	int swSize = searchWord.size();
	int rwSize = replaceWord.size();
	while (1) {
		fpos = str.find((searchWord), fpos);
		if (str[fpos + swSize] >= 'а' && str[fpos + swSize] <= 'я') {
			fpos = 0;
		}
		else{
			str.erase(fpos, swSize);
			str.insert(fpos, replaceWord);
			fpos += rwSize;
			cnt++;
		}
		

		if (str.find((searchWord), fpos) == str.npos) break;
	}
	cout << "Find search word - " << cnt << endl;

	cout << "\n-----------------------Отредактированный текст------------------\n\n";
	getline(file, str);
	cout << str;
	cout << "\n----------------------------------------------------------------\n\n";

	system("pause");
}