#include <iostream>
#include <fstream>


void writ_fish(std::string fish)
{
	std::ofstream bucket;
	bucket.open("D:\\Программы\\Write Files\\files\\bucket.txt", std::ios::app);

	bucket << fish << '\n';

	bucket.close();
}

bool cr(std::string fish, std::string fish2)
{
	for (int i = 0; i < fish.length() && i < fish2.length(); i++)
	{
		if (fish[i] != fish2[i]) return false;
	}
	return true;
}


int main()
{
	std::cout << "fishing\n";
	std::string fish_f = "";
	std::cin >> fish_f;

	std::ifstream river;
	river.open("D:\\Программы\\Write Files\\files\\river.txt");
	
	do
	{
		std::string fish = "";
		river >> fish;
		if (cr(fish, fish_f))
		{
			writ_fish(fish);
			std::cout << "Catch\n";
		}
	} 
	while (!river.eof());

	river.close();
	return 0;
}
