/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:50:00 by ilevy             #+#    #+#             */
/*   Updated: 2025/06/27 16:01:19 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main( void )
{
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
	return (0);
}
