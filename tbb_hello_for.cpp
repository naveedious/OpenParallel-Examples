#include <iostream>
#include "tbb/tbb.h"
#include <stdio.h>

using namespace std;
using namespace tbb;

class CountDown {
	public:
		void operator()(const blocked_range<int>& range) const {
			cout << "Starting Output\n";

			for (int i=range.end(); i != range.begin(); i--) {
				char temp[8];
				sprintf(temp, "%i\n", i);
				cout << temp;
				cout.flush();

				usleep(200);
			}

			cout << "Ending Output\n";

			usleep(500);
		}
};


int main()
{

	cout << "Hello World!" << endl; 


	CountDown cd;

	parallel_for(blocked_range<int>(0, 10000, 100), cd);

	return 0;
}
