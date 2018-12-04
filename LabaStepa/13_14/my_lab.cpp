#include <iostream>
#include "Time.h"
#include "my_lab.h"

void interface ()
{
	int flag = -1;
	int tmp1 = 0;
	int tmp2 = 0;
	Time T[3];
	T[0] = 0;
	T[1] = 0;
	T[2] = 0;
	while (flag != 0)
	{
		std::cout << "\n1 - set time\n";
		std::cout << "2 - output time\n";
		std::cout << "3 - change time\n";
		std::cout << "4 - compare times\n";
		std::cout << "0 - exit\n";
		std::cout << "\nInput flag: ";
		std::cin >> flag;
		switch (flag)
		{
			case (1):
				std::cout << "Enter time (1, 2 or 3): ";
				std::cin >> tmp1;
				if (tmp1 >= 1 && tmp1 <= 3)
				{
					std::cout << "time" << tmp1 << ":\n";
					std::cin >> T[tmp1 - 1];
				}
				else
				{
					std::cout << "Error\n";
				}
			break;
			case (2):
				std::cout << "Enter time (1, 2 or 3): ";
				std::cin >> tmp1;
				if (tmp1 >= 1 && tmp1 <= 3)
				{
					std::cout << "Time" << tmp1 << " = " << T[tmp1 - 1];
				}
				else
				{
					std::cout << "Error\n";
				}
			break;
			case (3):
				std::cout << "Enter time (1, 2 or 3): ";
				std::cin >> tmp1;
				if (tmp1 >= 1 && tmp1 <= 3)
				{
					std::cout << "How much seconds you want to increase: ";
					std::cin >> tmp2;
					T[tmp1 - 1] += tmp2;
				}
				else
				{
					std::cout << "Error\n";
				}
			break;
			case (4):
				std::cout << "Enter the first time(1, 2 or 3): ";
				std::cin >> tmp1;
				std::cout << "Enter the second time(1, 2 or 3): ";
				std::cin >> tmp2;
				if (tmp1 >= 1 && tmp1 <= 3 && tmp2 >= 1 && tmp2 <= 3)
				{
					std::cout << "time" << tmp1;
					if (T[tmp1 - 1] > T[tmp2 - 1])
					{
						std::cout << " > "; 
					}
					else if (T[tmp1 - 1] < T[tmp2 - 1])
					{
						std::cout << " < ";
					}
					else
					{
						std::cout << " = ";
					}
					std::cout << "time" << tmp2 << "\n";
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
	Time a;
	Time b (3);
	if (b > a) count++;
	if (a != b) count++;
	++a;
	a++;
	if (a.Get_tinsec () == 2) count++;
	if (b.Get_tinsec () == 3) count++;
	a = b;
	if (a == b) count++;
	count *= 2;
	std::cout << "Test passed for " << count << "/10" << std::endl;
}