#include "Transform2D.h"

Transform2D::Transform2D()
    : m_position({ 0.0f, 0.0f })  // �����ʒu�͌��_ (0, 0)
    , m_scale({ 1.0f, 1.0f })     // �X�P�[���͓��{ (1, 1)
    , m_rotation(0.0f)            // ��]�p�� 0 ���W�A���i��]�Ȃ��j
{
}

// �ʒu��ݒ�i�x�N�g���ňꊇ�w��j
void Transform2D::SetPosition(const VECTOR2& pos)
{
    m_position = pos;
}

// ���݂̈ʒu���擾
VECTOR2 Transform2D::GetPosition() const
{
    return m_position;
}

// �X�P�[����ݒ�i�x�N�g���ňꊇ�w��j
void Transform2D::SetScale(const VECTOR2& scale)
{
    m_scale = scale;
}

// ���݂̃X�P�[�����擾
VECTOR2 Transform2D::GetScale() const
{
    return m_scale;
}

// ��]�p��ݒ�i���W�A���P�ʁA���v��肪���j
void Transform2D::SetRotation(float rot)
{
    m_rotation = rot;
}

// ���݂̉�]�p���擾
float Transform2D::GetRotation() const
{
    return m_rotation;
}