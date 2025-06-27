/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:08:29 by ilevy             #+#    #+#             */
/*   Updated: 2025/06/27 18:46:32 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ): AForm("RobotomyRequestForm-42_default", 72, 45), _target( "Default_target" ), _form_num( "42_default" )
{
    std::cout << BLUE << "Copy constructor called for: " << this->getName() \
    << "\nTarget is: " << this->_target \
    << "\nRequired Grade to sign it is: " << this->getSignGrade()\
    << "\nRequired Grade to execute it is: " << this->getExecGrade() << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string& target, const std::string& form_num ): AForm("RobotomyRequestForm-" + form_num, 72, 45), _target( target ), _form_num( form_num)
{
    std::cout << BLUE << "Parameterized constructor called for: " << this->getName() \
    << "\nTarget is: " << this->_target \
    << "\nRequired Grade to sign it is: " << this->getSignGrade()\
    << "\nRequired Grade to execute it is: " << this->getExecGrade() << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& copy ): AForm("RobotomyRequestForm-" + copy._form_num + "_copy", 72, 45), _target( copy._target ), _form_num( copy._form_num + "_copy")
{
    std::cout << BLUE << "Copy constructor called for: " << this->getName() \
    << "\nTarget is: " << this->_target \
    << "\nRequired Grade to sign it is: " << this->getSignGrade()\
    << "\nRequired Grade to execute it is: " << this->getExecGrade() << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& src )
{
    (void) src;
    std::cout << BLUE << "Copy assignment operator called, assignation impossible for this class" << RESET << std::endl;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
    std::cout << RED << "Destructor called for: " << this->getName() << RESET << std::endl;
}

void    RobotomyRequestForm::performAction( void ) const
{
    int robotomySuccessChance = rand() % 2;
    std::cout << "whirrrrrrRRRRRRRRRRRRRRR CHUNK-chunk-VRRRT!vvvvVRRRRRT-pt-pt-pt..." << std::endl;
    if (robotomySuccessChance % 2 == 0)
        std::cout << "After a long arduous process, target " << this->getTarget() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Unfortunately the Robotomy process failed, target " << this->getTarget() << " is still a human being" << std::endl;
}

const std::string   RobotomyRequestForm::getTarget( void ) const
{
    return (this->_target);
}

const std::string   RobotomyRequestForm::getFormNum( void ) const
{
    return (this->_form_num);
}