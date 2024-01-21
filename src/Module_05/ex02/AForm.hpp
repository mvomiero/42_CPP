/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:02:07 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/10 12:06:39 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;

	AForm();

public:
	AForm( const std::string& name, int gradeToSign );
	AForm( const std::string& name, int gradeToSign, int gradeToExecute );
	AForm( const AForm& src );
	virtual ~AForm();

	AForm&   operator=( const AForm& rhs );

	std::string getName() const;
	bool		getSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	void		gradeRangeCheck();

	void		beSigned( const Bureaucrat& bureaucrat );

	virtual void	execute( const Bureaucrat& executor ) const = 0;


	/* EXCEPTIONS */
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class NotSignedException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream&	operator<<( std::ostream& o, const AForm& rhs );

#endif