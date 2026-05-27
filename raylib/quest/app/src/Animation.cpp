#include "Animation.h"

#include <nlohmann/json.hpp>
#include <fstream>
#include "spdlog/spdlog.h"

#include "Components/AnimationComponent.h"
#include "Components/AnimationDataComponent.h"
#include "Components/SpriteComponent.h"

void Animation::SetAnimation(gaia::ecs::World& world, gaia::ecs::Entity entity, const std::string& animationName)
{
    if (!world.has<AnimationDataComponent>(entity))
        return;

    const AnimationDataComponent& animationData = world.get<AnimationDataComponent>(entity);

    auto it = animationData.m_AnimationList.find(animationName);

    if (it == animationData.m_AnimationList.end())
        return;

    const AnimationFrame& animationFrame = it->second;

    if (!world.has<SpriteComponent>(entity))
        return;

    auto& sprite = world.set<SpriteComponent>(entity);
    sprite.m_SrcRect = animationFrame.m_FrameList[0];


    if (!world.has<AnimationComponent>(entity))
        return;
    
    auto& animation = world.set<AnimationComponent>(entity);
    animation.m_CurrentAnimation = animationName;
    animation.m_CurrentFrame = 0;
    animation.m_Timer = animationFrame.m_FrameDuration;
}

bool Animation::Load(const std::string& fileName, AnimationDataComponent& animation)
{
    std::ifstream file(fileName);

    if (!file.is_open())
    {
        spdlog::error("Could not open %s json file", fileName);
        return false;
    }

    nlohmann::json jsonData = nlohmann::json::parse(file);

    if (jsonData["width"] == nullptr)
    {
        spdlog::error("Mandatory width field not found");
        return false;
    }
    animation.m_Width = jsonData["width"];

    if (jsonData["height"] == nullptr)
    {
        spdlog::error("Mandatory height field not found");
    }
    animation.m_Height = jsonData["height"];

    if (jsonData["defaultAnimation"] == nullptr)
    {
        spdlog::error("Mandatory defaultAnimation field not found");
    }
    animation.m_DefaultAnimation = jsonData["defaultAnimation"];

    animation.m_AnimationList.clear();

    nlohmann::json animationListJson = jsonData["animation"];

    for (auto& animationJson : animationListJson.items())
    {
        nlohmann::json frameJson = animationJson.value();

        AnimationFrame frameData;
        if (frameJson["frameRate"] == nullptr || frameJson["frameRate"] == 0)
        {
            spdlog::error("Mandatory frameRate field not found or zero");
            return false;
        }
        
        frameData.m_FrameDuration = 1.0f /  (float)frameJson["frameRate"];

        if (frameJson["frames"] == nullptr)
        {
            spdlog::error("Mandatory frames field not found");
            return false;
        }

        frameData.m_Frames = frameJson["frames"];

        if (frameJson["flip"] != nullptr)
        {
            frameData.m_Flip = frameJson["flip"];
        }
        else 
        {
            frameData.m_Flip = false;
        }

        float x = 0;
        float y = 0;

        if (frameJson["x"] != nullptr)
        {
            x = frameJson["x"];
        }

        if (frameJson["y"] != nullptr)
        {
            y = frameJson["y"];
        }

        for (int xCount = 0; xCount < frameData.m_Frames; xCount++) 
        {
            x += xCount * animation.m_Width;
            frameData.m_FrameList.push_back({x,y, animation.m_Width, animation.m_Height});
        }

        animation.m_AnimationList.emplace(animationJson.key(),std::move(frameData));
    }

    return true;
}
