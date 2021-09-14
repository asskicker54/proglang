#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int gN = 0;

struct DateTime{
  unsigned int second;
  unsigned int minute;
  unsigned int hour;
  unsigned int day;
  unsigned int month;
  unsigned int year;

  void Output(int);
  void GetNext();
  void GetPrev();

};

void DateTime::Output(int n){
  printf("%d: \t%02u/%02u/%02u %02u:%02u:%02u\n", n, day, month, year, hour, minute, second);
 
}

void DateTime::GetNext(){
  
}

DateTime* ReadFile()
{
  ifstream tempLine("data");
  string c;
  while(getline(tempLine, c)) {
    gN++;
  }
  cout << gN << endl;

  ifstream file("data");

  DateTime *date = new DateTime[gN];
  int i = 0;
  string line;
  DateTime *tempArr;
  while(getline(file, line)){
    istringstream fileLine(line);
    tempArr = new DateTime;
    fileLine >> tempArr->day >> tempArr->month >> tempArr->year >> tempArr->hour >> tempArr->minute >> tempArr->second;
    date[i++] = *tempArr;
  }
  tempLine.close();
  file.close();

  return date;
}

int main(){
  DateTime* date = ReadFile();
  /*for(int i = 0; i < gN; i++){
    arr[i].Output(i);
  }*/
  DateTime* prev = new DateTime[gN];
  
}