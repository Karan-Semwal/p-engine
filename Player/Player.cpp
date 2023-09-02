#include "Player.h"
#include "PlayerController.h"
#include "PlayerAnimator.h"
#include "PlayerCollider.h"

Player::Player()
    : m_player(),
      m_veloctiy(3.f, 3.f),
      m_animator(new PlayerAnimator(*this, TextureManager::get_player_texture(), 4, 4, 0.15f)),
      m_collider(new PlayerCollider(*this)),
      m_controller(new PlayerController()),
      pstate(PlayerState::IDLE),
      pfacingDirection(PlayerFacingDirection::RIGHT)
{
    //initTexture();
    sf::Vector2f origin(m_player.getTextureRect().width / 2.f, m_player.getTextureRect().height / 2.f);
    this->m_player.setOrigin(origin);
}

Player::~Player()
{
    delete m_animator;
    delete m_controller;
    delete m_collider;
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
    sf::Vector2f playerPos = this->getPosition();

    m_collider->update(*this, map);
    m_controller->update(*this, m_collider->collisionSide);
    m_animator->switchAnimation(*this);
    m_animator->update();
}

void Player::render(sf::RenderWindow& window) 
{
    window.draw(m_player);
}


