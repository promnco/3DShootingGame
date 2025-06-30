#include "BulletEntity.h"
#include "DxLib.h"

BulletEntity::BulletEntity()
{
    active = true;
    transform = std::make_shared<TransformComponent>();
    AddComponent(transform);
}

void BulletEntity::Update()
{
    // ���x�ɂ���Ĉʒu���X�V
    transform->position = VAdd(transform->position, transform->velocity);

    // �͈͊O�Ŗ�����
    if (transform->position.z > 100.0f || transform->position.z < -50.0f ||
        transform->position.x < -50.0f || transform->position.x > 50.0f)
    {
        active = false;
    }
}

void BulletEntity::Draw()
{
	// ����`�� (�ʒu�A���a�A�Z�O�����g���A�F1�A�F2�A���`�`��t���O)
	// �����ł͐ԐF�̋���`��
    DrawSphere3D(transform->position, 1.0f, 16, GetColor(255, 255, 255), GetColor(255, 255, 255), TRUE);
}

//#include "BulletEntity.h"
//#include "BulletRenderComponent.h"
//
//BulletEntity::BulletEntity(int modelHandle)
//    : m_modelHandle(modelHandle)
//{
//    active = true;
//
//    // Transform ��ǉ�
//    transform = std::make_shared<TransformComponent>();
//    AddComponent(transform);
//
//    // ���f���`��R���|�[�l���g��ǉ�
//    AddComponent(std::make_shared<BulletRenderComponent>(transform, m_modelHandle));
//}
//
//void BulletEntity::Update()
//{
//    transform->position = VAdd(transform->position, transform->velocity);
//
//    if (transform->position.z > 100.0f || transform->position.z < -50.0f ||
//        transform->position.x < -50.0f || transform->position.x > 50.0f)
//    {
//        active = false;
//    }
//}
