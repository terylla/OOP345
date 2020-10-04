// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: February 13th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include <iostream>
#ifndef _SDDS__BOOK_H_
#define _SDDS__BOOK_H_

namespace sdds {
    class Book {
        std::string m_author;
        std::string m_title;
        std::string m_country;
        size_t m_year;
        double m_price;
        std::string m_desc;

    public:
        Book();
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();
        Book(const std::string& strBook);
        friend std::ostream& operator<<(std::ostream& os, const Book& book);
    };

    void trim(std::string& str);
}

#endif //_SDDS__BOOK_H_
