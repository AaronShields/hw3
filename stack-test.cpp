#include <iostream>

#include "stack.h"
using namespace std;

int main(int argc, char* argv[])
{
  Stack<int> stack;

  stack.push(10);
  stack.push(20);
  stack.push(30);
  stack.push(40);
  stack.push(50);

  cout << "Size = " << stack.size() << endl;
  cout << "Top Value = " << stack.top() << endl;
  stack.pop();
  cout << "Top Value After Pop = " << stack.top() << endl;
  cout << "Size = " << stack.size() << endl;
  stack.pop();
  stack.pop();
  stack.pop();
  stack.pop();
  stack.pop();



  

}