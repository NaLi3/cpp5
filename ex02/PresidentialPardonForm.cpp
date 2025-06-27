/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:08:24 by ilevy             #+#    #+#             */
/*   Updated: 2025/06/27 18:46:10 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ): AForm("PresidentialPardonForm-42_default", 25, 5), _target( "Default_target" ), _form_num( "42_default" )
{
    std::cout << BLUE << "Copy constructor called for: " << this->getName() \
    << "\nTarget is: " << this->_target \
    << "\nRequired Grade to sign it is: " << this->getSignGrade()\
    << "\nRequired Grade to execute it is: " << this->getExecGrade() << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string& target, const std::string& form_num ): AForm("PresidentialPardonForm-" + form_num, 25, 5), _target( target ), _form_num( form_num)
{
    std::cout << BLUE << "Parameterized constructor called for: " << this->getName() \
    << "\nTarget is: " << this->_target \
    << "\nRequired Grade to sign it is: " << this->getSignGrade()\
    << "\nRequired Grade to execute it is: " << this->getExecGrade() << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& copy ): AForm("PresidentialPardonForm-" + copy._form_num + "_copy", 25, 5), _target( copy._target ), _form_num( copy._form_num + "_copy")
{
    std::cout << BLUE << "Copy constructor called for: " << this->getName() \
    << "\nTarget is: " << this->_target \
    << "\nRequired Grade to sign it is: " << this->getSignGrade()\
    << "\nRequired Grade to execute it is: " << this->getExecGrade() << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& src )
{
    (void) src;
    std::cout << BLUE << "Copy assignment operator called, assignation impossible for this class" << RESET << std::endl;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
    std::cout << RED << "Destructor called for: " << this->getName() << RESET << std::endl;
}

void    PresidentialPardonForm::performAction( void ) const
{
    std::cout << "The target of this form, " << this->getTarget() \
    << ", has been officially pardoned by our great president Zaphod Beeblebrox's two mouths" << RESET << std::endl;
}

const std::string   PresidentialPardonForm::getTarget( void ) const
{
    return (this->_target);
}

const std::string   PresidentialPardonForm::getFormNum( void ) const
{
    return (this->_form_num);
}