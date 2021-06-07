#pragma once
#include"user.h"
#include"reservation.h"
#include <iomanip>
#include <windows.h>

typedef enum Status {Paid, Unpaid};
typedef enum col { A = 1, B, C, D };

class ticket_agent : public user
{
	friend class customer;

public:
	
	static int fsearch(string s, string d, int m, int r)
	{
		vector<flight> flights;
		read(flights);

		int i;
		for (i = 0; i < flights.size(); i++)      //Traverse the vector until the target point is found
		{
			if (s== flights[i].source && d == flights[i].destination && m == flights[i].month && r == flights[i].day)  
			break;
		}

		if (i == flights.size())
			return 0;
		else
			return i + 1;

	}
	//check if a flight is in the text file.



	static int rsearch(string name, string No)
	{
		vector<reservation> reservs;
		read(reservs);

		int i;
		for (i = 0; i < reservs.size(); i++)      //Traverse the vector until the target point is found
		{
			if (name== reservs[i].name && No== reservs[i].No)  //出发日期和始末地点吻合
				break;
		}

		if (i == reservs.size())
			return 0;
		else
			return i + 1;

	}
	//check if a flight is in the text file.

	static void show(string name, string No)
	{
		vector<reservation> reservs;
		read(reservs);

		int i;   
		for (i = 0; i < reservs.size(); i++)      //Traverse the vector until the target point is found
		{
			if (name == reservs[i].name && No == reservs[i].No)  //date and the places meet
				break;
		}
		if (i == reservs.size())
		{
			cout << "This reservation doesn't exist.";
			Sleep(2000);
			system("cls");
			return;
		}
		string type = (reservs[i].ty == 1) ? "P62" : "P124";
		string st= (reservs[i].status== 1) ? "Paid" : "Unpaid";
		cout <<"name: "<< reservs[i].name << endl <<"flight number: "<< reservs[i].No << endl <<"plane type: "<< type<<"seat: "<< reservs[i].seat <<endl << st << endl <<"source: "<<reservs[i].source << endl <<"destination: "<< reservs[i].destination << endl <<"month"<<reservs[i].month << endl << "date: "<<reservs[i].day << endl;
	}

	static void add_record(string name, flight f, bool status, string seat)	//add reservation record
	{
		ofstream fout("reservations.txt", ios::app);
		reservation cus(name, f.No,(int)f.ty, seat, status, f.source, f.destination, f.month, f.day);
		fout << name << '\t' << f.No << '\t'<<f.ty<<'\t'<<seat<<'\t' << status << '\t' << f.source << '\t' << f.destination << '\t' << f.month << '\t' << f.day << endl;  // expiration date of reservation: 5 days before
		fout.close();
	}

	
	static void seat_plan(flight f)	//find the seat view the certain plane
	{
		cout << "Here is the seat plan, * is available, o is occupied" << endl << endl;;

		switch (f.ty)
		{
			case P62:
			{
				cout << "   " << 'A' << ' ' << 'B' << endl;
				for (int i = 1; i < 7; i++)
				{
					cout << setw(2) << i << ' ';
					for (int j = 1; j < 3; j++)
					{
						if (!istaken(i, j, f.No))
							cout << "* ";
						else
							cout << "o ";
					}
					cout << endl;
				}
				break;
			}
			

			case P124:
			{
				cout << "   " << 'A' << ' ' << 'B' << " " << 'C' << ' ' << 'D' << endl;
				for (int i = 1; i < 13; i++)
				{
					cout << setw(2) << i << ' ';
					for (int j = 1; j < 5; j++)
					{

						if (!istaken(i, j, f.No))
							cout << "* ";
						else
							cout << "o ";
					}
					cout << endl;
				}
				break;
			}
			
		}
	}

	static bool istaken(int m, int n, string No)
	{

		vector<reservation> reservs;  //read file to the vectors
		read(reservs);
		string s; string num; int row; int column;
		for (int j = 0; j < reservs.size(); j++)      //Traverse the vector until the target point is found
		{
			if (No == reservs[j].No)
			{
				s = reservs[j].seat;
				for (int i = 0; i < s.size(); i++)
				{
					if (isdigit(s[i]))
						num += s[i];
				}
				row = stoi(num);
				column = s[s.size()-1]-'A'+1;
				if ((m == row) && (n == column)) return 1;
			}
		}

		return 0;

	}

	
	static void Delete(string name, string No)      //expiration
	{
		int pos;
		pos = rsearch(name, No);          //get the position pos of the target point
		if (pos == 0)
			cout << "The reservation can't be found.";
		else
		{
			vector<reservation> reservs;
			read(reservs);


			for (int j = pos - 1; j < reservs.size() - 1; j++)      //Move all elements following pos down (to a lower index) by one slot
				reservs[j] = reservs[j + 1];
			reservs.pop_back();

			ofstream fout("reservations.txt", ios::trunc);
			for (int k = 0; k < reservs.size(); k++)
				
			fout << reservs[k].name << '\t' << reservs[k].No << '\t' << reservs[k].ty << '\t' << reservs[k].seat << '\t' << reservs[k].status << '\t' << reservs[k].source << '\t' << reservs[k].destination << '\t' << reservs[k].month << '\t' << reservs[k].day << endl;  // expiration date of reservation: 5 days before
			fout.close();

			vector<flight> flights;
			read(flights);


			int i;
			for (i = 0; i < flights.size(); i++)      //seat number increase by 1 
			{
				if (flights[i].No == reservs[pos - 1].No)
					flights[i].seats++;
					break;
			}

			ofstream fout2("flights.txt", ios::trunc);
			for (int i = 0; i < flights.size(); i++)      //Traverse the vector until the target point is found
			{
				fout2 << flights[i].No << '\t' << flights[i].ty << '\t' << flights[i].source << '\t' << flights[i].destination << '\t' << flights[i].month << '\t' << flights[i].day << '\t' << flights[i].hour << '\t' << flights[i].minute << '\t' << flights[i].seats << '\t' << flights[i].price << endl;
			}
			fout2.close();

			cout << " Your reservation has been cancelled." << endl;
		}

	}
	//delete a point from the text file.


	static void update(string name, string No)   //amend record
	{	
		int pos;
		pos = rsearch(name, No);          //get the position pos of the target point
		if (pos == 0)
			cout << "The reservation can't be found.";
		else
		{
			vector<reservation> reservs;
			read(reservs);

			reservs[pos - 1].status = 1;

			ofstream fout("reservations.txt", ios::trunc);
			for (int k = 0; k < reservs.size(); k++)
            fout << reservs[k].name << '\t' << reservs[k].No << '\t' << reservs[k].ty << '\t' << reservs[k].seat << '\t' << reservs[k].status << '\t' << reservs[k].source << '\t' << reservs[k].destination << '\t' << reservs[k].month << '\t' << reservs[k].day << endl;  // expiration date of reservation: 5 days before
			fout.close();

			cout << " Your payment status has been updated." << endl;
		}
	}
	
	static void check_sellnum()
	{
		int a, b;
		cout << "Please choose the departure time." << endl;
		cout << "month:" << endl;
		cin >> a;
		cout << "day:" << endl;
		cin >> b;

		vector<flight> flights;
		read(flights);
		int sum = 0;

		for (int i = 0; i < flights.size(); ++i)
		{
			if (flights[i].month == a && flights[i].day == b)
			{
				if (flights[i].ty == P62)
					sum +=12 - flights[i].seats;
				else
					sum +=48 - flights[i].seats;
			}
			
		}
		
		cout << "The number of tickets you have sold is " << sum << endl;
	}

};
