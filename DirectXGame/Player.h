#pragma once

class Object3D;
class Camera;

class Player
{
private:
    Object3D &object3D;
    Camera &camera;

    float eyeAngle;

    // 移動
    void Move();

    // カメラの回転
    void RotateCamera();

public:
    Player(Object3D &object3D,
           Camera &camera);
    ~Player();

    // 更新処理
    void Update();
};