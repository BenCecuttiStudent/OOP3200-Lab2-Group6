// Name: WorkTicket.cpp
// Authors: Alexus Girotto(100727793) & 
//         Ben Cecutti(100754039)
// Date: September 15th 2021

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

WorkTicket::~WorkTicket() = default;


// Copy Constructor
WorkTicket::WorkTicket(const WorkTicket& ticket2)
{
	SetWorkTicket(ticket2.GetWorkTicketNumber(), ticket2.GetClientID(), ticket2.GetWorkTicketDay(),
	              ticket2.GetWorkTicketMonth(), ticket2.GetWorkTicketYear(), ticket2.GetWorkTicketDescription());
	std::cout << "\nA WorkTicket object was COPIED. \n";
}

// Getters
int WorkTicket::GetWorkTicketNumber() const { return workTicketNumber; }

std::string WorkTicket::GetClientID() const { return clientID; }

std::string WorkTicket::GetWorkTicketDescription() const { return workTicketDescription; }

int WorkTicket::GetWorkTicketDay() const { return workTicketDay; }

int WorkTicket::GetWorkTicketMonth() const { return workTicketMonth; }

int WorkTicket::GetWorkTicketYear() const { return workTicketYear; }

// Setters
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
			throw std::invalid_argument("Number must be greater or equal to 0");
		}

		if (client_id.length() > 0)
		{
			SetClientID(client_id);
		}
		else
		{
			throw std::invalid_argument("String must be at least one character");
		}

		if (work_ticket_day >= 1 && work_ticket_day <= 31)
		{
			SetWorkTicketDay(work_ticket_day);
		}
		else
		{
			throw std::invalid_argument("Number must be between 1 and 31");
		}

		if (work_ticket_month >= 1 && work_ticket_month <= 12)
		{
			SetWorkTicketMonth(work_ticket_month);
		}
		else
		{
			throw std::invalid_argument("Number must be between 1 and 12");
		}

		if (work_ticket_year >= 2000 && work_ticket_year <= 2099)
		{
			SetWorkTicketYear(work_ticket_year);
		}
		else
		{
			throw std::invalid_argument("Number must be between 2000 and 2099");
		}
		return true;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what();
		return false;
	}
}

bool WorkTicket::operator==(const WorkTicket& newTicket) const
{
	return (GetWorkTicketNumber() == newTicket.GetWorkTicketNumber())
			&& (GetClientID() == newTicket.GetClientID())
			&& (GetWorkTicketDay() == newTicket.GetWorkTicketDay())
			&& (GetWorkTicketMonth() == newTicket.GetWorkTicketMonth())
			&& (GetWorkTicketYear() == newTicket.GetWorkTicketYear())
			&& (GetWorkTicketDescription() == newTicket.GetWorkTicketDescription());
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

	std::cout << temp;
	return temp;

	// Work Ticket # 2 - ABC123 (10/3/1012): User cannot locate 'any' key
}
