#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#pragma warning(disable:4996)

using namespace std;

// Adjust date by a number of days +/-
void DatePlusDays(struct tm* date, int days)
{
	const time_t ONE_DAY = 24 * 60 * 60;

	// Seconds since start of epoch
	time_t date_seconds = mktime(date) + (days * ONE_DAY);

	// Update caller's date
	// Use localtime because mktime converts to UTC so may change date
	*date = *localtime(&date_seconds); ;
}

void hex_converter()
{
	struct tm date = { 0, 0, 12 };  // nominal time midday (arbitrary).
	int year = 1900;
	int month = 1;  // February
	int day = 1;   // 26th
	int long offset = 25567;

	// Set up the date structure
	date.tm_year = year - 1900;
	date.tm_mon = month - 1;  // note: zero indexed
	date.tm_mday = day;       // note: not zero indexed

							  // Date, less 100 days
	DatePlusDays(&date, 40175 - offset); //need to replace this number with a days variable

	// Show time/date using default formatting
	std::cout << asctime(&date) << std::endl;
}

int extractHex(string hex)
{
	bool first_portion = true;
	string hex_portion;
	for (unsigned int i = 0; i < hex.size(); i++)
	{
		if (hex.at(i) != 'x' && hex.at(i) != '0')
		{
			first_portion = false;
		}
		if (first_portion == false)
		{
			if (hex.at(i) == '0' && hex.at(i + 1) == '0')
			{
				break;
			}
			hex_portion += hex.at(i);
		}

	}

	int num = stoi(hex_portion, 0, 16);
	return num;
}

int main()
{
	string hex = "0x00009CEF00A25634";
	int value = extractHex(hex);
	cout << value << endl;
	hex_converter();

	system("pause");
	return 0;
}