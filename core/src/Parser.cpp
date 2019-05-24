/*
** EPITECH PROJECT, 2019
** OOP - Arcade
** File description:
** Parser
*/

#include "Parser.hpp"
#include <iostream>

Parser::Parser(const std::string &lib, const std::string &games)
{
    this->_tabGame = parseDir(this->_tabGame, games);
    this->_tabGraph = parseDir(this->_tabGraph, lib);
}

Parser::~Parser()
{
}

std::vector<std::string> Parser::getTabGraph() const
{
    return (this->_tabGraph);
}

std::vector<std::string> Parser::getTabGame() const
{
    return (this->_tabGame);
}

std::vector<std::string> Parser::parseDir(std::vector<std::string> tab, const std::string &path)
{
    DIR *dirStream = opendir(path.c_str());
    struct dirent *file = nullptr;

    if (dirStream == nullptr)
        throw DirectoryNotFoundError("Rather the ./games/ or the ./lib/ directory wasn't found.", "Parser");
    file = readdir(dirStream);
    while (file != nullptr) {
        if (file->d_name[strlen(file->d_name) - 1] == 'o' &&
            file->d_name[strlen(file->d_name) - 2] == 's' &&
            file->d_name[strlen(file->d_name) - 3] == '.')
            tab.push_back(file->d_name);
        file = readdir(dirStream);
    }
    closedir(dirStream);
    return (tab);
}
