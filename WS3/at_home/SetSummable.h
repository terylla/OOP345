// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: February 2nd, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_SetSummable_h
#define SDDS_SetSummable_h
#include "Set.h"
#include <iostream>

namespace sdds
{
	template < typename T, size_t N, typename K, typename V >

	class SetSummable : public Set <T, N>
	{
	public:
	
		// accumulates all values stored in the collection that have the key `key`
		//into a local object of type `V`
		V accumulate(const K& key) const {
			T temp;
			// get the initial value from type `T` and store it into a local variable of type `V`
			V m_accumulator = temp.getInitialValue();
			// iterate over the collection and call the function `sum()` for each item
			//use the overloaded `operator[]` to access the item at index `i`)
			for (size_t i = 0; i < ((Set<T, N> &)* this).size(); i++) {
				//store the result of `sum()` into the accumulator.
				m_accumulator = (*this)[i].sum(key, m_accumulator);
			}
			return m_accumulator; //return the accumulator to the client.
		}
	};
}

#endif /* SetSummable_h */

