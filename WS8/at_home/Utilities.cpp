// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: March 19th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (size_t i = 0; i < desc.size(); i++) { //size() returns number of element in the VECTOR
			for (size_t o = 0; o < price.size(); o++) { // iterate again here
				//For each successful comparison
				if (desc[i].code == price[o].code) {
					//function allocates dynamic memory of Product type using that description and the price
					Product *newProduct = new Product(desc[i].desc, price[o].price);
					//function then validates the Product object....
					newProduct->validate(); //can't use .
					//...and adds it to its list5
					priceList += newProduct;
					//deallocate (not in instruction)
					delete newProduct;
				}
			}
		}
		//returns a copy of this list.
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t i = 0; i < desc.size(); i++) { //size() returns number of element in the VECTOR
			for (size_t o = 0; o < price.size(); o++) { // iterate again here
				//For each successful comparison
				if (desc[i].code == price[o].code) {
					//function allocates dynamic memory of Product type using that description and the price
					unique_ptr<Product> newProduct(new Product(desc[i].desc, price[o].price));
					//function then validates the Product object....
					newProduct->validate(); //can't use .
					//...and adds it to its list
					priceList += std::move(newProduct); //can't copy unique_ptr, only move
					
					/* EXTRA STUFF */
					//priceList.push_back(std::move(newProduct)); DOES NOT WORK
					//delete newProduct;
					/* unique_ptr deletes the obj when it goes out of scope so no need for deallocation */
				}
			}
		}
		//returns a copy of this list.
		return priceList;
	}
}
