// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: February 18th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor


#define _CRT_SECURE_NO_WARNINGS_
#include <algorithm>
#include <iomanip>
#include <iostream>
#include "Book.h"
//#include "SpellChecker.h"

namespace sdds {

    Book::Book() {
        m_year = 0;
        m_price = 0;
    }

	//returns the title of the book
    const std::string &Book::title() const {
        return m_title;
    }
	//eturns the publication country
    const std::string &Book::country() const {
        return m_country;
    }
	
	//returns the publication year
	const size_t &Book::year() const {
        return m_year;
    }
	
	//returns the price by reference, allowing you to update the price
    double &Book::price() {
        return m_price;
    }
	
	const std::string &Book::description() const {
		return m_desc;
	}

	//spacingggg
	void trim(std::string& str) {
		size_t i = 0;
		for (i = 0; i < str.length() && str[i] == ' '; i++);
		str = str.substr(i);
		
		for (i = str.length(); i > 0 && str[i - 1] == ' '; i--);
		str = str.substr(0, i);
	}

	
	//Same thing as ws4
    Book::Book(const std::string &book) {

		std::string temp;
		temp = book;
		trim(temp);
		size_t position;
		
		position = temp.find(',');
		m_author = temp.substr(0, position);
		trim(m_author);
		temp.erase(0, position + 1);
		
		position = temp.find(',');
		m_title = temp.substr(0, position);
		trim(m_title);
		temp.erase(0, position + 1);
		
		position = temp.find(',');
		m_country = temp.substr(0, position);
		trim(m_country);
		temp.erase(0, position + 1);
		
		position = temp.find(',');
		m_price = std::stod(temp.substr(0, position)); //make sure to  change to stod, otherwise 9.00 instead of 9.99
		temp.erase(0, position + 1);
		
		position = temp.find(',');
		m_year = std::stoi(temp.substr(0, position));
		temp.erase(0, position + 1);
		
		//We are not trying to get rid of commas in description, only spacing
		//position = temp.find(',');
		m_desc = temp.substr(0);
		trim(m_desc);
		//temp.erase(0, position + 1);
	}
	
	
	//overload to insert the content of a book object into an ostream object
    std::ostream &operator<<(std::ostream &os, const Book &book) {
		os << std::setw(20) << book.m_author << " | ";
		os << std::setw(22) << book.m_title << " | ";
		os << std::setw(5) << book.m_country << " | ";
		os << std::setw(4) << book.m_year << " | ";
		os << std::setw(6) << std::fixed << std::setprecision(2) << book.m_price << " | ";
		os << book.m_desc << std::endl;
		
        return os;
    }


}
