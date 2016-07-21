/*
 * PersistenceManager.h
 *
 *  Created on: May 23, 2016
 *      Author: raydelto
 */

#ifndef PERSISTENCEMANAGER_H_
#define PERSISTENCEMANAGER_H_
#include <iostream>
#include <fstream>
#include <string>

//TODO: Implement a persistence handler that allows data to remain permanently in the computer

class PersistenceManager
{
	public:
		PersistenceManager();
		void savePhone_book(std::string contact);
   private:
	
};  
	 

#endif /* PERSISTENCEMANAGER_H_ */
