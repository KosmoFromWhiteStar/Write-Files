#include <iostream>
#include <fstream>
#include <string>

int f_valet(int val, int bill, int* arr)
{
	int result = 0;
	std::ofstream valet;
	valet.open("D:\\Программы\\Write Files\\files\\valet.txt", std::ios::app);

	int count = val / bill;
	if (count * bill <= val && count != 0)
	{
		for (int i = 0; i < 1000 && count != 0; i++)
		{
			if (arr[i] == bill)
			{
				count--;
				valet << arr[i] << " ";
				result += bill;
				arr[i] = -2;
			}

		}
	}
	valet.close();
	return result;
}

void fill()
{
	std::ofstream atm;
	atm.open("D:\\Программы\\Write Files\\files\\atm.txt");
	if (!atm.is_open()) std::cerr << "Atm isn't open";
	long long sum = 0;
	int arr[1000];
	for (int i = 0; i < 1000; i++)
	{
		int u = std::rand() % std::rand();

		if (u % 10 == 0) arr[i] = 100;
		else if (u % 10 == 1)  arr[i] = 100;
		else if (u % 10 == 2) arr[i] = 200;
		else if (u % 10 == 3) arr[i] = 500;
		else if (u % 10 == 4) arr[i] = 1000;
		else if (u % 10 == 5) arr[i] = 2000;
		else if (u % 10 == 6) arr[i] = 5000;
		else if (u % 10 == 7) arr[i] = 5000;
		else if (u % 10 == 8) arr[i] = 500;
		else if (u % 10 == 9) arr[i] = 100;

		sum += arr[i];
	}

	atm << sum << "\n";
	for (int i = 0; i < 1000; i++)
	{
		if (arr[i] > 0)atm << arr[i] << '\n';
	}

	atm.close();
}

int main()
{

	std::cout << "ATM\nYou are welcom\nAction:\n";
	char c;
	std::cin >> c;
	std::ifstream atm;
	atm.open("D:\\Программы\\Write Files\\files\\atm.txt");

	if (c == '+') fill();
	else
	{
		std::string str;
		atm >> str;
		if (str == "")
		{
			std::cout << "Not money in atm";
			return -1;
		}
		int sum = std::stoul(str);


		int val = 0;
		std::cin >> val;
		if (val < 0) {
			std::cout << "Invalid sum";
			return -1;
		}
		if (sum < val)
		{
			std::cout << "Not enought money. ";
		}
		int arr[1000];

		for (int i = 0; i < 1000; i++)
		{
			atm >> arr[i];
		}

		std::cout << "Банкомат!\n";
		

		if (val < 100) std::cout << "Купюр ниже 100 нет.\n";
		else if (val % 10 != 0 || val % 100 != 0)
			{
				std::cout << "Купюр ниже 100 не выдаём, следовательно." << val - val % 100 << " рублей невыдадим\n";
			}

		val -= f_valet(val, 5000, arr);
		
		if (val > 0) val -= f_valet(val, 2000, arr);
			
		if (val > 0) val -= f_valet(val, 1000, arr);
		
		if (val > 0) val -= f_valet(val, 500, arr);
		
		if (val > 0) val -= f_valet(val, 200, arr);
			
		if (val > 0) val -= f_valet(val, 100, arr);

		atm.close();

		std::ofstream atm;
		atm.open("D:\\Программы\\Write Files\\files\\atm.txt");
		sum = 0;
		for (int i = 0; i < 1000; i++)
		{
			sum += (arr[i] == -2 ? 0 : arr[i]);
		}

		atm << sum << '\n';
		
		for (int i = 0; i < 1000; i++)
		{
			atm << (arr[i] == -2 ? 0 : arr[i]) << '\n';
		}
	}
	atm.close();
	return 0;
}