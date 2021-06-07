#include "administrator.h"
#include "customer.h"
#include "flight.h"
#include "manager.h"
#include "ticket agent.h"
#include "user.h"
 


int main()
{
	
	int id, opt;
	enum {Administrator, Manager, Ticket_agent, Customer};
	
	bool Flag = 1, flag=1;

	do {
		cout <<  "Welcome to the airways management system!" << endl;
		cout << "Please select your identity:" << endl;
		cout <<  "0.Administrator" << setw(12) << "1.Manager" << "\n" << "2.Ticket agent" << setw(14)<< "3.Customer" <<"\n"<< "4.Exist"<< endl;

		cin >> id;
		if (id == 4) Flag = 0; //while select exist, end loop;
		switch (id)		//login with different identity
		{
		case Administrator:
			{	
				
				system("cls");
				
				administrator a;
				do  
				{
					cout << "Please select the options you wish to do" << endl;
					cout << "1.Add flight " << "2.Add planes " << "3.Back to main menu " << endl;
					cin >> opt;
					system("cls");
					
					if (opt == 3)
					{
						flag = 0;  //finish loop back to the main menu
					}
					else if (opt == 2) a.add_plane();
					else if (opt == 1) a.add_flight();
					else cout << "Please choose a correct number of option" << endl;
					system("pause");
					system("cls");
					
				} while(flag);
			}
			break;
		
		case Manager:
			{
				do
				{
					system("cls");
					manager m;
					flag = 1;
					cout << "Please select the options you wish to do" << endl;
					cout << "1.Check plane numbers " <<setw(30)<< "2.Check passenger per flight " <<"\n"<< "3.Check revenue "<< setw(30) <<"4.Back to main menu " << endl;
					cin >> opt;
					system("cls");

					if (opt == 4)
					{
						flag = 0;
					}
					else if (opt == 3) m.check_revenue();
					else if (opt == 1) m.check_plane();
					else if (opt == 2) m.check_passenger();
					else cout << "Please choose a correct number of option" << endl;
					system("pause");
					system("cls");
				} while (flag);
			}
			break;
		
		case Ticket_agent:
			{
				
				do
				{
					system("cls");
					ticket_agent t; string name, no;
					flag = 1;
					cout << "Please select the options you wish to do" << endl;
					cout << "0.check how many ticket you have sold " << endl;
					cout<<"1.check reservations for a customer " <<endl<< "2.Update reservations " << endl;
					cout <<"3.Delete reservations "<<"4.Exist " <<endl;
					cin >> opt;
					system("cls");

					if (opt == 4)
					{
						flag = 0;
					}

					else if (opt == 3)
					{
						cout << "Please enter custormer's name:" << endl;
						cin >> name;
						cout << "Please enter flight number:" << endl;
						cin >> no;
						ticket_agent::Delete(name,no);
					}
					else if (opt == 2)
					{
						cout << "Please enter custormer's name:" << endl;
						cin >> name;
						cout << "Please enter flight number:" << endl;
						cin >> no;
						ticket_agent::update(name,no);
					}
					else if (opt == 1)
					{
						cout << "Please enter custormer's name:" << endl;
						cin >> name;
						cout << "Please enter flight number:" << endl;
						cin >> no;
						ticket_agent::show(name, no);
					}

					else if (opt == 0)
					{
						ticket_agent::check_sellnum();
					}
				
					else cout << "Please choose a correct number of option" << endl;
					system("pause");
					system("cls");

				} while (flag);
			}
			break;
		
		case Customer:
			{
			system("cls");
			string name;

			cout << "Please enter your name:" << endl;
			cin >> name;

			do
			{
				flag = 1;
				cout << "Please select the options you wish to do" << endl;
				cout << "1.Book tickets " << "2.Back to main menu" << endl;
				cin >> opt;
				system("cls");

				if (opt == 2)
				{
					flag = 0;
				}
				else if (opt == 1)
				{
				
				customer::book_ticket(name);
				system("cls");
			    }
					else 
					{
					   cout << "Please choose a correct number of option" << endl;
					   Sleep(2000);
					   system("cls"); 
					}
					
					

				} while (flag);

			}
			break;
		
		default:
			{
				cout << "Please enter a correct option" << endl;
				system("pause");
				system("cls");
			}
				

		}
	} while (Flag);
	
	cout << "Exit successfully!" << endl;
	system("pause");

}