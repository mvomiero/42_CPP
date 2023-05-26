/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:59:23 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/26 14:07:03 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>


class   Harl
{
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );


/* public:
	Harl();
	~Harl(); */
public:
	void	complain( std:: string level );

};

typedef void (Harl::*t_func) ( void );