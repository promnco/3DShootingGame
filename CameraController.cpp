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

    // �v���C���[�̉E������E�΂ߏォ�猩���낷�ʒu�i�����\�j
    VECTOR offset = VGet(0.0f, 20.0f, -40.0f);

    VECTOR cameraPos = VAdd(targetPos, offset);

    // �J�����ʒu�E�����_���X�V
    m_camera->SetPosition(cameraPos);
    m_camera->SetTarget(targetPos);

    // �j�A�^�t�@�[�N���b�v�𖈃t���[���K�p�i�K�v�ɉ����ď������������ɂ��Ă�OK�j
    SetCameraNearFar(1.0f, 500.0f);

    // DxLib�ɓK�p
    m_camera->ApplyToDxLibCamera();
}

//void CameraController::Update()
//{
//    if (!m_camera || !m_target) return;
//
//    // ���ڃ����o�[�ϐ��ɃA�N�Z�X�i���t�@�N�^�����O�Ȃ��j
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
//// �R���X�g���N�^�FCameraComponent ���O������󂯎��
//CameraController::CameraController(std::shared_ptr<CameraComponent> camera)
//    : m_camera(camera)
//{
//}
//
//// �Ǐ]����ΏہiTransform�j���Z�b�g
//void CameraController::SetTarget(std::shared_ptr<TransformComponent> target)
//{
//    m_target = target;
//}
//
//// ���t���[���̃J�����Ǐ]����
//void CameraController::Update()
//{
//    if (!m_camera || !m_target)
//        return;
//
//    VECTOR targetPos = m_target->position;
//
//    // �J�����̈ʒu��Ώۂ̌��΂ߏ�ɐݒ�i��F�g�b�v�_�E�����j
//    VECTOR cameraPos = VAdd(targetPos, VGet(0.0f, 10.0f, -30.0f));
//
//    m_camera->SetPosition(cameraPos);
//    m_camera->SetTarget(targetPos);
//
//    // �J�����̐ݒ��DxLib�ɓK�p
//    m_camera->ApplyToDxLibCamera();
//}