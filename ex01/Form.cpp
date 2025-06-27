/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:23:17 by ilevy             #+#    #+#             */
/*   Updated: 2025/04/09 14:08:22 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"
# include "Bureaucrat.hpp"

//Default constructor
Form::Form( void ): _name("Default form"), _requiredGradeSign(75), _requiredGradeExec(75), _signed(false)
{
	std::cout << GREEN << "Default constructor called for the form: " << this->getName() << \
	" with a required grade for signature: " << this->getSignGrade() << \
	" and for execution: " << this->getExecGrade() << RESET <<std::endl;
}

int Form::processGrade(int grade, bool isSignGrade) const
{
	try
	{
		if (grade < 1)
			throw (Form::GradeTooHighException());
		if (grade > 150)
			throw (Form::GradeTooLowException());
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << (isSignGrade ? "Sign_Grade " : "Exec_Grade ") \
		<< e.what() <<", clamping to 1." << std::endl;
		return (1);
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << (isSignGrade ? "Sign_Grade " : "Exec_Grade ") \
		<< e.what() <<", clamping to 150." << std::endl;
		return (150);
	}
	return (grade);
}


//Parameterized constructor
Form::Form( const std::string& new_name, int sign_grade, int exec_grade ): _name(new_name),\
	_requiredGradeSign(processGrade(sign_grade, true)),\
	_requiredGradeExec(processGrade(exec_grade, false)), _signed(false)
{
	std::cout << GREEN << "Parameterized constructor called for the form: " << this->getName() << \
	" with a required grade for signature: " << this->getSignGrade() << \
	" and for execution: " << this->getExecGrade() << RESET <<std::endl;
}

//Copy constructor
Form::Form( const Form& copy ): _name(copy._name),_requiredGradeSign(copy._requiredGradeSign), _requiredGradeExec(copy._requiredGradeExec), _signed(copy._signed)
{
	std::cout << GREEN << "Copy constructor called for the form: " << this->getName() << \
	" with a required grade for signature: " << this->getSignGrade() << \
	" and for execution: " << this->getExecGrade() << RESET <<std::endl;
}

//Copy assignment operator
Form&	Form::operator=( const Form& src )
{
	(void) src;
	std::cout << GREEN << "Copy assignment operator called. Nothing can be assigned" << RESET << std::endl;
	return (*this);
}

//Destructor
Form::~Form()
{
	std::cout << GREEN << "Default destructor called for the form: " << this->_name <<  RESET << std::endl;
}

std::string	Form::getName( void ) const
{
	return (this->_name);
}

int	Form::getExecGrade( void ) const
{
	return (this->_requiredGradeExec);
}

int	Form::getSignGrade( void ) const
{
	return (this->_requiredGradeSign);
}

bool Form::isSigned( void ) const
{
	return (this->_signed);
}

bool Form::beSigned( Bureaucrat& signer )
{
	try
	{
		if (this->isSigned() == true)
			std::cout << MAGENTA << "Bureaucrat named " << signer.getName() << " Cannot sign form named " << this->getName() << " because it is already signed" << RESET << std::endl;
		else if (this->_signed == false && signer.getGrade() > this->_requiredGradeSign)
		{
			std::cout << MAGENTA << "Bureaucrat named " << signer.getName() << " can't sign form named "\
			<< this->getName() << " with a sign grade of " << signer.getGrade() << " (Minimum grade required"\
			" is " << this->getSignGrade() << ")" << RESET << std::endl;
			throw(Form::GradeTooLowException());
		}
		else if (this->_signed == false && signer.getGrade() <= this->_requiredGradeSign)
		{
			this->_signed = true;
			std::cout << MAGENTA << "Bureaucrat named " << signer.getName() << " signed form named "\
			<< this->getName() << " with a sign grade of " << signer.getGrade() << " (Minimum grade required"\
			" is " << this->getSignGrade() << ")" << RESET << std::endl;
			return (true);
		}
		return(false);
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
		return (false);
	}
}

const char* Form::GradeTooLowException::what( void ) const throw()
{
	return( "Error: Grade too low");
}

const char* Form::GradeTooHighException::what( void ) const throw()
{
	return( "Error: Grade too high");
}

std::ostream& operator<<(std::ostream& os, const Form& fm)
{
	std::string var = "isn't signed";
	if (fm.isSigned() == true)
		var = "is signed";
	return (os << BLUE << fm.getName() << ", form sign_grade " << fm.getSignGrade() \
	<< ", form exec_grade " << fm.getExecGrade()\
	<< ", form sign status " << var << std::endl);
}
