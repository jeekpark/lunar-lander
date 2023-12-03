/**
 * @file Render.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#pragma once

#include "llan/common.hpp"

#include "llan/Core/Terrain.hpp"

namespace Llan
{
  class Render
  {
  public:
    Render();
    ~Render();

    void setRenderPosition(float renderX, float renderY);
    void render(const Terrain& terrain, sf::RenderWindow& window);
  private:
    float mRenderWidth;
    float mRenderHeight;
    float mRenderX;
    float mRenderY;

  };
}