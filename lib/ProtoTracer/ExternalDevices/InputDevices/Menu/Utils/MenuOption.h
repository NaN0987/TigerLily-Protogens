/**
 * @file MenuOption.h
 * @brief Provides a struct for organizing menu options.
 *
 * This file defines a simple struct, MenuOption, which contains all of the data
 * associated with a single menu option.
 *
 * @date 12/10/2025
 * @author NaN0987
 */

#pragma once

struct MenuOption {
    int currentValue;         ///< The current value of the option.
    const int maxValue;       ///< The maximum value the option can take.
    const String optionName;  ///< The name of the option.
    const bool isOnOff;       ///< If true, the menu will have the options "ON" and "OFF".
};