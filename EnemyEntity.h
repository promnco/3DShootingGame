#pragma once
#include "Entity.h"
#include "TransformComponent.h"
#include "RenderModelComponent.h"
#include "EnemyBulletEntity.h"
#include <memory>               // std::shared_ptr ���g�p���邽�߂̃w�b�_�[�t�@�C��
#include <vector>               // std::vector ���g�p���邽�߂̃w�b�_�[�t�@�C��

// �G�L�����N�^�[�̃G���e�B�e�B���Ǘ�����N���X
// �G�̈ʒu�A�ړ��A�U���AAI�Ȃǂ̏������s���܂��B
class EnemyEntity : public Entity
{
public:
    // TransformComponent �͈ʒu�⑬�x���Ǘ�����
    std::shared_ptr<TransformComponent> m_enemyTransform;

    // �e���˂̃^�C�}�[�i�G���e�𔭎˂���^�C�~���O���Ǘ��j
    int m_shotTimer;

    // �R���X�g���N�^
    EnemyEntity(int modelHandle, VECTOR pos);

    // UpdateAI ���\�b�h�F�G��AI���X�V���A�^�[�Q�b�g�i�v���C���[�j�Ɋ�Â��ē��������
    // target �̓v���C���[�̈ʒu�Abullets �͓G�̒e�̃��X�g
    void UpdateAI(VECTOR target, std::vector<std::shared_ptr<EnemyBulletEntity>>& bullets);
};
