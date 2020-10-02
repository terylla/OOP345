// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: February 9th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS_
#include "Restaurant.h"
#include <iostream>
#include <cstring>

namespace sdds {

    Restaurant::Restaurant()  {
        m_res = nullptr;
        m_num  = 0;
    }

    Restaurant::Restaurant(Reservation *reservations[], size_t cnt) {
        if (reservations != nullptr && cnt > 0) { // if parameter not empty then allocate
            m_res = new Reservation*[cnt];
            for (size_t i = 0; i < cnt; i++) {
                m_res[m_num] = new Reservation(*reservations[i]);  //each element of array is a pointer
                m_num++;
            }
        } else {
            *this = Restaurant();
        }
    }
	
	// Copy constructor
    Restaurant::Restaurant(const Restaurant &cp) {
        *this = cp;
    }
	// Copy assignment
	Restaurant& Restaurant::operator= (const Restaurant& cp) {
		if (this != &cp) {
			delete [] m_res;
			m_num  = cp.m_num ;
			m_res = new Reservation*[m_num];
			
			for (size_t i = 0; i < m_num; i++) {
				m_res[i] = new Reservation;
				*(m_res[i]) = *(cp.m_res[i]);
			}
		}
		return *this;
	}

	
	// Move constructor
    Restaurant::Restaurant(Restaurant&& mv) {
        *this = std::move(mv);
    }

	//Move assignment
    Restaurant& Restaurant::operator= (Restaurant&& mv) {
        if (this != &mv) {
            delete [] m_res;
            m_num  = mv.m_num ;
            m_res = mv.m_res;
            mv.m_num  = 0;
            mv.m_res = nullptr;
        }
        return *this;
    }

	// return number of reservation in system
    size_t Restaurant::size() const {
        return m_num ;
    }

	//overload insertion operator
   std::ostream& operator << (std::ostream& os, const Restaurant& res) {
        if (res.size() == 0) {
            os << "--------------------------" << std::endl;
            os << "Fancy Restaurant" << std::endl;
            os << "--------------------------" << std::endl;
            os << "The object is empty!" << std::endl;
            os << "--------------------------" << std::endl;

        } else {
            os << "--------------------------" << std::endl;
            os << "Fancy Restaurant" << std::endl;
            os << "--------------------------" << std::endl;

            for (size_t i = 0; i < res.m_num ; i++) {
                os << *res.m_res[i];
            }
			
			os << "--------------------------" << std::endl;

        }
       return os;
    }

	
	//Do a full deallocation like this to avoid memory leak
    Restaurant::~Restaurant() {
		for (size_t i = 0; i < m_num ; i++){
           delete m_res[i];
		}
		  delete [] m_res; //you can do just this but memory leak
	}



}

