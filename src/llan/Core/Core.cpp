/**
 * @file Core.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "llan/Core/Core.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Window/Keyboard.hpp"

namespace Llan
{
  Core::Core()
  : mWindow()
  , mWindowTitle("lunar-lander")
  {
    srand(time(NULL));
    mWindowTitle.append(LLAN_VERSION);
    mWindow.create(sf::VideoMode(WINDOW_X, WINDOW_Y), mWindowTitle);
    mWindow.setFramerateLimit(60);
    mWindow.clear();
  }

  Core::~Core()
  {

  }

  void Core::run()
  {
    sf::Texture a;
    a.loadFromFile("./resources/background.png");
    sf::Sprite b;
    b.setTexture(a);


    while (mWindow.isOpen())
    {
      mWindow.clear();
      mEventManager.handleEventQueue(mWindow);
      mStarship.update
      (
        mEventManager.isKeyPressed(sf::Keyboard::W),
        mEventManager.isKeyPressed(sf::Keyboard::D),
        mEventManager.isKeyPressed(sf::Keyboard::A)
      );

      if (mEventManager.isKeyPressed(sf::Keyboard::L))
      {
        mRender.setRenderTerrainHeight(40);
      }
      else
      {
        mRender.setRenderTerrainHeight(100);
      }
      

      mWindow.draw(b);
      mRender.setRenderTerrainPosition(mStarship.getPosition().getX(), mStarship.getPosition().getY());
      mRender.renderTerrain(mTerrain, mWindow);
      mRender.renderStarship(mStarship, mWindow);


      mUI.setFlightAltitude(1001.5f - mStarship.getPosition().getY());
      mUI.setHorizontalVelocity(mStarship.getVelocity().getX());
      mUI.setVerticalVelocity(mStarship.getVelocity().getY());
      mUI.setSafetyLanding(mStarship.getIsSafetyLandingVelocty());
      mWindow.draw(mUI.getFlightAltitude());
      mWindow.draw(mUI.getHorizontalVelocity());
      mWindow.draw(mUI.getVerticalVelocity());
      mWindow.draw(mUI.getSafetyLanding());
      


      mWindow.display();
    }
  }

  void Core::close()
  {
    mWindow.close();
  }

  float Core::pCalculateAngle(Vec2 source, Vec2 target)
  {
    float dx = target.getX() - source.getX();
    float dy = target.getY() - source.getY();
    return std::atan2(dy, dx) * 180.f / M_PI;
  }
}