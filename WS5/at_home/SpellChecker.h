// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: February 18th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor

#ifndef _SDDS_SpellChecker_H_
#define _SDDS_SpellChecker_H_

#include <iostream>

namespace sdds {
	
	class SpellChecker {
		private:
		std::string m_badWords[5];
		std::string m_goodWords[5];
		public:
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;
	};
}
#endif /*  _SDDS_SpellChecker_H_ */
