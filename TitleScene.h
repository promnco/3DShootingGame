#pragma once

#include "Scene.h"
#include "Game.h"
#include "CameraController.h"
#include "CameraComponent.h"
#include "UIManager.h"
#include <memory>

// �^�C�g���V�[��
class TitleScene : public Scene
{
private:
    int m_playerModelHandle;
    int m_enemyModelHandle;

    std::shared_ptr<CameraComponent> m_cameraComponent;
    std::unique_ptr<CameraController> m_cameraController;

    std::unique_ptr<UIManager> m_uiManager;
    int m_animTimer;

public:
    TitleScene(int playerModel, int enemyModel);
    void Update(Game& game) override;
    void Draw() override;
};

//#pragma once
//
//#include "Scene.h"
//#include "Game.h"
//#include "CameraController.h"
//#include "CameraComponent.h"
//#include "UIManager.h"
//#include <memory>
//
//// �^�C�g���V�[��
//class TitleScene : public Scene
//{
//private:
//	// ���f���͌���g�p���Ă��Ȃ��������I�Ɏg�p����\�������邽��
//
//    // �v���C���[�L�����N�^�[��3D���f���n���h��
//    int m_playerModelHandle;
//
//    // �G�L�����N�^�[��3D���f���n���h��
//    int m_enemyModelHandle;
//
//    // �ȉ��̕ϐ��̌^�͒����Ȃ邽�߁Acpp���ł͒Z�k�ړI�Ƃ���
//	// auto�̌^���_��p���Ă���
//
//    // �^�C�g���p�J�����̃R���|�[�l���g
//    // Transform��ʂ��ăJ�����ʒu�E�����̐�����s��
//    std::shared_ptr<CameraComponent> m_cameraComponent;
//
//    // �J��������N���X
//    // ��������]������Ȃǂ̉��o�Ɏg�p
//    std::unique_ptr<CameraController> m_cameraController;
//
//    // UI�̊Ǘ��N���X�i�{�^���⃍�S�̕\����S���j
//    std::shared_ptr<UIManager> m_uiManager;
//
//    // �A�j���[�V�����p�^�C�}�[�i���S�̗h��ȂǂɎg�p�j
//    int m_animTimer;
//
//public:
//    // �R���X�g���N�^�F�v���C���[�E�G���f���̃n���h�����󂯎��
//    TitleScene(int playerModel, int enemyModel);
//
//    // �V�[���X�V�����i���͏�����A�j���[�V�����i�s�Ȃǁj
//    void Update(Game& game) override;
//
//    // �`�揈���i3D���f���A�J�����AUI�Ȃǂ�`��j
//    void Draw() override;
//};