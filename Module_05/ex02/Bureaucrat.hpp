/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:13:41 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/10 13:48:13 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"
#include "colors.h"

class AForm;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

	Bureaucrat();

public:
	Bureaucrat( const std::string& name, int grade );
	Bureaucrat( const Bureaucrat& src );
	~Bureaucrat();

	Bureaucrat& operator=( const Bureaucrat& rhs );

	std::string	getName() const;
	int			getGrade() const;

	void		incrementGrade();
	void		decrementGrade();

	void		gradeRangeCheck();

	void		signForm( AForm& AForm );

	void		executeForm( const AForm& form ) const;  


	/* EXCEPTIONS subclasses 
		they are all derived from std::exception
	*/
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw(); // throw() is actually just for older versions of cpp
				// declared virtual in case you need to overwrite if you ever make subclasses
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

};

std::ostream& operator<<( std::ostream& o, const Bureaucrat& rhs );

#endif