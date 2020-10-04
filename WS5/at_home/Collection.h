// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: February 18th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef _SDDS_Collection_h_
#define _SDDS_Collection_h_

#include <iostream>

namespace sdds {
	
	template <typename T>
	class Collection {
		
	private:
		std::string m_name;
		T* m_item;
		size_t m_arrSize;
		void (*itemAdded) (const Collection&, const T&) = nullptr;
		
	public:
		
		//sets the name of the collection to the parameter and all other attributes to their default value
		Collection(std::string name) {
			m_name = name;
			m_item = nullptr;
			m_arrSize = 0;
		}
		
		//this class doesn't support copy operations; delete them.
		Collection ( const Collection&) = delete;
		Collection& operator=( const Collection&) = delete;
		
		//Deallocation
		~Collection(){
			delete[] m_item;
		}
		
		// returns the name of the collection
		const std::string& name() const {
			return m_name;
		}
		
		//returns how many items are in the collection
		size_t size() const {
			return m_arrSize;
		}
		
		//The parameter is a pointer to a function that returns void and accepts two parameters // observer function in private
		void setObserver(void (*observer)(const Collection<T>&, const T&)){
			itemAdded = observer;
		}
		
		
		Collection<T>& operator+=(const T& item) {
			//If item is already in the collection, this function does nothing.
			for (size_t i = 0; i < m_arrSize; i++) {
				if (m_item[i].title() == item.title()) { //check if ANY item is in the collection
					return *this;
				}
			}
			
			//NOTE: You cannot resize array, you can only allocate new one (with a bigger size) and copy old array's contents
			//adds a copy of item to the collection
			//resize the array to accomodate the new item
			T* copy = new T[m_arrSize + 1];
			for (size_t i = 0; i < m_arrSize; i++){
				copy[i] = m_item[i];
			}
				copy[m_arrSize] = item; //add copy of new item to 'copy'
				delete [] m_item; // clear m_item before passing 'copy' over
				m_item = copy; //m_item is now new item
				m_arrSize ++; //add item
			
			//if there is an observer registered, call the observer function passing *this and the new item as parameters
			if (itemAdded != nullptr)
				itemAdded (*this, m_item[m_arrSize-1]);
			
			return *this;
		}
		
		
		T& operator[](size_t idx) const {
			//if idx is our of range
			if (idx >= m_arrSize) {
				std::string message;
				
				message = "Bad index [";
				message = message + std::to_string(idx); //operator + to concatenate strings
				message = message + "]. Collection has [";
				message = message + std::to_string(m_arrSize);
				message = message + "] items.";
				
				throw std::out_of_range(message);
				
			}
			//returns the item at index idx.
			return m_item[idx];
			
		}
		
		T* operator[] (std::string title) const {
			//because m_item is T* so we have to convert to string first to mathc m_title?
			for (size_t i = 0; i < m_arrSize; i++) {
				if (m_item[i].title() == title) {
					return &(m_item[i]); //return address of item with title
				}
			}
			return nullptr;
		}
	};
	
	template<typename T>
	//Iterate over all elements in the collection and insert each one into the ostream object (do not add newlines
	std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {
		for (size_t i = 0; i < collection.size(); i++) {
			os << collection[i];
		}
		return os;
	}

}

#endif /* _SDDS_Collection_h_ */
