#include "validation.h"
//----------------------------------------------------------------------------------------//
/*
Checks that received string has only letters/spaces/hyphens
*/
bool Validation::checkString(const int length, const char* string)
{
	//scan string for any characters that are not a space or letter
	for (int i = 0; i < length; i++)
	{
		//Check for invalid characters
		if (string[i] != '-' && string[i] != ' ' && (string[i] < 'A' || string[i] > 'z'
			|| (string[i] > 'Z' && string[i] < 'a'))) //KI#1,2
		{
			return false;
		}
	}

	return true;
}
//----------------------------------------------------------------------------------------//
/*
Checks validy of password
*/
bool Validation::passwordCheck(const char* password)
{
	//check if length of password is valid
	if (strlen(password) < MIN_PASSWORD_LENGTH || strlen(password) > MAX_PASSWORD_LENGTH)
	{
		cout << "Password must contain 6-15 characters\n";
		return false;
	}
	else
	{
		bool uppercase_found = 0, lowercase_found = 0, number_found = 0;

		//scans the password for lowercase/uppercase letters and numbers
		for (int i = 0; i < strlen(password),
			(uppercase_found == 0 || lowercase_found == 0 || number_found == 0); i++)
		{
			//check if password has spaces
			if (password[i] == ' ')
			{
				cout << "Invalid space in password\n";
				return false;
			}
			//check for number
			if (password[i] >= '0' && password[i] <= '9' && !number_found)
				number_found = 1;
			//check for lowercase letter
			if (password[i] >= 'a' && password[i] <= 'z' && !lowercase_found)
				lowercase_found = 1;
			//check for uppercase letter
			if (password[i] >= 'A' && password[i] <= 'Z' && !uppercase_found)
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
bool Validation::usernameCheck(const char* username)
{
	//check if username length is valid
	if (strlen(username) < MIN_USERNAME_LENGTH || strlen(username) > MAX_USERNAME_LENGTH)
	{
		cout << "Username must contain 6-15 characters\n";
		return false;
	}
	else
	{
		//check if name contains symbols/spaces/invalid characters
		for (int i = 0; i < strlen(username); i++)
		{
			if (username[i] < '0' || username[i] > 'z'
				|| (username[i] > '9' && username[i] < 'A')
				|| (username[i] > 'Z' && username[i] < 'a'))
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