#include "objects/composites.hpp"

namespace RRE::Objects {

Object::Object(Texture2D *tex, Vector2 i_pos) : pos(i_pos), texture(tex) {}
void Object::draw() { DrawTextureV(*texture, pos, WHITE); }

void Player::update() {
    if (IsKeyDown(KEY_W)) {
        pos.y -= speed;
    }
    if (IsKeyDown(KEY_S)) {
        pos.y += speed;
    }
    if (IsKeyDown(KEY_A)) {
        pos.x -= speed;
    }
    if (IsKeyDown(KEY_D)) {
        pos.x += speed;
    }
}
} // namespace RRE::Objects