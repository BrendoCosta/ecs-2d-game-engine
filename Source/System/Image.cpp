#include "Image.h"
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <ios>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

std::shared_ptr<SDL_Surface> Project::System::Image::load_image(std::string const& path)
{
    auto p = std::filesystem::path(path);
    if (!std::filesystem::exists(p) || !std::filesystem::is_regular_file(p))
    {
        return nullptr;
    }

    auto input_stream = std::ifstream();
    input_stream.open(p, std::ios::in | std::ios::binary);
    if (!input_stream.is_open())
    {
        return nullptr;
    }
    
    std::uintmax_t size = std::filesystem::file_size(p);
    if (size == 0)
    {
        return nullptr;
    }
    
    auto buffer = std::shared_ptr<std::uint8_t>(new std::uint8_t[size], [](std::uint8_t* ptr) { delete[] ptr; });
    input_stream.read((char*) buffer.get(), size);
    input_stream.close();
    return std::shared_ptr<SDL_Surface>(IMG_Load_RW(SDL_RWFromConstMem((const void*) buffer.get(), size), 1), [](SDL_Surface* ptr) { SDL_FreeSurface(ptr); });
}