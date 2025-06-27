/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:04:24 by ilevy             #+#    #+#             */
/*   Updated: 2025/06/27 18:55:06 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# pragma once

# include <iostream>
# include <exception>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShruberryCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define BLUE "\033[34m"
# define RESET "\033[0m"

class AForm;
class Bureaucrat;

class Intern
{
	private:
			Intern( const Intern& copy );
			Intern& operator=( const Intern& src );
			
	public:
		AForm* makeForm( const std::string& formName, const std::string& target ) const ;
		Intern( void );
		~Intern( void );

		class UnknownFormNameException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif