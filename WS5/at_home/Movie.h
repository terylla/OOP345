// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: February 18th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef _SDDS_Movie_H_
#define _SDDS_Movie_H_

#include <string>
#include <iostream>
#include "SpellChecker.h"

namespace sdds {
	
	class Movie {
		
	private:
		std::string m_title;
		size_t m_releaseYear;
		std::string m_description;
	
	public:
		Movie();
		//~Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
		
		//Template function
		template <typename T>
		void fixSpelling(T spellChecker){
			spellChecker.operator()(m_title);
			spellChecker.operator()(m_description);
		}
	};
}

#endif /* _SDDS_Movie_H_*/
