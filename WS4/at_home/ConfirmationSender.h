// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: February 9th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"
#include <iostream>

namespace sdds {
    class ConfirmationSender {

        const Reservation** m_res = nullptr;
        size_t m_size = 0;

    public:

		//NOT IN INSTRUCTION
        ConfirmationSender();
		~ConfirmationSender();
        ConfirmationSender(const ConfirmationSender& res);
        ConfirmationSender(ConfirmationSender&& res);
        ConfirmationSender& operator = (const ConfirmationSender& res);
        ConfirmationSender& operator = (ConfirmationSender&&);
		
		// INSTRUCTION
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
        friend std::ostream& operator << (std::ostream& os, const ConfirmationSender& confirm);

    };
}

#endif //SDDS_CONFIRMATIONSENDER_H
