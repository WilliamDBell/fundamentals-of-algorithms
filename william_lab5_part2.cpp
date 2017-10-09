#include <iostream>
#include <string>

using namespace std;

int ExcelColumnToNumber(string columnName); // function header

int main(){
  cout << "A: " << ExcelColumnToNumber("A") << endl;
  cout << "AH: "<< ExcelColumnToNumber("AH") << endl;
  cout << "Z: " << ExcelColumnToNumber("Z") << endl;
  return 0;
}

int ExcelColumnToNumber(string columnName) {
  int sum = 0;
  for (int i = 0; i < columnName.size(); i++) {
    sum *= 26;
    sum += (columnName[i] - 'A' + 1);
  }
  return sum;
}
