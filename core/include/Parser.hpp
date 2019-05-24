/*
** EPITECH PROJECT, 2019
** OOP - Arcade
** File description:
** Parser.hpp
*/

#ifndef PARSER_HPP_
# define PARSER_HPP_

# include <string>
# include <cstring>
# include <vector>
# include <dirent.h>
#include "Errors.hpp"

class Parser {
public:
    Parser(const std::string &lib, const std::string &games);
    ~Parser();
    std::vector<std::string> getTabGraph() const;
    std::vector<std::string> getTabGame() const;
private:
    std::vector<std::string> parseDir(std::vector<std::string> tab, const std::string &path);
private:
    std::vector<std::string> _tabGraph;
    std::vector<std::string> _tabGame;
};

#endif /* !PARSER_HPP_ */
