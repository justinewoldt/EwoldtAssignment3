#include <iostream>
#include <exception>
#include <cstdlib>
using namespace std;

template <typename T>
class GenStack
{
  public:
    GenStack();//constructor
    GenStack(int maxSize); //overloaded constructor
    ~GenStack();//destructor

    void push(T d);
    T pop();
    T peek(); //aka top()

    int getSize();
    bool isEmpty();
    bool isFull();

    int size;
    int top;

    T *myArray;



};
template <class T>
GenStack<T>::GenStack() //default constructor
{
  //initialize variables to default values
  myArray = new char[5];
  size = 5;
  top = -1;
}
template <class T>
GenStack<T>::GenStack(int maxSize)//overloaded constructor
{
  myArray = new char[maxSize];
  size = maxSize;
  top = -1;
}
template <class T>
GenStack<T>::~GenStack()//destructor
{

}
template <class T>
void GenStack<T>::push(T d)
{
  //add character to stack
  if(top == size-1)
  {
    size = size*2;
    T *tempArray = new T(size);
    for(int i = 0; i < size/2; i++)
    {
      tempArray[i] = myArray[i];
    }
    myArray = tempArray;

  }
  myArray[++top] = d;
}
template <class T>
T GenStack<T>::pop()
{
  if(top == -1)
  {
    cout << "Your stack is empty." << endl;
  }
  else
  {
  char temp = myArray[top--];
  return temp;
  }
}
template <class T>
T GenStack<T>::peek()
{
  return myArray[top];
}
template <class T>
bool GenStack<T>::isFull()
{
  return (top == size-1);
}
template <class T>
bool GenStack<T>::isEmpty()
{
  return (top == -1);
}
template <class T>
int GenStack<T>::getSize()
{
  return top+1;
}
