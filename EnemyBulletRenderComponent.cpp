#include "EnemyBulletRenderComponent.h"
#include "DxLib.h"

// �R���X�g���N�^
EnemyBulletRenderComponent::EnemyBulletRenderComponent(std::shared_ptr<TransformComponent> tf)
	: m_enemyBulletRenderTransform(tf)      // TransformComponent���󂯎��
{
    // TransformComponent�i�e�̈ʒu�j��ݒ�
}

// ���t���[���̍X�V����
// ���̃N���X�ł͈ʒu�̍X�V�Ȃǂ͍s�킸�ATransformComponent �ɂ���ĊǗ�
void EnemyBulletRenderComponent::Update()
{
    // �ʒu�̍X�V�� TransformComponent ���S��
}

// �G�̒e��`��
// TransformComponent �̈ʒu���g���Ēe��`��
void EnemyBulletRenderComponent::Draw()
{
    // �e��3D��Ԃɕ`��i���̂��g�p�j
	// DX���C�u������ DrawSphere3D �֐����g�p
    DrawSphere3D
    (
		m_enemyBulletRenderTransform->position      // TransformComponent����ʒu���擾
		, 0.2f, 6, GetColor(255, 50, 50)            // ���a0.2�A������6�A�F���w��
		, GetColor(255, 0, 0)                       // �F��Ԍn���ɐݒ�
		, TRUE                                      // �����x��L���ɂ���
    );
}
