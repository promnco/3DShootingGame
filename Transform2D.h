#pragma once
#include "DxLib.h"

// 2D�x�N�g���\����
// UI��2D�I�u�W�F�N�g�̈ʒu�E�X�P�[����\�����߂Ɏg�p
struct VECTOR2
{
    float x;
    float y;
};

// UI��2D�`��p�I�u�W�F�N�g�ɋ��ʂ���Transform�����Ǘ�����N���X
class Transform2D
{
private:
    VECTOR2 m_position;  // �ʒu�i�������Ƃ���X, Y���W�j
    VECTOR2 m_scale;     // �X�P�[���i�g�嗦: 1.0f = ���{�j
    float   m_rotation;  // ��]�p�i���W�A���P�ʁA���v���j

public:
    // �R���X�g���N�^
    Transform2D();

    // �ʒu�̐ݒ�
    void SetPosition(const VECTOR2& pos);  // �ʒu���ꊇ�Őݒ�
    // �ʒu���擾
    VECTOR2 GetPosition() const;           

    // �X�P�[���̐ݒ�
    void SetScale(const VECTOR2& scale);  // �X�P�[�����ꊇ�Őݒ�
    // �X�P�[�����擾
    VECTOR2 GetScale() const;             

    // ��]�̐ݒ�i���W�A���P�ʁj
    void SetRotation(float rot); 
	// ��]���擾�i���W�A���P�ʁj
    float GetRotation() const;

    // �ʂ�X���W�EY���W�̎擾�i���삵�₷���d���j
    float GetX() const { return m_position.x; }
    float GetY() const { return m_position.y; }

	// �ʂ�X���W�EY���W�̐ݒ�
    void SetX(float x) { m_position.x = x; }
    void SetY(float y) { m_position.y = y; }
};