/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:33:05 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/10 13:05:30 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {

private:
	std::string   _target;

	ShrubberyCreationForm();

public:
	ShrubberyCreationForm( const std::string& target );
	ShrubberyCreationForm( const ShrubberyCreationForm& src );
	~ShrubberyCreationForm();

	ShrubberyCreationForm&  operator=( ShrubberyCreationForm& rhs );

	void	execute( const Bureaucrat& executor ) const;

};

#endif