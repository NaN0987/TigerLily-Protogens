#include "Image.h"

Image::Image(const uint8_t* data, const uint8_t* rgbColors, unsigned int xPixels, unsigned int yPixels, uint8_t colors) {
    this->data = data;
    this->rgbColors = rgbColors;
    this->xPixels = xPixels;
    this->yPixels = yPixels;
    this->colors = colors;
}

void Image::SetData(const uint8_t* data) {
    this->data = data;
}

void Image::SetColorPalette(const uint8_t* rgbColors) {
    this->rgbColors = rgbColors;
}

void Image::SetSize(Vector2D size) {
    this->size = size;
}

void Image::SetPosition(Vector2D offset) {
    this->offset = offset;
}

void Image::SetRotation(float angle) {
    this->angle = angle;
}

void Image::SetHueAngle(float hueAngle) {
    this->hueAngle = hueAngle;
}

RGBColor Image::GetRGB(const Vector3D& position, const Vector3D& normal, const Vector3D& uvw) {
    Vector2D rPos = angle != 0.0f ? Vector2D(position.X, position.Y).Rotate(angle, offset) - offset : Vector2D(position.X, position.Y) - offset;

    int x = (int)Mathematics::Map(rPos.X, size.X / -2.0f, size.X / 2.0f, float(xPixels), 0.0f);
    int y = (int)Mathematics::Map(rPos.Y, size.Y / -2.0f, size.Y / 2.0f, float(yPixels), 0.0f);

    if (x < 0 || y < 0)
        return RGBColor();

    if (static_cast<unsigned>(x) >= xPixels ||
        static_cast<unsigned>(y) >= yPixels)
        return RGBColor();

    unsigned int rgbPos = data[x + y * xPixels] * 3;

    if (rgbPos > (colors * 3) - (unsigned int)1) return RGBColor();

    return RGBColor(rgbColors[rgbPos], rgbColors[rgbPos + 1], rgbColors[rgbPos + 2]).HueShift(hueAngle);
}
