#include "findUrls.hpp"
#include <algorithm>
#include <cctype>
#include <string_view>

namespace
{
bool isUrlChar(char c)
{
    constexpr std::string_view allowedChars = "!;/?:@=&$-_+!'(),.";
    return std::isalnum(c) || std::find(allowedChars.cbegin(), allowedChars.cend(), c) != allowedChars.cend();
}

std::string::const_iterator urlBeg(std::string::const_iterator b, std::string::const_iterator e)
{
    constexpr std::string_view separator = "://";

    std::string::const_iterator i = b;
    while ((i = std::search(i, e, separator.cbegin(), separator.cend())) != e)
    {
        if (i != b && (i + separator.size()) != e)
        {
            auto beg = i;
            while (beg != b && std::isalpha(beg[-1]))
            {
                --beg;
            }
            if (beg != i && isUrlChar(i[separator.size()]))
            {
                return beg;
            }
        }
        i += separator.size();
    }
    return e;
}

std::string::const_iterator urlEnd(std::string::const_iterator b, std::string::const_iterator e)
{
    return std::find_if_not(b, e, [](const auto c) { return isUrlChar(c); });
}
} // namespace

std::vector<std::string> findUrls(const std::string& str)
{
    std::vector<std::string> ret;

    auto b = str.cbegin();
    while (b != str.cend())
    {
        b = urlBeg(b, str.cend());

        if (b != str.cend())
        {
            const auto after = urlEnd(b, str.cend());
            ret.emplace_back(b, after);
            b = after;
        }
    }
    return ret;
}
