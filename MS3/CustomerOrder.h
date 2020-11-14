
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _SDDS_CustomerOrder_H_
#define _SDDS_CustomerOrder_H_
#include "Station.h"
#include "Utilities.h"

#include <iostream>



struct Item
{
	std::string m_itemName = "";
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;
	
	Item(const std::string& src) : m_itemName(src) {};
};


class CustomerOrder {
	
private:
	std::string m_name; //the name of the customer (e.g., John, Sara, etc)
	std::string m_product; //–\ the name of the product being assembled (e.g., Desktop, Laptop, etc)
	unsigned int m_cntItem;//a count of the number of items for the customer's order
	Item** m_lstItem; // a dynamically allocated array of pointers. Each element of the array is a dynamically allocated object of type `Item` (see below). **This is the resource** that your class must manage.
	static size_t m_widthField; // the maximum width of a field, used for display purposes
	
public:
	CustomerOrder(); // default
	CustomerOrder(std::string src); //custom constructor
	CustomerOrder( const CustomerOrder&);
	CustomerOrder& operator=( const CustomerOrder&) = delete;
	CustomerOrder( CustomerOrder&& cust) noexcept;
	CustomerOrder& operator=( CustomerOrder&& cust) noexcept;
	~CustomerOrder();
	
	bool isOrderFilled() const;
	bool isItemFilled(const std::string& itemName) const;
	void fillItem(Station& station, std::ostream& os);
	void display(std::ostream& os) const;
	
};

#endif /* _SDDS_CustomerOrder_H_ */
