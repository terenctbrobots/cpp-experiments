#include "Systems/RenderSystem.h"

#include "Components/ImageComponent.h"
#include "Components/LayerComponent.h"
#include "Components/Transform2D.h"

gaia::ecs::SystemBuilder RegisterRenderLayerOneSystem(gaia::ecs::World& world)
{
    return world.system()
        .all<Transform2D>()
        .all<ImageComponent>() 
        .all<LayerOneComponent>()
        .on_each([](const Transform2D& pos, const ImageComponent& sprite)
        {
            ClearBackground(BLACK);

            Rectangle drawRect = sprite.m_SrcRect;

            if (sprite.m_Flip) drawRect.width *= -1.0f;

            DrawTextureRec(sprite.m_Texture, drawRect, pos, WHITE);
        });
}

gaia::ecs::SystemBuilder RegisterRenderLayerTwoSystem(gaia::ecs::World& world)
{
    return world.system()
        .all<Transform2D>()
        .all<ImageComponent>() 
        .all<LayerTwoComponent>()
        .on_each([](const Transform2D& pos, const ImageComponent& sprite)
        {
            Rectangle drawRect = sprite.m_SrcRect;

            if (sprite.m_Flip) drawRect.width *= -1.0f;

            DrawTextureRec(sprite.m_Texture, drawRect, pos, WHITE);
        });
}

gaia::ecs::SystemBuilder RegisterRenderLayerThreeSystem(gaia::ecs::World& world)
{
    return world.system()
        .all<Transform2D>()
        .all<ImageComponent>()
        .all<LayerThreeComponent>()
        .on_each([](const Transform2D& pos, const ImageComponent& sprite)
        {
            Rectangle drawRect = sprite.m_SrcRect;

            if (sprite.m_Flip) drawRect.width *= -1.0f;

            DrawTextureRec(sprite.m_Texture, drawRect, pos, WHITE);
        });
}