#pragma once
#include <string>

class CustomTimeValidation
{
	public:
		bool IsValid(int year) const;
		bool IsValid(int year, int month) const;
		bool IsValid(int year, int month, int date) const;
};