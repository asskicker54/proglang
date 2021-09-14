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
  void GetPrevious();

};

void DateTime::Output(int n){
  printf("%d: \t%02u/%02u/%02u %02u:%02u:%02u\n", n, day, month, year, hour, minute, second);
 
}

void DateTime::GetNext(){
  
}

DateTime * ReadFile(){
  ifstream tempLine("data");
  string c;
  while(getline(tempLine, c)) {
    gN++;
  }
  cout << gN << endl;

  ifstream file("data");

  DateTime *arr = new DateTime[gN];
  int i = 0;
  string line;
  DateTime *tempArr;
  while(getline(file, line)){
    istringstream fileLine(line);
    tempArr = new DateTime;
    fileLine >> tempArr->day >> tempArr->month >> tempArr->year >> tempArr->hour >> tempArr->minute >> tempArr->second;
    arr[i++] = *tempArr;
  }

  return arr;
}

int main(){
  DateTime * arr = ReadFile();
  for(int i = 0; i < gN; i++){
    arr[i].Output(i);
  }
}