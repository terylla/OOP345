// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel

#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h"

using namespace sdds;

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Book library[7];
	{
		// TODO: load the collection of books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the array "library"
		//       - lines that start with "#" are considered comments and should be ignored
	
	std::ifstream file(argv[1]);
	if (!file) {
		std::cerr << "Error: Cannot open file [" << argv[1] << "]." << std::endl;
		return 1;
	}
	
	std::string strBook;
	size_t i = 0;
	// Count how many records are in the file
	do {
		std::getline(file, strBook);
		
		if (file) {
			// Check for the commented line
			if (strBook[0] != '#') {
				// Store string into each library element
				Book temp(strBook);
				library[i] = strBook;
				++i;
			}
		}
		
		} while (file);

	}
	
	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object

	auto price = [&](Book& book)
	{
	if (book.country() == "US")
		{
		book.price() *= usdToCadRate;
		}
	if (book.country() == "UK" && (book.year() >= 1990 && book.year() <= 1999))
		{
		book.price() *= gbpToCadRate;
		}
	
	};

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n\n";

	// TODO: iterate over the library and update the price of each book
	//         using the lambda defined above.
	//for each book in library
	for (auto& book : library)
		{
		price(book); //get the price of book
		}

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n";

	return 0;
}
