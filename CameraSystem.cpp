#include "CameraSystem.h"

// CameraSystem�̃R���X�g���N�^
void CameraSystem::AddCamera(const std::shared_ptr<CameraComponent>& camera)
{
	// push_back�ŃJ������ǉ�
    m_cameras.push_back(camera);

    // �ŏ��ɒǉ����ꂽ�J�������A�N�e�B�u�ɂ���
    if (m_activeCameraIndex == -1)
    {
        m_activeCameraIndex = 0;
    }
}

void CameraSystem::SetActiveCamera(int index)
{
	// �C���f�b�N�X���L���Ȕ͈͓��ł���΃A�N�e�B�u�J������ݒ�
    if (index >= 0 && index < static_cast<int>(m_cameras.size()))
    {
        m_activeCameraIndex = index;
    }
}

std::shared_ptr<CameraComponent> CameraSystem::GetActiveCamera() const
{
	// �A�N�e�B�u�ȃJ�������L���ȃC���f�b�N�X�ł���ΕԂ�
    if (m_activeCameraIndex >= 0 && m_activeCameraIndex < static_cast<int>(m_cameras.size()))
    {
        return m_cameras[m_activeCameraIndex];
    }
    return nullptr;
}

void CameraSystem::ApplyActiveCamera()
{
	// auto�L�[���[�h���g�p���ăA�N�e�B�u�ȃJ�������擾
    auto camera = GetActiveCamera();
    if (camera)
    {
        camera->ApplyToDxLibCamera();
    }
}

int CameraSystem::GetCameraCount() const
{
    return static_cast<int>(m_cameras.size());
}