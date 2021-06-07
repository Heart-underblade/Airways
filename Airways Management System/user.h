#pragma once
#include"flight.h"
#include"fstream"
#include<iostream>
#include<vector>
#include <string>
#include "reservation.h"

class user
{
public:
	
	static void read(vector<flight>& flights) //read information about the flights stored
	{
		ifstream fin("flights.txt");

		int a, b, c, m, p, sn,ty;   // sn stands for seat number
		string n, s, d;
		
		while (!fin.eof())
		{
			fin >> n >> ty >> s >> d;
			
			fin >> a >> b >> c >> m >> sn >> p;
			flight f(a, b, c, m, ty, p, sn,  n, s, d);
			flights.push_back(f);     //Read in a flight from the file and append it to 
		}

		flights.pop_back();

		fin.close();

	}
	// read flights from the text file into a vector
	static void read(vector<reservation>& reservs)
	{
		ifstream fin("reservations.txt");

		string name; string No; string seat; bool status; string source; string destination; int month; int day;
		int ty;

		while (!fin.eof())
		{
			fin >> name >>No >>ty>> seat >> status >> source>> destination>>month>>day;
			reservation r(name, No, ty, seat, status, source, destination, month, day);
			reservs.push_back(r);     //Read in a reservation from the file and append it to 
		}

		reservs.pop_back();

		fin.close();
	}

	

	
};