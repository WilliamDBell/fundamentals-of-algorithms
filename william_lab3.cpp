#include <iostream>
#include <string>

using namespace std;

string pattern(int num);
int returnRand();
void mergeSort(string arr[], int left, int right);
void merge(string arr[], int left, int middle, int right);
bool stringNumComp(string a, string b);

int main(){
  int nums[10];
  string patternNums[10];
  for(int i = 0; i < 10; i++){
    nums[i] = returnRand();
    // cout << nums[i] << endl;
  }
  for(int i = 0; i < 10; i++){
    patternNums[i] = (pattern(nums[i]));
    // cout << patternNums[i] << endl;
  }
  mergeSort(patternNums, 0, 9);
  for(int i = 0; i <10; i++){
    cout << patternNums[i] << endl;
  }
  return 0;
}

bool stringNumComp(string a, string b){
  if(a.size() > b.size()){
    return true;
  }
  if(b.size() > a.size()){
    return false;
  }
  for(int i = 0; i < a.length(); ++i){
    if ((a[i] - '0') < (b[i] - '0'))
    {
        return false;
    }
  }
  return true;
}

int returnRand(){
  return 5 + ( rand() % ( 11 ) );
}

string pattern(int n){
  if (n == 1){
    return "1";
  }
  if (n == 2){
    return "11";
  }
  string str = "11";
  for (int i = 3; i<=n; i++){
    str += '$';
    int len = str.length();
    int cnt = 1;
    string  tmp = "";
    for (int j = 1; j < len; j++){
      if (str[j] != str[j-1]){
        tmp += cnt + '0';
        tmp += str[j-1];
        cnt = 1;
      }
      else {
        cnt++;
      }
    }
    str = tmp;
  }

  return str;
}

void merge(string arr[], int left_index, int middle_index, int right_index)
{
  int i, j, k;
  int n1 = middle_index - left_index + 1;
  int n2 =  right_index - middle_index;
  string left[n1], right[n2]; // temporary arrays
  for (i = 0; i < n1; i++)
      left[i] = arr[left_index + i];
  for (j = 0; j < n2; j++)
      right[j] = arr[middle_index + 1+ j];
  /* Merge the temp arrays back into arr[l..r]*/
  i = 0; // Initial index of first subarray
  j = 0; // Initial index of second subarray
  k = left_index; // Initial index of merged subarray
  while (i < n1 && j < n2) {
    if (stringNumComp(right[j], left[i])){
      arr[k] = left[i];
      i++;
    }
    else{
      arr[k] = right[j];
      j++;
    }
    k++;
  }
  /* Copy the remaining elements of L[], if there are any */
  while (i < n1){
    arr[k] = left[i];
    i++;
    k++;
  }
  /* Copy the remaining elements of R[], if there are any */
  while (j < n2){
    arr[k] = right[j];
    j++;
    k++;
  }
}

void mergeSort(string arr[], int left, int right){
  if (left < right){
    // Same as (l+r)/2, but avoids overflow for
    // large l and h
    int middle = left+(right-left)/2;
    // Sort first and second halves
    mergeSort(arr, left, middle);
    mergeSort(arr, middle+1, right);
    merge(arr, left, middle, right);
  
