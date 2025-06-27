/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:23:14 by ilevy             #+#    #+#             */
/*   Updated: 2025/04/09 13:59:54 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define BLUE "\033[34m"
# define RESET "\033[0m"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_requiredGradeSign;
		const int			_requiredGradeExec;
		bool				_signed;
	public:
		//Constructors and destructor
		Form( void );
		Form( const std::string& new_name, const int sign_grade, const int exec_grade );
		Form( const Form& copy );
		Form& operator=( const Form& src );
		~Form( void );

		int					processGrade(int grade, bool whichGrade) const;
		//Getters
		std::string			getName( void ) const;
		int					getSignGrade( void ) const;
		int					getExecGrade( void ) const;
		bool				isSigned( void ) const;

		//Setter signed function
		bool	beSigned( Bureaucrat& signer );

		//Exception classes
		class GradeTooHighException
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &o, const Form &form);

#endif
