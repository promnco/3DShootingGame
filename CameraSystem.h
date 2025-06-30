#pragma once
#include "CameraComponent.h"
#include <vector>
#include <memory>

// �J�����R���|�[�l���g���Ǘ����A���݃A�N�e�B�u�ȃJ������K�p����V�X�e��
// ���̃V�X�e���́A�����̃J�������Ǘ����A�K�v�ɉ����ăA�N�e�B�u�ȃJ������؂�ւ��邱�Ƃ��ł��܂��B
class CameraSystem
{
public:
    // �J������o�^
    void AddCamera(const std::shared_ptr<CameraComponent>& camera);

    // �A�N�e�B�u�J������؂�ւ���
    void SetActiveCamera(int index);

    // �A�N�e�B�u�J�������擾
    std::shared_ptr<CameraComponent> GetActiveCamera() const;

    // DxLib �J�����Ɍ��݂̃J������K�p
    void ApplyActiveCamera();

    // �o�^�ς݂̃J������
    int GetCameraCount() const;

private:
    std::vector<std::shared_ptr<CameraComponent>> m_cameras;
    int m_activeCameraIndex = -1; // -1 �͖��I�����
};

// Camera�֘A�N���X�̓���
//[CameraController] --->�ʒu�̍X�V�iTransformComponent�j
//��
//[CameraEntity] ------->CameraComponent �ɒl��n���AApplyCamera()
//��
//[CameraComponent] --->SetCameraPositionAndTarget_UpVecY �Ȃǂ� DxLib �ɓK�p
//��
//[CameraSystem]   ---- > �i��������΁j�ǂ� CameraEntity ��`�掞�ɓK�p���邩����