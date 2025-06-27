/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:23:14 by ilevy             #+#    #+#             */
/*   Updated: 2025/04/10 17:17:36 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AForm_HPP
# define AForm_HPP

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

class AForm
{
	private:
		const std::string	_name;
		const int			_requiredGradeSign;
		const int			_requiredGradeExec;
		bool				_signed;
	public:
		//Constructors and destructor
		AForm( void );
		AForm( const std::string& new_name, const int sign_grade, const int exec_grade );
		AForm( const AForm& copy );
		AForm& operator=( const AForm& src );
		virtual ~AForm( void ) = 0;

		int					processGrade(int grade, bool whichGrade) const;
		//Getters
		std::string			getName( void ) const;
		int					getSignGrade( void ) const;
		int					getExecGrade( void ) const;
		bool				isSigned( void ) const;

		//Setter signed function
		bool				beSigned( Bureaucrat& signer );

		// Executor function
		void				execute( const Bureaucrat& executor ) const;
		
		// Requirement checker class;
		bool				requirementChecker( const Bureaucrat& executor ) const ;
		virtual void		performAction( void ) const = 0;

		//Exception classes
		class GradeTooHighException:public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException:public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class UnsignedFormException:public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class InvalidFormNameException:public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &o, const AForm &AForm);

#endif
