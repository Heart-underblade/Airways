#pragma once
#include"user.h"
#include"ticket agent.h"
#include <iomanip>


class customer : public user
{

public:
	
	static void book_ticket(string name)     
	{
		string s, d;
		int a, b;
		bool status;
		string seat;

		vector<flight> all_f;
		read(all_f);
		cout << "F_No.  Depature  Arrival  Month  Date  Hour  Minute  Price" << endl;
		for (int i = 0; i < all_f.size(); ++i)		//show flights table
		{
			cout << all_f[i].No << setw(9) << all_f[i].source << setw(8) << all_f[i].destination << setw(8) << all_f[i].month << setw(5) << all_f[i].day << setw(5) << all_f[i].hour << setw(8) << all_f[i].minute << setw(8) << all_f[i].price << endl;
		}
		
		
		cout << "Please set the departure time." << endl;
		cout << "month:" << endl;
		cin >> a;
		cout << "day:" << endl;
		cin >> b;
		

		vector<reservation> reservs;
		read(reservs);

		int w;
		for (w = 0; w < reservs.size(); w++)      
		{
			if ((name == reservs[w].name && a == reservs[w].month) && b == reservs[w].day)
			{
				cout << "You can only book one ticket for yourself during the same duration" << endl;
				Sleep(2000);
				system("cls");
				return;
			}
		}

		cout << "Please set the source:";		//search for required information
		cin >> s;
		cout << "Please set the destination:";
		cin >> d;


		int x=ticket_agent::fsearch(s, d, a, b);

		vector<flight> flights;
		read(flights);

		if (x == 0 || flights[x - 1].seats == 0)
		{
			cout << "Sorry, there isn't any flight meet your demand." << endl;
			Sleep(2000);
			system("cls");
		}
		else
		{
			
			cout << "Found the flight successfully!" << endl;
			cout << "Flight number is "<< flights[x - 1].No<<" departure time is "<< flights[x - 1].hour<<" arrive time is "<< flights[x - 1].minute << endl;
			
			
			ticket_agent::seat_plan(flights[x - 1]);
					
			bool f ;
			cout << endl << endl;
			do
			{
				f = 0;
				cout << "Please select your seat"<<endl;  //register a seat on the plane			
				cin >> seat;
				vector<reservation> reservs;
				read(reservs);
				for (int i = 0; i < reservs.size(); ++i)
				{
					if (flights[x - 1].No == reservs[i].No && seat == reservs[i].seat)
					{
						cout << "The seat has been taken, please choose another" << endl;
						f = 1;
						break;

					}
					
				}
				

			} while (f);
			
			
			cout << "The ticket price is " << flights[x - 1].price << " do you want to pay now?(1 pay now, 0 pay later)" << endl;
			cin >> status;
			//Status st = (Status)status;
			ticket_agent::add_record(name, flights[x - 1], status, seat);
			
			
			flights[x - 1].seats--; 
			
			ofstream fout("flights.txt", ios::trunc);
			for (int i = 0; i < flights.size(); i++)      //Traverse the vector until the target point is found
			{
				fout << flights[i].No << '\t' << flights[i].ty << '\t' << flights[i].source << '\t' << flights[i].destination << '\t' << flights[i].month << '\t' << flights[i].day << '\t' << flights[i].hour << '\t' << flights[i].minute << '\t' << flights[i].seats << '\t' << flights[i].price << endl;
			}
			fout.close();
		}
	}
};
