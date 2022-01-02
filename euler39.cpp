/*
Integer right triangles
Problem 39
Published on 14 March 2003 at 06:00 pm [Server Time]

If p is the perimeter of a right angle triangle with integral length sides,
{a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?
*/

#include <cmath>
#include <iostream>
#include <string>
#include <vector>



class triplet
{
      public:
	int a;
	int b;
	int c;
	std::string getValues()
	{
		std::string temp = "{" + std::to_string(a) + " " + std::to_string(b) + " " +
		       std::to_string(c)+"}";
		return temp;
		
	}

	triplet(int _a, int _b, int _c)
	{
		a = _a;
		b = _b;
		c = _c;
		}
};

std::vector<std::vector<triplet>> solutionabc(100);



int valMax{1000};
bool logger = false;

bool isValidTriangle(int a, int b, int c)
{
	if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
		return true;
	}
	return false;
}

int CountSolutions(int p)
{
	//s = count of solutions
	int s = 0;
	for (int a = 1; a <= p / 2; a++) {

		// Optimizations:
		//  b = a to avoid double matches like:
		//  3 4 5
		//  4 3 5
		//  Only loop until half of p, no need to loop the other half,
		//  because of...reasons.
		for (int b = a; b <= p / 2; b++) {
			int c = sqrt(pow(a, 2) + pow(b, 2));
			if (a + b + c == p) {
				if (isValidTriangle(a, b, c)) {

					solutionabc[0].push_back(triplet(a,b,c));
					s++;
					if (logger) {
					printf("New triplet found! p = %d\t%s\n", p,solutionabc[0][solutionabc[0].size()-1].getValues().c_str());
					}
				}
			}
		}
	}

	return s;
}

int main(int argc, char *argv[])
{
	if (argc > 1) {
		valMax = atoi(argv[1]);
	}
	if (argc > 2) {
		logger = true;
	}
	
	int pMax = 0;
	int maxSolutions = 0;
	int solutions = 0;

	for (int p = 1; p <= valMax; p++) {
		solutions = CountSolutions(p);
		if (solutions > maxSolutions) {
			pMax = p;
			maxSolutions = solutions;
			solutionabc[1] = solutionabc[0];

		} else {
			solutionabc[0].clear();
		}
		
	}
	if (logger) {
		printf("p = %d\nsolutions = %d\n", pMax, maxSolutions);
for (int i = 0; i < solutionabc[1].size(); i++) {
			std::cout << solutionabc[1][i].getValues() << ' ';
		}
		printf("\n");
	} else {
		printf("%d\n", pMax);
	}
			

	return 0;
}
