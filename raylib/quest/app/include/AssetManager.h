#pragma once
#include "raylib.h"
#include "tsl/robin_map.h"

#include <string>
#include <sys/types.h>

namespace TileList
{
    struct Tile;
}

namespace AssetManager
{
    struct AnimationFrame
    {
        std::vector<Rectangle> m_FrameList;
        float m_FrameDuration;
        u_int m_Frames;
        bool m_Flip;
    };

    struct Animation
    {
        float m_Width;
        float m_Height;

        Vector2 m_Offset = Vector2{0, 0};

        uint32_t m_DefaultAnimation;
        tsl::robin_map<std::string, AssetManager::AnimationFrame> m_AnimationFrames;
    };

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
        tsl::robin_map<std::string, AssetManager::Animation> m_Animation;
    };

    bool Initialize();
    Texture2D GetTexture(const std::string& key);
    void Clear();
}; // namespace AssetManager
