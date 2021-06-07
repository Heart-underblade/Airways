#pragma once
#include"user.h"
class manager : public user
{

public:
	
	void check_plane()
	{
		ifstream fin("admin.txt");
		int x, y;
		fin >> x >> y;

		cout << "The number of each type of planes are" << endl;
		cout << "P62:" << " " << x << endl;   //output number of planes
		cout << "P124:" << " " << y << endl;
	}

	void check_passenger()
	{
		vector<flight> flights;
		read(flights);
			
		for (int i = 0; i<flights.size(); i++)
		{
			if (flights[i].ty == P62)
				cout << "Flight NO." << flights[i].No << '\t' << "Passenger numbers:" << 12 - flights[i].seats << endl;
			else
				cout << "Flight NO." << flights[i].No << '\t' << "Passenger numbers:" << 48 - flights[i].seats << endl;
		}

	}
	
	void check_revenue()
	{
		vector<flight> flights;
		read(flights);
		int sum = 0;

		for (int i = 0; i < flights.size(); ++i)
		{
			if (flights[i].ty == P62)
				sum += flights[i].price * (12-flights[i].seats);
			else
				sum += flights[i].price * (48 - flights[i].seats);	
		}
		cout << "The total revenue is " << sum << endl;
	}
};
