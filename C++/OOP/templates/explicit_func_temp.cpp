#include <iostream>
#include <cstring>

using namespace std;

template <class T>
long indexOf( T searchVal, const T * table, unsigned size ) {
  for (unsigned i = 0; i < size; i++)
    if (searchVal == table[i])
      return i;
  return -1;
}

// overding function indexOf (which belong to the template)
long indexOf( const char * searchVal, char * table[], unsigned size ) {
  for(unsigned i = 0; i < size; i++)
    if( strcmp(searchVal, table[i]) == 0 )
      return i;
  return -1;
}


int main() {  
  const unsigned iCount = 10, nCount = 5;
  int iTable[iCount] = { 0,10,20,30,40,50,60,70,80,90 };
  cout << indexOf( 20, iTable, iCount )  << endl; //2
  const char * names[nCount] = { "John", "Mary", "Sue", "Dan", "Bob" };
  const char * key = "Dan";
  cout << indexOf( key, names, nCount ) << endl; //3
  return 0;
}//ex4-expicit.cpp

