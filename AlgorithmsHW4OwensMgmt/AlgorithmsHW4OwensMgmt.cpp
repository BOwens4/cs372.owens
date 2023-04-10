//This problem will implement the two functions we made for convex hull by brute force and by divide and conquer
// It will solve a problem involving conservation management
//Braden Owens
//2/27/23
//Algorithms Assignment 04
#include <iostream>
#include <utility>
#include <vector>
#include<set>
using namespace std;
using namespace std;
vector<int>Point;
pair<double, double>
vector<Point>& convexHullByBruteForce(vector<Point>& pointsVector)
{
	set<pair<double, double>>set;
	int pos = 0;
	int neg = 0;
	for (int a = a + 1; a < pointsVector.size(); a++)
	{
		for (int b = b + 1; b < pointsVector.size(); b++)
		{
			int x1 = pointsVector[a].first;
			int x2 = pointsVector[b].first;
			int y1 = pointsVector[a].second;
			int y2 = pointsVector[b].second;
			int a1 = y1 - y2;
			int b1 = x2 - x1;
			int c1 = x1 * y2 - y1 * x2;

		}
	}
}
vector<Point>& convexHullByDandC(vector<Point>& pointsVector)
{

}
int main()
{
	cout << "This problem will solve a convex hull problem by brute force and divide and conquer" << endl;
	cout << "It will use this to find the home range of a population of wildlife" << endl;
	return 0;
}
