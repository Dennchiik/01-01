#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    int operator-(const Date& other) const {
        int days1 = year * 365 + month * 30 + day;
        int days2 = other.year * 365 + other.month * 30 + other.day;
        return std::abs(days1 - days2);
    }

    Date operator+(int days) const {
        int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        Date result = *this;

        while (days > 0) {
            daysInMonth[2] = (result.year % 4 == 0 && (result.year % 100 != 0 || result.year % 400 == 0)) ? 29 : 28;

            int daysLeftInMonth = daysInMonth[result.month] - result.day + 1;

            if (days >= daysLeftInMonth) {
                days -= daysLeftInMonth;
                result.day = 1;
                if (++result.month > 12) {
                    result.month = 1;
                    ++result.year;
                }
            }
            else {
                result.day += days;
                days = 0;
            }
        }

        return result;
    }
};

int main() {
    Date date1(1, 1, 2023);
    Date date2(1, 1, 2024);

    int difference = date2 - date1;
    std::cout << "Difference between dates: " << difference << " days" << std::endl;

    Date futureDate = date1 + 100;
    std::cout << "Date 100 days after: " << futureDate.getDay() << "/" << futureDate.getMonth() << "/" << futureDate.getYear() << std::endl;

    return 0;
}
