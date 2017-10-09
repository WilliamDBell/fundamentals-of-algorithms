#include <iostream>
#include <vector>

using namespace std;

vector< pair<int, int> > findPairs(vector<int> arr, int sum); // function header

int main() {
  vector <int> v = {1, 2, 3, 4, 5};
  int sum = 6;
  vector< pair<int, int> > pairs = findPairs(v, sum);
  cout << "Sum" << endl;
  cout << sum << endl;
  cout << "List" << endl;
  for(int i = 0; i < v.size(); i++){
    cout << v.at(i) << " ";
  }
  cout << endl << "Pairs" << endl;
  for(int i = 0; i < pairs.size(); i++){
    cout << pairs.at(i).first << " + " << pairs.at(i).second << " = " << sum << endl;
  }
  return 0;
}

vector< pair<int, int> > findPairs(vector<int> arr, int sum){
  vector< pair<int, int> > pairs;
  for(int i = 0; i < arr.size(); i++){
    for(int j = i + 1; j < arr.size(); j++){
      if(arr.at(i) + arr.at(j) == sum){
        pairs.push_back(make_pair(arr.at(i), arr.at(j)));
      }
    }
  }
  return pairs;
}
