#include "TextureManager.h"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>


// Returns a unique ID for the loaded texture
uint32_t TextureManager::Load(SDL_Renderer* renderer, const std::string& filePath) 
{
    if (m_PathMap.count(filePath))
    {
        return m_PathMap[filePath];
    };

    SDL_Texture* tex = IMG_LoadTexture(renderer, filePath.c_str());
    if (!tex) 
    {
        return 0; // Handle error
    }

    uint32_t id = m_NextId++;
    m_Textures[id] = tex;
    m_PathMap[filePath] = id;
    return id;
}

SDL_Texture* TextureManager::Get(uint32_t id) 
{
    return m_Textures.count(id) ? m_Textures[id] : nullptr;
}

void TextureManager::Cleanup() 
{
    for (auto& [id, tex] : m_Textures) 
    {
        SDL_DestroyTexture(tex);
    }
    m_Textures.clear();
    m_PathMap.clear();
}