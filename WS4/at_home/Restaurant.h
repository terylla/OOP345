// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: February 9th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H


#include "Reservation.h"
#include <iostream>

namespace sdds {

    class Restaurant {

        Reservation** m_res = nullptr;
        size_t m_num = 0;


    public:
		//NOT IN INSTRUCTION
        Restaurant();
		 ~Restaurant();
        Restaurant(const Restaurant& restaurant);
        Restaurant(Restaurant&&);
        Restaurant& operator = (const Restaurant&);
        Restaurant& operator = (Restaurant&&);
       
		//INSTRUCTION
		Restaurant(Reservation* reservation[], size_t cnt);
        size_t size() const;
        friend std::ostream& operator << (std::ostream& os, const Restaurant& restaurant);

    };
}

#endif // SDDS_RESTAURANT_H
