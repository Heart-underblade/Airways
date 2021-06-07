#pragma once
#include<string>

using namespace std;

class reservation
{
	friend class customer;
	friend class ticket_agent;
	friend class administrator;
	friend class manager;
private:
	int month;
	int day;

	bool status;

	string name;
	string No;
	string source;
	string destination;
	string seat;
	Type ty;



public:
	reservation(string name, string No, int ty, string seat, bool status, string source, string destination, int month, int day)
	{
		this->name = name;
		this->No = No;
		this->ty = (Type)ty;    //type of the planes
		this->seat = seat;
		this->status = status;
		this->source = source;
		this->destination = destination;
		this->month = month;
		this->day = day;
		
	}

	
	
	
};