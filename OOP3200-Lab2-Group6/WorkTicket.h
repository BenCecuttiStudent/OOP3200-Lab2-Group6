// Name: Lab 2 - Class Operators and Data Type Conversions
// Authors: Alexus Girotto(100727793) & 
//         Ben Cecutti(100754039)
// Date: September 24th 2021
#pragma once
#ifndef __WORK_TICKET__
#define __WORK_TICKET__
#include <string>

class WorkTicket
{


public:

	/* Constructor */
	WorkTicket(int work_ticket_number = 0, const std::string& client_id = "", int work_ticket_day = 0, int work_ticket_month = 0, int work_ticket_year = 0,
	           const std::string& work_ticket_description = "");

	/* Deconstructor */
	~WorkTicket();

	/* Copy Constructor */
	WorkTicket(const WorkTicket& ticket2);
	
	/* Accessors */
	int GetWorkTicketNumber() const;

	std::string GetClientID() const;

	std::string GetWorkTicketDescription() const;

	int GetWorkTicketDay() const;

	int GetWorkTicketMonth() const;

	int GetWorkTicketYear() const;

	/* Mutators */
	void SetWorkTicketNumber(int work_ticket_number);

	void SetClientID(const std::string& client_id);

	void SetWorkTicketDay(const int work_ticket_day);

	void SetWorkTicketMonth(const int work_ticket_month);

	void SetWorkTicketYear(const int work_ticket_year);

	void SetWorkTicketDescription(const std::string& work_ticket_description);

	bool SetWorkTicket(const int work_ticket_number, const std::string& client_id, const int work_ticket_day, const int work_ticket_month, const int work_ticket_year, const std::string& work_ticket_description);
	
	/* Operator Overloads */
	bool operator== (const WorkTicket& ticket2) const;
	WorkTicket operator= (const WorkTicket& ticket2);
	friend std::istream& operator>>(std::istream& in, WorkTicket& ticket);
	friend std::ostream& operator<<(std::ostream& out, const WorkTicket& ticket);

	/* Utility */
	void ShowWorkTicket() const;

	std::string ToString() const;

private:
	int workTicketNumber{};
	std::string clientID;
	int workTicketDay{};
	int workTicketMonth{};
	int workTicketYear{};
	std::string workTicketDescription;
};
#endif