/**
 * @file EventManager.hpp
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

namespace Llan
{
  class EventManager
  {
  public:
    EventManager();
    ~EventManager();

    void handleEventQueue(sf::Window& window);
    bool isKeyPressed(sf::Keyboard::Key key);
  private:
    sf::Event mEvent;
    std::map<sf::Keyboard::Key, bool> mKeyMap;
  };
}