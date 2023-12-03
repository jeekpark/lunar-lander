/**
 * @file common.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
#include <ctime>
#include <sstream>
#include <random>
#include <iomanip>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "llan/Helper/Vec2.hpp"

#define LLAN_VERSION        "0.0.1a"
#define WINDOW_X            1280
#define WINDOW_Y            720
#define FRAME_PER_SECOND    60.f
#define TIME_STEP_MS        16.66667f
#define TIME_STEP_S         0.016667f
#define MAIN_FONT_PATH      "resources/Minecraft.ttf"

#define LUNAR_GRAVITY_ACCELERATION  1.625f // 1.625m/s^2
#define LUNAR_MODULE_WEIGHT         15188.f // 15188kg

