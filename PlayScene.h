#pragma once

#include "Scene.h"
#include "Game.h"
#include "EntitySystem.h"
#include "PlayerEntity.h"
#include "EnemyEntity.h"
#include "BulletEntity.h"
#include "CameraController.h"
#include "CameraComponent.h"
#include "UIManager.h"
#include "EnemyPrototype.h"
#include "BulletPrototype.h"
#include "SoundManager.h"
#include <memory>
#include <vector>

class PlayScene : public Scene
{
private:
    // �G���e�B�e�B��UI
    EntitySystem m_entitySystem;
    std::shared_ptr<PlayerEntity> m_player;
    std::vector<std::shared_ptr<EnemyEntity>> m_enemies;
    std::vector<std::shared_ptr<BulletEntity>> m_playerBullets;
    std::vector<std::shared_ptr<EnemyBulletEntity>> m_enemyBullets;

    // �X�R�A�E�^�C�}�[�Ȃ�
    int m_enemyTimer;
    int m_score;
    int m_bulletCooldown;

    // ���f���n���h��
    int m_playerModelHandle;
    int m_enemyModelHandle;

    // �J����
    std::shared_ptr<CameraComponent> m_cameraComponent;
    std::unique_ptr<CameraController> m_cameraController;

    // UI
    std::unique_ptr<UIManager> m_uiManager;

    // �v���g�^�C�v
    std::shared_ptr<EnemyPrototype> m_enemyPrototype;
    std::shared_ptr<BulletPrototype> m_bulletPrototype;

    // �w�i�摜�n���h��
    int m_backgroundHandle;

	// �X�R�A�w�i�摜�n���h��
	int m_scoreBackgroundHandle;

	// �n�ʂ̉摜�n���h��
	int m_groundTextureHandle;

    int m_shootSEHandle;  // �e���ˉ�SE�n���h��

    // �T�E���h
    SoundManager m_soundManager;

public:
    PlayScene(int playerModel, int enemyModel);
    void Update(Game& game) override;
    void Draw() override;
};