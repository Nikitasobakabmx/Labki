class Data{
private:
    int dayInMonth[2][12] ={
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    long int day = 0;
    long int month = 0;
    long int year = 0;
    int high;
public:
    Data(): day(0), month(0), year(0),high(0){}
    Data(int day, int month, int year);
    Data(Data& data);
    Data operator +(int val);
    Data operator -(int val);
    void operator +=(int val);
    void operator =(Data& tmp);
    void operator =(int tmp);
    bool operator ==(Data tmp);
    bool operator !=(Data tmp);
    bool operator >(Data tmp);
    bool operator >=(Data tmp);
    bool operator <(Data tmp);
    bool operator <=(Data tmp);
    void operator ++(int);
    void operator --(int);
    int getDay();
    friend std::ostream& operator<< (std::ostream& os, const Data& a);
	friend std::istream& operator>> (std::istream& is, Data& a);
    ~Data();
};