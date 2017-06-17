#include <iostream>
#include <vector>

using namespace std;

#define DEBUG

inline int max(int a, int b) { return (a > b ? a : b);}
inline int min(int a, int b) { return (a > b ? b : a);}
inline int abs(int a) {return (a > 0 ? a : -a); }

#ifdef DEBUG
string strDir[8] = {"eEast", "eNortheast", "eNorth", "eNorthwest", "eWest", "eSouthwest", "eSouth",	"eSoutheast"};
#endif

enum direction
{
	eEast,
	eNortheast,
	eNorth,
	eNorthwest,
	eWest,
	eSouthwest,
	eSouth,
	eSoutheast
};

struct coordinate
{
	int row, col;
};

int isInWay(const coordinate& queen, const coordinate& obstacle, int& distance)
{
	int direction = -1;

	if (queen.row == obstacle.row)
	{
		if(queen.col < obstacle.col){
			direction = eEast;
			distance = obstacle.col - queen.col;
		}
		else if (queen.col > obstacle.col){
			direction = eWest;
			distance = queen.col - obstacle.col;
		}
	}
	else if (queen.col == obstacle.col) {
		if(queen.row < obstacle.row){
			direction = eNorth;
			distance = obstacle.row - queen.row;
		}
		else if (queen.row > obstacle.row){
			direction = eSouth;
			distance = queen.row - obstacle.row;
		}
	}
	// diagonal case
	else if (abs(queen.col - obstacle.col) == abs(queen.row - obstacle.row)) {
		distance = abs(queen.col - obstacle.col);
		if (queen.row < obstacle.row) {
			if (queen.col < obstacle.col)
				direction = eNortheast;
			else
				direction = eNorthwest;
		}
		else {
			if (queen.col > obstacle.col)
				direction = eSouthwest;
			else
				direction = eSoutheast;
		}
	}

	return direction;
}

int main()
{

	int gridSize, numObstacles, retVal = 0;
	coordinate queen, obstacle;
	vector<int> maxDistFromObstacle(8);	

	cin >> gridSize >> numObstacles >> queen.row >> queen.col;

	// Initiate max distance as the distance from queen to grid edge
	
	//	BUG IN INITIATION. TO FIX THIS, PURCHASED INPUT.TXT
	/*
	maxDistFromObstacle[eEast] = gridSize - queen.row;
	maxDistFromObstacle[eNorth] = gridSize - queen.col;
	maxDistFromObstacle[eWest] = queen.row - 1;
	maxDistFromObstacle[eSouth] = queen.col - 1;
	*/
	maxDistFromObstacle[eEast] = gridSize - queen.col;
	maxDistFromObstacle[eNorth] = gridSize - queen.row;
	maxDistFromObstacle[eWest] = queen.col - 1;
	maxDistFromObstacle[eSouth] = queen.row - 1;

	// diagonal distance is equal to the min of horizontal and vertical distance
	maxDistFromObstacle[eNortheast] = min(maxDistFromObstacle[eEast], 	maxDistFromObstacle[eNorth]);
	maxDistFromObstacle[eNorthwest] = min(maxDistFromObstacle[eNorth], 	maxDistFromObstacle[eWest]);
	maxDistFromObstacle[eSouthwest] = min(maxDistFromObstacle[eWest], 	maxDistFromObstacle[eSouth]);
	maxDistFromObstacle[eSoutheast] = min(maxDistFromObstacle[eSouth], 	maxDistFromObstacle[eEast]);

	#ifdef DEBUG
	for(int i = 0 ; i < 8 ; ++i) {
		cout << strDir[i] << " " << maxDistFromObstacle[i] << endl;
	}
	#endif

	for (int i = 0; i < numObstacles; ++i)
	{
		int direction, distance;
		cin >> obstacle.row >> obstacle.col;

		direction = isInWay(queen, obstacle, distance);
		if (direction >= 0 && distance > 0)
		{
			maxDistFromObstacle[direction] = min(maxDistFromObstacle[direction], distance - 1);
			#ifdef DEBUG
				cout << "obs " << obstacle.row << " " << obstacle.col << " " << strDir[direction] << " " << distance << endl;
			#endif
		}
	}
	#ifdef DEBUG
		cout << endl << endl;
	#endif

	for(int i = 0 ; i < 8 ; ++i) {
		retVal += maxDistFromObstacle[i];

		#ifdef DEBUG
			cout << strDir[i] << " " << maxDistFromObstacle[i] << endl;
		#endif
	}
	cout << retVal << endl;
}