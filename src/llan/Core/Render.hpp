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

#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Clock.hpp"
#include "llan/Core/Starship.hpp"
#include "llan/common.hpp"

#include "llan/Core/Terrain.hpp"

namespace Llan
{
  class Render
  {
  public:
    Render();
    ~Render();

    /**
     * @brief Render a section of terrain within a specified window using SFML.
     * 
     * @param terrain The Terrain object containing height data.
     * @param window The SFML RenderWindow where the terrain is to be rendered.
     */
    void renderTerrain(const Terrain& terrain, sf::RenderWindow& window);

    void setRenderTerrainPosition(float renderX, float renderY);
    void setRenderTerrainWidth(float renderWidth);
    void setRenderTerrainHeight(float renderHeight);
    float getTerrainScale() const;

    
    void renderStarship(const Starship& starship, sf::RenderWindow& window);
  private:
    float mRenderTerrainWidth;
    float mRenderTerrainHeight;
    float mRenderTerrainX;
    float mRenderTerrainY;
    float mTerrainScale;

    sf::Texture mStarshipSpriteTexture;
    sf::Sprite mStarshipSprite;
    sf::IntRect mFrameRect;
    int mStarshipRectSize;

  private:
    float pMap(float value, float inMin, float inMax, float outMin, float outMax) const;
    float pCalculateAngle(Vec2 source, Vec2 target) const;
  };
}