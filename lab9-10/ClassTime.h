#pragma once

#include <iostream>
#include <ctime>

using namespace std;
class Time
{
public:
	Time(){ hour = minute = second = 0; };
	
private:
	int hour;
	int minute;
	int second;

public: void setTime(int h, int m, int s)
	{
		hour = (h >= 0 && h < 24) ? h : 0;
		minute = (m >= 0 && m < 60) ? m : 0;
		second = (s >= 0 && s < 60) ? s : 0;
	}

public: void printStandard()
	{
		cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
			<< ":" << (minute < 1 ? "0" : "") << minute
			<< ":" << (second < 1 ? "0" : "") << second
			<< (hour < 12 ? " AM" : " PM");
	}
};
