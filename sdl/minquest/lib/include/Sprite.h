#pragma once

#include <memory>

class Image;

class Sprite
{
    public:
        Sprite() = default;
    private:
        std::shared_ptr<Image> m_Image;
};