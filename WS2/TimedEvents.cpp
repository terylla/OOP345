// Name: Tran (Teryl) La
// Seneca Student ID: 150353175
// Seneca email: ntla1@myseneca.ca
// Date of completion: Jan 23, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iomanip>
#include "TimedEvents.h"


namespace sdds {
	

	// Stop time
	void TimedEvents::startClock() {
		 m_startTime = std::chrono::steady_clock::now();
	}
	
	// Stop time
	void TimedEvents::stopClock() {
		m_endTime = std::chrono::steady_clock::now();
	}
	
	// Record an event
	void TimedEvents::recordEvent(const char* msg)
	{
	if (m_recordsNo < MAX_NUM)
		{
		m_structCycle[m_recordsNo].m_eventName =  msg;
		m_structCycle[m_recordsNo].m_unitOfTime = "nanoseconds";
		m_structCycle[m_recordsNo].m_duration =
		std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
		m_recordsNo ++;
		}
	}
	
	// Report the set of times recorded
	std::ostream& operator<<(std::ostream& os, const TimedEvents& obj)
		{
		os << "--------------------------\n";
		os << "Execution Times:\n";
		os << "--------------------------\n";
		for (size_t i = 0; i < obj.m_recordsNo; i++)
		os << std::setw(20) << std::left
		<< obj.m_structCycle[i].m_eventName << ' ' << std::setw(12) << std::right
		<< obj.m_structCycle[i].m_duration.count() << ' '
		<< obj.m_structCycle[i].m_unitOfTime << '\n';
		os << "--------------------------\n";
		return os;
		}
		}


