/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:31:26 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/12 16:31:27 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Converter.hpp"

int main( int ac, char ** av )
{
    if ( ac != 2 ) {
        std::cout << "Usage: ./convert number" << std::endl;
        return EXIT_FAILURE;
    }

    Converter c;

    try
    {
        c.setStr( av[1] );
        c.convert();

        std::cout << c;
    }
    catch( const std::exception& e ) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    

    return EXIT_SUCCESS;
}