// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: April 5th, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

//#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <iomanip>
#include <vector>
#include "CustomerOrder.h"

size_t CustomerOrder::m_widthField;


CustomerOrder::CustomerOrder(std::string src) {
	Utilities utilities;
	size_t position = 0;
	bool more = false;
	std::vector<Item*> v_item;
	
	m_name = utilities.extractToken(src, position, more);
	m_product = utilities.extractToken(src, position, more);
	
	while(more) {
		v_item.push_back(new Item(utilities.extractToken(src, position, more)));
	}
	
	m_cntItem = v_item.size();
	m_lstItem = new Item* [m_cntItem];
	
	for (size_t i = 0; i < m_cntItem; i++) {
		m_lstItem[i] = std::move(v_item[i]);
	}
	
	if (m_widthField < utilities.getFieldWidth()) {
		m_widthField = utilities.getFieldWidth();
	}

}





CustomerOrder::CustomerOrder(CustomerOrder&) {
	throw std::string("No copy allowed");
}
//CustomerOrder& operator=(const CustomerOrder&) = delete;

CustomerOrder::CustomerOrder( CustomerOrder &&cust) noexcept {
	*this = std::move(cust);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder &&cust) noexcept {
	
	if(this != &cust) {
		
		m_name = cust.m_name;
		m_product = cust.m_product;
		m_cntItem = cust.m_cntItem;
		//m_widthField = cust.m_widthField;
		
		m_lstItem = cust.m_lstItem;
		
		cust.m_lstItem = nullptr;
		cust.m_product = '\0';
		cust.m_cntItem = 0;
		cust.m_name = '\0';
		
	}
	return *this;
}

CustomerOrder::~CustomerOrder() {
	for (size_t i = 0; i < m_cntItem; i++) {
		delete m_lstItem[i];
		m_lstItem[i] = nullptr;
	}
	
	delete [] m_lstItem;
	m_lstItem = nullptr;
}

bool CustomerOrder::isOrderFilled() const {
	size_t size = 0;
	for (size_t i = 0; i < m_cntItem; i++) {
		if(m_lstItem[i]->m_isFilled) {
			size ++;
		}
	}
	
	if (size < m_cntItem) {
		return false;
	} else {
		return true;
	}
}
	
bool CustomerOrder::isItemFilled(const std::string& itemName) const { 
	bool more = false;
	for(size_t i = 0; i < m_cntItem; i++) {
		if(m_lstItem[i]->m_itemName == itemName && m_lstItem[i]->m_isFilled) {
				more = true;
		}
	}
	return more;
}
	

void CustomerOrder::fillItem(Station& station, std::ostream& os) {
	
	for(size_t i = 0; i < m_cntItem; i++) {
		if (station.getItemName() == m_lstItem[i]->m_itemName && station.getQuantity() > 0) {
			station.getQuantity();
			m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
			m_lstItem[i]->m_isFilled= true;
			
			os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
		}
		if (station.getItemName() == m_lstItem[i]->m_itemName && station.getQuantity() == 0) {
			os << "Unable to fill" << m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;
		}
	}
	
	
}

void CustomerOrder::display(std::ostream &os) const {
	os << m_name << " - " << m_product << std::endl;
	for (size_t i = 0; i < m_cntItem; i++) {
		os << "["
			<< std::setfill('0') << std::setw(6) << m_lstItem[i]->m_serialNumber
			<< "] "
			<< std::setw(m_widthField) << std::setfill(' ') << m_lstItem[i]->m_itemName
			<< " - ";
		
		if (m_lstItem[i]->m_isFilled) {
			os << "FILLED";
		} else {
			os << "MISSING";
		}

		os << std::endl;
	}
	
}
