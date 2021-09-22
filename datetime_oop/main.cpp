#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;

class Datetime 
{
private:
    unsigned int second;
    unsigned int minute;
    unsigned int hour;
    unsigned int day;
    unsigned int month;
    unsigned int year;

public:
//Constructor
    Datetime(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    Datetime();
//Get
    unsigned int Get(int);

    string GenerateString(int, string);
    Datetime GetNext();
    Datetime GetPrev();
    Datetime CurrentTime();
};

Datetime::Datetime(unsigned int d, unsigned int mon, unsigned int y,unsigned int h, unsigned int min, unsigned int s) 
{
    second = s;
    minute = min;
    hour = h;
    day = d;
    month = mon;
    year = y;
}
unsigned int Datetime::Get(int arg) 
{
    switch(arg) {
        case 0:
            return day;
        case 1:
            return month;
        case 2:
            return year;
        case 3:
            return hour;
        case 4:
            return minute;
        case 5:
            return second;
        default:
            return 0;
    }
}

void ReadFile(Datetime*&, int&);

int main() 
{
    Datetime* arr;
    int n = 0;
    ReadFile(arr, n);

    cout << "№\tТекущая\t\t\tСледующая\t\tПредыдущая\n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << ":" << arr[i].GenerateString(i + 1, "cnp");
    }

    
    int count = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i].GetNext().Get(1) == arr[i].GetPrev().Get(1)) {
            cout << count << ":" << arr[i].GenerateString(count, "cnp");
            count++;
        }
    }

    Datetime currTime = currTime.CurrentTime();
    cout << "\nСейчас " << currTime.GenerateString(0, "c") << endl;

    delete[] arr;
    return 0;
}

void ReadFile(Datetime*& arr, int& n) 
{
    cout << "Enter filename: ";
    string filename;
    cin >> filename;

    ifstream in(filename);
    if (!in.is_open()) {
        cout << "Error opening file\n";
        exit(1);
    }

    //counting lines
    ifstream counter(filename);
    string c;
    while (getline(counter, c)) {
        n++;
    }

    arr = new Datetime[n];

    unsigned int day, month, year, hour, minute, second;

    Datetime a;
    string line;
    int i = 0;
    while (getline(in, line)) {
        istringstream conv(line);
        conv >> day >> month >> year >> hour >> minute >> second;
        Datetime d(day, month, year, hour, minute, second);
        arr[i++] = d;
    }
}

string Datetime::GenerateString(int id, std::string arg) 
{
    char curr[100] = "\0";
    char next[100] = "\0";
    char prev[100] = "\0";
    char format[31] = "\t%02u.%02u.%04u %02u:%02u:%02u";
    
    Datetime N, P;

    sprintf(curr, format, day, month, year, hour, minute, second);
    N = GetNext();
    sprintf(next, format, N.day, N.month, N.year, N.hour, N.minute, N.second);
    P = GetPrev();
    sprintf(prev, format, P.day, P.month, P.year, P.hour, P.minute, P.second);

    std::string result = "";

    for (int i = 0; i < arg.length(); i++) {
        switch (arg[i]) {
            case 'c':
                result += curr;
                break;
            case 'n':
                result += next;
                break;
            case 'p':
                result += prev;
                break;
        }
    }

    return result + '\n';
}

namespace 
{
    unsigned int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    unsigned int daysPrev[12] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
}

Datetime Datetime::GetNext() 
{
    Datetime r (*this);

    bool isLeap = false;
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        isLeap = true;
    }

    if (month == 2 && day == 28 && isLeap) {
        r.day += 1;
    } else {
        if (day == days[month-1]) {
            r.day = 1;
            if (month == 12) {
                r.month = 1;
                r.year += 1;
            } else {
                r.month += 1;
            }
        } else {
            r.day += 1;
        }
    }
    return r;
}

Datetime Datetime::GetPrev() 
{
    Datetime r (*this);

    bool isLeap = false;
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        isLeap = true;
    }

    if (month == 3 && day == 1 && isLeap) {
        r.day = 29;
        r.month = 2;
    } else {
        if (day == 1) {
            r.day = daysPrev[month-1];
            if (month == 1) {
                r.month = 12;
                r.year -= 1;
            } else {
                r.month -= 1;
            }
        } else {
            r.day -= 1;
        }
    }
    return r;
}

Datetime Datetime::CurrentTime() 
{
    Datetime r;
    time_t t;
    time(&t);

    tm* ct = localtime(&t);
    
    r.day = ct->tm_mday;
    r.month = ct->tm_mon + 1;
    r.year = ct->tm_year + 1900;
    r.hour = ct->tm_hour;
    r.minute = ct->tm_min;
    r.second = ct->tm_sec;

    return r;
}