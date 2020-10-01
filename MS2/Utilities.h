// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: April 5th, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _SDDS_UTILITIES_H_
#define _SDDS_UTILITIES_H_

//#include <stdio.h>
	
	class Utilities {
		
	private:
		unsigned int m_widthField = 1; //default value is 1
		static char m_delimiter;
		
	public:
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};

#endif /* _SDDS_UTILITIES_H_ */
