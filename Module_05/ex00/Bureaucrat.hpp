/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:13:41 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/09 12:38:02 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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

	/* EXCEPTIONS subclasses */
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Grade too high"; }
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Grade too low"; }
	};

};

std::ostream& operator<<( std::ostream& o, const Bureaucrat& rhs );

#endif