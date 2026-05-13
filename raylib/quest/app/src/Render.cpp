#include "Render.h"

#include "Components/SpriteComponent.h"
#include "Components/Transform2D.h"
#include "spdlog/spdlog.h"

void Render(gaia::ecs::World& world)
{
    gaia::ecs::Query q = world.query()
        .all<Transform2D>()
        .all<SpriteComponent>();

    q.each([&] (const Transform2D& pos, const SpriteComponent& sprite)
    {
        DrawTextureRec(sprite.m_Texture, sprite.m_SrcRect, pos, WHITE);
    });
}
