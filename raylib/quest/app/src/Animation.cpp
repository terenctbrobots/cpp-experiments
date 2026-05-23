#include "Animation.h"

#include <nlohmann/json.hpp>
#include <fstream>
#include "spdlog/spdlog.h"

#include "Components/AnimationDataComponent.h"

bool Animation::Load(const std::string& fileName, AnimationDataComponent& animation)
{
    std::ifstream file(fileName);

    if (!file.is_open())
    {
        return false;
    }

    nlohmann::json jsonData = nlohmann::json::parse(file);

    animation.m_Width = jsonData["width"];
    animation.m_Height = jsonData["height"];

    animation.m_AnimationList.clear();

    nlohmann::json animationListJson = jsonData["animation"];

    float y = 0;

    for (auto& animationJson : animationListJson.items())
    {
        nlohmann::json frameJson = animationJson.value();

        Vector2 offset = {0, 0};

        if (frameJson["offsetX"] != nullptr)
        {
            offset.x = animation.m_Width * (float)frameJson["offsetX"];
        }

        if (frameJson["offsetY"] != nullptr)
        {
            offset.y = animation.m_Height * (float)frameJson["offsetY"];
        }

        AnimationFrame frameData;
        frameData.m_FrameRate = frameJson["frameRate"];
        frameData.m_Frames = frameJson["frames"];

        for (int xCount = 0; xCount < frameData.m_Frames; xCount++) 
        {
            float x = xCount * animation.m_Width;
            frameData.m_frameList.push_back({x,y, animation.m_Width, animation.m_Height});
        }

        animation.m_AnimationList.emplace(animationJson.key(),std::move(frameData));

        y += animation.m_Height;
    }

    return true;
}
