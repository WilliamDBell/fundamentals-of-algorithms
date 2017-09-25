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


int postFixEval(string word);
string convertToPostFix(string expression);
bool isOp(char c);
bool isNum(char c);
int doOp(char operation, int operand1, int operand2);

int main() {
  cout << "Input: 3 + 4 * 2 - 1 " << endl;
  postFixEval(convertToPostFix("3 + 4 * 2 - 1 "));
  cout << "Input: 1 + 2 / 2 - 2 " << endl;
  postFixEval(convertToPostFix("1 + 2 / 2 - 2 "));
  cout << "Input: 5 + 1 " << endl;
  postFixEval(convertToPostFix("5 + 1"));
  return 0;
}

string convertToPostFix(string expression){
  string newExpression;
  ArrayStack<char> opStack;
  for(int i = 0; i < expression.size(); i++){
    if(isNum(expression[i])){
      newExpression += expression[i];
      newExpression += ' ';
    }
    else if(isOp(expression[i])){
      while(opStack.top() == '/' || opStack.top() == '*'){
        newExpression += opStack.pop();
        newExpression += ' ';
      }
      opStack.push(expression[i]);
    }
  }
  while(opStack.len()){
    newExpression += opStack.pop();
    newExpression += ' ';
  }
  return newExpression;
}

bool isNum(char c){
  return (c >= '0' && c <= '9');
}
bool isOp(char c){
  return (c == '+' || c == '-' || c == '*' || c == '/');
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

int postFixEval(string expression){
  cout << expression << ", ";
  ArrayStack<int> numStack;
  for(int i = 0; i < expression.size(); i++){
    if(isNum(expression[i])){
      numStack.push((int) expression[i] - '0');
    }
    if(isOp(expression[i])){
      int op2 = numStack.pop();
      int op1 = numStack.pop();
      numStack.push(doOp(expression[i], op1, op2));
    }
  }
  cout << numStack.top() << endl;
  return numStack.pop();
}

int doOp(char operation, int operand1, int operand2){
	if(operation == '+') return operand1 + operand2;
	else if(operation == '-') return operand1 - operand2;
	else if(operation == '*') return operand1 * operand2;
	else if(operation == '/') return operand1 / operand2;
  else return -1;
}
