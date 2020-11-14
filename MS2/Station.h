
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _SDDS_STATION_H_
#define _SDDS_STATION_H_
#include <iostream>
#include "Utilities.h"

//#include <stdio.h>
class Station {
	
private:
	unsigned int m_id;
	std::string m_itemName;
	std::string m_desc;
	unsigned int m_serial;
	unsigned int m_inStock;
	
	static unsigned int m_widthField;
	static unsigned int id_generator;
	
public:
	Station(std::string& str);
	void display(std::ostream& os, bool full) const;
	
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	
	
	};
#endif /* _SDDS_STATION_H_ */
