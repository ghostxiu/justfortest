//本程序用来测试运算符重载和友元，包括 timefriend.cc,time.cc,time.h
#include<iostream>
#include"time.cc"
int main()
{
	using std::cout ;
	using std::endl ;

	Time kitty;
	Time john(4,50);
	Time patty(2,20);
	Time kiss(10,05);
	Time total;

	cout << "Show Kitty:"<<endl;
	kitty.show();

	cout << "Show john:" <<endl;
	john.show();

	cout << "Show patty:" <<endl;
	patty.show();

	cout <<"Show kiss:"<<endl ;
	kiss.show();

	cout << "Show john sum patty:";
	total = john.sum(patty);
	total.show();

	cout << "patty + kiss = " ;
	total = patty.operator+(kiss);
	total.show();


	cout << "john + patty + kiss = " ;
	total = john + patty + kiss;
	total.show();

	cout << "kiss - patty = " ;
	total = kiss - patty ;
	total.show();

	int mul = 3;
	cout << "patty * 3 = " ;
	total = patty * mul;
	total.show();

	mul = 2;
	cout << "kiss * 2 = " ;
	total = mul * kiss;
	total.show();

	total.reset_time();
	cout << "Now total is reset:";
	total.show();

}
