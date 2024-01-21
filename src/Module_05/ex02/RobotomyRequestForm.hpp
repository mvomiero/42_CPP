/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:18:10 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/10 14:41:11 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string	_target;

	RobotomyRequestForm();

public:
	RobotomyRequestForm( const std::string& target );
	RobotomyRequestForm( const RobotomyRequestForm& src );
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=( RobotomyRequestForm& rhs );

	void	execute( const Bureaucrat& executor ) const;
};

#endif