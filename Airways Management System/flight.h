#pragma once
#include<string>
using namespace std;

typedef enum Type { P62=1, P124=2 };
class flight
{
	friend class customer;
	friend class ticket_agent;
	friend class administrator;
	friend class manager;
	friend class reservation;
private:	
     int month;
	 int day;
	 int hour;
	 int minute;
	
	string No;
	string source;
	string destination;
	Type ty;

protected:
	int price;
	int seats; // number of seats left
	

public:

	flight(int a, int b, int c, int m, int t, int p, string n, string s, string d)
	{
		month = a;
		day = b;
		hour = c;
		minute = m;
		No = n;
		source = s;
		destination = d;
		ty = (Type)t;
		if (ty == 1)
			seats = 12;
		else
			seats = 48;
		price = p;
	}


	flight(int a, int b, int c, int m, int t, int p, int sn, string n, string s, string d)
	{
		month = a;
		day = b;
		hour = c;
		minute = m;
		No = n;
		source = s;
		destination = d;
		ty = (Type)t;
		seats = sn;
		price = p;
	}

		
};


