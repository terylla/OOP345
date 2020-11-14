
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS_
#include "Station.h"
#include "Utilities.h"
#include <iostream>
#include <iomanip>

unsigned int Station::m_widthField;
unsigned int Station::id_generator;

	Station::Station(std::string& str) {
	 
		//Utilities` object (created local in the function) to extract each token from th record and populates the `Station` object accordingly.
		 Utilities m_utilities;
		 bool more;
		 size_t nextPOS = 0;
		 
		
		if (nextPOS != std::string::npos) {
			 //extract *name* from the record,
			m_itemName= m_utilities.extractToken(str, nextPOS, more);
			nextPOS = str.find(m_utilities.getDelimiter(), nextPOS + 1) + 1;
			
			//extract *starting serial number* from record
			std::string serial = m_utilities.extractToken(str, nextPOS, more);
			m_serial = stoi(serial);
			nextPOS = str.find(m_utilities.getDelimiter(), nextPOS + 1) + 1;
			 
			//extract *quantity* from the record,
			std::string quantity = m_utilities.extractToken(str, nextPOS, more);
			m_inStock = stoi(quantity);
			nextPOS = str.find(m_utilities.getDelimiter(), nextPOS + 1) + 1;
		}
		
		
		 //once the constructor has extracted nane, serial, and quantity...
		 //...it updates `Station::m_widthField` to the maximum value of `Station::m_widthField` and `Utilities::m_widthField`.
		 if (m_widthField != m_utilities.getFieldWidth()) {
			 Station::m_widthField = m_utilities.getFieldWidth();
		 }
	 
		 //extract from record
		if (nextPOS != std::string::npos) {
		 m_desc = m_utilities.extractToken(str, nextPOS, more);
		 nextPOS = str.find(m_utilities.getDelimiter(), nextPOS + 1) + 1;
		}
		
		 m_id = ++id_generator;
		
	}


	//returns the name of the current `Station` object
	const std::string& Station::getItemName() const {
		return m_itemName;
	}
	//returns the next serial number to be used on the assembly line and increments `m_serialNumber`
	unsigned int Station::getNextSerialNumber() {
		return m_serial++;
	}
	//returns the remaining quantity of the current `Station` object
	unsigned int Station::getQuantity() const {
		return m_inStock;
	}
	//subtracts 1 from the available quantity; should not go below 0.
	void Station::updateQuantity() {
		if (m_inStock > 0) { // 'while' doesn't work
			m_inStock--;
		} ;
	}

	// inserts the content of the current object into first parameter.
	void Station::display(std::ostream& os, bool full) const {

		if (full == false) {
			os  << "[" << std::setw(3) << std::setfill('0') << std::right << m_id << "]" << std::setfill (' ')
				<< " Item: " << std::setw(m_widthField) << std::left << m_itemName << std::setfill(' ')
				<< "[" << std::setw(6) << std::setfill('0') << std::right << m_serial << "]" << std::setfill(' ')
				<< std::endl;
		} else {
			os  << "[" << std::setw(3) << std::setfill('0') << std::right << m_id << "]" << std::setfill (' ')
				<< " Item: " << std::setw(m_widthField)  << std::left << m_itemName << std::setfill(' ')
				<< "[" << std::setw(6) << std::setfill('0') << std::right << m_serial << "]" << std::setfill(' ')
				
				<< " Quantity: " << std::setw(m_widthField) << std::left << m_inStock << std::setfill(' ')
				<< "Description: " << m_desc
				<< std::endl;
		}
}
