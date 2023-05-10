/* Module: Utils
 * -------------
 * COMP.CS.110 Ohjelmointi 2: Rakenteet / Programming 2: Structures
 * -------------
 * Module for different utilities needed in the program.
 *
 * Note: Students shouldn't need to make changes to this file.
 * */
#ifndef UTILS_HH
#define UTILS_HH

#include <vector>
#include <string>

namespace Utils
{
/**
 * @brief split
 * @param str
 * @param delim
 * @return vector containing the parts, no delim chars
 * Splits the given string at every delim char.
 */
std::vector<std::string> split(const std::string& str, char delim = ';');

/**
 * @brief is_empty
 * @param str
 * @return true if given string consists only of empty spaces
 */
bool is_empty(const std::string& str);

/**
 * @brief is_numeric
 * @param str
 * @return true if given string is numeric
 */
bool is_numeric(const std::string& str);

/**
 * @brief numeric_part
 * @param str
 * @return numeric sequence from the given string,
 * if no numeric sequence occurs, returns 0
 */
int numeric_part(const std::string& str);

/**
 * @brief to_lower
 * @param str
 * @return the given string written with lower case letters
 */
std::string to_lower(const std::string& str);

}

#endif // UTILS_HH

