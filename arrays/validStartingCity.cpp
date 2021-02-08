/*
 * Given an array of distances where each distance is the distance
 * to the next city and an array of fuel where each element indicates
 * the fuel in a city and mpg a car can travel. Find a valid city
 * from which the trip can start and circle all the cities and return
 * with zero or more gas to the starting point.
 */

#include <vector>
using namespace std;

bool hasCycle(int start,
							vector<int> &distances,
              vector<int> &fuel,
							int mpg)
{
	int count=0;
	int miles=0;
	int prev_miles=0;
	int cur=start;
	while(count<distances.size()){
		miles=fuel[cur]*mpg+prev_miles;
		if(miles<distances[cur]){
			return false;
		}
		prev_miles=miles-distances[cur];
		cur++;
		cur=cur%distances.size();
		count++;
	}
	return true;
}

//time O(N^2) and space O(1)
int validStartingCity(vector<int> distances, vector<int> fuel, int mpg) {
	//from each city check if the trip can circle and complete
	for(int i=0; i<distances.size(); i++){
		if(hasCycle(i, distances, fuel, mpg)){
			return i;
		}
	}
	return -1;
}

//based on greedy algorithm approach
//city with minimum miles remaining should be starting city
//so that all the available excess gas can be used to reach there
//time O(N) and space O(1)
int validStartingCity(vector<int> distances, vector<int> fuel, int mpg) {
	int milesRemaining = 0;
	int minMilesRemaining=0;
	int startingCity=0;
	for(int i=1; i<distances.size(); i++){
	  milesRemaining+=fuel[i-1]*mpg-distances[i-1];	
		if(milesRemaining<minMilesRemaining){
			minMilesRemaining=milesRemaining;
			startingCity=i;
		}
	}
	return startingCity;
}


