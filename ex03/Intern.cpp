/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:07:57 by ilevy             #+#    #+#             */
/*   Updated: 2025/06/27 19:02:51 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void )
{
	std::cout << GREEN << "Employed some random Intern" << RESET << std::endl;
}

Intern::~Intern( void )
{
	std::cout << GREEN << "Let some random Intern go" << RESET << std::endl;
}

Intern::Intern( const Intern& copy )
{
	std::cout << "Nothing to learn from one Intern to another" << std::endl;
	(void) copy;
}

Intern& Intern::operator=( const Intern& src )
{
	std::cout << "Nothing to learn from one Intern to another" << std::endl;
	(void) src;
	return (*this);
}

static AForm*	president( const std::string target )
{
	return (new PresidentialPardonForm(target));
}

static AForm*	robot( const std::string target )
{
	return (new RobotomyRequestForm(target));
}

static AForm*	shrub( const std::string target )
{
	return (new ShruberryCreationForm(target));
}

AForm* Intern::makeForm( const std::string& formName, const std::string& target ) const
{
	AForm* (*forms[])(const std::string possible_names) = {&president, &robot, &shrub};
	std::string possible_forms[] = {"presidential pardon", "robotomy request", "shruberry creation"};

	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (possible_forms[i] == formName)
			{
				std::cout << "Intern creates " << formName << " now" << std::endl;
				return (forms[i](target));
			}
		}
		throw Intern::UnknownFormNameException();
	}
	catch(const Intern::UnknownFormNameException& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
}

const char*	Intern::UnknownFormNameException::what( void ) const throw()
{
	return (RED "Error: Unknown form name, form cannot be created." RESET);
}
