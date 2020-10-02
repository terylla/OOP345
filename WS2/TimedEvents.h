// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: Jan 23, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_TimedEvents_hpp
#define SDDS_TimedEvents_hpp

#include <iostream>
#include <chrono>

//using namespace std;

namespace sdds {
	const size_t MAX_NUM = 7;
	
	class TimedEvents{
	private:
		size_t m_recordsNo;
		std::chrono::steady_clock::time_point m_startTime;
		std::chrono::steady_clock::time_point m_endTime;
		struct {
			const char* m_eventName;
			const char* m_unitOfTime;
			std::chrono::steady_clock::duration m_duration;
		} m_structCycle[MAX_NUM]; // anonymous struc running 7 times only
		
	public:
		//TimedEvents();
		//~TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char*);
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& obj);
	};
}

#endif  
