#!/bin/bash

YELLOW='\033[33m'
RESET='\033[0m'

PROGRAM="./converter"

test_conversion() {
    echo -e "${YELLOW}Testing input: $1 ${RESET}"
    $PROGRAM "$1"
    echo -e "${YELLOW}---------------------${RESET}"
}


# Test char values
test_conversion "a"
test_conversion "Z"
test_conversion "!"

# Test int values
test_conversion "0"
test_conversion "-42"
test_conversion "12345"

# Test float values
test_conversion "0.0f"
test_conversion "-4.2f"
test_conversion "123.456f"

# Test double values
test_conversion "0.0"
test_conversion "-4.2"
test_conversion "123.456"

# Test special cases
test_conversion "nan"
test_conversion "nanf"
test_conversion "+inf"
test_conversion "+inff"
test_conversion "-inf"
test_conversion "-inff"

# Test very large numbers
test_conversion "78658768798776587587987"

# Add more test cases as needed

echo "Tests completed"
