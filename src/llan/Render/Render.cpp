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

#include "llan/Render/Render.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/PrimitiveType.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Vertex.hpp"
#include "SFML/System/Clock.hpp"
#include "llan/Core/Starship.hpp"
#include "llan/common.hpp"


namespace Llan
{
  Render::Render()
  {
    mRenderTerrainHeight = 1000.f;
    mRenderTerrainWidth = mRenderTerrainHeight / 9.f * 16.f;
    mRenderTerrainX = 2000.f;
    mRenderTerrainY = 1010.f;
    mTerrainScale = pMap(mRenderTerrainX - (mRenderTerrainWidth / 2) + 1.f, mRenderTerrainX - (mRenderTerrainWidth / 2), mRenderTerrainX + (mRenderTerrainWidth / 2), 0, WINDOW_X);

    mStarshipRectSize = 128;
    mStarshipSpriteTexture.loadFromFile(STARSHIP_SPRITE_PATH);
    mStarshipSpriteTexture.setSmooth(true);
    mStarshipSprite.setTexture(mStarshipSpriteTexture);
    mFrameRect = sf::IntRect(0, 0, mStarshipRectSize, mStarshipRectSize);
    mStarshipSprite.setTextureRect(mFrameRect);
  }

  Render::~Render()
  {

  }

  void Render::setRenderTerrainPosition(float renderX, float renderY)
  {
    mRenderTerrainX = renderX;
    mRenderTerrainY = renderY;
  }

  void Render::setRenderTerrainWidth(float renderWidth)
  {
    mRenderTerrainWidth = renderWidth;
    mRenderTerrainHeight = mRenderTerrainWidth / 16.f * 9.f;
    mTerrainScale = pMap(mRenderTerrainX - (mRenderTerrainWidth / 2) + 1.f, mRenderTerrainX - (mRenderTerrainWidth / 2), mRenderTerrainX + (mRenderTerrainWidth / 2), 0, WINDOW_X);
  }

  void Render::setRenderTerrainHeight(float renderHeight)
  {
    mRenderTerrainHeight = renderHeight;
    mRenderTerrainWidth = mRenderTerrainHeight / 9.f * 16.f;
    mTerrainScale = pMap(mRenderTerrainX - (mRenderTerrainWidth / 2) + 1.f, mRenderTerrainX - (mRenderTerrainWidth / 2), mRenderTerrainX + (mRenderTerrainWidth / 2), 0, WINDOW_X);
  }

  void Render::renderTerrain(const Terrain& terrain, sf::RenderWindow& window)
  {
    float startXFloat = mRenderTerrainX - (mRenderTerrainWidth / 2);
    int startXInt = static_cast<int>(startXFloat);
  
    float endXFloat = mRenderTerrainX + (mRenderTerrainWidth / 2);
    int endXInt = static_cast<int>(endXFloat) + 1;

    for (int i = startXInt; i < endXInt; ++i)
    {
      float heightFirst = terrain.getTerrainHeight(i);
      float heightSecond = terrain.getTerrainHeight(i + 1);
      sf::Vertex line[] =
      {
        sf::Vertex(sf::Vector2f(pMap(i, startXFloat, endXFloat, 0, WINDOW_X),
          pMap(heightFirst, mRenderTerrainY - (mRenderTerrainHeight / 2), mRenderTerrainY + (mRenderTerrainHeight / 2), 0, WINDOW_Y))),
        sf::Vertex(sf::Vector2f(pMap(i + 1, startXFloat, endXFloat, 0, WINDOW_X),
          pMap(heightSecond, mRenderTerrainY - (mRenderTerrainHeight / 2), mRenderTerrainY + (mRenderTerrainHeight / 2), 0, WINDOW_Y)))
      };
      window.draw(line, 2, sf::Lines);
      if (i % 50 == 0)
      {sf::Vertex lineVertical[] =
      {
        sf::Vertex(sf::Vector2f(pMap(i + 1, startXFloat, endXFloat, 0, WINDOW_X),
          0)),
        sf::Vertex(sf::Vector2f(pMap(i + 1, startXFloat, endXFloat, 0, WINDOW_X),
          pMap(heightSecond, mRenderTerrainY - (mRenderTerrainHeight / 2), mRenderTerrainY + (mRenderTerrainHeight / 2), 0, WINDOW_Y)))
      };

      lineVertical[0].color = sf::Color(50, 50, 50, 255);
      lineVertical[1].color = sf::Color(50, 50, 50, 255);
      window.draw(lineVertical, 2, sf::Lines);}
    }
  }

  float Render::getTerrainScale() const
  {
    return mTerrainScale;
  }


  void Render::renderStarship(const Starship& starship, sf::RenderWindow& window)
  {    
    int thrustLevel = starship.getThrustLevel() / 1; // -> 0~9
    if (thrustLevel == 9)
    {
      thrustLevel -= (rand() % 8);
    }
    mFrameRect.left = thrustLevel * 128;
    mStarshipSprite.setTextureRect(mFrameRect);
    mStarshipSprite.setOrigin(64, 16);
    mStarshipSprite.setScale(mTerrainScale / 32 * LUNAR_MODULE_HEIGHT_M, mTerrainScale / 32 * LUNAR_MODULE_HEIGHT_M);
    mStarshipSprite.setRotation(pCalculateAngle(Vec2(0, 0), starship.getDirection()) + 90);
    mStarshipSprite.setPosition(WINDOW_X / 2.f, WINDOW_Y / 2.f);
    window.draw(mStarshipSprite);
  }





  float Render::pMap(float value, float inMin, float inMax, float outMin, float outMax) const
  {
    float scale = (outMax- outMin) / (inMax - inMin);
    return outMin + (value - inMin) * scale;
  }

  float Render::pCalculateAngle(Vec2 source, Vec2 target) const
  {
    float dx = target.getX() - source.getX();
    float dy = target.getY() - source.getY();
    return std::atan2(dy, dx) * 180.f / M_PI;
  }
}