// Name: Main.cpp
// Authors: Alexus Girotto(100727793) & 
//         Ben Cecutti(100754039)
// Date: September 15th 2021

#include <iostream>
#include "WorkTicket.h"

void main()
{
	int workTicketNumber = 0;
	std::string clientID = " ";
	int workTicketDay = 0;
	int workTicketMonth = 0;
	int workTicketYear = 0;
	std::string workTicketDescription = " ";

	std::cout << "Work Ticket Report Program"
		<< "\n==========================";

	WorkTicket WorkTicketArray[3];

	for (int x = 0; x < 3;) // Loop 3 times for ticket input
	{
		std::cout << "\n\nTicket " << x + 1
			<< "\n----------" << std::endl;
		std::cout << "Ticket Number: ";
		std::cin >> workTicketNumber;
		std::cin.clear(); // Clear the buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "ClientID: ";
		std::cin >> clientID;
		std::cin.clear(); // Clear the buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Ticket Date(dd mm yyyy): ";
		std::cin >> workTicketDay;
		std::cin >> workTicketMonth;
		std::cin >> workTicketYear;
		std::cin.clear(); // Clear the buffer so getline can work properly
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Description: ";
		std::getline(std::cin, workTicketDescription);

		if (WorkTicketArray[x].SetWorkTicket(workTicketNumber, clientID, workTicketDay, workTicketMonth, workTicketYear, workTicketDescription))
		{
			x++;
		}
	}

	std::cout << "\nTicket Output" // Loop Ticket Output
		<< "\n===============\n";
	for (int x = 0; x < 3; x++)
	{
		std::cout << "\nTicket " << x + 1
			<< "\n----------" << std::endl;
		WorkTicketArray[x].ShowWorkTicket();
	}
}