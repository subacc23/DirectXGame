#pragma once

class Object3D;
class InputKey;
class Camera;

class PlayerController
{
private:
    Object3D &object3D;
    InputKey &ik;
    Camera &camera;

    float eyeAngle;

    // 移動
    void Move();

    // カメラの回転
    void RotateCamera();
public:
    PlayerController(Object3D &object3D,
                     InputKey &ik,
                     Camera &camera);
    ~PlayerController();

    // 更新処理
    void Update();
};