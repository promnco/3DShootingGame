#include "PlayerEntity.h"
#include "DxLib.h"

PlayerEntity::PlayerEntity(int modelHandle)
    : m_hp(3)
    , m_invincibleTimer(0)
{
    active = true;

    // �����ʒu��Transform
    m_playerTransform = std::make_shared<TransformComponent>(VGet(0, 0, -30));
    AddComponent(m_playerTransform);

    // ���f���`��R���|�[�l���g
    AddComponent(std::make_shared<RenderModelComponent>(modelHandle, m_playerTransform));
}

void PlayerEntity::HandleInput()
{
	// ���͏����F�L�[�{�[�h�̖��L�[�ňړ�
	VECTOR velocity = VGet(0, 0, 0);                            // ������
    if (CheckHitKey(KEY_INPUT_DOWN))  velocity.z -= 0.3f;
    if (CheckHitKey(KEY_INPUT_UP))    velocity.z += 0.3f;
    if (CheckHitKey(KEY_INPUT_LEFT))  velocity.x -= 0.3f;
    if (CheckHitKey(KEY_INPUT_RIGHT)) velocity.x += 0.3f;

    // �ړ�����
    m_playerTransform->velocity = velocity;

    // ��]�����F�ړ������Ɍ�����iY���j
    if (VSize(velocity) > 0.01f) {
        m_playerTransform->rotation.y = atan2f(velocity.x, velocity.z);
    }
}

// �v���C���[�̃_���[�W����
void PlayerEntity::Update()
{
    Entity::Update();
    if (m_invincibleTimer > 0) m_invincibleTimer--;
}