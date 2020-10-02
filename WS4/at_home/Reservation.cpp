// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: February 9th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <string>
#include "Reservation.h"
#include <iomanip>
#include <algorithm>


namespace sdds {

	Reservation::Reservation() {
		m_reservationID = {};
		m_reservationName = {};
		m_email = {};
		m_numOfppl = 0;
		m_day = 0;
		m_hour = 0;
	}

	void Reservation::trim(std::string& str) {
		str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
	}

	Reservation::Reservation(const string& res) {
		string temp;
		temp = res;
		trim(temp);
		size_t position;

		position = temp.find(":");
		m_reservationID = temp.substr(0, position);
		trim(m_reservationID);
		temp.erase(0, position + 1);

		position = temp.find(",");
		m_reservationName = temp.substr(0, position);
		trim(m_reservationName);
		temp.erase(0, position + 1);

		position = temp.find(",");
		m_email = temp.substr(0, position);
		trim(m_email);
		temp.erase(0, position + 1);

		position = temp.find(",");
		m_numOfppl = std::stoi(temp.substr(0, position));
		temp.erase(0, position + 1);

		position = temp.find(",");
		m_day = std::stoi(temp.substr(0, position));
		temp.erase(0, position + 1);

		position = temp.find(",");
		m_hour = std::stoi(temp.substr(0, position));
		temp.erase(0, position + 1);
	}
	
	std::ostream& operator<<(std::ostream& os, const Reservation& cp) {
		std::cout << "Reservation " << cp.m_reservationID << ": "
			<< std::setw(10) << std::right
			<< cp.m_reservationName << "  "
			<< std::setw(24) << std::left
			<< "<" + cp.m_email + ">";

		if (6 <= cp.m_hour && cp.m_hour <= 9) {
			std::cout << "Breakfast";
		}
		else if (11 <= cp.m_hour && cp.m_hour <= 15) {
			std::cout << "Lunch";
		}
		else if (17 <= cp.m_hour && cp.m_hour <= 21) {
			std::cout << "Dinner";
		}
		else {
			std::cout << "Drinks";
		}
		std::cout << " on day " << cp.m_day << " @ " << cp.m_hour << ":00"
			<< " for " << cp.m_numOfppl << " people." << std::endl;

		return os;
	}
	
}
