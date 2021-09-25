// Name: Lab 2 - Class Operators and Data Type Conversions
// Authors: Alexus Girotto(100727793) & 
//         Ben Cecutti(100754039)
// Date: September 24th 2021

#include "WorkTicket.h"
#include <string>
#include <iostream>
#include <stdexcept>


// Constructor
WorkTicket::WorkTicket(int work_ticket_number, const std::string& client_id, int work_ticket_day, int work_ticket_month,
                       int work_ticket_year, const std::string& work_ticket_description)
{
	SetWorkTicket(work_ticket_number, client_id, work_ticket_day, work_ticket_month, work_ticket_year,
	              work_ticket_description);
}

// Deconstructor
WorkTicket::~WorkTicket() = default;

// Copy Constructor
WorkTicket::WorkTicket(const WorkTicket& ticket2)
{
	SetWorkTicket(ticket2.GetWorkTicketNumber(), ticket2.GetClientID(), ticket2.GetWorkTicketDay(),
	              ticket2.GetWorkTicketMonth(), ticket2.GetWorkTicketYear(), ticket2.GetWorkTicketDescription());
	std::cout << "\nA WorkTicket object was COPIED. \n";
}


/* ACCESSORS */
int WorkTicket::GetWorkTicketNumber() const { return workTicketNumber; }

std::string WorkTicket::GetClientID() const { return clientID; }

std::string WorkTicket::GetWorkTicketDescription() const { return workTicketDescription; }

int WorkTicket::GetWorkTicketDay() const { return workTicketDay; }

int WorkTicket::GetWorkTicketMonth() const { return workTicketMonth; }

int WorkTicket::GetWorkTicketYear() const { return workTicketYear; }


/* MUTATORS*/
void WorkTicket::SetWorkTicketNumber(int work_ticket_number) { workTicketNumber = work_ticket_number; }

void WorkTicket::SetClientID(const std::string& client_id) { clientID = client_id; }

void WorkTicket::SetWorkTicketDay(const int work_ticket_day) { workTicketDay = work_ticket_day; }

void WorkTicket::SetWorkTicketMonth(const int work_ticket_month) { workTicketMonth = work_ticket_month; }

void WorkTicket::SetWorkTicketYear(const int work_ticket_year) { workTicketYear = work_ticket_year; }

void WorkTicket::SetWorkTicketDescription(const std::string& work_ticket_description)
{
	workTicketDescription = work_ticket_description;
}

bool WorkTicket::SetWorkTicket(const int work_ticket_number, const std::string& client_id, const int work_ticket_day, const int work_ticket_month, const int work_ticket_year, const std::string& work_ticket_description)
{
	try
	{
		if (work_ticket_number > 0)
		{
			SetWorkTicketNumber(work_ticket_number);
		}
		else
		{
			throw std::invalid_argument("ERROR! Ticket number must be greater than 0\n");
		}

		if (client_id.length() > 0)
		{
			SetClientID(client_id);
		}
		else
		{
			throw std::invalid_argument("ERROR! ClientID must be at least one character");
		}

		if (work_ticket_day >= 1 && work_ticket_day <= 31)
		{
			SetWorkTicketDay(work_ticket_day);
		}
		else
		{
			throw std::invalid_argument("ERROR! Day must be between 1 and 31");
		}

		if (work_ticket_month >= 1 && work_ticket_month <= 12)
		{
			SetWorkTicketMonth(work_ticket_month);
		}
		else
		{
			throw std::invalid_argument("ERROR! Month must be between 1 and 12");
		}

		if (work_ticket_year >= 2000 && work_ticket_year <= 2099)
		{
			SetWorkTicketYear(work_ticket_year);
		}
		else
		{
			throw std::invalid_argument("ERROR! Year must be between 2000 and 2099");
		}

		if (work_ticket_description.length() > 0)
		{
			SetWorkTicketDescription(work_ticket_description);
		}
		else
		{
			throw std::invalid_argument("ERROR! Description must be at least one character");
		}
		return true;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what();
		return false;
	}
}


/* OPERATOR OVERLOADS */
bool WorkTicket::operator==(const WorkTicket& ticket2) const
{
	return (GetWorkTicketNumber() == ticket2.GetWorkTicketNumber())
			&& (GetClientID() == ticket2.GetClientID())
			&& (GetWorkTicketDay() == ticket2.GetWorkTicketDay())
			&& (GetWorkTicketMonth() == ticket2.GetWorkTicketMonth())
			&& (GetWorkTicketYear() == ticket2.GetWorkTicketYear())
			&& (GetWorkTicketDescription() == ticket2.GetWorkTicketDescription());
}

WorkTicket WorkTicket::operator=(const WorkTicket& ticket2) 
{
	SetWorkTicket(ticket2.GetWorkTicketNumber(), ticket2.GetClientID(), ticket2.GetWorkTicketDay(),
	              ticket2.GetWorkTicketMonth(), ticket2.GetWorkTicketYear(), ticket2.GetWorkTicketDescription());

	std::cout << "\nA WorkTicket object was ASSIGNED. \n";

	return *this;
}

std::istream& operator>>(std::istream& in, WorkTicket& ticket)
{
	int tmpNum;
	int tmpNum2;
	int tmpNum3;
	std::string tmpString;
	try
	{
		std::cout << "Work Ticket Number:";
		in >> tmpNum;
		if (tmpNum > 0)
		{
			ticket.workTicketNumber = tmpNum;
		}
		else
		{
			throw std::invalid_argument("ERROR! Ticket number must be greater than 0");
		}

		std::cout << "ClientID:";
		in >> tmpString;
		if (tmpString.length() > 0)
		{
			ticket.clientID = tmpString;
		}
		else
		{
			throw std::invalid_argument("ERROR! ClientID must be at least one character");
		}

		std::cout << "Work Ticket Date(dd mm yyyy):";
		in >> tmpNum >> tmpNum2 >> tmpNum3;
		if (tmpNum>= 1 && tmpNum <= 31)
		{
			ticket.workTicketDay = tmpNum;
		}
		else
		{
			throw std::invalid_argument("ERROR! Day must be between 1 and 31");
		}

		if (tmpNum2 >= 1 && tmpNum2 <= 12)
		{
			ticket.workTicketMonth = tmpNum2;
		}
		else
		{
			throw std::invalid_argument("ERROR! Month must be between 1 and 12");
		}

		if (tmpNum3 >= 2000 && tmpNum3 <= 2099)
		{
			ticket.workTicketYear = tmpNum3;
		}
		else
		{
			throw std::invalid_argument("ERROR! Year must be between 2000 and 2099");
		}

		in.ignore();
		std::cout << "Description: ";
		std::getline(in, tmpString);
		if (tmpString.length() > 0)
		{
			ticket.workTicketDescription = tmpString;
		}
		else
		{
			throw std::invalid_argument("ERROR! Description must be at least one character");
		}
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what();
	}
	/*
	std::cout << "Work Ticket Number:";
	in >> ticket.workTicketNumber;
	std::cout << "ClientID:";
	in.ignore();
	in >> ticket.clientID;
	std::cout << "Work Ticket Date(dd mm yyyy):";
	in.ignore();
	in >> ticket.workTicketDay >> ticket.workTicketMonth >> ticket.workTicketYear;
	in.ignore();
	std::cout << "Description: ";
	std::getline(in, ticket.workTicketDescription);
	in.ignore();
	return in;
	*/
}

std::ostream& operator<<(std::ostream& out, const WorkTicket& ticket)
{
	out << ticket.ToString();
	return out;
}


// Output Ticket Information
void WorkTicket::ShowWorkTicket() const
{
	std::cout << "Number: ";
	std::cout << GetWorkTicketNumber() << std::endl;
	std::cout << "ClientID: ";
	std::cout << GetClientID() << std::endl;
	std::cout << "Date: ";
	std::cout << GetWorkTicketDay() << "/" << GetWorkTicketMonth() << "/" << GetWorkTicketYear() << std::endl;
	std::cout << "Description: ";
	std::cout << GetWorkTicketDescription() << std::endl;
}

std::string WorkTicket::ToString() const
{
	std::string temp;

	temp.append("WorkTicket # ");
	temp.append(std::to_string(GetWorkTicketNumber()));
	temp.append(" - ");
	temp.append(GetClientID());
	temp.append(" (");
	temp.append(std::to_string(GetWorkTicketDay()));
	temp.append("/");
	temp.append(std::to_string(GetWorkTicketMonth()));
	temp.append("/");
	temp.append(std::to_string(GetWorkTicketYear()));
	temp.append("): ");
	temp.append(GetWorkTicketDescription());
	temp.append("\n");

	return temp;
}