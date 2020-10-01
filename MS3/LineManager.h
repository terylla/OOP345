// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: April 12th, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _SDDS_LINEMANAGER_H_
#define _SDDS_LINEMANAGER_H_
#include <iostream>
#include <deque> 
#include <vector>
#include "Workstation.h"


	class LineManager {
		
	private:
		
		std::vector<Workstation*> AssemblyLine;
		std::deque<CustomerOrder> ToBeFilled;
		std::deque<CustomerOrder> Completed;
		unsigned int m_cntCustomerOrder = 0;
		
		//Workstation* firstStation = nullptr;
		//Workstation* lastStation = nullptr;
			
	public:
		
		LineManager(const std::string&, std::vector<Workstation*>&, std::vector<CustomerOrder>&);
		std::deque<Workstation*> sort(const std::vector<Workstation*>&) const;
		bool run(std::ostream& os);
		void displayCompletedOrders(std::ostream& os) const;
		void displayStations() const;
		void displayStationsSorted() const;
	};

#endif // _SDDS_LINEMANAGER_H_
