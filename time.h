//本程序用来测试运算符重载和友元，包括 timefriend.cc,time.cc,time.h
#ifndef TIME_H_
#define TIME_H_

class Time{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h , int m);
	//构造函数
	void add_hour(int &h);//小时增加
	void add_min(int& m);//分钟增加
	void show() const;//输出时间
	void reset_time(int h = 0,int m = 0 );
	Time sum(const Time & t) const ;
	Time operator+(const Time &t) const;
	Time operator-(const Time &t) const;
	Time operator*(const int &mul) const;//乘以一个时间因子
	~Time();//析构函数
	//friend Time operator*(double m , const Time & t);
	//友元函数，更换了二元运算符两边参数的位置

};
#endif // TIME_H_
