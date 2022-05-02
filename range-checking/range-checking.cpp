#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Entry{
  string name;
  int number;
};

template <typename T>
class Vec : public std::vector<T> {
public:
  using vector<T>::vector;           // use the constructor from vector (under the name Vec)

  T& operator[](int i){              // range check
    return vector<T>::at(i);
  }

  const T& operator[](int i) const { // range check const objects
    return  vector<T>::at(i);
  }
    
};

void checked(Vec<Entry> &book) {
  try {
    book[book.size()] = {"Joe Maloen",999999}; // will throw an exception
  }
  catch (out_of_range) {
    cerr << "range error!" << endl;
  }
}

////////////////////////////////////////////////////////////////////////////////
//
// MAIN FUNCTION
//
////////////////////////////////////////////////////////////////////////////////
int main()
{
  cout << "Prelude of output 1.." << endl;

  vector<Entry> book{{"Pepe Phone",654654}};
  int i = book[book.size()].number;
  cout << "Prelude of output 2.." << endl;
  cout << "Book Size: " << book.size() << endl;
  cout << "First Number: " << book[0].number << endl;
  cout << "Number: " << i << endl;

  Vec<Entry> book2{{"Pepe Phone",654654}};
  checked(book2);
  
  return 0;
}
