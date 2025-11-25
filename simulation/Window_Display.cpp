#include "Window_Display.h"
#include <stdexcept>

Window_Display::Window_Display(int grid_width, int grid_height) : width(grid_width), height(grid_height) {
    // if (SDL_Init(SDL_INIT_VIDEO) != 0)
    //     throw std::runtime_error("Failed to initialize SDL");

    // window = SDL_CreateWindow(
    //     "ProtoTracer Sim",
    //     SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    //     width * PIXEL_SIZE, height * PIXEL_SIZE,
    //     SDL_WINDOW_SHOWN
    // );

    // if (!window)
    //     throw std::runtime_error("Failed to create window");

    // renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    // if (!renderer)
    //     throw std::runtime_error("Failed to create renderer");

    // pixels.resize(width * height);
    // clear();
}

Window_Display::~Window_Display() {
    // if (renderer) SDL_DestroyRenderer(renderer);
    // if (window) SDL_DestroyWindow(window);
    // SDL_Quit();
}

void Window_Display::setPixel(int x, int y, rgb24 color) {
    // if (x < 0 || x >= width || y < 0 || y >= height)
    //     return;  // ignore out of bounds
    // pixels[y * width + x] = rgb24ToSDLColor(color);
}

void Window_Display::clear(rgb24 color) {
    // std::fill(pixels.begin(), pixels.end(), rgb24ToSDLColor(color));
}

void Window_Display::render() {
    // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    // SDL_RenderClear(renderer);

    // for (int y = 0; y < height; ++y) {
    //     for (int x = 0; x < width; ++x) {
    //         SDL_Color c = pixels[y * width + x];
    //         SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    //         SDL_Rect rect = {x * PIXEL_SIZE, y * PIXEL_SIZE, PIXEL_SIZE, PIXEL_SIZE};
    //         SDL_RenderFillRect(renderer, &rect);
    //     }
    // }

    // SDL_RenderPresent(renderer);
}

bool Window_Display::pollEvents() {
    // SDL_Event e;
    // while (SDL_PollEvent(&e)) {
    //     if (e.type == SDL_QUIT)
    //         return false;
    // }
    return true;
}
