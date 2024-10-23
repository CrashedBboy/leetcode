#include <iostream>

using namespace std;

enum Sex {MAN, WOMAN};
enum Season {SPRING = 1, SUMMER = 2, FALL = 3, WINTER = 4};

int main() {

	Sex mySex = Sex::MAN;
	Season myFavoriteSeason = Season::SPRING;

	// to check its actual value
	cout << mySex << endl;
	cout << myFavoriteSeason << endl;

	return 0;
}