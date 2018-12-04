<<<<<<< HEAD
#include "List.h"
#include <iostream>

struct Point{
	int x;
	int y;
	int z;
};

int main()
{
	List<struct Point> PointList();
	List<int> listOne(45);
	listOne.push_back(11);
	listOne.push_front(44);
	printf("%d\n", listOne.size());
	try
	{
		listOne.find_and_erase(34);
	}
	catch (except ex)
	{
		printf("%s\n", ex.what());
	}
	printf("%d\n", listOne.size());
	try
	{
		printf("%d\n", listOne.at(0));
	}
	catch (except ex)
	{
		printf("%s\n", ex.what());
	}
	List<int> listTwo;
	listTwo = listOne;
	List<int> listThree(listTwo);
	printf("%d\n", listTwo.size());
	try
	{
		printf("List Two %d\n", listTwo.at(1));
		printf("List Three %d\n", listThree.at(0));
	}
	catch (except ex)
	{
		printf("%s\n", ex.what());
	}
	return 0;
=======
#include "List.h"
#include <stdio.h>

int main()
{
	List<int> listOne(12);
	List<int> listTwo;
	listOne.push_back(5);
	listOne.push_front(11);
	printf("%d\n", listOne.size());
	try
	{
		listOne.find_and_erase(32);
	}
	catch (except ex)
	{
		printf("%s\n", ex.string);
	}
	printf("%d\n", listOne.size());
	try
	{
		printf("%d\n", listOne.at(2));
	}
	catch (except ex)
	{
		printf("%s\n", ex.string);
	}
	listTwo = listOne;
	List<int> listThree(listTwo);

	printf("%d\n", listTwo.size());

	try
	{
		printf("%d\n", listTwo.at(0));
		printf("%d\n", listThree.at(1));
	}
	catch (except ex)
	{
		printf("%s\n", ex.string);
	}

	return 0;
>>>>>>> a21eea7f6e198389ea6cc655b5462626ec06f9de
}