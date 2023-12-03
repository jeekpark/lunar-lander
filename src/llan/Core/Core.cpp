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
      mEventManager.handleEventQueue(mWindow);
      mStarship.update
      (
        mEventManager.isKeyPressed(sf::Keyboard::W),
        mEventManager.isKeyPressed(sf::Keyboard::D),
        mEventManager.isKeyPressed(sf::Keyboard::A)
      );
      Vec2 pos = mStarship.getPosition();
      mWindow.clear();
      sf::RectangleShape a(sf::Vector2f(3, 3));
      sf::Texture t;
      t.loadFromFile("./resources/Starship.png");
      t.setSmooth(true);
      sf::Sprite sprite;
      sprite.setTexture(t);
      sprite.setOrigin(16,16);
      sprite.setPosition(pos.getX(), pos.getY());
      
      Vec2 dir = mStarship.getDirection();
      sprite.setRotation(pCalculateAngle(Vec2(0, 0), dir) + 90);
      
      sf::RectangleShape fire(sf::Vector2f(3, 10));
      a.setFillColor(sf::Color::White);
      a.setPosition(sf::Vector2f(pos.getX(), pos.getY()));
      fire.setFillColor(sf::Color::Red);
      fire.setPosition(sf::Vector2f(pos.getX(), pos.getY() + 3));
      //mWindow.draw(a);
      mWindow.draw(sprite);
      if (mEventManager.isKeyPressed(sf::Keyboard::W))
        mWindow.draw(fire);
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