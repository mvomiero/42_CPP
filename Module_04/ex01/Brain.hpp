/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:24:40 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/18 13:45:22 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
private:
	std::string _ideas[100];

public:
	Brain( void );
	Brain( const Brain& src );
	~Brain( void );

	Brain& operator=( const Brain& rhs );
	std::string getIdea( int n );
	void setIdea( int n, std::string idea );
};

#endif