/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedPro.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:52:56 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/26 13:37:24 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDPRO_HPP
#define SEDPRO_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>

class SedPro
{
private:
	std::string _inFile;
	std::string _outFile;

public:
	SedPro( std::string filename);
	~SedPro();

	void	replace( std::string s1, std::string s2);
};

#endif