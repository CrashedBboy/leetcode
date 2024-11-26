#include <iostream>

using namespace std;

enum class Sex {MAN, WOMAN};
enum class Season {SPRING = 1, SUMMER = 2, FALL = 3, WINTER = 4};

int main() {

	Sex mySex = Sex::MAN;
	Season myFavoriteSeason = Season::SPRING;

	if (mySex == Sex::MAN) {
		cout << "It's a man!" << endl;

		// if (mySex == 0) {}  -> error!
		// values in enum class are not converted into other types
	}


	return 0;
}


/*

Use enum class for modern C++ code:
	Provides better type safety.
	Avoids naming conflicts.
	Explicit scoping improves code readability and maintainability.

*/