
// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: January 30, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_SET_H_
#define SDDS_SET_H_

namespace sdds {
	template <class T, size_t N>
	
	class Set {
		T m_capacity[N]; //capacity of the array
		size_t m_noOfElements = 0; //number of elemnets added to the set //or size_t
		
	public:
		
		//return number of elements in the set
		size_t size() const {
		return m_noOfElements;	
		}
		
		//returns element at index i if parameter is valid
		const T& operator[](size_t idx) const {
				return m_capacity[idx];
		}
		
		//if est didnt reach capacity, add copy of the parameter to array
		void operator+=(const T& item) {
			if (N > m_noOfElements){
				m_capacity[m_noOfElements] = item;
				m_noOfElements++;
			}
		}
	};
}

#endif /* Set_h */
