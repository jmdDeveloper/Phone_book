/*
 * PersistenceManager.cpp
 *
 *  Created on: May 23, 2016
 *      Author: raydelto
 */

#include "PersistenceManager.h"
using namespace std;

PersistenceManager::PersistenceManager() {

}

void PersistenceManager::savePhone_book(string contact)
{
	fstream file;// a file of type fstream to work with files
	file.open("Phone_book.txt", fstream::in | fstream::out | fstream::app);//creating and open file
	file <<contact<<endl;//writting or appending conten to the file
	file.close();//closing file
	cout<<"\n \t Contact save in the computer at 'Phone_book.txt'"<<endl;
	
}

