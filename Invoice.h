//Invoice.h
#ifndef INVOICE_H
#define INVOICE_H

#include <string>
using namespace std;

class invoice	//base class
{
public:
	void customer_WorkOrder();
	void admin_menu();
    	void create_WorkOrder();
    	void cancel_WorkOrder();
    	void update_WorkOrder();
	void print_WorkOrder();
	void view_WorkOrder();
	void exit();
	
	invoice();//constuctor
};

invoice::invoice()
{
	//constructor
}

struct node //construct node
{
	int invoice_number;
	string customerName;
	string date;
	string x;

	node *prev;
	node *next;
	node *link;

}*q, *temp; //pointer declaration


node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;

void invoice::customer_WorkOrder()		
{
	system("cls");
    cout<<"\n\t======================================\n"
		<<"\t|  Computer Repair Invoicing System  |\n"
		<<"\t======================================\n\n"
		<<"\tEnter Repair Ticket Details\n"
		<<"\t--------------------------------------\n";
	node *temp;
	temp = new node;
	
	cout << "\tType Ticket #: ";
    	cin >> temp->invoice_number;
	cout<< "\tEnter Your Name: ";
		cin.ignore();                      
		getline(cin, temp->customerName);
	cout<<"\tEnter Date: ";
		cin>>temp->date;
	cout<< "\tEnter Description for Issue (1000 words maximum): "
		<<"\n\t\t";
		cin.ignore();                      
		getline(cin, temp->x);

    cout<<"\n\t======================================\n"
		<<"\t*    Ticket Created Successfully!    *\n"
    	<<"\t======================================\n";
    
	system ("PAUSE");

    temp->next=NULL;
	if(start_ptr!=NULL)
		{
			temp->next=start_ptr;
		}
	start_ptr=temp;
	system("cls");
}

void invoice::admin_menu()
{
	invoice admin;
	int menu;
	string userName, userPassword;

	system("cls");

    cout<<"\n\t======================================\n"
		<<"\t|  Computer Repair Invoicing System  |\n"
		<<"\t======================================\n\n"
  		<<"\t--------------------------------------\n"
    	<<"\t*          Technician Login          *\n"
    	<<"\t--------------------------------------\n"
    	<<"\tPlease enter your user name: ";
    	cin >> userName;
    cout<<"\tPlease enter your user password: ";
    	cin >> userPassword;

    if (userName == "user" && userPassword == "pass")
    	{
	    	do
			{
		        system("cls");
		        cout<<"\n\t======================================\n"
					<<  "\t|  Computer Repair Invoicing System  |\n"
					<<  "\t======================================\n"
					<<  "\t1. Create a Ticket\n"
					<<  "\t2. View Ticket\n"
					<<  "\t3. Update Ticket Status\n"
					<<  "\t4. Print Ticket\n"
					<<  "\t5. Cancel A Ticket\n"
					<<	"\t6. Exit\n"
					<<  "\t======================================\n\n"
					<<	"\tEnter choice: ";
				cin>>menu;
		
				switch (menu)
				{
					case 1:
					{
						admin.create_WorkOrder();
						break;
					}
					case 2:
					{
						admin.view_WorkOrder();
						system("PAUSE");
						break;
					}
					case 3:
					{
						admin.update_WorkOrder();
						system("PAUSE");
						break;
					}
					case 4:
					{
						admin.print_WorkOrder();
						system("PAUSE");
						break;
					}
					case 5:
					{
						admin.cancel_WorkOrder();
						system("PAUSE");
						break;
					}
		        		case 6:
					{
						cout<<"\n\tLogged Out!\n";
						break;
					}
            		default: //Incorrect Main Menu Selection Notification
            		{
    	        		cout <<"\n\tSorry, That Is Not An Option!\n\n";
    					system("PAUSE");
            		}
				}//end Switch	
			}while(menu!=6);//end do
			system ("PAUSE");
	}
	else
	{
        cout << "\n\tLogin Incorrect!\n\tPlease Try Again";
        system("PAUSE");
        system ("cls");
        admin.admin_menu();
    }
}

void invoice::create_WorkOrder()
{
	system("cls");
    cout<<"\n\t======================================\n"
		<<"\t|  Computer Repair Invoicing System  |\n"
		<<"\t======================================\n"
		<<"\tAdd Ticket Details\n"
		<<"\t______________________________________\n";

	node *temp;
	temp = new node;
	cout << "\tType Ticket #: ";
    	cin >> temp->invoice_number;
	cout<< "\tEnter Customer Name: ";
		cin.ignore();
		getline(cin, temp->customerName);
	cout<<"\tEnter Date : ";
		cin>>temp->date;
	cout<< "\tComplaint Description (1000 Words Maximum): \n\t\t";
		cin.ignore();
		getline(cin, temp->x);
	cout<<"\n\t======================================\n"
		<<  "\t*     Ticket Created Successfully    *"
    	<<"\n\t======================================\n";
	system ("PAUSE");

    temp->next=NULL;
	if(start_ptr!=NULL)
		{
			temp->next=start_ptr;
		}
	start_ptr=temp;
	system("cls");
}

void invoice::view_WorkOrder()
{
	int num;
	bool found;			//variable to search
	system("cls");
	node *temp;

	temp=start_ptr;
	found = false;
	
    cout<<"\n\t======================================\n"
		<<"\t|  Computer Repair Invoicing System  |\n"
		<<"\t======================================\n"
		<<"\tEnter the Ticket Number To Search For: ";
		cin>>num;
	cout<<"\n\t---------------------------------------\n"
		<<"\t*       Here Is The Ticket Info       *"
		<<"\n\t---------------------------------------\n";
	if(temp == NULL) 
		{
			cout<<"\tTicket Not Found\n";
		}
	while(temp !=NULL && !found)
		{
			if (temp->invoice_number==num)
				{
					found = true;
				}
			else
				{
					temp = temp -> next;
				}
	        if (found)
		        {
				cout<<"\tTicket Number: "<<temp->invoice_number<<"\n"
					<<"\tCustomer Name: "<<temp->customerName<<"\n"
					<<"\tTicket Date: "<<temp->date<<"\n"
					<<"\tTicket Description: \n\t\t"
					<<temp->x<<endl;
				}
		}
}

void invoice::cancel_WorkOrder()
{
	system("cls");
	int num, count;
	
	cout<<"\n\t======================================\n"
		<<"\t|  Computer Repair Invoicing System  |\n"
		<<"\t======================================\n"
		<<"\tEnter Ticket Number To Cancel: ";
    cin>>num;
    node *q;
	node *temp;
	bool found;

	if(start_ptr == NULL)
		cerr<<"\tCan't Cancel From Empty List\n";
	else
		{	
			if(start_ptr->invoice_number == num)
			{
				q = start_ptr;
				start_ptr = start_ptr->next;
				count--;
				if(start_ptr == NULL)
				last = NULL;
				delete q;
				cout<<"\tThe Ticket Was Cancelled"<<endl;
			}
			else
			{
				found = false;
				temp = start_ptr;
				q = start_ptr->next;
	
				while((!found) && (q != NULL))
					{
		  			if(q->invoice_number != num)
					{
						temp = q;
						q = q-> next;
					}
					else
						found = true;
					}
	
				if(found)
					{
						temp->next = q->next;
						count--;
		
						if(last == q)
						last = temp;
						delete q;
						cout<<"\tThe Ticket Was Cancelled"<<endl;
					}
				else
					cout<<"\tTicket Was Not Found"<<endl;
			}
		}
}

void invoice::update_WorkOrder()
{
	system("cls");
	int sid;
	bool found;
	found = false;
	temp = start_ptr;
	
	cout<<"\n\t======================================\n"
		<<"\t|  Computer Repair Invoicing System  |\n"
		<<"\t======================================\n"
		<<"\tEnter Ticket Number To Update: ";
		cin>>sid;
	if (temp==NULL && sid==0)
		{
			cout<<"\n\tTicket Not Found!"<<endl;
		}
	else
		{
			while(temp !=NULL && !found)
			{
				if (temp->invoice_number==sid)
				{
					found = true;
				}
				else
				{
					temp = temp -> next;
				}
			if (found)
				{
					cout<<"\tChange Ticket Number: ";
						cin >> temp->invoice_number;
					cout<<"\tChange Customer Name: ";
						cin.ignore();
						getline(cin, temp->customerName);
					cout<<"\tChange Date : ";
						cin>>temp->date;
					cout<<"\tTicket Description (1000 Words Maximum): \n\t\t";
						cin.ignore();
						getline(cin, temp->x);	
					system("PAUSE");
					temp = temp->next;
					cout<<"\n\t======================================\n"
						<<  "\t*       Ticket Created Updated       *"
    					<<"\n\t======================================\n";
				}
			if(temp != NULL && temp->invoice_number != sid)
				{
					cout<<"\n\tInvalid Ticket Number!\n";
				}
			}
		}	
}

void invoice::print_WorkOrder()		
{
	int num;	
	bool found;			//variable to search 
	system("cls");
	ofstream outputFile;
	outputFile.open("Invoice.txt");
	node *temp;

	temp=start_ptr;
	found = false;
	
	cout<<"\n\t======================================\n"
		<<"\t|  Computer Repair Invoicing System  |\n"
		<<"\t======================================\n"
		<<"\tEnter Ticket Number To Print: ";
	cin>>num;
	cout<<"\n\t---------------------------------------\n"
		<<"\t*       Here Is The Ticket Info       *"
		<<"\n\t---------------------------------------\n";

	if(temp == NULL)
		{
			cout << "\tTicket Not Found\n";
		}
	while(temp !=NULL && !found)
		{
			if (temp->invoice_number==num)
			{
				found = true;
			}
			else
			{
				temp = temp -> next;
			}
	        if (found)	//print the ticket
	        	{
					cout <<"\tTicket Number : "<<temp->invoice_number << endl;
					outputFile <<"Ticket Number : "<<temp->invoice_number << endl;
					cout<<"\tCustomer Name: "<<temp->customerName << endl;
					outputFile << "Customer Name: "<<temp->customerName << endl;
					cout<<"\tOrder Date : "<<temp->date << endl;
					outputFile << "Order Date : "<<temp->date << endl;
					cout<<"\tTicket description: "<< endl;
					outputFile << "Ticket description: "<< endl;
					cout<<"\t\t" << temp->x << endl;
					outputFile << temp->x << endl; 	
					temp=temp->next;
				}
			outputFile.close();
			cout << "Ticket Printed Succesfully....!\n";
			cout<<"\n\t======================================\n"
				<<  "\t*     Ticket Printed Succesfully     *"
    			<<"\n\t======================================\n";
		}		
}	//End function

void invoice::exit() //Function to exit
{
	cout<<"\nGood Bye!\n"<<endl;
}	//end function exit

#endif
