#pragma once
// #include <SDL2/SDL.h>
#include <vector>
#include "rgb24.h"
#include <cstdint>

class Window_Display {
private:
    // SDL_Window* window = nullptr;
    // SDL_Renderer* renderer = nullptr;
    // std::vector<SDL_Color> pixels;
    int width;
    int height;

    // SDL_Color rgb24ToSDLColor(rgb24 color) {
    //     return SDL_Color{color.R, color.G, color.B, 255};
    // }

public:
    static constexpr int PIXEL_SIZE = 10;  // how large each pixel appears

    Window_Display(int grid_width, int grid_height);
    ~Window_Display();

    void setPixel(int x, int y, rgb24 color);
    void clear(rgb24 color = {0, 0, 0});
    void render();
    bool pollEvents();
};
