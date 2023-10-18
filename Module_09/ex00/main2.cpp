#include <iostream>
#include <ctime>
#include <cstring>

int main() {
    std::string dateStr = "2023-10-18"; // Your input date string in "yyyy-mm-dd" format

    struct tm date; // Create a tm struct to store the date
    std::memset(&date, 0, sizeof(date)); // Initialize the tm struct

    // Parse the date string into the tm struct
    if (sscanf(dateStr.c_str(), "%d-%d-%d", &date.tm_year, &date.tm_mon, &date.tm_mday) == 3) {
        date.tm_year -= 1900; // Adjust year
        date.tm_mon--; // Adjust month (0-11)

        // Convert the tm struct to a time_t
        time_t time = mktime(&date);

        // You now have a time_t representing the date with a precision of one day
        std::cout << "Date: " << asctime(&date);
    } else {
        std::cout << "Invalid date format!" << std::endl;
    }

    return 0;
}
