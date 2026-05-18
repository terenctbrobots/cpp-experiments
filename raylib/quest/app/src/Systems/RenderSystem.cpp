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

            DrawTextureRec(sprite.m_Texture, sprite.m_SrcRect, pos, WHITE);
        });
}