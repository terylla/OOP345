// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: April 5th, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

//#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <string>
#include "Utilities.h"


char Utilities::m_delimiter;

	//sets the field width of the current object to the value of the parameter
	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}
	//returns the field width of the current object
	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}


	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		
		//uses delimiter to extract the next token from `str` starting at `next_pos`
		//std::string token = str.substr(next_pos, str.find(m_delimiter, next_pos));
		
		std::string token = str.substr(next_pos);
		size_t position = token.find(m_delimiter);
		
		if (position == std::string::npos) {
			
			if(token[token.length() - 1] == '\r'){
				token = token.substr(0, token.length() - 1);
			}
			
			more = false;
			//std::string err = "ERROR: Two delimiters with no token between them";
			//throw err;
			
		} else {
			
			token = token.substr(0, position);
			
			//updates the current object's `m_widthField` data member...
			//...if its current value is less than the size of the token extracted
			if ( getFieldWidth() < token.length() ) {
				setFieldWidth(token.length());
			}
			
			next_pos += position +1;
			more = true;
		}
		
		return token;
	}


	//sets the delimiter for this class to the character received
	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}

	//returns the delimiter character.
	char Utilities::getDelimiter() {
		return m_delimiter;
	}
