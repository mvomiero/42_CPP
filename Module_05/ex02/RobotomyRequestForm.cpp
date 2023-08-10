/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:18:00 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/10 14:40:56 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target ) : AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src ) : AForm(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&    RobotomyRequestForm::operator=( RobotomyRequestForm& rhs ) {
	_target = rhs._target; 
	return *this;
}

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	std::cout << YELLOW "\n🎇* !!!===//... drilling noises... tunz tunz tunz !!! ===??? *\n" RESET << std::endl;
	if ( this->getSigned() == false )
		throw AForm::NotSignedException();
	if ( executor.getGrade() > this->getGradeToExecute() )
		throw AForm::GradeTooLowException();
	else {
		static int  i;
		if ( i % 2 == 0 )
			std::cout << GREEN "BZZZZZT! " << _target << " has been robotomized!" RESET << std::endl;
		else
			std::cout << RED "Robotomy failed! " << _target << " is still alive." RESET << std::endl;
		i++;
	}
}