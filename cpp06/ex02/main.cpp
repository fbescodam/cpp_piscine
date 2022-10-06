/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:42:22 by fbes          #+#    #+#                 */
/*   Updated: 2022/10/06 16:00:29 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	int r = rand() % 3;
	switch (r)
	{
		case 0:
			return (dynamic_cast<Base*>(new A()));
		case 1:
			return (dynamic_cast<Base*>(new B()));
		default:
			std::cerr << "[WARNING] Random number was not between 0, 1 or 2!" << std::endl;
		case 2:
			return (dynamic_cast<Base*>(new C()));
	}
}

void identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);

	std::cout << "Identifying by pointer...   ";
	if (a)
		std::cout << "A" << std::endl;
	else if (b)
		std::cout << "B" << std::endl;
	else if (c)
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	std::cout << "Identifying by reference... ";
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (...) { }
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (...) { }
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (...) { }
}

int main(void)
{
	Base*	base;
	for (int i = 0; i < 10; i++)
	{
		base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
	return (0);
}