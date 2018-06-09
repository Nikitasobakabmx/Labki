#include <iostream>
#include "Data.h"
#include "myLab.h"

void interface ()
{
	int flag = -1;
	int tmp1 = 0;
	int tmp2 = 0;
	Data data[3];
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
	while (flag != 0)
	{
		std::cout << "\n1 - set date\n";
		std::cout << "2 - output date\n";
		std::cout << "3 - change data\n";
		std::cout << "4 - compare data\n";
		std::cout << "0 - exit\n";
		std::cout << "\nInput flag: ";
		std::cin >> flag;
		switch (flag)
		{
			case (1):
				std::cout << "Enter data (1, 2 or 3): ";
				std::cin >> tmp1;
				if (tmp1 >= 1 && tmp1 <= 3)
				{
					std::cout << "data" << tmp1 << ":\n";
					std::cin >> data[tmp1 - 1];
				}
				else
				{
					std::cout << "Error\n";
				}
			break;
			case (2):
				std::cout << "Enter data (1, 2 or 3): ";
				std::cin >> tmp1;
				if (tmp1 >= 1 && tmp1 <= 3)
				{
					std::cout << "Data" << tmp1 << " = " << data[tmp1 - 1];
				}
				else
				{
					std::cout << "Error\n";
				}
			break;
			case (3):
				std::cout << "Enter data (1, 2 or 3): ";
				std::cin >> tmp1;
				if (tmp1 >= 1 && tmp1 <= 3)
				{
					std::cout << "How much days you want to increase: ";
					std::cin >> tmp2;
					data[tmp1 - 1] += tmp2;
				}
				else
				{
					std::cout << "Error\n";
				}
			break;
			case (4):
				std::cout << "Enter the first data(1, 2 or 3): ";
				std::cin >> tmp1;
				std::cout << "Enter the second data(1, 2 or 3): ";
				std::cin >> tmp2;
				if (tmp1 >= 1 && tmp1 <= 3 && tmp2 >= 1 && tmp2 <= 3)
				{
					std::cout << "Data" << tmp1;
					if (data[tmp1 - 1] > data[tmp2 - 1])
					{
						std::cout << " > "; 
					}
					else if (data[tmp1 - 1] < data[tmp2 - 1])
					{
						std::cout << " < ";
					}
					else
					{
						std::cout << " = ";
					}
					std::cout << "data" << tmp2 << "\n";
				}
			break;
			case (0):
				std::cout << "Goodbye";
			break;
			default:
				std::cout << "Error\n";
			break;
		}
	}
}

void test ()
{
	int count = 0;
	Data a;
	Data b(3,0,0);
    Data c(b);
	if (b > a) count++;
	if (a != b) count++;
	a+=1;
	a++;
	if (a.getDay () == 2) count++;
	if (b.getDay () == 3) count++;
	a = b;
	if ((a == b)&&(b == c)) count++;
	count *= 2;
	std::cout << "Test passed for " << count << "/10" << std::endl;
}