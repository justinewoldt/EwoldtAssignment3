#include "GenStack.h"
#include <iostream>
#include <fstream>

using namespace std;

main(int argc, char *argv[])
{
  GenStack<char> myStack; //generates stack
  string line; // variable for reading lines
  int numLine = 0; //line that currently on
  bool check = true; //if we are missing a delimiter
  ifstream file(argv[1]); //open the cpp file
  while(!file.eof()) //run until end of file
  {
    getline(file,line);
    numLine++; //incrementing the line
    for(int i = 0; i < line.length(); i++) //go through each char
    {
      switch(line[i]) //characters to stop at
      {
        case '{':
          myStack.push(line[i]);
          break;
        case '(':
          myStack.push(line[i]);
          break;
        case '[':
          myStack.push(line[i]);
          break;
        case '}':
          if(myStack.pop() != '{')
          {
            check = false;
            cout << "You are missing a " << myStack.peek() << " on line: " << numLine << endl;
            break;
          }
          break;
        case ')':
          if(myStack.pop() != '(')
          {
            check = false;
            cout << "You are missing a " << myStack.peek() << " on line: " << numLine << endl;
            break;
          }
          break;
        case ']':
          if(myStack.pop() != '[')
          {
            check = false;
            cout << "You are missing a " << myStack.peek() << " on line: " << numLine << endl;
            break;
          }
          break;
        default:
          break;

      }
      if(check == false) //if found wrong syntax, leave forloop
      {
        break;
      }

    }
    if(check == false) // leave while loop
    {
      break;
    }

  }
  if(!myStack.isEmpty() && check == true) // if there is anythign left in the stack it must mean wrong syntax
  {
    cout << "Reached end of file, missing }" << endl;
  }
  else if (myStack.isEmpty() && check == true)
  {
    cout << "No errors!" << endl;
  }
  return 0;

}
