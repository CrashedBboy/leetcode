#include <iostream>
#include <string>

using namespace std;

class Person {

public:

	// Constructor Overlading (Polymorphism)
	Person() : name(""), age(0) {}
	Person(string name, int age): name(name), age(age) {}

	// for runtime polymorphism
	virtual void introduce() {
		cout << "I'm a person caleld " << name << endl;
	}

	// pure virtual function: there is no meaningful definition you could give for the function in the base class.
	// we can use pure virtual function to define abstract class -> define interface!
	virtual void quit() = 0;

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

	// runtime polymorphism
	void introduce() {
		cout << "I'm a teacher " << name << " who teaches " << subject << endl;
	}

	// We have to implement the abstract function from base class
	void quit() {
		cout << "I don't want to teach anymore!" << endl;
	}

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

class Engineer : public Person {
	public:
		Engineer(string name, int age, string language): Person(name, age), language(language) {}
		Engineer(string name, int age): Person(name, age), language("") {}
		Engineer(): Person(), language("") {}

		// runtime polymorphism
		void introduce() {
			cout << "I'm a engineer called " << name << " who uses " << language << endl;
		}

		// We have to implement the abstract function from base class
		void quit() {
			cout << "I don't want to write code anymore!" << endl;
		}

		// getter
		string getLanguage() {
			return language;
		}

		// setter
		void setLanguage(string lan) {
			if (!lan.empty()) {
				language = lan;
			}
		}

	private:
		string language;
};

int main() {

	Engineer me ("Austin", 25, "C++");
	Teacher you ("Justin", 23, "Math");

	return 0;
}