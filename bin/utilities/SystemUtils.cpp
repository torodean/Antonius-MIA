/**
 * File: SystemUtils.cpp
 * Author: Antonius Torode
 * Date: 03/09/2021
 * Description:
 */

#include <thread>
#include <chrono>
#include "SystemUtils.hpp"

void SystemUtils::sleepMilliseconds(int time = 500)
{
    std::this_thread::sleep_for (std::chrono::milliseconds(time));
}

void SystemUtils::sleepMinutes(int time = 1)
{
    std::this_thread::sleep_for (std::chrono::minutes(time));
}

void SystemUtils::sleepSeconds(int time = 1)
{
    std::this_thread::sleep_for (std::chrono::seconds(time));
}
