#include <SFML/Graphics.hpp>
#include <cmath>
#include <random>

inline constexpr float scale = 30.f;
inline constexpr float PI = 3.14f;

// Utils for box2d
// float toPixel(float meterData);
// float toMeter(float pixelData);
//b2Vec2 tobv(const sf::Vector2f& sfVec2);
//sf::Vector2f tosfv(const b2Vec2& b2ve2);

// ------------------------------------------------------ //

float lerpValue(float currentValue, float targetValue, float interpolationPoint);
sf::Vector2f operator+(sf::Vector2f& v1, sf::Vector2f& v2);
sf::Vector2f operator-(sf::Vector2f& v1, sf::Vector2f& v2);
sf::Vector2f operator*(sf::Vector2f& v1, sf::Vector2f& v2);
sf::Vector2f operator+(sf::Vector2f& v, float n);
sf::Vector2f operator-(sf::Vector2f& v, float n);
sf::Vector2f operator*(sf::Vector2f& v, float n);
sf::Vector2f operator/(sf::Vector2f& v, float n);
sf::Vector2f normalize(const sf::Vector2f& v);
sf::Vector2f randomVector2f(int min, int max);
float DegToRadian(float degree);
int randomInteger(int min, int max);
void operator<<(std::ostream& os, sf::Vector2f v);
sf::Color randomColor();







