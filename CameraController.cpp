// CameraController.cpp
#include "CameraController.h"

CameraController::CameraController(std::shared_ptr<CameraComponent> camera)
    : m_camera(camera)
{
}

void CameraController::SetTarget(std::shared_ptr<TransformComponent> target)
{
    m_target = target;
}

void CameraController::Update()
{
    if (!m_camera || !m_target) return;

    VECTOR targetPos = m_target->position;

    // プレイヤーの右肩後方・斜め上から見下ろす位置（調整可能）
    VECTOR offset = VGet(0.0f, 20.0f, -40.0f);

    VECTOR cameraPos = VAdd(targetPos, offset);

    // カメラ位置・注視点を更新
    m_camera->SetPosition(cameraPos);
    m_camera->SetTarget(targetPos);

    // ニア／ファークリップを毎フレーム適用（必要に応じて初期化時だけにしてもOK）
    SetCameraNearFar(1.0f, 500.0f);

    // DxLibに適用
    m_camera->ApplyToDxLibCamera();
}

//void CameraController::Update()
//{
//    if (!m_camera || !m_target) return;
//
//    // 直接メンバー変数にアクセス（リファクタリングなし）
//    VECTOR targetPos = m_target->position;
//
//    VECTOR cameraPos = VAdd(targetPos, VGet(0.0f, 10.0f, -30.0f));
//
//    m_camera->SetPosition(cameraPos);
//    m_camera->SetTarget(targetPos);
//    m_camera->ApplyToDxLibCamera();
//}


//#include "CameraController.h"
//
//// コンストラクタ：CameraComponent を外部から受け取る
//CameraController::CameraController(std::shared_ptr<CameraComponent> camera)
//    : m_camera(camera)
//{
//}
//
//// 追従する対象（Transform）をセット
//void CameraController::SetTarget(std::shared_ptr<TransformComponent> target)
//{
//    m_target = target;
//}
//
//// 毎フレームのカメラ追従処理
//void CameraController::Update()
//{
//    if (!m_camera || !m_target)
//        return;
//
//    VECTOR targetPos = m_target->position;
//
//    // カメラの位置を対象の後ろ斜め上に設定（例：トップダウン風）
//    VECTOR cameraPos = VAdd(targetPos, VGet(0.0f, 10.0f, -30.0f));
//
//    m_camera->SetPosition(cameraPos);
//    m_camera->SetTarget(targetPos);
//
//    // カメラの設定をDxLibに適用
//    m_camera->ApplyToDxLibCamera();
//}