#include <iostream>
#include <string>

using namespace std;

class Person {

public:

	// Constructor Overlading (Polymorphism)
	Person() : name(""), age(0) {}
	Person(string name, int age): name(name), age(age) {}

	// getter
	string getName() { return name; }
	int getAge() { return age; }

	// setter
	void setName(string newName) {
		if (!newName.empty()) {
			name = newName;
		}
	}
	void setAge(int newAge) {
		if (newAge >= 0) {
			age = newAge;
		}
	}

protected:
	// Encapsulation:
	// 1. Hide the data inside the object & make it unaccessible outside the class
	// 2. Provide public getter & setter function for these private member attributes
	string name;
	int age;
};

class Teacher : public Person {

public:
	// Constructors which inherit the constructor of parent class
	Teacher(string name, int age, string subject) : Person(name, age), subject(subject) { }
	Teacher(string name, int age) : Person(name, age), subject("") {}
	Teacher() : Person(), subject("") {}

	// getter
	string getSubject() {
		return subject;
	}

	// setter
	void setSubject(string newSubject) {
		if (!newSubject.empty()) {
			subject = newSubject;
		}
	}

	// Operator Overloading
	Teacher operator+ (Teacher& a) {
		return Teacher(
			this->getName() + "," + a.getName(),
			this->age,
			this->getSubject()+","+a.getSubject()
		);
	}
	bool operator> (Teacher& a) {
		if (this->age > a.age) {
			return true;
		}
		else {
			return false;
		}
	}

protected:
	string subject;
};

int main() {

	Teacher a("Justin", 18, "Math");
	Teacher b("Austin", 25, "Math");

	if (b > a) {
		cout << b.getName() << " is bigger than " << a.getName() << endl;
	}

	Teacher c = a + b;
	cout << c.getSubject() << endl;

	return 0;
}