#include "Player.h"
#include "PlayerController.h"
#include "PlayerAnimator.h"

Player::Player()
    : m_player(),
      m_veloctiy(3.5f, 3.5f),
      hitbox(sf::Vector2f{0., 0.}, sf::Vector2f{0., 0.}),
      m_animator(new PlayerAnimator(*this, TextureManager::get_player_texture(), 4, 4, 0.15f)),
      m_controller(new PlayerController()),
      pstate(PlayerState::IDLE),
      pfacingDirection(PlayerFacingDirection::RIGHT)
{
    //initTexture();
    m_size.x = m_player.getTextureRect().width;
    m_size.y = m_player.getTextureRect().height;
    sf::Vector2f origin(m_size.x / 2.f, m_size.y / 2.f);
    hitbox.setSize({m_size.x - 30.f, m_size.y - 50.f});
    hitbox.setPosition({m_player.getPosition().x, m_player.getPosition().y + 20.f});
    this->m_player.setOrigin(origin);
}

Player::~Player()
{
    delete m_animator;
    delete m_controller;
}

void Player::initTexture()
{
    m_player.setTexture(TextureManager::get_player_texture());
    float w = TextureManager::get_player_texture().getSize().x;
    float h = TextureManager::get_player_texture().getSize().y;
    m_player.setTextureRect(sf::IntRect(0, 0, w / 4, h / 4));
}

sf::Vector2f Player::getPosition() const
{
    return m_player.getPosition();
}

void Player::setPosition(const sf::Vector2f& pos) 
{
    m_player.setPosition(pos);
}

sf::Sprite& Player::getObject() 
{
    return m_player; 
}

sf::Vector2f& Player::getVelocity() 
{
    return m_veloctiy; 
}

void Player::setVelocity(const sf::Vector2f& vel) 
{
    this->m_veloctiy = vel;
}

void Player::update(Tilemap& map)
{
    hitbox.update({m_player.getPosition().x, m_player.getPosition().y});
    m_controller->update(*this, map);
    m_animator->switchAnimation(*this);
    m_animator->update();
    // hitbox.update({m_player.getPosition().x, m_player.getPosition().y + 20.f});
}

void Player::render(sf::RenderWindow& window) 
{
    window.draw(m_player);
    // hitbox.render(window);
}


