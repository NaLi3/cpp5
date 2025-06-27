/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:08:35 by ilevy             #+#    #+#             */
/*   Updated: 2025/04/10 17:21:39 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <exception>
# include <fstream>

# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define BLUE "\033[34m"
# define RESET "\033[0m"

class ShruberryCreationForm: public AForm
{
    private:
    
        const std::string   _target;
        const std::string   _form_num;

    public:
        
        // Constructors, destructor and copy assignment operator
        ShruberryCreationForm( void );
        ShruberryCreationForm( const std::string& target, const std::string& form_num );
        ShruberryCreationForm( const ShruberryCreationForm& copy );
        ShruberryCreationForm& operator=( const ShruberryCreationForm& src );
        ~ShruberryCreationForm( void );

        void                performAction( void ) const;
        const std::string   getTarget() const;
        const std::string   getFormNum() const;
};

#endif

