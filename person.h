#pragma once

#include<string>

class PersonBuilder;
class Person
{
	// address
	
	std::string street_address, post_code, city;

	//employment 
	//
	std::string company_name, position;

	int annual_income{0};


	static PersonBuilder create();

	friend class PersonBuilder;
	friend class PersonJobBuilder;
	friend class PersonAddressBuilder;
};


// we want a nice fluent interface
