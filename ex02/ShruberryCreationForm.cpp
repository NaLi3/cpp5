/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:08:33 by ilevy             #+#    #+#             */
/*   Updated: 2025/06/27 16:02:47 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShruberryCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm( void ): AForm("ShruberryCreationForm-42_default", 145, 137), _target( "Default_target" ), _form_num( "42_default" )
{
    std::cout << BLUE << "Copy constructor called for: " << this->getName() \
    << "\nTarget is: " << this->_target \
    << "\nRequired Grade to sign it is: " << this->getSignGrade()\
    << "\nRequired Grade to execute it is: " << this->getExecGrade() << RESET << std::endl;
}

ShruberryCreationForm::ShruberryCreationForm( const std::string& target, const std::string& form_num ): AForm("ShruberryCreationForm-" + form_num, 145, 137), _target( target ), _form_num( form_num)
{
    std::cout << BLUE << "Parameterized constructor called for: " << this->getName() \
    << "\nTarget is: " << this->_target \
    << "\nRequired Grade to sign it is: " << this->getSignGrade()\
    << "\nRequired Grade to execute it is: " << this->getExecGrade() << RESET << std::endl;
}

ShruberryCreationForm::ShruberryCreationForm( const ShruberryCreationForm& copy ): AForm("ShruberryCreationForm-" + copy._form_num + "_copy", 145, 137), _target( copy._target ), _form_num( copy._form_num + "_copy")
{
    std::cout << BLUE << "Copy constructor called for: " << this->getName() \
    << "\nTarget is: " << this->_target \
    << "\nRequired Grade to sign it is: " << this->getSignGrade()\
    << "\nRequired Grade to execute it is: " << this->getExecGrade() << RESET << std::endl;
}

ShruberryCreationForm& ShruberryCreationForm::operator=( const ShruberryCreationForm& src )
{    
    (void) src;
    std::cout << BLUE << "Copy assignment operator called, assignation impossible for this class" << RESET << std::endl;
    return (*this);
}

ShruberryCreationForm::~ShruberryCreationForm( void ) 
{
    std::cout << RED << "Destructor called for: " << this->getName() << RESET << std::endl;
}

void    ShruberryCreationForm::performAction( void ) const
{
    std::string filename = this->_target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    
    outfile << "    #        #    " << std::endl;
    outfile << "   ###      ###   " << std::endl;
    outfile << "  #####    #####  " << std::endl;
    outfile << " #######  ####### " << std::endl;
    outfile << "    |        |    " << std::endl;
    outfile << "    |        |    " << std::endl;

    outfile.close();
}

const std::string   ShruberryCreationForm::getTarget( void ) const
{
    return (this->_target);
}

const std::string   ShruberryCreationForm::getFormNum( void ) const
{
    return (this->_form_num);
}
