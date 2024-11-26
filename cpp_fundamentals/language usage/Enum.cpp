#include <iostream>

using namespace std;

enum Gender {MAN, WOMAN};
enum Season {SPRING = 1, SUMMER = 2, FALL = 3, WINTER = 4};

int main() {

	Gender myGender = Gender::MAN;
	Season myFavoriteSeason = Season::SPRING;

	// to check its actual value
	cout << myGender << endl;
	cout << myFavoriteSeason << endl;

	return 0;
}