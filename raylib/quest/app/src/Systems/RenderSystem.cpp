#include "Systems/RenderSystem.h"

#include "Components/ImageComponent.h"
#include "Components/LayerComponent.h"
#include "Components/Transform2D.h"

void RenderSystem::Init(gaia::ecs::World& world)
{
    queryLayerOne = world.query().all<Transform2D>().all<ImageComponent>().all<LayerOneComponent>();
    queryLayerTwo = world.query().all<Transform2D>().all<ImageComponent>().all<LayerTwoComponent>();
    queryLayerThree = world.query().all<Transform2D>().all<ImageComponent>().all<LayerThreeComponent>();
}

void RenderSystem::Update()
{
    queryLayerOne.each(
        [](const Transform2D& pos, const ImageComponent& sprite)
        {
            Rectangle drawRect = sprite.m_SrcRect;
            if (sprite.m_Flip)
                drawRect.width *= -1.0f;
            DrawTextureRec(sprite.m_Texture, drawRect, pos, WHITE);
        });

    queryLayerTwo.each(
        [](const Transform2D& pos, const ImageComponent& sprite)
        {
            Rectangle drawRect = sprite.m_SrcRect;
            if (sprite.m_Flip)
                drawRect.width *= -1.0f;
            DrawTextureRec(sprite.m_Texture, drawRect, pos, WHITE);
        });

    queryLayerThree.each(
        [](const Transform2D& pos, const ImageComponent& sprite)
        {
            Rectangle drawRect = sprite.m_SrcRect;
            if (sprite.m_Flip)
                drawRect.width *= -1.0f;
            DrawTextureRec(sprite.m_Texture, drawRect, pos, WHITE);
        });
}