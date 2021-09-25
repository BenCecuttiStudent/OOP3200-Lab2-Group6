// Name: Lab 2 - Class Operators and Data Type Conversions
// Authors: Alexus Girotto(100727793) & 
//         Ben Cecutti(100754039)
// Date: September 24th 2021

#include <iostream>
#include "WorkTicket.h"

int main()
{
	int workTicketNumber = 0;
	std::string clientID = " ";
	int workTicketDay = 0;
	int workTicketMonth = 0;
	int workTicketYear = 0;
	std::string workTicketDescription = " ";

	std::cout << "Work Ticket Report Program"
		<< "\n==========================";

	// Existing Ticket
	WorkTicket ticket1(13, "CecuttiB", 07, 12, 2021, "Fan is very loud");

	WorkTicket ticket2 = ticket1;

	// Typecast
	std::cout << ticket2;

	WorkTicket ticket3(1, "1", 1, 1, 2000, " ");
	WorkTicket ticket4(1, "1", 1, 1, 2000, " ");
	std::cout << "\nTicket 1:\n";
	std::cin >> ticket3;
	std::cout << "Ticket 2:\n";
	std::cin >> ticket4;

	std::cout << "\nAre the two tickets equal?: " << (ticket3 == ticket4) << std::endl;
	ticket3 = ticket4;

	std::cout << ticket4;

}