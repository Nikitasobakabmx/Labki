#include "List.h"
#include <stdio.h>
#include <iostream>

int main()
{
	List<int> listOne(12);
	List<int> listTwo;
	listOne.push_back(5);
	listOne.push_front(11);
	printf("%d\n", listOne.size());
	std::cout << listOne.size() << std:: endl;
	try
	{
		listOne.find_and_erase(32);
	}
	catch (except ex)
	{
		printf("%s\n", ex.string);
		std::cout << ex.string << std:: endl;
	}
	printf("%d\n", listOne.size());
	try
	{
		printf("%d\n", listOne.at(2));
		std::cout << listOne.at(2) << std:: endl;
	}
	catch (except ex)
	{
		printf("%s\n", ex.string);
		std::cout << ex.string << std:: endl;
	}
	listTwo = listOne;
	List<int> listThree(listTwo);

	printf("%d\n", listTwo.size());
	std::cout << listTwo.size() << std:: endl;

	try
	{
		printf("%d\n", listTwo.at(0));
		std::cout << listTwo.at(0) << std:: endl;
		printf("%d\n", listThree.at(1));
		std::cout << listTwo.at(1) << std:: endl;
	}
	catch (except ex)
	{
		printf("%s\n", ex.string);
		std::cout << ex.string << std:: endl;
	}

	return 0;
}
