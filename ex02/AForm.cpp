/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:23:17 by ilevy             #+#    #+#             */
/*   Updated: 2025/04/10 17:36:16 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "Bureaucrat.hpp"

//Default constructor
AForm::AForm( void ): _name("Default AForm"), _requiredGradeSign(75), _requiredGradeExec(75), _signed(false)
{
	std::cout << GREEN << "Default constructor called for the AForm: " << this->getName() << \
	" with a required grade for signature: " << this->getSignGrade() << \
	" and for execution: " << this->getExecGrade() << RESET <<std::endl;
}

int AForm::processGrade(int grade, bool isSignGrade) const
{
	try
	{
		if (grade < 1)
			throw (AForm::GradeTooHighException());
		if (grade > 150)
			throw (AForm::GradeTooLowException());
	}
	catch(const AForm::GradeTooHighException& e)
	{
		std::cerr << (isSignGrade ? "Sign_Grade " : "Exec_Grade ") \
		<< e.what() <<", clamping to 1." << std::endl;
		return (1);
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << (isSignGrade ? "Sign_Grade " : "Exec_Grade ") \
		<< e.what() <<", clamping to 150." << std::endl;
		return (150);
	}
	return (grade);
}


//Parameterized constructor
AForm::AForm( const std::string& new_name, int sign_grade, int exec_grade ): _name(new_name),\
	_requiredGradeSign(processGrade(sign_grade, true)),\
	_requiredGradeExec(processGrade(exec_grade, false)), _signed(false)
{
	std::cout << GREEN << "Parameterized constructor called for the AForm: " << this->getName() << \
	" with a required grade for signature: " << this->getSignGrade() << \
	" and for execution: " << this->getExecGrade() << RESET <<std::endl;
}

//Copy constructor
AForm::AForm( const AForm& copy ): _name(copy._name),_requiredGradeSign(copy._requiredGradeSign), _requiredGradeExec(copy._requiredGradeExec), _signed(copy._signed)
{
	std::cout << GREEN << "Copy constructor called for the AForm: " << this->getName() << \
	" with a required grade for signature: " << this->getSignGrade() << \
	" and for execution: " << this->getExecGrade() << RESET <<std::endl;
}

//Copy assignment operator
AForm&	AForm::operator=( const AForm& src )
{
	(void) src;
	std::cout << GREEN << "Copy assignment operator called. Nothing can be assigned" << RESET << std::endl;
	return (*this);
}

//No Destructor because Aform is an abstract class
AForm::~AForm()
{
	// std::cout << GREEN << "Default destructor called for the AForm: " << this->_name <<  RESET << std::endl;
}

std::string	AForm::getName( void ) const
{
	return (this->_name);
}

int	AForm::getExecGrade( void ) const
{
	return (this->_requiredGradeExec);
}

int	AForm::getSignGrade( void ) const
{
	return (this->_requiredGradeSign);
}

bool AForm::isSigned( void ) const
{
	return (this->_signed);
}

bool AForm::beSigned( Bureaucrat& signer )
{
	try
	{
		if (this->isSigned() == true)
			std::cout << MAGENTA << "Bureaucrat named " << signer.getName() << " Cannot sign AForm named " << this->getName() << " because it is already signed" << RESET << std::endl;
		else if (this->_signed == false && signer.getGrade() > this->_requiredGradeSign)
		{
			std::cout << MAGENTA << "Bureaucrat named " << signer.getName() << " can't sign AForm named "\
			<< this->getName() << " with a sign grade of " << signer.getGrade() << " (Minimum grade required"\
			" is " << this->getSignGrade() << ")" << RESET << std::endl;
			throw(AForm::GradeTooLowException());
		}
		else if (this->_signed == false && signer.getGrade() <= this->_requiredGradeSign)
		{
			this->_signed = true;
			std::cout << MAGENTA << "Bureaucrat named " << signer.getName() << " signed AForm named "\
			<< this->getName() << " with a sign grade of " << signer.getGrade() << " (Minimum grade required"\
			" is " << this->getSignGrade() << ")" << RESET << std::endl;
			return (true);
		}
		return(false);
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
		return (false);
	}
}

void	AForm::execute( const Bureaucrat& executor ) const
{
	if (this->requirementChecker(executor) == true)
		this->performAction();
}

bool	AForm::requirementChecker( const Bureaucrat& executor ) const
{
	try
	{
		if (this->getName().find("RobotomyRequestForm") != std::string::npos \
		|| this->getName().find("ShruberryCreationForm") != std::string::npos \
		|| this->getName().find("PresidentialPardonForm") != std::string::npos)		
		{
			if (this->isSigned() == false)
				throw(AForm::UnsignedFormException());
			if (executor.getGrade() > this->_requiredGradeExec)
				throw(AForm::GradeTooLowException());
			return (true);
		}
		else
			throw(AForm::InvalidFormNameException());
	}
	catch(AForm::UnsignedFormException& e)
	{
		std::cerr << e.what() << std::endl;
		return (false);
	}
	catch(AForm::InvalidFormNameException& e)
	{
		std::cerr << e.what() << std::endl;
		return (false);
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
		return (false);
	}
}

void	AForm::performAction( void ) const
{
	
}

const char* AForm::GradeTooLowException::what( void ) const throw()
{
	return( "Error: Grade too low" );
}

const char* AForm::GradeTooHighException::what( void ) const throw()
{
	return( "Error: Grade too high" );
}

const char* AForm::UnsignedFormException::what( void ) const throw()
{
	return ( "Error: Form is unsigned" );
}

const char* AForm::InvalidFormNameException::what( void ) const throw()
{
	return ( "Error: Couldn't find form name");
}

std::ostream& operator<<(std::ostream& os, const AForm& fm)
{
	std::string var = "isn't signed";
	if (fm.isSigned() == true)
		var = "is signed";
	return (os << BLUE << fm.getName() << ", AForm sign_grade " << fm.getSignGrade() \
	<< ", AForm exec_grade " << fm.getExecGrade()\
	<< ", AForm sign status " << var << std::endl);
}
