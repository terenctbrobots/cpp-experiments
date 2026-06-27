#include "Animation.h"

#include "Components/AnimationComponent.h"
#include "Components/AnimationDataComponent.h"
#include "Components/ImageComponent.h"
#include "Hash.h"
#include "spdlog/spdlog.h"

#include <fstream>
#include <nlohmann/json.hpp>

void Animation::SetAnimation(gaia::ecs::World& world, gaia::ecs::Entity entity, const uint32_t animationName)
{
    if (!world.has<AnimationDataComponent>(entity))
    {
        return;
    }

    const AnimationDataComponent& animationData = world.get<AnimationDataComponent>(entity);

    auto it = animationData.m_AnimationList.find(animationName);

    if (it == animationData.m_AnimationList.end())
        return;

    const AnimationFrame& animationFrame = it->second;

    if (!world.has<ImageComponent>(entity))
        return;

    auto& sprite = world.set<ImageComponent>(entity);
    sprite.m_SrcRect = animationFrame.m_FrameList[0];
    sprite.m_Offset = animationData.m_Offset;

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
        spdlog::error("Could not open {} json file", fileName);
        return false;
    }

    nlohmann::json jsonData = nlohmann::json::parse(file);

    if (!jsonData.contains("width"))
    {
        spdlog::error("Mandatory width field not found");
        return false;
    }
    animation.m_Width = jsonData.value("width", 64);

    if (!jsonData.contains("height"))
    {
        spdlog::error("Mandatory height field not found");
    }
    animation.m_Height = jsonData.value("height", 64);

    if (jsonData.contains("origin"))
    {
        std::string origin = jsonData.value("origin", "center");

        // If origin center draw sprite half the width left and half the height up
        if (origin == "center")
        {
            animation.m_Offset = {-(animation.m_Width / 2), -(animation.m_Height / 2)};
        }
    }

    if (!jsonData.contains("defaultAnimation"))
    {
        spdlog::error("Mandatory defaultAnimation field not found");
    }
    animation.m_DefaultAnimation = HS(jsonData["defaultAnimation"]);

    animation.m_AnimationList.clear();

    nlohmann::json animationListJson = jsonData["animation"];

    for (auto& animationJson : animationListJson.items())
    {
        nlohmann::json frameJson = animationJson.value();

        AnimationFrame frameData;
        if (!frameJson.contains("frameRate") || frameJson.value("frameRate", 0) == 0)
        {
            spdlog::error("Mandatory frameRate field not found or zero");
            return false;
        }

        frameData.m_FrameDuration = 1.0f / (float)frameJson.value("frameRate", 200);

        if (!frameJson.contains("frames"))
        {
            spdlog::error("Mandatory frames field not found");
            return false;
        }

        frameData.m_Frames = frameJson.value("frames", 1);

        if (frameJson.contains("flip"))
        {
            frameData.m_Flip = frameJson.value("flip", false);
        }
        else
        {
            frameData.m_Flip = false;
        }

        float x = 0;
        float y = 0;

        if (frameJson.contains("x"))
        {
            x = frameJson.value("x", 0);
        }

        if (frameJson.contains("y"))
        {
            y = frameJson.value("y", 0);
        }

        for (int i = 0; i < frameData.m_Frames; i++)
        {
            frameData.m_FrameList.push_back({x, y, animation.m_Width, animation.m_Height});
            x += animation.m_Width;
        }
        const uint32_t key = HS(animationJson.key());

        auto [it, inserted] = animation.m_AnimationList.try_emplace(key, frameData);

        if (!inserted)
        {
            spdlog::warn("Duplicate key {} found", animationJson.key());
        }
    }

    return true;
}
