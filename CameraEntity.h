#pragma once
#include "Entity.h"
#include "CameraComponent.h"
#include "CameraController.h"
#include <memory>

class CameraEntity : public Entity
{
public:
    CameraEntity();

    void Update() override;

    std::shared_ptr<CameraComponent> GetCameraComponent() const { return m_cameraComponent; }
    std::shared_ptr<CameraController> GetCameraController() const { return m_cameraController; }

private:
    std::shared_ptr<CameraComponent> m_cameraComponent;
    std::shared_ptr<CameraController> m_cameraController;
};

//#pragma once
//
//#include "Entity.h"
//#include "CameraComponent.h"
//#include "CameraController.h"
//#include <memory>
//
//// �J�����G���e�B�e�B�F�V�[���ɔz�u�����J����
//class CameraEntity : public Entity
//{
//public:
//    CameraEntity();
//
//    std::shared_ptr<CameraController> GetCameraController();  // �� �ǉ�
//
//private:
//    std::shared_ptr<CameraComponent> m_cameraComponent;
//    std::shared_ptr<CameraController> m_cameraController;
//};
