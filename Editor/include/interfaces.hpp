#pragma once

class gameObject {
  public:
    virtual ~gameObject() = default;
};

class updatable : public gameObject {
  public:
    updatable();
    virtual void update() = 0;
};

class drawable : public gameObject {
  public:
    drawable();
    virtual void draw() = 0;
};

class updatableHandler;
class drawableHandler;

updatableHandler &getUpdatableHandler();
drawableHandler &getDrawableHandler();
