/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:50:00 by ilevy             #+#    #+#             */
/*   Updated: 2025/04/11 10:11:55 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main( void )
{
	srand(time(0));
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

	std::cout << "\n------------------EXERCICE 02: SpecificFormS-------------------\n" << std::endl;

	std::cout << "Here we've created different forms based on the base abstract class AForm." << std::endl;
	std::cout << "Below are a few tests to see how the forms work." << std::endl;
	ShruberryCreationForm default_SCForm;
	Samantha.signAForm(default_SCForm);
	Samantha.executeForm(default_SCForm);
	std::cout << "\n\nHere Samantha signed and created a .txt file named \"42_default\" containing an ASCII tree" << std::endl;
	std::cout << "Let's try again with another, but this time have Denis try it.\n\n" << std::endl;
	ShruberryCreationForm default_SCForm2;
	Denis.signAForm(default_SCForm2);
	Samantha.executeForm(default_SCForm2);
	Denis.executeForm(default_SCForm);
	std::cout << "\n\nLet's try the other forms too, including the random chance robotomy one first" << std::endl;
	std::cout << "This form when executed will begin a procedure upon the target that will succeed with a 50% chance." << std::endl;
	std::cout << "Therefore, when we execute the program multiple times, the amount of times the procedure succeeds should be equal to the amount of failures (on average)" << std::endl;
	RobotomyRequestForm param_rrform("Corrector", "4444");
	Samantha.signAForm(param_rrform);
	for (int i = 0; i < 10; i++)
		Samantha.executeForm(param_rrform);
	std::cout << "\n\nAnd the last one is a presidential pardon, where the target will be pardonned by the most electable president in the whole Galaxy." << std::endl;
	PresidentialPardonForm param_ppform("Corrector", "1");
	Samantha.signAForm(param_ppform);
	Samantha.executeForm(param_ppform);
	return (0);
}
