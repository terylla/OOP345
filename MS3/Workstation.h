
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _SDDS_WORKSTATION_H_
#define _SDDS_WORKSTATION_H_
#include "Station.h"
#include "CustomerOrder.h"
#include <deque>
#include <iostream>

class Workstation : public Station {
	
	private:
	
    std::deque<CustomerOrder> m_orders;
    Workstation* m_pNextStation;
    
    public:
	
        Workstation(const std::string&);
	
		//A `Workstation` object represents a single location on the assembly line for filling items into customer orders.
		//Therefore, a `Workstation` object cannot be copied or moved.
        Workstation(const  Workstation&) = delete;
		Workstation& operator =(const Workstation&) = delete;
        Workstation(const  Workstation&&) = delete;
		Workstation& operator =(const  Workstation&&) = delete;
		//....
	
	
		void runProcess(std::ostream&);
		bool moveOrder();
		void setNextStation(Workstation& station);
		const Workstation* getNextStation() const;
		bool getIfCompleted(CustomerOrder& order);
		void display(std::ostream&);
		Workstation& operator+=(CustomerOrder&&);

};

#endif // _SDDS_WORKSTATION_H_
