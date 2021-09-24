// Name: WorkTicket.cpp
// Authors: Alexus Girotto(100727793) & 
//         Ben Cecutti(100754039)
// Date: September 15th 2021

#include "WorkTicket.h"
#include <string>
#include <iostream>
#include <stdexcept>

class WorkTicket
{
private:
	// Attributes
	int workTicketNumber = 0;
	std::string clientID = " ";
	int workTicketDay = 0;
	int workTicketMonth = 0;
	int workTicketYear = 0;
	std::string workTicketDescription = " ";

public:
	// Parameterized Constructor
	WorkTicket(const int work_ticket_number, const std::string& client_id, const int work_ticket_day,
		const int work_ticket_month, const int work_ticket_year, const std::string& work_ticket_description)
	{
		workTicketNumber = work_ticket_number;
		clientID = client_id;
		workTicketDay = work_ticket_day;
		workTicketMonth = work_ticket_month;
		workTicketYear = work_ticket_year;
		workTicketDescription = work_ticket_description;
	}

	// Default Constructor
	WorkTicket()
	{
		workTicketNumber = 0;
		clientID = "";
		workTicketDay = 1;
		workTicketMonth = 1;
		workTicketYear = 2000;
		workTicketDescription = "";
	}

	// Getters
	int GetWorkTicketNumber() const { return workTicketNumber; }

	std::string GetClientID() const { return clientID; }

	std::string GetWorkTicketDescription() const { return workTicketDescription; }

	int GetWorkTicketDay() const { return workTicketDay; }

	int GetWorkTicketMonth() const { return workTicketMonth; }

	int GetWorkTicketYear() const { return workTicketYear; }

	// Setters
	void SetWorkTicketNumber(int work_ticket_number) { workTicketNumber = work_ticket_number; }

	void SetClientID(const std::string& client_id) { clientID = client_id; }

	void SetWorkTicketDay(const int work_ticket_day) { workTicketDay = work_ticket_day; }

	void SetWorkTicketMonth(const int work_ticket_month) { workTicketMonth = work_ticket_month; }

	void SetWorkTicketYear(const int work_ticket_year) { workTicketYear = work_ticket_year; }

	void SetWorkTicketDescription(const std::string& work_ticket_description)
	{
		workTicketDescription = work_ticket_description;
	}

	bool SetWorkTicket(const int work_ticket_number, const std::string& client_id, const int work_ticket_day, const int work_ticket_month, const int work_ticket_year, const std::string& work_ticket_description)
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
		catch (std::exception ex)
		{
			std::cout << ex.what();
			return false;
		}

	}

	// Output Ticket Information
	void ShowWorkTicket()
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
};