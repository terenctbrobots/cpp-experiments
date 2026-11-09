#include "Systems/RenderSystem.h"

#include "Components/BoundingBoxComponent.h"
#include "Components/ImageComponent.h"
#include "Components/LayerComponent.h"
#include "Components/Transform2D.h"

#include <raylib.h>

void RenderSystem::Init(gaia::ecs::World& world)
{
    if (m_Debug)
    {
        m_QueryLayerOne = world.query()
                              .all<Transform2D>()
                              .all<Animation::ImageComponent>()
                              .all<Game::BoundingBoxComponent>()
                              .all<Render::LayerOneComponent>();
        m_QueryLayerTwo = world.query()
                              .all<Transform2D>()
                              .all<Animation::ImageComponent>()
                              .all<Game::BoundingBoxComponent>()
                              .all<Render::LayerTwoComponent>();
        m_QueryLayerThree = world.query()
                                .all<Transform2D>()
                                .all<Animation::ImageComponent>()
                                .all<Game::BoundingBoxComponent>()
                                .all<Render::LayerThreeComponent>();
    }
    else
    {
        m_QueryLayerOne =
            world.query().all<Transform2D>().all<Animation::ImageComponent>().all<Render::LayerOneComponent>();
        m_QueryLayerTwo =
            world.query().all<Transform2D>().all<Animation::ImageComponent>().all<Render::LayerTwoComponent>();
        m_QueryLayerThree =
            world.query().all<Transform2D>().all<Animation::ImageComponent>().all<Render::LayerThreeComponent>();
    }
}

void RenderSystem::Update()
{
    ClearBackground(BLACK);

    if (m_Debug)
    {
        m_QueryLayerOne.each(
            [](const Transform2D& pos, const Animation::ImageComponent& sprite,
               const Game::BoundingBoxComponent& boundBox)
            {
                Rectangle drawRect = sprite.m_SrcRect;
                if (sprite.m_Flip)
                    drawRect.width *= -1.0f;

                const Vector2 drawPos = Vector2Add(pos.m_Pos, sprite.m_Offset);
                DrawTextureRec(sprite.m_Texture, drawRect, drawPos, WHITE);

                if (boundBox.m_Show)
                {
                    DrawRectangleLinesEx(boundBox.m_Collision, 0.5f, RED);
                }
            });

        m_QueryLayerTwo.each(
            [](const Transform2D& pos, const Animation::ImageComponent& sprite,
               const Game::BoundingBoxComponent& boundBox)
            {
                Rectangle drawRect = sprite.m_SrcRect;
                if (sprite.m_Flip)
                    drawRect.width *= -1.0f;

                const Vector2 drawPos = Vector2Add(pos.m_Pos, sprite.m_Offset);
                DrawTextureRec(sprite.m_Texture, drawRect, drawPos, WHITE);

                if (boundBox.m_Show)
                {
                    DrawRectangleLinesEx(boundBox.m_Collision, 0.5f, RED);
                }
            });

        m_QueryLayerThree.each(
            [](const Transform2D& pos, const Animation::ImageComponent& sprite,
               const Game::BoundingBoxComponent& boundBox)
            {
                Rectangle drawRect = sprite.m_SrcRect;
                if (sprite.m_Flip)
                    drawRect.width *= -1.0f;

                const Vector2 drawPos = Vector2Add(pos.m_Pos, sprite.m_Offset);
                DrawTextureRec(sprite.m_Texture, drawRect, drawPos, WHITE);

                if (boundBox.m_Show)
                {
                    DrawRectangleLinesEx(boundBox.m_Collision, 0.5f, RED);
                }
            });

        return;
    }

    m_QueryLayerOne.each(
        [](const Transform2D& pos, const Animation::ImageComponent& sprite)
        {
            Rectangle drawRect = sprite.m_SrcRect;
            if (sprite.m_Flip)
                drawRect.width *= -1.0f;

            const Vector2 drawPos = Vector2Add(pos.m_Pos, sprite.m_Offset);
            DrawTextureRec(sprite.m_Texture, drawRect, drawPos, WHITE);
        });

    m_QueryLayerTwo.each(
        [](const Transform2D& pos, const Animation::ImageComponent& sprite)
        {
            Rectangle drawRect = sprite.m_SrcRect;
            if (sprite.m_Flip)
                drawRect.width *= -1.0f;

            const Vector2 drawPos = Vector2Add(pos.m_Pos, sprite.m_Offset);
            DrawTextureRec(sprite.m_Texture, drawRect, drawPos, WHITE);
        });

    m_QueryLayerThree.each(
        [](const Transform2D& pos, const Animation::ImageComponent& sprite)
        {
            Rectangle drawRect = sprite.m_SrcRect;
            if (sprite.m_Flip)
                drawRect.width *= -1.0f;

            const Vector2 drawPos = Vector2Add(pos.m_Pos, sprite.m_Offset);
            DrawTextureRec(sprite.m_Texture, drawRect, drawPos, WHITE);
        });
}

void RenderSystem::ToggleDebug(gaia::ecs::World& world)
{
    m_Debug = !m_Debug;
    Init(world);
}
