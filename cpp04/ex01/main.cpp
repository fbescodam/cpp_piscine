/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 07:54:15 by fbes          #+#    #+#                 */
/*   Updated: 2022/08/25 20:15:54 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int 	amount = 10;
	Animal*	animals[amount];
	int		i;

	for (i = 0; i < amount; i++) {
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	for (i = 0; i < amount; i++) {
		animals[i]->makeSound();
	}
	for (i = 0; i < amount; i++)
		delete animals[i];
	// system("leaks animals");
	return 0;
}
