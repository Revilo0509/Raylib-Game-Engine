#include "objects/composites.hpp"

namespace RRE::Objects {

void Object::draw() { DrawTextureV(*texture, pos, WHITE); }

Player::Player(RREVec2 i_pos) : Movable(i_pos) {
    speed = 6;
    velocity = Velocity(0.0f, 0.0f);
}

void Player::update() {
    velocity.velocity.x = 0.0f;
    velocity.velocity.y = 0.0f;

    if (IsKeyDown(KEY_W))
        velocity.velocity.y = -speed;
    if (IsKeyDown(KEY_S))
        velocity.velocity.y = speed;
    if (IsKeyDown(KEY_A))
        velocity.velocity.x = -speed;
    if (IsKeyDown(KEY_D))
        velocity.velocity.x = speed;

    Movable::update();
}

} // namespace RRE::Objects