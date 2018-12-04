#ifndef _TIME_H_
#define _TIME_H_

class Time
{
private:
	size_t hours;
	size_t minutes;
	size_t seconds;
public:
	Time ();
	Time (int val);
	Time (Time& a);
	~Time ();
	int Get_tinsec () const;
	void Set (int val);
	Time operator+ (int val) const;
	Time& operator+= (int val);
	Time& operator-= (int val);
	Time& operator= (const Time& a);
	Time& operator= (int val);
	bool operator== (const Time& a) const;
	bool operator!= (const Time& a) const;
	bool operator> (const Time& a) const;
	bool operator< (const Time& a) const;
	bool operator>= (const Time& a) const;
	bool operator<= (const Time& a) const;
	Time& operator++ ();
	Time& operator-- ();
	Time operator++ (int);
	Time operator-- (int);
	friend std::ostream& operator<< (std::ostream& os, const Time& a);
	friend std::istream& operator>> (std::istream& is, Time& a);
};

#endif