// CameraComponent.cpp
#include "CameraComponent.h"

CameraComponent::CameraComponent()
    : m_position(VGet(0, 0, -10)), m_target(VGet(0, 0, 0)), m_upVector(VGet(0, 1, 0)) {
}

void CameraComponent::SetPosition(const VECTOR& pos) { m_position = pos; }
void CameraComponent::SetTarget(const VECTOR& target) { m_target = target; }
void CameraComponent::SetUpVector(const VECTOR& up) { m_upVector = up; }

VECTOR CameraComponent::GetPosition() const { return m_position; }
VECTOR CameraComponent::GetTarget() const { return m_target; }
VECTOR CameraComponent::GetUpVector() const { return m_upVector; }

void CameraComponent::ApplyToDxLibCamera() const
{
    SetCameraPositionAndTargetAndUpVec(m_position, m_target, m_upVector);
}

void CameraComponent::Update() {}
void CameraComponent::Draw() {}

//#include "CameraComponent.h"
//
//// �R���X�g���N�^
//CameraComponent::CameraComponent()
//    : m_cameraPosition(VGet(0.0f, 5.0f, -10.0f))
//    , m_target(VGet(0.0f, 0.0f, 0.0f))
//    , m_up(VGet(0.0f, 1.0f, 0.0f))
//    , m_fov(DX_PI_F / 4.0f)     // ��45�x
//    , m_nearClip(1.0f)
//    , m_farClip(1000.0f)
//{
//}
//
//// �J�����̈ʒu�ݒ�
//void CameraComponent::SetPosition(const VECTOR& pos)
//{
//    m_cameraPosition = pos;
//}
//
//// �����_�̐ݒ�
//void CameraComponent::SetTarget(const VECTOR& tgt)
//{
//    m_target = tgt;
//}
//
//// ������x�N�g���̐ݒ�
//void CameraComponent::SetUpVector(const VECTOR& upVec)
//{
//    m_up = upVec;
//}
//
//// DxLib�ɂ��̃J�����̏���K�p
//void CameraComponent::ApplyToDxLibCamera() const
//{
//    SetCameraPositionAndTarget_UpVecY(m_cameraPosition, m_target);
//    SetCameraNearFar(m_nearClip, m_farClip);
//	// �����I�ɂ�FOV�̐ݒ���ǉ����邩��
//}
//
//// Component �̏������z�֐��̋����
//void CameraComponent::Draw()
//{
//    // �J�������͕̂`��Ώۂł͂Ȃ����߁A�����͋��OK
//}