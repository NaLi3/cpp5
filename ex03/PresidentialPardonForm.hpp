/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:08:26 by ilevy             #+#    #+#             */
/*   Updated: 2025/06/27 18:38:15 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <exception>

# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define BLUE "\033[34m"
# define RESET "\033[0m"

class PresidentialPardonForm:public AForm
{
    private:
        const std::string   _target;
        const std::string   _form_num;
    public:
        
        // Constructors, destructor and copy assignment operator
        PresidentialPardonForm( void );
        PresidentialPardonForm( const std::string& target, const std::string& form_num );
		PresidentialPardonForm( const std::string& target );
        PresidentialPardonForm( const PresidentialPardonForm& copy );
        PresidentialPardonForm& operator=( const PresidentialPardonForm& src );
        ~PresidentialPardonForm( void );

        void                performAction( void ) const;
        const std::string   getTarget() const;
        const std::string   getFormNum() const;
};

#endif