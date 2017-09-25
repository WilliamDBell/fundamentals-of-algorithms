#include <iostream>
#include <list>
#include <string>

using namespace std;

template <class T>
class ArrayStack{
public:
  void push(T x);    //   Adds element x at the top of the stack
  T pop();           //   Removes and returns element at top of the stack
  T top();           //   Returns (but doesn't remove) element at top of stack
  bool is_empty();   //   Returns True if the stack is empty
  int len();         //   Returns the number of items in the stack
  list<T> stack;
};

template <class T>
class ArrayQueue{
public:
  void enqueue(T x); //   Adds element x at the back of the queue
  T dequeue();       //   Removes and returns element at front of the queue
  T first();         //   Returns (but doesn't remove) element at front of queue
  bool is_empty();   //   Returns True if the queue is empty
  int len();         //   Returns the number of items in the queue
  list<T> queue;
};

bool is_palindrone(string word); // Check if string is palindrone

int main() {
  cout << "Is \"a\" a palindrone: " << is_palindrone("a") << endl;
  cout << "Is \"a bba\" a palindrone: " << is_palindrone("a bba") << endl;
  cout << "Is \"a aa\" a palindrone: " << is_palindrone("a aa") << endl;
  cout << "Is \"abababab\" a palindrone: " << is_palindrone("abababab") << endl;
  cout << "Is \"Ta: c o. ?cat\" a palindrone: " << is_palindrone("Ta: c o. ?cat") << endl;
  cout << "Is \"thisisnotapalindrone\" a palindrone: " << is_palindrone("thisisnotapalindrone") << endl;

  return 0;
}

template <class T>
void ArrayQueue<T>::enqueue(T x){
  queue.push_front(x);
}

template <class T>
T ArrayQueue<T>::dequeue(){
  T val = queue.back();
  queue.pop_back();
  return val;
}

template <class T>
T ArrayQueue<T>::first(){
  return queue.back();
}

template <class T>
bool ArrayQueue<T>::is_empty(){
  return queue.empty();
}

template <class T>
int ArrayQueue<T>::len(){
  return  queue.size();
}

template <class T>
void ArrayStack<T>::push(T x){
  stack.push_front(x);
}

template <class T>
T ArrayStack<T>::pop(){
  T val = stack.front();
  stack.pop_front();
  return val;
}

template <class T>
T ArrayStack<T>::top(){
  return stack.front();
}

template <class T>
bool ArrayStack<T>::is_empty(){
  return stack.empty();
}

template <class T>
int ArrayStack<T>::len(){
  return stack.size();
}

bool is_palindrone(string word){
  ArrayStack<char> stack;
  ArrayQueue<char> queue;
  transform(word.begin(), word.end(), word.begin(), ::tolower);
  for(int i = 0; i < word.size(); i++){
    if(isalpha(word[i])){
      stack.push(word[i]);
      queue.enqueue(word[i]);
    }
  }
  for(int i = 0; i < stack.len(); i++){
    if(stack.pop() != queue.dequeue()){
      return false;
    }
  }
  return true;
}
