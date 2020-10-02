// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: Jan 23, 2020
// WORKSHOP 2 AT_HOME
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

//#include <stdio.h>
#include "RecordSet.h"
#include <fstream>
#include <iostream>

namespace sdds {
	
	//Default constructor
	RecordSet::RecordSet(){};
	
	//1-argument default constructor
	RecordSet::RecordSet(const std::string& filename){	
	    std::string c;
         size_t i = 0;
    	    std::ifstream file;
	    file.open(filename);

        if (file.is_open()) {	
 			while (getline(file, c, ' ')){
			i++;
			}
            S = new std::string[i];
            m_numOfRecord = i;
            file.close();
		}

           file.open(filename);
		if (file.is_open()) {
            int i = 0;
            while (getline(file, S[i], ' ')) {
                i++;
            }
		}
		
      }     
    
	
	//Copy Constructor
	RecordSet::RecordSet(const RecordSet& obj) {
		if (obj.S != nullptr) {
	m_numOfRecord = obj.m_numOfRecord;
			S = new std::string[obj.m_numOfRecord];
			for (size_t i = 0; i < m_numOfRecord; i++){
				S[i] = obj.S[i];
			}	
		} else {
			S = nullptr;
			m_numOfRecord = 0;
		}
	}

	//Assignment Constructor
	RecordSet& RecordSet::operator=(const RecordSet& obj){
		if (this != &obj){
			delete[] S;
		m_numOfRecord = obj.m_numOfRecord;
			S = new std::string[obj.m_numOfRecord];
			for (size_t i = 0; i < m_numOfRecord; i++){
				S[i] = obj.S[i];
			}
		}
		return *this;
	}
	
	//Deallocate
	RecordSet::~RecordSet(){
		delete[] S;
		S = nullptr;
	}
	
	//return number of records stored in current object
	size_t RecordSet::size() const {
		return m_numOfRecord;
	}
	
	//If the index is invalid, this function should return the empty string.
	std::string RecordSet::getRecord(size_t index){
		if (index >= 0 && index < m_numOfRecord){
			return S[index];
		} else return "";
	}
	

	//Move Constructor
	RecordSet::RecordSet(RecordSet&& mv){
		S = mv.S;
		m_numOfRecord = mv.m_numOfRecord;

		mv.S = nullptr;
		mv.m_numOfRecord = 0;
		}
	
	//Move-assignment constructor
	RecordSet& RecordSet::operator=(RecordSet&& mv){
		if (this != &mv) {
			delete[] S;
			S = mv.S;
			m_numOfRecord = mv.m_numOfRecord;	

			mv.S = nullptr;
			mv.m_numOfRecord = 0;
		}
 		return *this;
	}
}