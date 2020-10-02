//
// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: January 30, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H

#include <iostream>

using namespace std;

namespace sdds {
	template <typename K, typename V>
	
	class Pair {
		K m_keyType;
		V m_valueType;
		
	public:
		Pair(){
			//m_keyType = 0;
			//m_keyType = 0;
		}
		
		//copies values received into instance variables
		Pair(const K& key, const V& value){
			m_keyType = key;
			m_valueType = value;
		}
		
		//return key component of the pair
		const K& key() const {
			return m_keyType;
		}
		
		//return value component of the pair
		const V& value() const {
			return m_valueType;
		}
		
		
		void display(ostream& os) const{		
			cout << m_keyType << " : " << m_valueType << endl;
		}
		
	};

	
	//Free helper
	template <typename K, typename V>
	ostream& operator<<(ostream& os, const Pair <K, V> & pair) {
		pair.display(os);
		return os;
	}

}
#endif /* Pair_h */
