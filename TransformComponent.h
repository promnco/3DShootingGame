#pragma once
#include "Component.h"
#include "DxLib.h"

// �G���e�B�e�B(�Q�[���I�u�W�F�N�g)�̈ʒu�E���x�E��]���Ǘ������{�I�ȋ�ԏ��R���|�[�l���g
// �Q�[���I�u�W�F�N�g�̈ړ��E��]�����`��ʒu�̎Q�ƂɎg�p
class TransformComponent : public Component
{
public:
    // --- ��ԃv���p�e�B ---
    // �ϐ���private�ɂ��āAGet/Set�֐���ʂ��ăA�N�Z�X���邱�Ƃ����������(�J�v�Z����)
    // �����I�ɍ�蒼��
    
    // �ʒu�x�N�g���i���[���h���W��̈ʒu��\���j
    VECTOR position;

    // ���x�x�N�g���i���t���[�����Z�����ړ��ʁj
    VECTOR velocity;

    // ��]�x�N�g���iX, Y, Z���̉�]�p�x��\���B�P�ʂ̓��W�A���܂��͓x���œ��ꂪ�K�v�j
    VECTOR rotation;

    // �f�t�H���g�R���X�g���N�^
    TransformComponent();

    // �����t���R���X�g���N�^�F�����ʒu���w�肵�ď�����
    TransformComponent(VECTOR pos);

    // ���t���[���Ă΂��X�V����
    void Update() override;

    // �f�o�b�O�p�r�Ȃǂňʒu�\������ۂɌĂ΂��
    void Draw() override;
};