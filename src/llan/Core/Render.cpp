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
    mRenderX = 2000.f;
    mRenderY = 1010.f;
    mScale = pMap(mRenderX - (mRenderWidth / 2) + 1.f, mRenderX - (mRenderWidth / 2), mRenderX + (mRenderWidth / 2), 0, WINDOW_X);
    std::cout << mScale << std::endl;
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
    float startXFloat = mRenderX - (mRenderWidth / 2);
    int startXInt = static_cast<int>(startXFloat);
  
    float endXFloat = mRenderX + (mRenderWidth / 2);
    int endXInt = static_cast<int>(endXFloat) + 1;

    for (int i = startXInt; i < endXInt; ++i)
    {
      float heightFirst = terrain.getTerrainHeight(i);
      float heightSecond = terrain.getTerrainHeight(i + 1);
      sf::Vertex line[] =
      {
        sf::Vertex(sf::Vector2f(pMap(i, startXFloat, endXFloat, 0, WINDOW_X),
          pMap(heightFirst, mRenderY - (mRenderHeight / 2), mRenderY + (mRenderHeight / 2), 0, WINDOW_Y))),
        sf::Vertex(sf::Vector2f(pMap(i + 1, startXFloat, endXFloat, 0, WINDOW_X),
          pMap(heightSecond, mRenderY - (mRenderHeight / 2), mRenderY + (mRenderHeight / 2), 0, WINDOW_Y)))
      };
      window.draw(line, 2, sf::Lines);
    }
  }

  float Render::getScale() const
  {
    return mScale;
  }

  float Render::pMap(float value, float inMin, float inMax, float outMin, float outMax) const
  {
    float scale = (outMax- outMin) / (inMax - inMin);
    return outMin + (value - inMin) * scale;
  }
}