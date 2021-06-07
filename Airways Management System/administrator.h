#pragma once
#include"user.h"

class administrator : public user
{
	friend class user;

public:

	void add_plane()
	{
		int num1, num2;
		ifstream fin("admin.txt");
		fin >> num1 >> num2;
		int m,n;
		cout << "Please set the plane type (1 for P62, 2 for P124):";
		cin >> m;
		cout << "How many do you want to add:";
		cin >> n;
		if (m == 1)
			num1 += n;
		else
			num2 += n;
		ofstream fout("admin.txt", ios::trunc);
		fout << num1 << '\t' << num2;
		cout << "Now there are " << num1 << " planes for P62 " << num2 << " planes for P124" << endl;

	}

	void add_flight()
	{
			int a, b, c, m, ty, p; 
			string n, s, d;

			ofstream fout("flights.txt", ios::app);

			cout << "Please set the flight number:";
			cin >> n;
			cout << "Please set the plane type (1 for P62, 2 for P124):";
			cin >> ty;
			cout << "Please set the departure time." << endl;
			cout << "month:" << endl;
			cin >> a;
			cout << "day:" << endl;
			cin >> b;
			cout << "hour:" << endl;                 
			cin >> c;
			cout << "minute:" << endl;
			cin >> m;
			cout << "Please set the source:";
			cin >> s;
			cout << "Please set the destination:";
			cin >> d;
			cout << "Please set the price per ticket:";
			cin >> p;

			flight f(a, b, c, m, ty, p, n, s, d);
			
			fout << f.No << '\t' << f.ty<< '\t' << f.source<< '\t' << f.destination << '\t' << f.month << '\t' << f.day << '\t' << f.hour<< '\t' << f.minute<< '\t' << f.seats << '\t' << f.price<<endl;
			fout.close();
			cout << "Successfully add a plane, now go back to menu" << endl;
			system("pause");

	}
};
