/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:40:38 by mvomiero          #+#    #+#             */
/*   Updated: 2023/09/29 11:48:16 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern {

private:
	typedef struct	sFormList
			{
				std::string const &	formName;
				AForm *	(*function)(std::string const &);
			}	formList;

public:
	Intern();
	Intern( const Intern& src );
	~Intern();

	Intern& operator=( const Intern& rhs );

	AForm*   makeForm( std::string name, std::string target );
};