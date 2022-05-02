#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Entry{
  string name;
  int number;
};


// Define output format.
ostream &operator<<(ostream &os, const Entry &e) {
  return os << "{\"" << e.name << "\", " << e.number << "}";
}

// Define input format.
istream &operator>>(istream &is, Entry &e) {
  char c, c2;
  if (is>>c && c=='{' && is>>c2 && c2=='"'){ // starts with a {"
    string name;                             // the default value of a string is the empty string: ""
    while (is.get(c) && c!='"')              // anything before a " is part of the name.
      name+=c;

    if (is>>c && c==','){
      int number = 0;
      if (is>>number>>c && c=='}'){          // read the number and a }
	e = {name,number};                   // assign to the entry
	return is;
      }
    }
  }
  is.setstate(ios_base::failbit); // register the failure in the stream.
  return is;
}

// Print phone book.
void print_book(const vector<Entry>& book)
{
  for (const auto& x : book)
  {
    cout << x << endl;
  }			    
}

// Insert new element.
void input(vector<Entry>& book) {
  for (Entry e; cin>>e;)
    book.push_back(e);
}

////////////////////////////////////////////////////////////////////////////////
//
// MAIN FUNCTION
//
////////////////////////////////////////////////////////////////////////////////
int main()
{

  vector<Entry> phone_book = {
    {"Pepe Phone",123456},
    {"Iron Man",234567},
    {"Betty Davis",345678}
  };

  print_book(phone_book);

  cout << "Size: " << phone_book.size() << endl;
  cout << "Capacity: " << phone_book.capacity() << endl;
  
  // input(phone_book);
  // print_book(phone_book);
  
  return 0;
}
