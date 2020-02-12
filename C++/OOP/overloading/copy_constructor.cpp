#include <iostream>
using namespace std;

const int MAXCOURSE = 40;

class Transcript {
  int count;
  string * courses;
public:
  Transcript();
  Transcript( const Transcript & T);
  Transcript & operator=(const Transcript & T);
};

Transcript::Transcript() {
  cout << "Default Constructor \n";
  count=1;
  courses = new string[MAXCOURSE];
}

Transcript::Transcript( const Transcript & T ) {
  count = T.count;
  courses = new string[MAXCOURSE];
  for(unsigned i = 0; i < count; i++)
    courses[i] = T.courses[i];
  cout << "Copy Constructor.\n";
}

Transcript & Transcript::operator =( const Transcript & T ) {  
  if( this != &T ) { // not the same object
      delete [] courses;
      courses = new string[MAXCOURSE];
      count = T.count;
      cout<<count;
      for(int i = 0; i < count; i++)
        courses[i] = T.courses[i];
  }
  cout << "= Operator\n";
  return *this;
}

int main() {
  Transcript T1;
  Transcript T2( T1 );  // copy constructor
  Transcript T4 = T1 ;  // copy constructor
  Transcript T3;
  T3 = T1;      // assignment operator
  return 0;
}

#include <iostream>
using namespace std;

const int MAXCOURSE = 40;

class Transcript {
  int count;
  string * courses;
public:
  Transcript();
  Transcript( const Transcript & T);
  Transcript & operator=(const Transcript & T);
};

Transcript::Transcript() {
  cout << "Default Constructor \n";
  count=1;
  courses = new string[MAXCOURSE];
}

Transcript::Transcript( const Transcript & T ) {
  count = T.count;
  courses = new string[MAXCOURSE];
  for(unsigned i = 0; i < count; i++)
    courses[i] = T.courses[i];
  cout << "Copy Constructor.\n";
}

Transcript & Transcript::operator =( const Transcript & T ) {  
  if( this != &T ) { // not the same object
      delete [] courses;
      courses = new string[MAXCOURSE];
      count = T.count;
      cout<<count;
      for(int i = 0; i < count; i++)
        courses[i] = T.courses[i];
  }
  cout << "= Operator\n";
  return *this;
}

int main() {
  Transcript T1;
  Transcript T2( T1 );  // copy constructor
  Transcript T4 = T1 ;  // copy constructor
  Transcript T3;
  T3 = T1;      // assignment operator
  return 0;
}

