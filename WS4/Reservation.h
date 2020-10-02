// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: February 6th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#ifndef _SDDS_RESERVATION_H_
#define _SDDS_RESERVATION_H_

#include <iostream>

using namespace std;

namespace sdds
{
	class Reservation
	{
	private:
		string m_reservationID;
		string m_reservationName;
		string m_email;
		unsigned int m_numOfppl;
		unsigned int m_day;
		unsigned int m_hour;

	public:
		Reservation(); 
		Reservation(const string& res);
		void trim(string& str);
		//Friend helper
		friend ostream& operator<<(ostream& os, const Reservation& copy);
	};

	

}


#endif // !SDDS_RESERVATION_H_
