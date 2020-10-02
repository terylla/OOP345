// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: February 2nd, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_PairSummable_H_
#define SDDS_PairSummable_H_
#include <iostream>
#include <string>
#include "Pair.h"

using namespace std;
namespace sdds
{
	template <typename K, typename V>
	class PairSummable : public Pair<K, V>
	{
		//K m_keyType;
		//V m_valueType; these are from Pair
		static V m_initialValue; //depends on key-value pair
		static size_t m_width;

	public:
	
		// return initial value stored
		static const V& getInitialValue() {
			return m_initialValue;
		}

		//no need to initialize
		PairSummable() {}

		//stores the pair in the collection, and updates the field width if necessary
		PairSummable(const K& key, const V& value) : Pair <K, V>(key, value) {
			if (m_width < key.size()) { //assumes K supports function size()
				m_width = key.size();
			}
		}

		//
		V sum(const K& key, const V& val) const {
			//If the key of the pair stored in the cur.inst. is `key`...
			if (key == Pair<K, V>::key()) {
			//...add the value of the pair and `val` together and return the result.
				return Pair<K, V>::value() + val;
			}
			return val;
		}

		//overload the `display()` function
		virtual void display(std::ostream& os) const {
			os.setf(ios::left);
			os.width(m_width);
			Pair<K, V> ::display(os);
			os.unsetf(ios::left);
		}
	};

	//Initialize m_width to 0
	template <class K, class V>
	size_t PairSummable<K, V>::m_width = 0;

	// SPECIALIZATION
	template<>
	string PairSummable<string, string> ::m_initialValue = "";
	template<>
	int PairSummable<string, int> ::m_initialValue = 0;

	template<>
	string PairSummable<string, string>::sum(const string& key, const string& val) const {
		if (key == this->key()) {
			if (val == "") {
				return val + Pair<string, string>::value();
			}
			else {
				 return (val + ", " + Pair<string, string>::value());
			}
		}
		return val;
	}
}


#endif /* PairSummable_h */

