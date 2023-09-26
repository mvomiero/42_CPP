/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <mvomiero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:02:07 by mvomiero          #+#    #+#             */
/*   Updated: 2023/09/26 17:06:27 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <cstdlib>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;

	Form();

public:
	Form( const std::string& name, int gradeToSign );
	Form( const std::string& name, int gradeToSign, int gradeToExecute );
	Form( const Form& src );
	~Form();

	Form&   operator=( const Form& rhs );

	std::string getName() const;
	bool		getSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	void		gradeRangeCheck();

	void		beSigned( const Bureaucrat& bureaucrat );

	/* EXCEPTIONS */
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream&	operator<<( std::ostream& o, const Form& rhs );

#endif