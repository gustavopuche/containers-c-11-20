#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <time.h>

using namespace std;
using std::vector;

template <typename T>
void exercise(int size, string commonname)
{
	T v;
	typedef typename T::value_type t_value;
	t_value res1("starting entry");
	v.push(res1);

	for (int i = 0; i < size; i++)
	{
		int r = (int) rand();
		string s;
		int ss = r % 100;
		s.reserve(ss);
		generate_n(back_inserter(s), ss, [ss](){return (char)('a' + ss/2);});
		t_value res(s);

    v.push(s);
	}

  for (int i = 0; i < v.size(); i++)
  {
    v.pop();
  }
}

int main()
{
	const int size = 1000000;

	cout << "Running queue with deque and list of " << size << " elements" << endl;

	struct timespec ctr1;
	struct timespec ctr2;

	clock_gettime(CLOCK_MONOTONIC, &ctr1);

	exercise<queue<string>>(size, "queue<string,deque<string>>");

	// Final time
	clock_gettime(CLOCK_MONOTONIC, &ctr2);

  cout << "start time sec  : " << ctr1.tv_sec << endl;
  cout << "start time: nsec: " << ctr1.tv_nsec << endl;

	double time = ((double)((ctr2.tv_sec*1000.0 + ctr2.tv_nsec/1000000.0) -(ctr1.tv_sec*1000.0 + ctr1.tv_nsec/1000000.0)));
	cout << "queue with deque time (ms): " << time << endl;

	// Init time
	clock_gettime(CLOCK_MONOTONIC, &ctr1);


	exercise<queue<string,list<string>>>(size, "queue<string,list<string>>");

	// Final time
	clock_gettime(CLOCK_MONOTONIC, &ctr2);

	time = ((double)((ctr2.tv_sec*1000.0 + ctr2.tv_nsec/1000000.0) -(ctr1.tv_sec*1000.0 + ctr1.tv_nsec/1000000.0)));
	cout << "queue with list time (ms): " << time << endl;

	return 0;
}
