#include "Systems/RenderSystem.h"

#include "Components/ImageComponent.h"
#include "Components/LayerComponent.h"
#include "Components/Transform2D.h"

void RenderSystem::Init(gaia::ecs::World& world)
{
    m_QueryLayerOne = world.query().all<Transform2D>().all<ImageComponent>().all<LayerOneComponent>();
    m_QueryLayerTwo = world.query().all<Transform2D>().all<ImageComponent>().all<LayerTwoComponent>();
    m_QueryLayerThree = world.query().all<Transform2D>().all<ImageComponent>().all<LayerThreeComponent>();
}

void RenderSystem::Update()
{
    ClearBackground(BLACK);

    m_QueryLayerOne.each(
        [](const Transform2D& pos, const ImageComponent& sprite)
        {
            Rectangle drawRect = sprite.m_SrcRect;
            if (sprite.m_Flip)
                drawRect.width *= -1.0f;

            Vector2 drawPos = Vector2Add(pos.m_Pos, sprite.m_Offset);
            DrawTextureRec(sprite.m_Texture, drawRect, drawPos, WHITE);
        });

    m_QueryLayerTwo.each(
        [](const Transform2D& pos, const ImageComponent& sprite)
        {
            Rectangle drawRect = sprite.m_SrcRect;
            if (sprite.m_Flip)
                drawRect.width *= -1.0f;

            Vector2 drawPos = Vector2Add(pos.m_Pos, sprite.m_Offset);
            DrawTextureRec(sprite.m_Texture, drawRect, drawPos, WHITE);
        });

    m_QueryLayerThree.each(
        [](const Transform2D& pos, const ImageComponent& sprite)
        {
            Rectangle drawRect = sprite.m_SrcRect;
            if (sprite.m_Flip)
                drawRect.width *= -1.0f;

            Vector2 drawPos = Vector2Add(pos.m_Pos, sprite.m_Offset);
            DrawTextureRec(sprite.m_Texture, drawRect, drawPos, WHITE);
        });
}