#include "TransformComponent.h"

// �f�t�H���g�R���X�g���N�^
TransformComponent::TransformComponent()
    : position(VGet(0, 0, 0))   // �����ʒu
    , velocity(VGet(0, 0, 0))   // �������x
    , rotation(VGet(0, 0, 0))   // ������]
{
}

// �ʒu�����w�肷��R���X�g���N�^
// �g�p��F����̈ʒu����J�n�������ꍇ
TransformComponent::TransformComponent(VECTOR pos)
    : position(pos)                    // �w�肳�ꂽ�ʒu�ŏ�����
    , velocity(VGet(0, 0, 0))          // �������x�̓[��
    , rotation(VGet(0, 0, 0))          // ������]���[��
{
}

// ���t���[���Ăяo�����X�V�����F
// ���x�x�N�g�������݈ʒu�ɉ��Z -> ����ɂ�葬�x�ɉ����ăI�u�W�F�N�g�̈ʒu���X�V�����
void TransformComponent::Update()
{
    position = VAdd(position, velocity);
}

// �i�`��͑��� RenderComponent �����S������z��j
void TransformComponent::Draw()
{
    // �����
}