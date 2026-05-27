#include "Systems/RenderSystem.h"

#include "Components/SpriteComponent.h"
#include "Components/Transform2D.h"

gaia::ecs::SystemBuilder RegisterRenderSystem(gaia::ecs::World& world)
{
    return world.system()
        .all<Transform2D>()
        .all<SpriteComponent>() 
        .on_each([](const Transform2D& pos, const SpriteComponent& sprite)
        {
            ClearBackground(BLACK);

            Rectangle drawRect = sprite.m_SrcRect;

            if (sprite.m_Flip) drawRect.width *= -1.0f;

            DrawTextureRec(sprite.m_Texture, drawRect, pos, WHITE);
        });
}