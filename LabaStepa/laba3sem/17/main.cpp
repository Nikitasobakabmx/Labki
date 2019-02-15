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
}