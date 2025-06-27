/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:08:31 by ilevy             #+#    #+#             */
/*   Updated: 2025/04/10 17:21:36 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <exception>
# include <cstdlib>

# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define BLUE "\033[34m"
# define RESET "\033[0m"

class RobotomyRequestForm:public AForm
{
    private:
        const std::string   _target;
        const std::string   _form_num;
 
    public:
        
        // Constructors, destructor and copy assignment operator
        RobotomyRequestForm( void );
        RobotomyRequestForm( const std::string& target, const std::string& form_num );
        RobotomyRequestForm( const RobotomyRequestForm& copy );
        RobotomyRequestForm& operator=( const RobotomyRequestForm& src );
        ~RobotomyRequestForm( void );
        
        void                performAction( void ) const;
        const std::string   getTarget() const;
        const std::string   getFormNum() const;
};

#endif