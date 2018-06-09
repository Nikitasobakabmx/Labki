#include <iostream>
#include "Data.h"

Data::Data(int day, int month, int year){
    if(day > this->dayInMonth[this->high][this->month-1])
        *this +(day);
    if(month > 12)
        this->year += month/12;
    this->month %= 12;
    
    this->year += year;
    if(((this->year % 4 == 0) && (this->year % 100 != 0)) || (this->year % 400 == 0))
        this->high = 1;
    else
        this->high = 0; 
}

Data::Data(Data& data){
    *this =(data);
}

Data Data::operator +(int val){
    day += val;
    while(day > dayInMonth[high][month-1]){
        day -= dayInMonth[high][month-1];
        month++;
        if(month > 12){
            month = 1;
            year++;
            if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
                high = 1;
            else
                high = 0;
        // if(month > 12)
        //     year += month/12;
        // month %= 12;
        // if(day > dayInMonth[high][month-1])
        //     *this +(day);
        // if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        //     high = 1;
        // else
        //     high = 0;
        }	
        
    }
    return *this;
}
Data Data::operator -(int val){
    while(true){
            if(val >= day){
                val -=day;
                day = dayInMonth[high][--month];
                continue;
            }
            day -= val;
            break;
        }
    return *this;
}

void Data::operator +=(int val){
    *this +(val);
}
void Data::operator =(Data& tmp){
    this->day = tmp.day;
    this->month = tmp.month;
    this->year = tmp.year;
    this->high = tmp.high;
}
void Data::operator =(int tmp){
    *this +(tmp);
}
bool Data::operator ==(Data data){
    bool tmp = true;
    if(this->day != data.day)
        tmp = false;
    if(this->month != data.month)
        tmp = false;
    if(this->year != data.year)
        tmp = false;
    if(this->high != data.high)
        tmp = false;
    return tmp;
}
bool Data::operator !=(Data tmp){
    return !(*this ==(tmp));
}
bool Data::operator >(Data data){
    bool tmp = true;
    if(this->year < data.year)
        tmp = false;
    if((this->month < data.month) && (this->year <= data.year))
        tmp = false;
    if((this->day < data.day) && (this->month <= data.month) && (this->year <= data.year))
        tmp = false;
    return tmp;
}
bool Data::operator >=(Data tmp){
    return !((*this >(tmp)) && (*this ==(tmp)));
}
bool Data::operator <(Data tmp){
    return (!(*this >(tmp)) || !(*this ==(tmp)));
}
bool Data::operator <=(Data tmp){
    return !(*this >(tmp));

}
void Data::operator ++(int){
    *this +(1);
}

void Data::operator --(int){
    *this -(1);
}
int Data::getDay(){
    return this->day;
}

std::ostream& operator<< (std::ostream& os, const Data& a){
	os << a.day << ':'<< a.month << ":"<< a.year;
	return os;
}

std::istream& operator>> (std::istream& is, Data& a){
    a.day = a.month = a.year = 0;
    int day;
	std::cout << "Input days: ";
	is >> day;
	std::cout << "Input month: ";
	is >> a.month;
	std::cout << "Input year: ";
	is >> a.year;
    if(a.month > 12)
        a.year += a.month/12;
    a.month %= 13;
    if(((a.year % 4 == 0) && (a.year % 100 != 0)) || (a.year % 400 == 0))
        a.high = 1;
    else
        a.high = 0;	
    // if(a.day > a.dayInMonth[a.high][a.month-1])
    a +(day);
    
}
Data::~Data(){
}