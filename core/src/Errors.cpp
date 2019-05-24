/*
** EPITECH PROJECT, 2019
** OOP - Arcade
** File description:
** Errors
*/

#include "Errors.hpp"

ArcadeError::ArcadeError(const std::string &message,
                         const std::string &component) noexcept :
    std::exception(),
    message(message),
    component(component)
{
    std::cerr << "Error: " << this->where() << ": " << this->what() << std::endl;
}

ArcadeError::~ArcadeError()
{
}

const char *ArcadeError::what() const noexcept
{
    return (message.c_str());
}

const char *ArcadeError::where() const noexcept
{
    return (component.c_str());
}
    
BadInputArgsError::BadInputArgsError(const std::string &message, const std::string &component) noexcept : ArcadeError(message, component)
{
}

OpeningGraphLibError::OpeningGraphLibError(const std::string &message, const std::string &component) noexcept : ArcadeError(message, component)
{
}

OpeningGameLibError::OpeningGameLibError(const std::string &message, const std::string &component) noexcept : ArcadeError(message, component)
{
}

DlOpenFailure::DlOpenFailure(const std::string &message, const std::string &component) noexcept : ArcadeError(message, component)
{
}

DlSymFailure::DlSymFailure(const std::string &message, const std::string &component) noexcept : ArcadeError(message, component)
{
}

LibNotFoundError::LibNotFoundError(const std::string &message, const std::string &component) noexcept : ArcadeError(message, component)
{
}

DirectoryNotFoundError::DirectoryNotFoundError(const std::string &message, const std::string &component) noexcept : ArcadeError(message, component)
{
}

NibblerMapNotFoundError::NibblerMapNotFoundError(const std::string &message, const std::string &component) noexcept : ArcadeError(message, component)
{
}

PacmanMapNotFoundError::PacmanMapNotFoundError(const std::string &message, const std::string &component) noexcept : ArcadeError(message, component)
{
}

SDLInitError::SDLInitError(const std::string &message, const std::string &component) noexcept : ArcadeError(message, component)
{
}

WindowCreationError::WindowCreationError(const std::string &message, const std::string &component) noexcept : ArcadeError(message, component)
{
}

RendererCreationError::RendererCreationError(const std::string &message, const std::string &component) noexcept : ArcadeError(message, component)
{
}

ResourceNotFoundError::ResourceNotFoundError(const std::string &message, const std::string &component) noexcept : ArcadeError(message, component)
{
}