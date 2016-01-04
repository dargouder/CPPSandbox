/* This demonstrates the diamond problem created when multiple inheritance is implemented incorrectly. This is and proposes a solution to it */
#pragma once
#include <iostream>
class Animal {
private:
	int weight;
public:
	Animal() : weight(0) {}
	Animal(int p_weight) : weight(p_weight) {
		std::cout << "Animal::Animal(int ) is called" << std::endl;
	}
	int GetWeight() const {
		return weight;
	}
};

class TigerWrong : public Animal {
public:
	TigerWrong(int p_weight) : Animal(p_weight) {
		std::cout << "Animal::Animal(int ) is called" << std::endl;
	}
};

class LionWrong : public Animal {
public:
	LionWrong(int p_weight) : Animal(p_weight) {
		std::cout << "Animal::Animal(int ) is called" << std::endl;
	}
};

class LigerWrong : public TigerWrong, public LionWrong {
public:
	LigerWrong(int p_weight) : TigerWrong(p_weight), LionWrong(p_weight) {
		std::cout << "Animal::Animal(int ) is called" << std::endl;
	}

};

class Tiger : virtual public Animal {
public:
	Tiger(int p_weight) : Animal(p_weight) {
		std::cout << "Animal::Animal(int ) is called" << std::endl;
	}

};

class Lion : virtual public Animal {
public:
	Lion(int p_weight) : Animal(p_weight) {
		std::cout << "Animal::Animal(int ) is called" << std::endl;
	}

};

class Liger : public Tiger, public Lion {
public:
	Liger(int p_weight) : Tiger(p_weight), Lion(p_weight) {
		std::cout << "Animal::Animal(int ) is called" << std::endl;
	}

};

void TestDiamondProblem() {
	/* This will call the animal constructor twice*/
	LigerWrong lg(10);

	/*	
	this will give out a compiler error because it is ambiguous
	int weight = lg.GetWeight();
	*/

	/* Calls animal constructor once*/
	Liger lg2(10);
	/* no compiler error - no longer ambiguous */
	int weight = lg2.GetWeight();


}