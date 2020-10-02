// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: Jan 23, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RecordSet_h
#define SDDS_RecordSet_h

#include <string>

namespace sdds {
	
	class RecordSet {
		
		size_t  m_numOfRecord = 0; 
		std::string *S = nullptr;

	public:
	RecordSet();
	~RecordSet();
	RecordSet(const std::string& );
	RecordSet(const RecordSet&);
	RecordSet& operator=(const RecordSet&);
	size_t size() const;
	std::string getRecord(size_t);
	};
	
}

#endif /* RecordSet_h */
