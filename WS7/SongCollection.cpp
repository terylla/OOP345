// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: March 12, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include "SongCollection.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <list>
#include <iomanip>
#include <iostream>

namespace sdds {

	//trim for display() function
	std::string& SongCollection::trim(std::string &str) {
		while(str.length() > 0 && str[0] == ' ') {
			str.erase(0, 1);
		}
		while (str.length() > 0 && str[str.length() - 1] == ' ') {
			str.erase(str.length() - 1, 1);
		}
		return str;
	}

	//custome constructor
	//receives as a parameter the name of the file containing the information about the songs to be added to the collection
	SongCollection::SongCollection(std::string filename) {
		std::fstream file(filename);
		if (!file){
			throw "Cannot read file";
		}
		
		while(file) {
			
			std::string copy;
			std::getline(file, copy);
			Song song;
			
			if (file) {
				trim(song.m_title = copy.substr(0, 25));
				trim(song.m_artist = copy.substr(25, 25));
				trim(song.m_album = copy.substr(50, 25));
				
				try {
					song.m_releaseYear = std::stoi(copy.substr(75, 5));
				}
				catch (...) {
				song.m_releaseYear = 0;
				}
				
				song.m_songLength = std::stoi(copy.substr(80, 5));
				song.m_price = std::stod(copy.substr(85, 5));
				
				m_song.push_back(song);
			}
		}
		file.close();
	}
	
	//print the content of the collection into the parameter (one song / line). Use the insertion operator (see below)
	void SongCollection::display(std::ostream& out) const {
		std::for_each(m_song.begin(), m_song.end(), [&](const Song& theSong) {
			out << theSong;
		});
	}
	
	 //inserts one song into the first parameter, using the following format
	std::ostream& operator<<(std::ostream& out, const Song& song)
	{
		// | title | artist | album 
		out << "| " << std::setw(20) << std::left << song.m_title << " | "
			<< std::setw(15) << std::left << song.m_artist << " | "
			<< std::setw(20) << std::left << song.m_album << " | "
			<< std::setw(6) << std::right;
	
		// print release year of fsong
		if (song.m_releaseYear == 0) {
			out << " ";
		} else {
			out << song.m_releaseYear;
		}
		
	// length of songs
	out << " | " << song.m_songLength / 60 << ":" << std::setw(2) << std::setfill('0') << song.m_songLength % 60
	// price of songs
	<< " | " << song.m_price << " |" << std::setfill(' ') << std::endl;
	
	return out;
	}
	
}

