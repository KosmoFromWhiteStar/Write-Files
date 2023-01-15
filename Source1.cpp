#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>


int main()
{
	std::srand(std::time(nullptr));

	int matx[20][10];
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 20; x++)
		{
			matx[x][y] = std::rand() % 2;
		}
	}

	std::ofstream pic("D:\\Программы\\Write Files\\files\\pic.txt");

	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 20; x++)
		{
			pic << matx[x][y];
			std::cout << matx[x][y];
		}
		pic << '\n';
		std::cout << std::endl;
	}

	pic.close();

	return 0;
}