#include "EnemyBulletEntity.h"
#include "EnemyBulletRenderComponent.h"

// �R���X�g���N�^�F�e�̔��ˈʒu�istartPos�j�ƕ����idir�j���󂯎��AEnemyBulletEntity ��������
// startPos �͒e�̔��ˈʒu�Adir �͒e�̈ړ�������\���x�N�g��
EnemyBulletEntity::EnemyBulletEntity(VECTOR startPos, VECTOR dir)
{
    // TransformComponent ���쐬���A�e�̏����ʒu��ݒ�
    m_enemyBulletTransform = std::make_shared<TransformComponent>(startPos);

    // �����x�N�g���idir�j���X�P�[�����Ĉړ����x��ݒ�
    m_enemyBulletTransform->velocity = VScale(dir, 0.3f);  // �e�̈ړ������Ƒ��x��ݒ�i0.3f �͒e�̑��x�j

    // TransformComponent ���G���e�B�e�B�ɒǉ�
    AddComponent(m_enemyBulletTransform);

    // �e�̕`��R���|�[�l���g�iEnemyBulletRenderComponent�j��ǉ�
    // transform�i�ʒu���j��n���ĕ`����s��
    AddComponent(std::make_shared<EnemyBulletRenderComponent>(m_enemyBulletTransform));  // �`�揈���p�R���|�[�l���g�̒ǉ�
}
