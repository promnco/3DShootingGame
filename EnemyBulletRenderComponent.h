#pragma once
#include "Component.h"
#include "TransformComponent.h"  
#include <memory>                // std::shared_ptr ���g�p���邽�߂̃w�b�_�[�t�@�C��

// �G�̒e�̕`���S������R���|�[�l���g
// �G�̒e�����ʒu���iTransform�j���g���āA�e��`�悵�܂��B
class EnemyBulletRenderComponent : public Component
{
public:
    std::shared_ptr<TransformComponent> m_enemyBulletRenderTransform; // �e�̈ʒu����ێ����� TransformComponent

    // �R���X�g���N�^
	// �����ɂ͒e�̈ʒu�������� TransformComponent �̃X�}�[�g�|�C���^���󂯎��
    EnemyBulletRenderComponent(std::shared_ptr<TransformComponent> tf);

    // ���t���[���̍X�V����
	// ���̃N���X�ł͕`��Ɋ֘A���鏈���݂̂̂��ߋ����
    void Update() override;

    // �G�̒e��`��
    void Draw() override;
};
