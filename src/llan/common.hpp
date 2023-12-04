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
#include <SFML/Audio.hpp>

#include "llan/Helper/Vec2.hpp"

#define LLAN_VERSION        	"0.0.1a"
#define WINDOW_X            	1280
#define WINDOW_Y            	720
#define FRAME_PER_SECOND    	60.f
#define TIME_STEP_MS        	16.66667f
#define TIME_STEP_S         	0.016667f
#define MAIN_FONT_PATH      	"resources/Minecraft.ttf"
#define STARSHIP_SPRITE_PATH  "resources/starshipSpriteSheet.png"


/**
 * @brief The gravity acceleration of Moon
 * @note 1.625m/s^2
 */
#define LUNAR_GRAVITY_ACCELERATION  1.625f

/**
 * @brief Weight of Appolo-13 lunar module
 * @note 15188kg
 */
#define LUNAR_MODULE_WEIGHT_KG      4672.0014f

/**
 * @brief Height of Appolo-13 lunar module.
 * @note 4.2m
 */
#define LUNAR_MODULE_HEIGHT_M       4.2f

/**
 * @brief Force(newton) of Applo-13 lunar module.
 * @note APS thrust: 3,500 lbf, 15568.7756 newton 
 */
#define LUNAR_MOUDLE_THRUST_FORCE 	15568.7756f * 10.f


/**
 * @brief Thrust accelation of Appolo-13 lunar module.
 * @note F = MA, A = F/M, (force) / (weight)
 */
#define LUNAL_MODULE_THRUST_ACCELERATION   LUNAR_MOUDLE_THRUST_FORCE / LUNAR_MODULE_WEIGHT_KG