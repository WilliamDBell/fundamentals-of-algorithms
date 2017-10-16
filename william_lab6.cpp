/*
William Bell
Fundamentals of Algorithms
Lab 6
**/
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void printMaxLineLength(istream& infile, int max_length); //

int main(){
  ifstream infile("infile.txt");
  int max_length = 30;
  printMaxLineLength(infile, max_length);
  return 0;
}

void printMaxLineLength(istream& infile, int max_length){
  int temp = 0;
  string word;
  while(!infile.eof()){
    infile >> word;
    if(word.size() + temp < max_length){
      cout << word << " ";
      temp = temp + word.size() + 1;
    }
    else{
      cout << endl << word << " ";
      temp = word.size() + 1;
    }
  }
}
