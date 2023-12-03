/**
 * @file Render.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "llan/Core/Render.hpp"


namespace Llan
{
  Render::Render()
  {
    mRenderHeight = 100.f;
    mRenderWidth = mRenderHeight / 9.f * 16.f;
    mRenderX = 500.f;
    mRenderY = 1000.f;
  }

  Render::~Render()
  {

  }

  void Render::setRenderPosition(float renderX, float renderY)
  {
    mRenderX = renderX;
    mRenderY = renderY;
  }

  void Render::render(const Terrain& terrain, sf::RenderWindow& window)
  {
    for (int i = mRenderX - (mRenderWidth / 2); i < mRenderX + (mRenderWidth / 2) - 1; ++i)
    {
      float heightFirst = terrain.getTerrainHeight(i);
      float heightSecond = terrain.getTerrainHeight(i + 1);
      sf::Vertex line[] =
      {
        sf::Vertex(sf::Vector2f(i / mRenderWidth*WINDOW_X, heightFirst / mRenderHeight*WINDOW_Y)),
        sf::Vertex(sf::Vector2f((i + 1) / mRenderWidth*WINDOW_X, heightSecond / mRenderHeight*WINDOW_Y))
      };
      window.draw(line, 2, sf::Lines);
    }
  }
}