//本程序用来测试运算符重载和友元，包括 timefriend.cc,time.cc,time.h
#include"time.h"
#include<iostream>
Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int  h ,int  m)
{
	hours = h;
	minutes = m ;
}

void Time::reset_time(int  h ,int  m)
{
	hours = h;
	minutes = m ;
}

void Time::add_hour(int &h)
{
	hours += h ;
}

void Time::add_min(int &m)
{
	minutes += m;
	hours += minutes / 60 ;
	minutes %= 60;
}

void Time::show() const
{
	std::cout << hours << ":" <<minutes<<std::endl;
}

Time Time::sum(const Time & t) const
{
	Time tp;
	tp.minutes = minutes + t.minutes;
	tp.hours = hours + t.hours + tp.minutes/60;
	tp.minutes = tp.minutes%60;
	return tp;
}

//在Time类中重载运算符+
Time Time::operator+(const Time &t) const
{
	Time tp ;
	tp.minutes = minutes + t.minutes;
	tp.hours = hours + t.hours + tp.minutes/60;
	tp.minutes = tp.minutes%60;
	return tp;
}
//在Time类中重载运算符-
Time Time::operator-(const Time &t) const
{
	Time tp;
	int total_minutes = (this -> minutes + this -> hours * 60) - (t.minutes + t.hours * 60);
	tp.hours = total_minutes / 60 ;
	tp.minutes = total_minutes % 60 ;
	return tp ;
}
//在Time类中重载运算符*
Time Time::operator*(const int & mul) const
{
	Time tp;
	int total_minutes = (this -> minutes + this -> hours * 60) * mul ;
	tp.hours = total_minutes / 60 ;
	tp.minutes = total_minutes % 60 ;
	return tp ;
}

Time::~Time()
{
	std::cout <<"\n\n\nMemory is freeing!\n";
}
/*

//友元函数
Time operator*(double mul , const Time & t)
{
	Time tp;
	int total_minutes = (t.minutes + t.hours * 60) * mul ;
	tp.hours = total_minutes / 60 ;
	tp.minutes = total_minutes % 60 ;
	return tp ;
}
*/

//使用这种方法可以不使用友元函数
Time operator*(double mul , const Time & t)
{
	return t*mul ;
}
