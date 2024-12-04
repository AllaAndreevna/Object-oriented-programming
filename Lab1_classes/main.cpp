#include <iostream>

using namespace std;

class Auto {
private:
    int year, month, day;
public:
    void message() {
        cout << "Class is working" << endl;
    }

    void set(int date_year, int date_month, int date_day) {
        year = date_year;
        month = date_month;
        day = date_day;
    }

    void get() {
        cout << "Year of auto is " << year << ", mont is " << month << ", day is " << day << endl;
    }
};

int main(int argc, char* argv[]) {
    Auto shkoda;
    shkoda.message();
    shkoda.set(2005, 11, 23);
    shkoda.get();

    cin.get();
    return 0;
}