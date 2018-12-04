#include <iostream>
#include "Time.h"

Time::Time ()
{
	Set (0);
}

Time::Time (int val)
{
	Set (val);
}

Time::Time (Time& a)
{
	hours = a.hours;
	minutes = a.minutes;
	seconds = a.seconds;
}

Time::~Time () {};

int Time::Get_tinsec () const
{
	return hours * 3600 + minutes * 60 + seconds;
}

void Time::Set (int val)
{
	while (val < 0)
	{
		val += 86400;
	}
	hours = 0;
	minutes = 0;
	val = val % 86400;
	while (val >= 3600)
	{
		val -= 3600;
		hours++;
	}
	while (val >= 60)
	{
		val -= 60;
		minutes++;
	}
	seconds = val;
}

Time Time::operator+ (int val) const
{
	Time tmp;
	tmp.Set (Get_tinsec () + val);
	return tmp;
}

Time& Time::operator+= (int val)
{
	Set (Get_tinsec () + val);
	return *this;
}

Time& Time::operator-= (int val)
{
	val *= -1;
	*this += val;
	return *this;
}

Time& Time::operator= (const Time& a)
{
	Set (a.Get_tinsec ()); 
	return *this;
}

Time& Time::operator= (int val)
{
	Set (val);
	return *this;
}

bool Time::operator== (const Time& a) const
{
	if (Get_tinsec () == a.Get_tinsec ())
	{
		return true;
	}
	return false;
}

bool Time::operator> (const Time& a) const
{
	if (Get_tinsec () > a.Get_tinsec ())
	{
		return true;
	}
	return false;
}

bool Time::operator!= (const Time& a) const
{
	return !(*this == a);
}

bool Time::operator< (const Time& a) const
{
	return !((*this > a) || (*this == a));
}

bool Time::operator>= (const Time& a) const
{
	return ((*this > a) || (*this == a));
}

bool Time::operator<= (const Time& a) const
{
	return ((*this < a) || (*this == a));
}

Time& Time::operator++ ()
{
	*this += 1;
	return *this;
}

Time& Time::operator-- ()
{
	*this -= 1;
	return *this;
}

Time Time::operator++ (int)
{
	Time tmp = *this;
	*this += 1;
	return tmp;
}

Time Time::operator-- (int)
{
	Time tmp = *this;
	*this -= 1;
	return tmp;
}

std::ostream& operator<< (std::ostream& os, const Time& a)
{
	int tmp = a.hours % 12;
	if (tmp == 0)
	{
		tmp = 12;
	}
	os << tmp << ':';
	if (a.minutes < 10)
	{
		std::cout << "0";
	}
	std::cout << a.minutes << ":";
	if (a.seconds < 10)
	{
		std::cout << "0";
	}
	std::cout << a.seconds;
	if (a.hours < 12)
	{
		std::cout << "am\n";
	}
	else
	{
		std::cout << "pm\n";
	}
	return os;
}

std::istream& operator>> (std::istream& is, Time& a)
{
	a.Set (0);
	int tmp = 0;	
	std::cout << "Input hours: ";
	is >> tmp;
	a += tmp * 3600;
	std::cout << "Input minutes: ";
	is >> tmp;
	a += tmp * 60;
	std::cout << "Input seconds: ";
	is >> tmp;
	a += tmp;
	
	return is;
}