#include "EnemyEntity.h"
#include "EnemyBulletEntity.h"
#include <cmath>                 // ���w�I�Ȍv�Z���s�����߂̃w�b�_�[�t�@�C��

// �R���X�g���N�^
// modelHandle �͓G���f���̎��ʗp�n���h���Apos �͓G�̏����ʒu
EnemyEntity::EnemyEntity(int modelHandle, VECTOR pos)
{
    active = true;  // �G���e�B�e�B���A�N�e�B�u��Ԃɐݒ�

    // TransformComponent ���쐬���A�ʒu��ݒ�
    m_enemyTransform = std::make_shared<TransformComponent>(pos);

    // TransformComponent ���G���e�B�e�B�ɒǉ�
    AddComponent(m_enemyTransform);

    // RenderModelComponent ���쐬���A�G���f����ݒ�
    AddComponent(std::make_shared<RenderModelComponent>(modelHandle, m_enemyTransform));

    // �e���˃^�C�}�[��������
    m_shotTimer = 0;
}

// UpdateAI ���\�b�h�F�G��AI���X�V���A�^�[�Q�b�g�i�ʏ�̓v���C���[�j�̈ʒu�Ɋ�Â��ē��������
void EnemyEntity::UpdateAI(VECTOR target, std::vector<std::shared_ptr<EnemyBulletEntity>>& bullets)
{
    // �^�[�Q�b�g�i�v���C���[�j�Ƃ̈ʒu�x�N�g�����v�Z
    VECTOR dir = VSub(target, m_enemyTransform->position);

    // �x�N�g���̒����i�����j���v�Z
    float len = VSize(dir);

    // �^�[�Q�b�g�Ƃ̋������\���ł���΁A�^�[�Q�b�g�����Ɍ��������x��ݒ�
    if (len > 0.01f)
    {
        // �x�N�g���𐳋K���i�P�ʃx�N�g���ɂ���j
        dir = VScale(dir, 1.0f / len);
        // �G�̑��x��ݒ�i���x�x�N�g�����^�[�Q�b�g�����ɐݒ�j
        m_enemyTransform->velocity = VScale(dir, 0.2f);  // 0.2f �͈ړ����x
    }
    else
    {
        // �^�[�Q�b�g�ɋ߂�����ꍇ�͒�~
        m_enemyTransform->velocity = VGet(0, 0, 0);
    }

    // �e���˃^�C�}�[��i�߂�
    if (++m_shotTimer > 120)
    {
        m_shotTimer = 0;  // �^�C�}�[�����Z�b�g
        // �e���˕������v�Z�i�^�[�Q�b�g�����j
        VECTOR shotDir = VSub(target, m_enemyTransform->position);
		// �e���˕����̒������v�Z
        float sLen = VSize(shotDir);

        // �^�[�Q�b�g�Ɍ����Ēe�𔭎�
        if (sLen > 0.01f)
        {
            // �e�̔��˕����𐳋K��
            shotDir = VScale(shotDir, 1.0f / sLen);
            // �e�𐶐����A�e�̃��X�g�ɒǉ�
            bullets.push_back(std::make_shared<EnemyBulletEntity>(m_enemyTransform->position, shotDir));
        }
    }
}