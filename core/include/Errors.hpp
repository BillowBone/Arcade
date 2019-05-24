/*
** EPITECH PROJECT, 2019
** OOP - Arcade
** File description:
** Errors.hpp
*/

#ifndef ERRORS_HPP_
# define ERRORS_HPP_

# include <exception>
# include <string>
# include <iostream>

class ArcadeError : public std::exception
{
    public:
        ArcadeError(const std::string &message = "Unknown",
                const std::string &component = "Unknown") noexcept;
        ~ArcadeError();
        const char *what() const noexcept;
        const char *where() const noexcept;
        
protected:
        const std::string &message;
        const std::string &component;
};

class BadInputArgsError : public ArcadeError
{
    public:
        BadInputArgsError(const std::string &message = "Unknown",
                        const std::string &component = "Unknown") noexcept;
};

class OpeningGraphLibError : public ArcadeError
{
    public:
        OpeningGraphLibError(const std::string &message = "Unknown",
                        const std::string &component = "Unknown") noexcept;
};

class OpeningGameLibError : public ArcadeError
{
    public:
        OpeningGameLibError(const std::string &message = "Unknown",
                        const std::string &component = "Unknown") noexcept;
};

class DlOpenFailure : public ArcadeError
{
    public:
        DlOpenFailure(const std::string &message = "Unknown",
                        const std::string &component = "Unknown") noexcept;
};

class DlSymFailure : public ArcadeError
{
    public:
        DlSymFailure(const std::string &message = "Unknown",
                        const std::string &component = "Unknown") noexcept;
};

class LibNotFoundError : public ArcadeError
{
    public:
        LibNotFoundError(const std::string &message = "Unknown",
                        const std::string &component = "Unknown") noexcept;
};

class DirectoryNotFoundError : public ArcadeError
{
    public:
        DirectoryNotFoundError(const std::string &message = "Unknown",
                        const std::string &component = "Unknown") noexcept;
};

class NibblerMapNotFoundError : public ArcadeError
{
    public:
        NibblerMapNotFoundError(const std::string &message = "Unknown",
                        const std::string &component = "Unknown") noexcept;
};

class PacmanMapNotFoundError : public ArcadeError
{
    public:
        PacmanMapNotFoundError(const std::string &message = "Unknown",
                        const std::string &component = "Unknown") noexcept;
};

class SDLInitError : public ArcadeError
{
    public:
        SDLInitError(const std::string &message = "Unknown",
                        const std::string &component = "Unknown") noexcept;
};

class WindowCreationError : public ArcadeError
{
    public:
        WindowCreationError(const std::string &message = "Unknown",
                        const std::string &component = "Unknown") noexcept;
};

class RendererCreationError : public ArcadeError
{
    public:
        RendererCreationError(const std::string &message = "Unknown",
                        const std::string &component = "Unknown") noexcept;
};

class ResourceNotFoundError : public ArcadeError
{
    public:
        ResourceNotFoundError(const std::string &message = "Unknown",
                        const std::string &component = "Unknown") noexcept;
};
#endif /* !ERRORS_HPP_ */
