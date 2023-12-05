/**
 * @file EventManager.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "llan/Core/EventManager.hpp"
#include "SFML/Window/Keyboard.hpp"

namespace Llan
{
  EventManager::EventManager()
  {
    mKeyMap[sf::Keyboard::W] = false;
    mKeyMap[sf::Keyboard::A] = false;
    mKeyMap[sf::Keyboard::S] = false;
    mKeyMap[sf::Keyboard::D] = false;
    mKeyMap[sf::Keyboard::L] = false;
  }

  EventManager::~EventManager()
  {}

  void EventManager::handleEventQueue(sf::Window& window)
  {
    while (window.pollEvent(mEvent))
    {
      if (mEvent.type == sf::Event::Closed)
      {
        window.close();
      }
      if (mEvent.type == sf::Event::KeyPressed)
      {
        if (mEvent.key.code == sf::Keyboard::Escape)
          window.close();
        mKeyMap[mEvent.key.code] = true;
      }
      else if (mEvent.type == sf::Event::KeyReleased)
      {
        mKeyMap[mEvent.key.code] = false;
      }
    }
  }

  bool EventManager::isKeyPressed(sf::Keyboard::Key key)
  {
    return mKeyMap[key];
  }
}