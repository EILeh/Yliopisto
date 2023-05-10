#include "utils.hh"

std::vector<std::string> Utils::split(const std::string& str, char delim)
{
    std::vector<std::string> result = {""};
    bool insideQuotation = false;
    for ( char currentChar : str )
    {
        if ( currentChar == '"' )
        {
            insideQuotation = not insideQuotation;
        }
        else if ( currentChar == delim and not insideQuotation)
        {
            result.push_back("");
        }
        else
        {
            result.back().push_back(currentChar);
        }
    }
    return result;
}

bool Utils::is_empty(const std::string &str)
{
    for ( char ch : str )
    {
        if ( ch != ' ' )
        {
            return false;
        }
    }
    return true;
}

bool Utils::is_numeric(const std::string& s)
{
    for ( unsigned int i = 0; i < s.size(); ++i )
    {
        if( not isdigit(s.at(i)) )
        {
            return false;
        }
    }
    return true;
}

int Utils::numeric_part(const std::string &s)
{
    std::string num = "";
    for ( unsigned int i = 0; i < s.size(); ++i )
    {
        while ( i < s.size() and isdigit(s.at(i)) )
        {
            num += s.at(i);
            ++i;
        }
    }
    if ( num == "" )
    {
        return 0;
    }
    else
    {
        return stoi(num);
    }
}

std::string Utils::to_lower(const std::string &s)
{
    std::string result = "";
    for ( unsigned int i = 0; i < s.size(); ++i )
    {
        result += tolower(s.at(i));
    }
    return result;
}

