/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedPro.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:52:48 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/26 19:05:26 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedPro.hpp"

SedPro::SedPro(std::string filename) : _inFile(filename), _outFile(filename + ".replace"){
}

SedPro::~SedPro ( void ) {
}

void	SedPro::replace( std::string toFind, std::string toReplace) {
	std::ifstream	infs(this->_inFile.c_str());
	if (infs.is_open()) {
		std::string content;  // a string from input where we do all the operations
		if (std::getline(infs, content, '\0')) {
			std::ofstream	outfs(this->_outFile.c_str());
			size_t			pos = content.find(toFind);

			while ( pos != std::string::npos ) {  //npos is the return value of an unsuccesful .find() call
				content.erase(pos, toFind.length());  //erase the content
				content.insert(pos, toReplace);  // insert the new one
				pos += toReplace.length();  // Increment pos after replacement
				pos = content.find(toFind, pos);  // new position
			}
			outfs << content;
			outfs.close();
		}
		else {
			std::cerr << "Empty file found." << std::endl;
		}
		infs.close();
	} else {
		std::cerr << "Unable to open the file." << std::endl;
		exit(EXIT_FAILURE);
	}
}