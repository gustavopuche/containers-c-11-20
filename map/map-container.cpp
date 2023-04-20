#include <iostream>
#include <map>
#include <unordered_map>

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

struct Ehash {
  size_t operator()(const Entry& e) const {
    return hash<string>()(e.name) ^ hash<int>()(e.number);
  }
};

////////////////////////////////////////////////////////////////////////////////
//
// MAIN FUNCTION
//
////////////////////////////////////////////////////////////////////////////////
int main()
{
  string fileName = "./ProcessRoot_g";

  std::size_t pos = fileName.find("./");

  if (pos == 0)
  {
    cout << "result: " << fileName.substr(2,fileName.length()) << endl;
  }
  else
  {
    cout << " Attention POS != 0" << endl;
  }

  map<string,int> phone_book {
    {"David Fist",123321},
    {"Eva Sec",453432},
    {"Karl Magn",654456},
    {"Betty Davis",987678}
  };

  cout << "Eva number:" << phone_book["Eva Sec"] << endl;
  if (phone_book.find("Gustavo") == phone_book.end())
  {
    cout << "Gustavo NOT FOUND!!!" << endl;
  }
  else
  {
    cout << "Gustavo found..." << endl;
  }

  unordered_map<string,int> phone_book2 {
    {"David Fist",123321},
    {"Eva Sec",453432},
    {"Karl Sagan",654456},
    {"Betty Davis",987678}
  };

  cout << "Karl Sagan Number:" << phone_book2["Karl Sagan"] << endl;

  Entry e1{"Peco Teco",555443};
  Entry e2{"Ges Eco",342675};
  Ehash ef;
  cout << "Hash funciton e1:" << ef(e1) << endl;
  cout << "Hash funciton e2:" << ef(e2) << endl;
  return 0;
}
