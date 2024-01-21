/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:41:13 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/10 13:42:18 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;

	PresidentialPardonForm();

public:
	PresidentialPardonForm( const std::string& target );
	PresidentialPardonForm( const PresidentialPardonForm& src );
	~PresidentialPardonForm();

	PresidentialPardonForm& operator=( const PresidentialPardonForm& rhs );
	
	void execute( const Bureaucrat& executor ) const;
};

#endif