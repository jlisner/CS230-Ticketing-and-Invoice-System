/*Project 2 -- Computer Repair Invoicing System

Login Info
username = user
password = pass
*/

#include <iostream>
#include <fstream>
#include "Invoice.h"

using namespace std;

int main()	// Main function
{
	invoice admin;
	int option;
		do{
			system("cls");
    		cout<<"\n\t======================================\n"
				<<"\t|  Computer Repair Invoicing System  |\n"
				<<"\t======================================\n"
				<<"\t|1. Customer                         |\n"
				<<"\t|2. Technician                       |\n"
				<<"\t|3. EXIT                             |\n"
				<<"\t======================================\n";
		
		    cout<<"\tEnter Menu Selection: ";
				cin>>option;
			switch(option)
				{
					case 1:
					{
						admin.customer_WorkOrder();
						break;
					}
					case 2:
					{
						admin.admin_menu();
						break;
					}
					case 3:
					{
						admin.exit();	//function exit
						break;
					}
            		default: //Incorrect Main Menu Selection Notification
            		{
    	        		cout <<"\n\tSorry, That Is Not An Option!\n\n";
    					system("PAUSE");
            		}
				}
		}while(option!=3);
		system ("PAUSE");
		return 0;
}
