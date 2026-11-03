#pragma once
#include "Animation.h"
#include "raylib.h"

#include <cstdint>
#include <string>
#include <sys/types.h>

namespace TileList
{
    struct Tile;
}

namespace AssetManager
{
    const std::string s_PlayerAsset = "player";

    enum class AssetType
    {
        Invalid,
        Sprite,
        TileSet
    };

    struct Asset
    {
        AssetType m_AssetType;
        std::string m_Path;
        std::string m_DataPath;
        Texture2D m_Texture;
        Animation::AnimationData m_Animation;
    };

    bool Initialize();
    Texture2D GetTexture(const std::string& key);
    const Animation::AnimationData* GetAnimation(const std::string& key);
    void Clear();
}; // namespace AssetManager
