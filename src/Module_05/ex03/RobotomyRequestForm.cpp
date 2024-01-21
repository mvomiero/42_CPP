/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:18:00 by mvomiero          #+#    #+#             */
/*   Updated: 2023/09/29 11:27:33 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target ) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src ) : AForm(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&    RobotomyRequestForm::operator=( RobotomyRequestForm& rhs ) {
	(void)rhs;
	return *this;
}

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if ( this->getSigned() == false )
		throw AForm::NotSignedException();
	else if ( executor.getGrade() > this->getGradeToExecute() )
		throw AForm::GradeTooLowException();
	else {
		std::cout << YELLOW "\n🎇* !!!===//... drilling noises... tunz tunz tunz !!! ===??? *\n" RESET << std::endl;
		static int  i;
		if ( i % 2 == 0 )
			std::cout << GREEN "BZZZZZT! " << _target << " has been robotomized!" RESET << std::endl;
		else
			std::cout << RED "Robotomy failed! " << _target << " is still alive." RESET << std::endl;
		i++;
	}
}