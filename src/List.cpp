/*
 * List.cpp
 *
 *  Created on: May 22, 2016
 *      Author: raydelto
 */

#include "List.h"
#include <iostream>
#include <cstdlib>
#include "PersistenceManager.h"
using namespace std;
PersistenceManager* mySecurityContact = new PersistenceManager();

List::List(): _first(NULL), _last(NULL)
{


}

void List::add(Element* element)
{
	//TODO: Implement this method
	//cout << "You should write the code for adding " << element -> _name << endl;
    if(!_first)// if isn't set the first
	{
    	_first = element;
    	_last = element;
    	
    	//saving contact at the file Phone_book.txt 
    	string contactData = _first->getName()+" "+_first->_number;
    	mySecurityContact->savePhone_book(contactData);
    	
    	cout<<endl<<"         First contact '"<<contactData<<": "<<_first->_name<<"' added sucessfull...!!!"<<endl<<endl;
    }else{ // if there are contacts
    	
    	_last -> _next = element;
    	_last = element;
    	
    	//saving contact at the file Phone_book.txt 
    	string contactData = element->getName()+" "+element->_number;
    	mySecurityContact->savePhone_book(contactData);
    	
    	cout<<endl<<"          Contact '"<<contactData<<": "<<_last->_name<<"' added sucessfull...!!!"<<endl<<endl;
    }
}

void List::remove(int index)
{
	//TODO: Implement this method
//	cout << "You should write the code for removing the index " << index << endl; 
		 if(index==1)// is if the first
		 {
		 	cout<<endl<<"        Contact '"<<_first->_name<<"' erased successfull...!!!"<<endl<<endl;
		 	_first = _first->_next;
		 	return ;
		 }
	 
	  Element* candidate = _first;
      Element* bCandidate = _first;//bCandidate mean BeforeCandidate
      
     for(int i=1; candidate && i<=index; i++, bCandidate = candidate, candidate = candidate->_next)
	 {	 		 	
	 	if(i==index)//if is the contact looked
		 {		 	
		 	cout<<endl<<"     Contact '"<<candidate->_name<<"' erased successfull...!!!"<<endl<<endl;
		 	bCandidate->_next = candidate->_next;
		 	return ;
	 	 }
     }
	 cout<<endl<<"         Contact not found."<<endl<<endl;
	
}

void List::modify(int index, std::string name, std::string number)
{
	//TODO: Implement this method
	//cout << "You should write the code for modifying the content for index " << index << endl;
    int y=1;
	for(Element* contact = _first; y<=index && contact; y++, contact = contact->getNext())
	{
		if(y==index)//if is the contact looked
		{
			contact->_name = name;
			
			if(number!=""){
				contact->_number = number;
	 	
			}
			cout<<"  Contact modified successfull...!!! \n"<<endl;
			
			//saving contact at the file Phone_book.txt 
            string contactData = contact->_name+" "+contact->_number;
		    mySecurityContact->savePhone_book(contactData);
			return ;
		}
    }	
    cout<<endl<<"         Contact not found."<<endl<<endl;
}
