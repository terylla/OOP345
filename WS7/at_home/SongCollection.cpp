// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: March 16, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CTR_SECURE_NO_WARNINGS_
#include "SongCollection.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <list>
#include <iomanip>
#include <iostream>

namespace sdds {
	
	// in_lab
	std::string& SongCollection::trim(std::string &str) {
		while(str.length() > 0 && str[0] == ' ') {
			str.erase(0, 1);
		}
		while (str.length() > 0 && str[str.length() - 1] == ' ') {
			str.erase(str.length() - 1, 1);
		}
		return str;
	}
	
	// in_lab
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
	
	//in_lab
	void SongCollection::display(std::ostream &out) const {
		std::for_each(m_song.begin(), m_song.end(), [&](const Song& theSong) {
			out << theSong << std::endl;
		});
		
	
		//AT_HOME
		// copied from w7_home:
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		// ...
		
		auto totalTime = std::accumulate(m_song.begin(), m_song.end(), 0u, [] (const size_t& res, const Song item) {
			return res + item.m_songLength;
		});
		
		std::string str = "Total Listening Time: ";
		str += std::to_string(totalTime/3600);
		str += ":";
		str += std::to_string((totalTime %= 3600) / 60);
		str += ":";
		str += std::to_string(totalTime % 60);
		out << "| " << std::setw(84) << str << " |"  << std::endl;
	}
	
	// receives as a parameter the name of the field used to sort the collection of songs in ascending order.
	//The parameter can have one of the values `title`, `album`, or `length`.
	void SongCollection::sort(std::string field) {
		// from sample code in class...
		if (field == "title") {
			std::sort(m_song.begin(), m_song.end(), [] (const Song& x, const Song& y) {
				return x.m_title < y.m_title;
			});
		} else if (field == "album") {
			std::sort(m_song.begin(), m_song.end(), [] (const Song& x, const Song& y) {
				return x.m_album < y.m_album;
			});
		} else if (field == "length") {
			std::sort(m_song.begin(), m_song.end(), [] (const Song& x, const Song& y) {
				return x.m_songLength < y.m_songLength;
			});
		}
	}
	
	//removes the token `[None]` from the album field of the songs that do not have a valid album
	void SongCollection::cleanAlbum() {
		/*auto itr = find(m_song.begin(), m_song.end(), "[None]");
		if (itr != m_song.end()){
			m_song.erase(itr);
		}*/
		for_each(m_song.begin(), m_song.end(), [] (Song& song) {
			if (song.m_album == "[None]") {
			 song.m_album = " ";
			}
		});
		
	}
	
	//receives the name of an artist as a parameter, and returns `true` if the collection contains any song by that artist. 
	bool SongCollection::inCollection(std::string artist) const {
		auto result = std::find_if(m_song.begin(), m_song.end(), [&artist] (const Song& song) {
			return song.m_artist == artist;
		});
		return result != m_song.end();
	}
	
	//receives the name of an artist as a parameter, and returns the the list of songs of that artist available in the collection. 
	std::list<Song> SongCollection::getSongsForArtist(std::string artist) const {
		auto count = std::count_if(m_song.begin(), m_song.end(), [&artist]( const Song& song) {
			return song.m_artist == artist;
		});
		
		std::list <Song> theSongs(count);
		std::copy_if(m_song.begin(), m_song.end(), theSongs.begin(), [&artist](const Song& song) {
			return song.m_artist == artist;
		});
		return theSongs;
	}
	
	//inserts one song into the first parameter, using the following format
	// | TITLE(20) | ARTIST(15) | ALBUM(20) | YEAR(6) | LENGTH | PRICE |
	std::ostream &operator<<(std::ostream &out, const Song& song) {
		// | title | artist | album
	out << "| " << std::left << std::setw(20)  << song.m_title
		<< " | " << std::left << std::setw(15)  << song.m_artist
		<< " | " << std::left << std::setw(20)  << song.m_album
		<< " | " << std::right << std::setw(6);
		
		// print release year of song
		if (song.m_releaseYear == 0) {
		out << " ";
		} else {
		out << song.m_releaseYear;
		}
		
		// length of songs
		out << " | " << song.m_songLength / 60 << ":" << std::setw(2) << std::setfill('0') << song.m_songLength % 60
		// price of songs
		<< " | " << std::fixed << std::setprecision(2) << song.m_price << " |" << std::setfill(' ');
		
		return out;
		
		}
		
		}


