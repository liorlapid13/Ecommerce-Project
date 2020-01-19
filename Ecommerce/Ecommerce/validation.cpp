#include "validation.h"
//----------------------------------------------------------------------------------------//
/*
Checks that received string has only letters/spaces/hyphens
*/
bool Validation::checkString(const string& string)
{
	string::const_iterator itr = string.begin();
	string::const_iterator itrEnd = string.end();

	//scan string for any characters that are not a space or letter
	for (; itr != itrEnd; ++itr)
	{
		//Check for invalid characters
		if (*itr != '-' && *itr != ' ' 
			&& (*itr < 'A' || *itr > 'z' 
			|| (*itr > 'Z' && *itr < 'a')))
			return false;
	}

	return true;
}
//----------------------------------------------------------------------------------------//
/*
Checks validy of password
*/
bool Validation::passwordCheck(const string& password)
{
	//check if length of password is valid
	if (password.length() < MIN_PASSWORD_LENGTH || password.length() > MAX_PASSWORD_LENGTH)
	{
		cout << "Password must contain 6-15 characters\n";
		return false;
	}
	else
	{
		bool uppercase_found = 0, lowercase_found = 0, number_found = 0;

		string::const_iterator itr = password.begin();
		string::const_iterator itrEnd = password.end();

		//scans the password for lowercase/uppercase letters and numbers
		for (;itr != itrEnd, (uppercase_found == 0 || lowercase_found == 0 || number_found == 0); ++itr)
		{
			//check if password has spaces
			if (*itr == ' ')
			{
				cout << "Invalid space in password\n";
				return false;
			}
			//check for number
			if (*itr >= '0' && *itr <= '9' && !number_found)
				number_found = 1;
			//check for lowercase letter
			if (*itr >= 'a' && *itr <= 'z' && !lowercase_found)
				lowercase_found = 1;
			//check for uppercase letter
			if (*itr >= 'A' && *itr <= 'Z' && !uppercase_found)
				uppercase_found = 1;
		}

		//check if lowercase letter, uppercase letter and number were found in password
		if (!uppercase_found || !lowercase_found || !number_found)
		{
			cout << "Password must contain at least one lowercase character, uppercase character and number\n";
			return false;
		}
		else
			return true;
	}
}
//----------------------------------------------------------------------------------------//
/*
Checks validity of username
*/
bool Validation::usernameCheck(const string& username)
{
	//check if username length is valid
	if (username.length() < MIN_USERNAME_LENGTH || username.length() > MAX_USERNAME_LENGTH)
	{
		cout << "Username must contain 6-15 characters\n";
		return false;
	}
	else
	{
		string::const_iterator itr = username.begin();
		string::const_iterator itrEnd = username.end();

		//check if name contains symbols/spaces/invalid characters
		for (; itr != itrEnd; ++itr)
		{
			if (*itr < '0' || *itr > 'z'
				|| (*itr > '9' && *itr < 'A')
				|| (*itr > 'Z' && *itr < 'a'))
			{
				cout << "Username can only contain alphanumeric characters (lower/uppercase letters A-Z, numbers 0-9)\n";
				return false;
			}
		}
		return true;
	}
}
//----------------------------------------------------------------------------------------//
/*
Checks memory allocations
*/
void Validation::checkAllocation(void* ptr)
{
	if (!ptr)
	{
		cout << "Memory allocation error! Exiting program!\n";
		exit(1);
	}
}
//----------------------------------------------------------------------------------------//