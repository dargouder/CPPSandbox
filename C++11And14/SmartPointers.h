#pragma once
#include <memory>
#include <iostream>

class A {
public:
	int x, y, z;

	A(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {

	}
};

class B {
public:
	std::unique_ptr<A> p_a;

	B() {
		p_a = std::make_unique<A>(0, 0, 0);

	}
	B(int x, int y, int z) {
		p_a = std::make_unique<A>(x,y,z);
		
	}
};

void DoStuff(B& b) {
	B temp(1,2,3);

	/* We have to use std::move to change the object that b owns. The standard states that since the previous memory area owned by b is no longer being pointed to, it is deleted;
	*/
	b = std::move(temp);

}

std::unique_ptr<A> GetUniquePtrViaMove() {
	return std::move(std::make_unique<A>(4, 5, 6));
}

std::unique_ptr<A> GetUniquePtr() {
	return std::make_unique<A>(4, 5, 6);
}

void TestUniquePtrMove() {
	/* create b which calls its default constructor and it's member object p_a of type A is allocated using a unique pointer. */
	B b;

	/* DoStuff will create a temporary object of type B, initialised with different Values than b. */
	DoStuff(b);
	
	std::cout << b.p_a->x << "\t" << b.p_a->y << "\t" << b.p_a->z << std::endl;

	std::shared_ptr<A> c = std::make_shared<A>(0, 0, 0);
	/* this demonstrates that the size of a shared pointer is twice the size of a unique ptr. */
	std::cout <<" Size of unique ptr b.p_a: "<< sizeof(b.p_a) << std::endl;
	std::cout << " Size of unique ptr c: " << sizeof(c) << std::endl;

	std::unique_ptr<A> d = GetUniquePtr();

	std::cout << "Unique ptr d " <<"\t" << d->x << "\t" << d->y << "\t" << d->z << std::endl;

}