
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "LineManager.h"


	LineManager::LineManager(const std::string& str, std::vector<Workstation*>& wk, std::vector<CustomerOrder>& cust) {

		std::fstream file(str);
	
			do {
				
				Utilities utilities;
				size_t position = 0;
				bool con = true;
				utilities.setDelimiter('|');

				std::string stri = "";
				getline(file, stri);
				
				std::string station = "";
				station = utilities.extractToken(stri, position, con);
				
				std::string next = "";
				if (con) {
					next =utilities.extractToken(stri, position, con);
				}
				
				for (unsigned int i = 0; i < wk.size(); i++) {
					if (station == wk[i]->getItemName()) {
						for (unsigned int o = 0; o < wk.size(); o++) {
							if (wk[o]->getItemName() == next){
								wk[i]->setNextStation(*wk[o]);
							}
						}
					}
				}
				
				
			} while (!file.eof());
		
		
		
			//Move all the `CustomerOrder` objects onto the back of the `ToBeFilled` queue
		for (unsigned int i = 0; i < cust.size(); i++){
			ToBeFilled.push_back(std::move(cust[i]));
		}
		
		//Copy all the `Workstation` objects into the `AssemblyLine` container
			AssemblyLine = wk;
			m_cntCustomerOrder = cust.size();

	}

	//custome sort functio
	std::deque<Workstation*> LineManager::sort(const std::vector<Workstation*>& wk) const {

		Workstation* ws = nullptr;
		std::deque<Workstation*>station;
		
		do {
			for (auto i : wk) { //try auto here
				if (i->getNextStation() == ws) {
					station.push_front(i);
					ws = i;
				}
			}
		} while (station.size() != wk.size());
		
		return station;
	}



	// performs **one** cycle of operations on the assembly line by doing the following:
	bool LineManager::run(std::ostream& os) {
		
		//how many times this function has been called by the client; use only local variables to count
		static unsigned int count = 1; //make sure to put 'static'
		os << "Line Manager Iteration: " << count << std::endl;
		count++;
		
	
		std::deque<Workstation*>station = sort(AssemblyLine);
		//Workstation* first = nullptr;
		if (!ToBeFilled.empty()) {
			*station.front() += std::move(ToBeFilled.front()); //move the one at the front of the queue onto the starting point of the `AssemblyLine`
			ToBeFilled.pop_front();
			}
		

		//Loop through all stations on the assembly line and run one cycle of the station's process
		for(unsigned int i = 0; i < AssemblyLine.size(); i++){
			AssemblyLine[i]->runProcess(os);
			//AssemblyLine[i]->moveOrder();
		}
		
		//Loop through all stations on the assembly line and move the `CustomerOrder` objects down the line.
		for(unsigned int i = 0; i < AssemblyLine.size(); i++) {
			AssemblyLine[i]->moveOrder();
		}
		
		CustomerOrder cust;
		//completed orders should be moved into the `Completed` queue.
		for(unsigned int i = 0; i < AssemblyLine.size(); i++) {
			if (AssemblyLine[i] -> getIfCompleted(cust)) {
				Completed.push_back(std::move(cust));
			}
		}
	
		return (Completed.size() == m_cntCustomerOrder);
		
	}

	//displays all the orders that were completed
	void LineManager::displayCompletedOrders(std::ostream& os) const {
		for(unsigned int i = 0; i < Completed.size(); i++){
			Completed[i].display(os);
		}
	}

	//display all stations on the assembly line in the order they were received from the client
	void LineManager::displayStations() const {
		for(unsigned int i = 0; i < AssemblyLine.size(); i++){
			AssemblyLine[i]->display(std::cout);
		}
	}



	//display all stations on the assembly line in the order they are linked.
	void LineManager::displayStationsSorted() const {
		std::deque<Workstation*>station = sort(AssemblyLine);
		for(unsigned int i = 0; i < AssemblyLine.size(); i++){
			station[i]->display(std::cout);
		}
	}
		
