#include "Player.h"
#include "PlayerController.h"
#include "PlayerAnimator.h"

// Player::Player()
//     : m_player(), m_veloctiy(5.f, 5.f), 
//       m_animator(std::make_unique<PlayerAnimator>(this->getPlayer(), TextureManager::get_player_texture(), 4, 4, 0.15f)),
//       m_controller(std::make_unique<PlayerController>()),
//       pstate(PlayerState::IDLE),
//       pfacingDirection(PlayerFacingDirection::RIGHT)
// {
// }

Player::Player()
    : m_player(), m_veloctiy(5.f, 5.f), 
      m_animator(new PlayerAnimator(this->getPlayer(), TextureManager::get_player_texture(), 4, 4, 0.15f)),
      m_controller(new PlayerController()),
      pstate(PlayerState::IDLE),
      pfacingDirection(PlayerFacingDirection::RIGHT)
{
    initialTexture();
}

void Player::initialTexture()
{
    m_player.setTexture(TextureManager::get_player_texture());
    float w = TextureManager::get_player_texture().getSize().x;
    float h = TextureManager::get_player_texture().getSize().y;
    m_player.setTextureRect(sf::IntRect(0, 0, w / 4, h / 4));
}

sf::Vector2f Player::getPosition() const {
    return m_player.getPosition();
}

void Player::setPosition(const sf::Vector2f& pos) {
    m_player.setPosition(pos);
}

sf::Sprite& Player::getPlayer() {
    return m_player; 
}

sf::Vector2f& Player::getVelocity() {
    return m_veloctiy; 
}

void Player::update() {
    m_controller->update(*this);
    m_animator->switchAnimation(*this);
    m_animator->update();
}

void Player::render(sf::RenderWindow& window) {
    window.draw(m_player);
}


