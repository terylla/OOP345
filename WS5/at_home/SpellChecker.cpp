// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: February 18th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor
//
#define _CRT_SECURE_NO_WARNINGS_
#include "SpellChecker.h"
#include <iostream>
#include <fstream>

namespace sdds {
	
	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename); //load content of file that has mispelled words
		if (!file.is_open()) { //if file is missing
			throw "Bad file name!";
		}
		
		// Looking for a size of an array in a for loop
		// NOTE: sizeof( myArray ) will get the total number of bytes allocated for that array.
		// Find the number of elements in the array by dividing by the size of one element in the array: sizeof( myArray[0] )
		// for i less than mumber of element in m_badWords
		for (size_t i = 0; i < sizeof(m_badWords) / sizeof(m_badWords[0]); i++) {
			//Each line from the file is in the format BAD_WROD GOOD_WORD so load both
			//the two fields can be separated by any number of spaces.
			file >> m_badWords[i]; // load content of file
			file >> m_goodWords[i]; // load content of file
		}
	}
	
	// FUNCTOR
	void SpellChecker::operator()(std::string& text) const {
		size_t word = 0;
		
		//if size of array is less than i = 0, i++
		for (size_t i = 0; i < sizeof(m_badWords)/ sizeof(m_badWords[0]); i++) {
			word = text.find(m_badWords[i]); // word = any bad word
			if (word != std::string::npos) { // if parameter 'text' contains m_badWords at least once in the whole 
				do {
					text.replace(word, m_badWords[i].size(), m_goodWords[i]); //replace it
					word = text.find(m_badWords[i]); //then keep looking
				} while (word != std::string::npos);
		}
		}
	}
}
