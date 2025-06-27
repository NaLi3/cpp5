/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:49:58 by ilevy             #+#    #+#             */
/*   Updated: 2025/04/04 13:15:26 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define BLUE "\033[34m"
# define RESET "\033[0m"

class Bureaucrat
{
	private:
		const	std::string _name;
		int					_grade;
	public:
		//Constructors, assignment operator and destructor
		Bureaucrat( void );
		Bureaucrat( const std::string& new_name, int new_grade );
		Bureaucrat( const Bureaucrat& copy );
		Bureaucrat& operator=( const Bureaucrat& src );
		~Bureaucrat( void );
		
		//Getters
		std::string	getName( void ) const;
		int			getGrade( void ) const;
		
		//Setter
		void		setGrade( const int new_grade );
		
		//Modifiers
		void		incrementGrade( void );
		void		decrementGrade( void );

		//Exception classes
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& bc);
};

#endif
