/*
 * Menu.cpp
 *
 *  Created on: May 22, 2016
 *      Author: raydelto
 */

#include "Menu.h"
#include <iostream>
using namespace std;

List* myContactList = new List();

Menu::Menu()
{

}

void Menu::clearScreen()
{
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
}

void Menu::pause()
{
	#ifdef _WIN32
	system("pause");
	#else
	cout<<endl;
	system("read -n1 -r -p \"Press any key to continue...\" key");
	#endif
}


bool Menu::validate(int option)
{
	if(option >= 1 && option <= 5)
	{
		return true;
	}else
	{
		cout << "Please pick an option between 1 and 5"<< endl;
		pause();
		return false;
	}
}

void Menu::routeAction(int option)
{
	switch(option)
	{
	case 1:
		listContacts();
		break;
	case 2:
		addContacts();
		break;
	case 3:
		removeContacts();
		break;
	case 4:
		modifyContacts();
		break;

	case 5:
		cout << "Thanks for using our software, good bye!" << endl;
	}
	pause();
}

void Menu::listContacts()
{
	//TODO: Implement this
	//cout << "Implement  Menu::listContacts" << endl;
	Element* j = myContactList->getFirst();
	if(j)// if isn't empty or if isn't null
	{
		cout<<"      All contacts: "<<endl;
		for(int x=1; j ; x++, j = j->getNext())
		{
			cout<<endl<<x<<". "<<j->getName()<<endl;//showing all contacts
			cout<<"   "<<j->getNumber()<<endl;
		}
		cout<<endl;
	}else{ //if is null
		cout<<endl<<"         List of contact empty."<<endl<<endl;
	}
	
}

void Menu::addContacts()
{
	//TODO: Implement this
	//cout << "Implement  Menu::addContacts" << endl;
	string name = "";
	string number = "";
	cout<<endl;
	cout<<"       Please, entry the name of the contact: ";
	cin>>name;
	cout<<"       Please, entry the number of the contact: ";
	cin>>number;
	Element* newContact = new Element(name, number);// creating the new Contact
	myContactList->add(newContact);// adding the new contact to my list of contact
}

void Menu::removeContacts()
{
	//TODO: Implement this
	//cout << "Implement  Menu::removeContacts" << endl;
	listContacts();// show all contact
	if(myContactList->getFirst())
	{
		int index = 0;
		cout<<"     Please, entry the number of the contac to delete: ";
		cin>>index;
		myContactList->remove(index);// removin one contact
	}
	
}

void Menu::modifyContacts()
{
	//TODO: Implement this
	//cout << "Implement  Menu::modifyContacts" << endl;
	listContacts();//show all  contact
	if(myContactList->getFirst())//id there is a contact
	{
		int index = 0;
		int desicion = 0;
		string name = "";
		string number = "";
		
		cout<<"     Please, entry the number of the contac to modify: ";
		cin>>index;
		
		cout<<"      Please, entry the new name: ";
		cin>>name;
		cout<<"     Do you want modify the number too? \n \t 1. Yes\n \t 2. No \t"<<endl;
		cin>>desicion;
		switch(desicion)
		{
		  case 1:
		  	cout<<"      Please, entry the new number: ";
		  	cin>>number;
		   break;
		  case 2:
		 	
		   break;		  
		  default: cout<<"\t Opcion Invalid."<<endl;	
		}
		
		myContactList->modify(index,name,number);// modifying the contact
	}
}

void Menu::show()
{
	int option;
	do
	{
		clearScreen();
		cout << "ITLA Phonebook" << endl;
		cout << "1- List contacts" << endl;
		cout << "2- Add contacts" << endl;
		cout << "3- Remove contact" << endl;
		cout << "4- Modify contact" << endl;
		cout << "5- Exit" << endl;
		cout << "Select an option => ";
		cin >> option;
		if(validate(option))
		{
			routeAction(option);
		}
	}while(option !=5);
}
