/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:49:55 by ilevy             #+#    #+#             */
/*   Updated: 2025/06/28 15:41:54 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat( void ): _name("Default"), _grade(75)
{
	std::cout << GREEN << "Default constructor called for bureaucrat. Name is " << this->getName();
	std::cout << " and their grade is " << this->getGrade() << RESET << std::endl;
}

// Parameterized constructor
Bureaucrat::Bureaucrat( const std::string& new_name, int new_grade): _name(new_name)
{
	this->setGrade(new_grade);
	std::cout << GREEN << "Parameterized constructor called for bureaucrat. Name is " << this->getName() \
	<< " and their grade is " << this->getGrade() << RESET << std::endl;
}

//Copy constructor
Bureaucrat::Bureaucrat( const Bureaucrat& copy ):_name(copy.getName()), _grade(copy.getGrade())
{
	std::cout << GREEN << "Copy constructor called for bureaucrat. Name is " << this->getName() \
	<< " and their grade is " << this->getGrade() << RESET << std::endl;
}

//Copy assignment operator
Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& src )
{
	this->setGrade(src.getGrade());
	std::cout << GREEN << "Copy assignment operator called for bureaucrat." \
	<< "(Name cannot be changed from assignation, so name is " << this->getName() \
	<< " and their grade is " << this->getGrade() << RESET << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat( void )
{
	if (this->_grade >= 100)
		std::cout << MAGENTA << "Fired Bureaucrat " << this->getName() << ", useless leach.." RESET << std::endl;
	if (this->_grade >= 50 && this->_grade < 100)
		std::cout << MAGENTA << "Gave a letter of recommendation to Bureaucrat " << this->getName() << " good luck in the job search!" RESET << std::endl;
	if (this->_grade < 50)
		std::cout << MAGENTA << "Promoted Bureaucrat " << this->getName() << " to branch Manager!" << RESET << std::endl;
}

//Setter
void	Bureaucrat::setGrade( const int new_grade )
{
	try 
	{
		if (new_grade <= 150 && new_grade >= 1)
		{
			this->_grade = new_grade;
			std::cout << BLUE << "Set " << this->getName() << \
			"'s grade to " << this->getGrade() << RESET << std::endl;
		}
		else if (new_grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (new_grade < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch( Bureaucrat::GradeTooHighException& e )
	{
		std::cerr << e.what() << std::endl;;
		std::cerr << RED << "Clamping grade to 1" << RESET << std::endl;
		this->_grade = 1;
	}
	catch( Bureaucrat::GradeTooLowException& e )
	{
		std::cerr << e.what() << std::endl;;
		std::cerr << RED << "Clamping grade to 150" << RESET << std::endl;
		this->_grade = 150;
	}
}
//Getter
int	Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}
//Getter
std::string Bureaucrat::getName( void ) const
{
	return (this->_name);
}
//Increment (1 is the highest grade)
void	Bureaucrat::incrementGrade( void )
{
	try
	{
		if (this->_grade > 1)
		{
			this->_grade--;
			std::cout << BLUE << "Incremented bureaucrat " << this->getName() << "'s grade to " << this->getGrade() << "." << RESET << std::endl;

		}
		else
		{
			std::cerr << RED << "Incrementing bureaucrat " << this->getName() << "'s name is impossible." << RESET << std::endl;
			throw Bureaucrat::GradeTooHighException();
		}
	}
	catch( Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;;
	}
}
//Decrement (150 is the lowest grade)
void	Bureaucrat::decrementGrade( void )
{
	try
	{
		if (this->_grade < 150)
		{
			this->_grade++;
			std::cout << BLUE << "Decremented bureaucrat " << this->getName() << "'s grade to " << this->getGrade() << "." << RESET << std::endl;

		}
		else
		{
			std::cerr << RED << "Decrementing bureaucrat " << this->getName() << "'s grade is impossible." << RESET << std::endl;
			throw Bureaucrat::GradeTooLowException();
		}
	}
	catch( Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

//Exception class too low
const char* Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return (RED"Error: Grade too low"RESET);
}

//Exception class too high
const char* Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return (RED"Error: Grade too high"RESET);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bc)
{
	return (os << BLUE << bc.getName() << ", bureaucrat grade " << bc.getGrade() << "." << RESET << std::endl);
}
