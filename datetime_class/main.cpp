#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include <stdio.h>
#include <ctime>

using namespace std;

class Datetime
{

    unsigned int second;
    unsigned int minute;
    unsigned int hour;
    unsigned int day;
    unsigned int month;
    unsigned int year;
public:    
    unsigned int Get(int);
    void Set(int, int);
    void Output();
    void GetNext(Datetime&);
    void GetPrev(Datetime&);
    Datetime GetSysTime();
};

unsigned int Datetime::Get(int arg)
{
  switch(arg)
  {
    case 0:
      return second;
      break;
    case 1:
      return minute;
      break;
    case 2:
      return hour;
      break;
    case 3:
      return day;
      break;
    case 4:
      return month;
      break;
    case 5:
      return year;
      break;  
    default:
      return 0;
      break;
  }
}

void Datetime::Set(int arg, int n)
{
  switch(arg)
  {
    case 0:
      second = n;
      break;
    case 1:
      minute = n;
      break;
    case 2:
      hour = n;
      break;
    case 3:
      day = n;
      break;
    case 4:
      month = n;
      break;
    case 5:
      year = n;
      break;  
    default:
      break;
  }
}

void Datetime::Output(){
  printf("%d: \t%02u/%02u/%02u %02u:%02u:%02u\n", day, month, year, hour, minute, second);
 
}

Datetime* ReadFile(int &n)
{
  ifstream tempLine("data");
  string c;
  n = 0;
  while(getline(tempLine, c))
  {
    n++;
  }
  cout << n << endl;

  ifstream file("data");

  Datetime *date = new Datetime[n];
  int i = 0;
  string line;
  Datetime *tempArr;
  while(getline(file, line)){
    istringstream fileLine(line);
    tempArr = new Datetime;
    fileLine >> tempArr->day >> tempArr->month >> tempArr->year >> tempArr->hour >> tempArr->minute >> tempArr->second;
    date[i++] = *tempArr;
  }
  tempLine.close();
  file.close();

  return date;
}

Datetime Datetime::GetSysTime()
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

time_t GetUnixTime(Datetime d)
{
    tm timeinfo;
    timeinfo.tm_year = d.year - 1900;
    timeinfo.tm_mon = d.month - 1;
    timeinfo.tm_mday = d.day;
    timeinfo.tm_hour = d.hour;
    timeinfo.tm_min = d.minute;
    timeinfo.tm_sec = d.second;
    time_t unix_time = mktime(&timeinfo);
    return unix_time;
}

void GetNormalTime(time_t unix_time, Datetime& d)
{
    tm timeinfo;
    localtime_s(&timeinfo, &unix_time);
    d.hour = timeinfo.tm_hour;
    d.minute = timeinfo.tm_min;
    d.second = timeinfo.tm_sec;
    d.day = timeinfo.tm_mday;
    d.month = timeinfo.tm_mon + 1;
    d.year = timeinfo.tm_year + 1900;
}

void Datetime::GetNext(Datetime& next)
{
    int min = 2419200 * 2;
    int max = 31536000;
    GetNormalTime(GetUnixTime(*this) + (min + rand() % (max - min + 1)), next);
}

void Datetime::GetPrev(Datetime& prev)
{
    int min = 2419200 * 2;
    int max = 31536000;
    GetNormalTime(GetUnixTime(*this) - (min + rand() % (max - min + 1)), prev);
}

int main(){
  Datetime date;
  Datetime prev;
  Datetime next;
  int n;
  Datetime* dateArr = ReadFile(n);
  Datetime* nextArr = new Datetime[n];

  date = date.GetSysTime(); 
  cout << "System time:" << endl;
  date.Output();

  for (int i = 0; i < n; i++)
  {
    dateArr[i].GetPrev(prev);
    dateArr[i].GetNext(next);
    printf("%i)\t", i + 1);
    dateArr[i].Output(); 
    printf("\t");
    next.Output();
    printf("\t");
    prev.Output();
    printf("\n");
    nextArr[i] = next;
  }
  
  for(int i{}; i < n; i++)
  {
    if (dateArr[i].year == nextArr[i].year)
        {
            printf("%i)\t", i + 1);
            dateArr[i].Output(); 
            printf("\t");
            prev.Output();
            printf("\n");
        }
  }
}