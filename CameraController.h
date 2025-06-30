// CameraController.h
#pragma once

#include "CameraComponent.h"
#include "TransformComponent.h"
#include <memory>

// �J�����̈ʒu�⒍���_��Ǐ]�E���䂷��R���g���[���[
class CameraController
{
public:
    CameraController(std::shared_ptr<CameraComponent> camera);

    void SetTarget(std::shared_ptr<TransformComponent> target);
    void Update();

private:
    std::shared_ptr<CameraComponent> m_camera;
    std::shared_ptr<TransformComponent> m_target;

    float m_distance = 30.0f;
    float m_height = 10.0f;
};

//#pragma once
//#include "CameraComponent.h"
//#include "TransformComponent.h"
//#include <memory>
//
//// Transform �ɒǏ]���� CameraComponent �𑀍삷��R���g���[���[
//// CameraComponent �́u��ԁv
//// CameraController �́u�����̐���v�ɕ���
//class CameraController
//{
//public:
//    // �J�����̑���ΏہiCameraComponent�j��n��
//    CameraController(std::shared_ptr<CameraComponent> camera);
//
//    // �^�[�Q�b�g�i�Ǐ]�Ώہj��ݒ�
//    void SetTarget(std::shared_ptr<TransformComponent> target);
//
//    // ���t���[���Ă΂��X�V����
//    void Update();
//
//private:
//    std::shared_ptr<CameraComponent> m_camera;
//    std::shared_ptr<TransformComponent> m_target;
//};
