#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Bubblesort(vector<string> &V);

int main() {
  int num_names;
  string name;
  vector<string> names;
  cout << "How many names would you like to sort?: ";
  cin >> num_names;
  for(int i = 0; i < num_names; i++){
    cout << "Enter the name: ";
    cin >> name;
    names.push_back(name);
  }
  cout << "**** Print Unsorted List ****" << endl;
  for(int i = 0; i < num_names; i++){
    cout << names.at(i) << "  ";
  }
  cout << endl;
  Bubblesort(names);
  cout << "**** Print Sorted List ****" << endl;
  for(int i = 0; i < num_names; i++){
    cout << names.at(i) << "  ";
  }
  cout << endl;
  return 0;
}

void Bubblesort(vector<string> &V){
  string temp;
  for(int i = 0; i < V.size(); i++){
    for(int j = V.size() - 1; j > i; j--){
      if(V.at(j-1).compare(V.at(j)) > 1){
        temp = V.at(j);
        V.at(j) = V.at(j-1);
        V.at(j-1) = temp;
      }
    }
  }
}
