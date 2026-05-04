#pragma once

#include <unordered_map>
#include <cstdint> 
#include <string>

// forward declare
struct SDL_Renderer;
struct SDL_Texture;

class TextureManager
{
    public:
        // Returns a unique ID for the loaded texture
        uint32_t Load(SDL_Renderer* renderer, const std::string& filePath);
        SDL_Texture* Get(uint32_t id);

        void Cleanup();

    private:
        std::unordered_map<uint32_t, SDL_Texture*> m_Textures;
        std::unordered_map<std::string, uint32_t> m_PathMap;
        uint32_t m_NextId = 1;
};