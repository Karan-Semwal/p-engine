#include "Util.h"

// float toPixel(float meterData)
// {
//     return meterData * scale;
// }

// float toMeter(float pixelData)
// {
//     return pixelData / scale;
// }

// b2Vec2 tobv(const sf::Vector2f& sfVec2) {
//     b2Vec2 vec2;
//     vec2.x = sfVec2.x / scale;
//     vec2.y = sfVec2.y / scale;
//     return vec2;
// }

// sf::Vector2f tosfv(const b2Vec2& b2ve2) {
//     sf::Vector2f vec2;
//     vec2.x = b2ve2.x * scale;
//     vec2.y = b2ve2.y * scale;
//     return vec2;
// }

// ------------------------------------------------------ //

float lerpValue(float currentValue, float targetValue, float interpolationPoint)
{
    currentValue += interpolationPoint;
    if (currentValue > targetValue) {
        return targetValue;
    }
    return currentValue;
}

sf::Vector2f operator+(sf::Vector2f& v1, sf::Vector2f& v2)
{
    sf::Vector2f resultPlus;
    resultPlus.x = v1.x + v2.x;
    resultPlus.y = v1.y + v2.y;
    return resultPlus;
}

sf::Vector2f operator-(sf::Vector2f& v1, sf::Vector2f& v2)
{
    sf::Vector2f resultMinus;
    resultMinus.x = v1.x - v2.x;
    resultMinus.y = v1.y - v2.y;
    return resultMinus;
}

sf::Vector2f operator*(sf::Vector2f& v1, sf::Vector2f& v2)
{
    sf::Vector2f resultMult;
    resultMult.x = v1.x * v2.x;
    resultMult.y = v1.y * v2.y;
    return resultMult;
}

sf::Vector2f operator+(sf::Vector2f& v, float n)
{
    sf::Vector2f resultDiv;
    resultDiv.x = v.x + n;
    resultDiv.y = v.y + n;
    return resultDiv;
}

sf::Vector2f operator-(sf::Vector2f& v, float n)
{
    sf::Vector2f resultDiv;
    resultDiv.x = v.x - n;
    resultDiv.y = v.y - n;
    return resultDiv;
}

sf::Vector2f operator*(sf::Vector2f& v, float n)
{
    sf::Vector2f result;
    result.x = v.x * n;
    result.y = v.y * n;
    return result;
}

sf::Vector2f operator/(sf::Vector2f& v, float n)
{
    sf::Vector2f resultDiv;
    resultDiv.x = v.x / n;
    resultDiv.y = v.y / n;
    return resultDiv;
}

sf::Vector2f normalize(const sf::Vector2f& v)
{
    float mag = std::sqrt((v.x)*(v.x) + (v.y) * (v.y));
    sf::Vector2f dir(v.x / mag, v.y / mag);
    return dir;
}

float DegToRadian(float degree)
{
    return degree * PI / 180.0f;
}

int randomInteger(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

sf::Vector2f randomVector2f(int min, int max)
{
    sf::Vector2f dir;
    dir.x = randomInteger(min, max);
    dir.y = randomInteger(min, max);
    return dir;
}

void operator<<(std::ostream& os, sf::Vector2f v)
{
    os << v.x << ", " << v.y << std::endl;
}

sf::Color randomColor() {
    sf::Color color;
    color.r = randomInteger(0, 255);
    color.g = randomInteger(0, 255);
    color.b = randomInteger(0, 255);
    return color;
}

