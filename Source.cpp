#include <fstream>
#include <iostream>
#include <istream>
#include <sstream>

void dt(std::string str)
{
	if (str == "") return;
	std::string t = "";
	t = str[0];
	t += str[1];
	for(int i = 0; i < t.length(); i++) if (t[i] < '0' || t[i] > '9') return;
	int day = std::stoi(t);
	if (day > 31 || day < 0)
	{
		std::cerr << "Invalid date:\n";
		return;
	}
	
	t = str[3];
	t += str[4];
	for (int i = 0; i < t.length(); i++) if (t[i] < '0' || t[i] > '9') return;
	int month = std::stoi(t);
	if (month > 12 || month < 0)
	{
		std::cerr << "Invalid date:\n";
		return;
	}

	t = "";
	for (int u = 6; u < str.length(); u++)
	{
		t += str[u];
	}
	for (int i = 0; i < t.length(); i++) if (t[i] < '0' || t[i] > '9') return;
	int year = std::stoi(t);
	if (year > 3000 || year < 0)
	{
		std::cerr << "Invalid date:\n";
		return;
	}


}


int main()
{
	std::ofstream files("D:\\Программы\\Write Files\\files\\decloration.txt", std::ios::app);
	std::stringstream temp;

	std::cout << "Decloration.\nForm:\nName Surname date value\n";

	std::string str;
	getline(std::cin, str);

	std::string name, surname, dat;
	int value;


	temp << str; // To separate the confusion (cathed crash when char >> int)

	temp >> name;
	temp >> surname;
	temp >> dat;
	temp >> value;

	if (name == "" || surname == "" || dat == "" || value == 0)
	{
		std::cout << "Not enought info\nNothing write";
	}
	else
	{
		dt(dat);
		if (value < 0) value == 0;
		files << name << " ";
		files << surname << " ";
		files << dat << " ";
		files << value << "\n";
	}


	files.close();

	return 0;
}