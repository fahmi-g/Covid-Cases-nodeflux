#include "CustomTimeValidation.h"

bool CustomTimeValidation::IsValid(int year) const
{
	bool validYear = year < 2020 || year > 2022;

	return !validYear;
}

bool CustomTimeValidation::IsValid(int year, int month) const
{
	bool invalidYear = year < 2020 || year > 2022;
	bool invalidMonth = month < 1 || month > 12;

	if (invalidYear || invalidMonth)
		return false;

	return true;
}

bool CustomTimeValidation::IsValid(int year, int month, int date) const
{
	const int specialMonths1{2};
	const int specialMonths2[5]{4, 6, 9, 11};

	bool invalidYear = year < 2020 || year > 2022;
	bool invalidMonth = month < 1 || month > 12;
	bool invalidDate = date < 1 || (month==specialMonths1 && date>28);

	for (int i = 0; i < 5; i++)
	{
		if (month == specialMonths2[i] && date > 30)
			invalidDate = true;
	}


	if (invalidYear || invalidMonth || invalidDate)
		return false;



	return true;
}