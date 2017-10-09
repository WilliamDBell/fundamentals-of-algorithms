#include <iostream>
#include <string>

using namespace std;

string NumbertoExcellColumn(int n);
int main(){
  cout << "26: " << NumbertoExcellColumn(26) << endl;
  cout << "34: " << NumbertoExcellColumn(34) << endl;
  cout << "1: " << NumbertoExcellColumn(1) << endl;
}

string NumbertoExcellColumn(int n) {
  char str[20];
  int i = 0;
  while (n>0) {
    int rem = n%26;
      if (rem==0) {
        str[i++] = 'Z';
        n = (n/26)-1;
      }
      else {
        str[i++] = (rem-1) + 'A';
        n = n/26;
      }
  }
  str[i] = '\0';
  reverse(str, str + strlen(str));
  return str;
}
