#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

string calcDate(int year) {
    int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int dayOfTheProgrammer = 256;
    if(year == 1918) {
        // Transition year
        // 14th was first day
        // Feb would have 28 days because 1918 is not divisible by 4
        daysInMonth[1] = 15;
    }
    else if(year < 1918) {
        // Julian calendar
        daysInMonth[1] = (year % 4 == 0) ? 29 : 28;
    }
    else {
        // Gregorian Calendar
        daysInMonth[1] = (year % 400 == 0) ? 29 : ((year % 4 == 0 && year % 100 != 0) ? 29 : 28);
    }
    int month = 1;
    int date = dayOfTheProgrammer;
    while(date - daysInMonth[month-1] > 0) {
        date -= daysInMonth[month-1];
        month++;
    }
    // The day of the programmer will never
    // land in February but to account for the
    // edge case
    if(year == 1918 && month == 2) {
        date += 13;
    }
    ostringstream out;
    out << setfill('0') << setw(2) << date << ".";
    out << setfill('0') << setw(2) << month << ".";
    out << setfill('0') << setw(4) << year;
    return out.str();
}

int main() {
    int year;
    cin >> year;
    cout << calcDate(year);
    return 0;
}
