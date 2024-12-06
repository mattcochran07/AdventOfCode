#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>

void loadFileContentsIntoVectors(std::string fileName);

std::vector<int> list1;
std::vector<int> list2;

int main(int argc, char** argv)
{
	if (argc == 2)
	{
		loadFileContentsIntoVectors(argv[1]);
		std::sort(list1.begin(), list1.end());
		std::sort(list2.begin(), list2.end());
		std::cout << "list1 size = " << list1.size() << std::endl;
		std::cout << "list2 size = " << list2.size() << std::endl;
		//verify sizes r same
		if (list1.size() == list2.size())
		{
			int sum = 0;
			for (int i = 0; i < list1.size(); i++)
				sum += abs(list1[i] - list2[i]);
			std::cout << "sum = " << sum << std::endl;
		}
	}
	return 0;
}

void loadFileContentsIntoVectors(std::string fileName)
{
	std::ifstream ifs(fileName.c_str());
	std::string line = "";
	while (std::getline(ifs, line))
	{
		std::stringstream ss(line.c_str());
		std::string arg = "";
		int spotInLine = 0;
		while (std::getline(ss, arg, ' '))
		{
			if (arg.find(" ") == std::string::npos && arg.size())
			{
				if (spotInLine == 0)
					list1.push_back((int)atoi(arg.c_str()));
				else
					list2.push_back((int)atoi(arg.c_str()));
				spotInLine++;
			}
		}
	}
}
