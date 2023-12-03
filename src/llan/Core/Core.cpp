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
      mStarship.update
      (
        mEventManager.isKeyPressed(sf::Keyboard::W),
        mEventManager.isKeyPressed(sf::Keyboard::D),
        mEventManager.isKeyPressed(sf::Keyboard::A)
      );
      Vec2 pos = mStarship.getPosition();
      
 
      sf::Texture t, fire;
      t.loadFromFile("./resources/Starship.png");
      fire.loadFromFile("./resources/MainThrust.png");
      t.setSmooth(true);
      fire.setSmooth(true);
      sf::Sprite sprite, spriteThrust;
      sprite.setTexture(t);
      spriteThrust.setTexture(fire);
      sprite.setScale(mRender.getScale() / 32 * LUNAR_MODULE_HEIGHT_M, mRender.getScale() / 32 * LUNAR_MODULE_HEIGHT_M);
      spriteThrust.setScale(mRender.getScale() / 32 * LUNAR_MODULE_HEIGHT_M, mRender.getScale() / 32 * LUNAR_MODULE_HEIGHT_M);
      sprite.setOrigin(mRender.getScale() * LUNAR_MODULE_HEIGHT_M / 2, mRender.getScale() * LUNAR_MODULE_HEIGHT_M / 2);
      spriteThrust.setOrigin(mRender.getScale() * LUNAR_MODULE_HEIGHT_M / 2, mRender.getScale() * LUNAR_MODULE_HEIGHT_M / 2);
      sprite.setPosition(WINDOW_X / 2.f, WINDOW_Y / 2.f);
      spriteThrust.setPosition(WINDOW_X / 2.f, WINDOW_Y / 2.f);
      
      Vec2 dir = mStarship.getDirection();
      sprite.setRotation(pCalculateAngle(Vec2(0, 0), dir) + 90);
      spriteThrust.setRotation(pCalculateAngle(Vec2(0, 0), dir) + 90);
      
      mRender.setRenderPosition(pos.getX(), pos.getY());
      mWindow.draw(sprite);
      if (mEventManager.isKeyPressed(sf::Keyboard::W))
        mWindow.draw(spriteThrust);
      mRender.render(mTerrain, mWindow);
      
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