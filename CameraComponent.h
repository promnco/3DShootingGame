// CameraComponent.h
#pragma once

#include "Component.h"
#include "DxLib.h"

// �J�����̈ʒu�E�����_�E�A�b�v�x�N�g�����Ǘ�����R���|�[�l���g
class CameraComponent : public Component
{
public:
    CameraComponent();

    void SetPosition(const VECTOR& pos);
    void SetTarget(const VECTOR& target);
    void SetUpVector(const VECTOR& up);

    VECTOR GetPosition() const;
    VECTOR GetTarget() const;
    VECTOR GetUpVector() const;

    void ApplyToDxLibCamera() const;

    void Update() override;
    void Draw() override;

private:
    VECTOR m_position;
    VECTOR m_target;
    VECTOR m_upVector;
};

//#pragma once
//#include "Component.h"
//#include "DxLib.h"
//
//// �J�����̏�ԁi�ʒu�E�����_�E����Ȃǁj��ێ�����R���|�[�l���g
//class CameraComponent : public Component
//{
//public:
//	// �J�v�Z�����̊ϓ_���珫���I�Ƀ����o�ϐ���private�ɂ���
//
//    // �J�����̈ʒu
//    VECTOR m_cameraPosition;
//
//    // �����_�i�J��������������̍��W�j
//    VECTOR m_target;
//
//    // ������x�N�g���i�ʏ� VGet(0, 1, 0)�j
//    VECTOR m_up;
//
//    // ����p�i���W�A���P�ʁj
//    float m_fov;
//
//    // �N���b�v����
//    float m_nearClip;
//    float m_farClip;
//
//    // �R���X�g���N�^
//    CameraComponent();
//
//    // �e��ݒ�
//    void SetPosition(const VECTOR& pos);
//    void SetTarget(const VECTOR& tgt);
//    void SetUpVector(const VECTOR& upVec);
//
//    // DxLib�̃J�����ɔ��f
//    void ApplyToDxLibCamera() const;
//
//    // Component �̏������z�֐��������i������j
//    void Draw() override;
//};