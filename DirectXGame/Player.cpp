#include "Player.h"
#include "Object3D.h"
#include "Camera.h"
#include "InputKey.h"
#include "InputMouse.h"

#include <dinput.h>

using namespace DirectX;

Player::Player(Object3D &object3D,
               Camera &camera):
    object3D(object3D), camera(camera)
{
    eyeAngle = 0.0f;
}

Player::~Player()
{
}

// 移動
void Player::Move()
{
    // 左
    if ( InputKey::GetInstance()->IsKeyPress(DIK_A) )
    {
        object3D.MoveX(-1.0f);
    }

    // 右
    if ( InputKey::GetInstance()->IsKeyPress(DIK_D) )
    {
        object3D.MoveX(1.0f);
    }

    // 上
    if ( InputKey::GetInstance()->IsKeyPress(DIK_W) )
    {
        object3D.MoveY(1.0f);
    }

    // 下
    if ( InputKey::GetInstance()->IsKeyPress(DIK_S) )
    {
        object3D.MoveY(-1.0f);
    }

    // 奥
    if ( InputKey::GetInstance()->IsKeyPress(DIK_Q) )
    {
        object3D.MoveZ(1.0f);
    }

    // 手前
    if ( InputKey::GetInstance()->IsKeyPress(DIK_E) )
    {
        object3D.MoveZ(-1.0f);
    }
}

// カメラの回転
void Player::RotateCamera()
{
    // 左回転
    if ( InputKey::GetInstance()->IsKeyPress(DIK_LEFT) )
    {
        eyeAngle += XMConvertToRadians(1.0f);

        // Y軸まわりに回転
        camera.RotateBaseY(eyeAngle);
    }

    // 右回転
    if ( InputKey::GetInstance()->IsKeyPress(DIK_RIGHT) )
    {
        eyeAngle -= XMConvertToRadians(1.0f);

        // Y軸まわりに回転
        camera.RotateBaseY(eyeAngle);
    }

    // 上回転
    if ( InputMouse::GetInstance()->IsMousePress(DIM_LEFT) )
    {
        eyeAngle += XMConvertToRadians(1.0f);
        camera.RotateBaseX(eyeAngle);
    }

    // 下回転
    if ( InputMouse::GetInstance()->IsMousePress(DIM_RIGHT) )
    {
        eyeAngle -= XMConvertToRadians(1.0f);
        camera.RotateBaseX(eyeAngle);
    }
}

// 更新処理
void Player::Update()
{
    Move();
    RotateCamera();

    // ポリゴンの回転
    // 左
    if ( InputKey::GetInstance()->IsKeyPress(DIK_Z) )
    {
        object3D.RotateY(0.5f);
    }

    // 右
    if ( InputKey::GetInstance()->IsKeyPress(DIK_X) )
    {
        object3D.RotateY(-0.5f);
    }

    // 上
    if ( InputKey::GetInstance()->IsKeyPress(DIK_C) )
    {
        object3D.RotateX(0.5f);
    }

    // 下
    if ( InputKey::GetInstance()->IsKeyPress(DIK_V) )
    {
        object3D.RotateX(-0.5f);
    }
}