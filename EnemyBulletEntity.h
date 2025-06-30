#pragma once
#include "Entity.h"
#include "TransformComponent.h"
#include <memory>               // std::shared_ptr ���g�p���邽�߂̃w�b�_�[�t�@�C��

// �G�̒e���Ǘ�����G���e�B�e�B�N���X
// �e�̈ʒu�ƈړ��Ɋւ�����������A�G���甭�˂����e�̃f�[�^���Ǘ����܂��B
class EnemyBulletEntity : public Entity
{
public:
    // �e�̈ʒu�ƈړ����Ǘ����� TransformComponent
    std::shared_ptr<TransformComponent> m_enemyBulletTransform;

    // �R���X�g���N�^
    EnemyBulletEntity(VECTOR startPos, VECTOR dir);
};