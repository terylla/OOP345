
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include "Workstation.h"


	//This string contains a single record (one line) that has been retrieved from the input file specified by the user to be used for `Station` instantiation.
	Workstation::Workstation(const std::string& str) : Station(str) {
		m_pNextStation = nullptr; //set the `m_pNextStation` to a safe state.
	}


	// runs a single cycle of the assembly line for the current station.
	void Workstation::runProcess(std::ostream& os) {
		// If there are `CustomerOrders` in the queue
		if (!m_orders.empty()) {
			//this function fills the order in the front at the current `Workstation`
			if (!m_orders.front().isOrderFilled())
				m_orders.front().fillItem(*this, os);
		}
	}

	bool Workstation::moveOrder() {
		bool move = true;
		if (!m_orders.empty()) {
			// if the order at the front of the queue doesn't require service at the current station
			if (m_pNextStation != nullptr && m_orders.front().isItemFilled(getItemName())) {
					//move it to the next station on the assembly lines
					*m_pNextStation += std::move(m_orders.front());
					m_orders.pop_front(); // remove the first order
					return move; //and return `true`
			} else {
				move = false;
			}
		}
			return move = false;
	}

	//stores the provided `Station` object's reference into the `m_pNextStation` pointer.
	void Workstation::setNextStation(Workstation& station) {
		m_pNextStation = &station;
	}

	//return the next station on the assembly line
	const Workstation* Workstation::getNextStation() const {
		return m_pNextStation;
	}


	bool Workstation::getIfCompleted(CustomerOrder& cust) {
		bool complete = true;
		if (!m_orders.empty()) {
			// if the order at the front of the queue is completed
			if (m_orders.front().isOrderFilled()) {
				cust = std::move(m_orders.front());
				m_orders.pop_front();
				return complete;
			} else {
				complete = false;
			}
		}
		return complete = false;
	}

	//display
	void Workstation::display(std::ostream& os) {
		if (m_pNextStation != nullptr) {
			os << getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
		} else {
			os << getItemName() << " --> " << "END OF LINE" << std::endl;
		}
	}

	//moves the parameter onto the back of the `CustomerOrder` queue.
	Workstation& Workstation::operator+=(CustomerOrder&& cust) {
		m_orders.push_back(std::move(cust));
		return *this;
	}


