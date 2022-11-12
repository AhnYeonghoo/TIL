// 2021040016_�ȿ���

#include "Circle.h"
#include "string"

Circle::Circle(Position _center, double _radius) : center(_center), radius(_radius) {
	Type = "Circle";
	area = cal_area();
}
double Circle::cal_area() {
	return SQUARE(radius) * PI;
}

class Human {
	std::string name;
	int age;
	int health;
	int damage;
	int defense;
	
	public
		std::string getName() {
			return name;
		}
		
		int getAge() {
			return age;
		}
		
		int getHealth() {
			return health;
		}
		
		void setName(std::string name) {
			name = name;
		}

		void setAge(int age) {
			age = age;
		}

		void setHealth(int health) {
			health = health;
		}
		
		int getAttack() {
			std::cout << "Attack a Damage " << std::endl;
			return damage;
		}

		int getDefense() {
			std::cout << "Success Defense " << std::endl;
			return defense;
		}

	
		

	

		

}