/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:50:00 by ilevy             #+#    #+#             */
/*   Updated: 2025/04/09 14:09:58 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main( void )
{
	std::cout << "\n---------------EXERCICE 00: BUREAUCRATS--------------\n" << std::endl;
	std::cout << "\nThis module is meant to teach us about exceptions in c++ and programming in general." << std::endl;
	std::cout << "We know that programs are prone to bugs and errors for whatever reason may be. Whether it's a divide by 0, out of bounds, wrong type" << std::endl;
	std::cout << "We use exception classes and try/throw/catch loops in order to avoid problematic inputs and behaviors\n\n" << std::endl;
	std::cout << "I will show you an example with my exception class. Our bureaucrat (Named denis) cannot have a grade lower than 150." << std::endl;
	std::cout << "Let's see what happens when we break this rule and go out of bounds.\n\n" << std::endl;

	Bureaucrat Denis("Denis", 149);
	Denis.decrementGrade();

	std::cout << "\nHere I'm using a function called decrementGrade in order to lower his grade by 1" \
	"(150 is the worst.) Let's see what happens when we go over 150\n" << std::endl;
	Denis.decrementGrade();

	std::cout << "\nLet's do the opposite and have his colleague, Samantha, be too good at her job.\n" << std::endl;
	Bureaucrat Samantha("Samantha", 2);
	Samantha.incrementGrade();
	Samantha.incrementGrade();
	std::cout << "\nHere are Samantha and Denis' stats:\n" << Samantha << Denis << std::endl;
	std::cout << "Notice that they are stuck on the last available grade they could take, as the exception was caught," \
	"and therefore they didnt get invalid values.\n" << std::endl;

	std::cout << "\n------------------EXERCICE 01: FORMS-------------------\n" << std::endl;

	std::cout << "\nUsing the previous bureaucrats, let's now have them interact with another class: Forms!" << std::endl;
	std::cout << "Here we'll create three forms:\nA default form (using the default constructor)" << std::endl;
	std::cout << "A pikachu inspection form, using personalized parameters (you can change freely)" << std::endl;
	std::cout << "And a copy-kachu form, using copy constructor on the pikachu form\n\n" << std::endl;
	std::cout << "We'll also try to assign pikachu_inspection form's values to the default one, but nothing will happen. (forms cant be modified)" << std::endl;
	Form	default_form;
	Form	param_form("Pikachu_inspection", 1511, 42);
	Form	copykachu_form(param_form);
	default_form = param_form;
	std::cout << "\n" << std::endl;
	std::cout << default_form << std::endl;
	Denis.signForm(default_form);
	Samantha.signForm(default_form);
	Samantha.signForm(default_form);
	return (0);
}
