#pragma once

#include "UIComponent.h"
#include "Transform2D.h"
#include <string>
#include <DxLib.h>

// �݌v�̃|�C���g
// �ė��p���F�X�v���C�g�`��@�\��P�̃R���|�[�l���g�Ƃ��Đ؂�o�����ƂŁAUI�v�f�ɊȒP�ɓK�p�ł���
// �g����  �FTransform2D �ɂ��_��Ȕz�u�E�g��k���E��]���\
// ��ѐ�  �FUIComponent ���p�����A�|�����[�t�B�Y�������������ꊇ�`��Ǘ�������

// �摜��ǂݍ��݁ATransform2D ��ʂ��Ĉʒu�E�X�P�[���E��]�𐧌䂷�钊�ۃN���X
// UIComponent ���p�����邱�ƂŁA����UI�R���|�[�l���g�Ƌ��ʂ̃C���^�[�t�F�[�X�������A
// �V�[���S�̂ł̈ꊇ�X�V�E�`�搧���e�Ղɂ���
class SpriteRenderer : public UIComponent
{
protected:
    int m_handle;             // DxLib �摜�n���h���iLoadGraph �Ŏ擾�j
    int m_originalWidth;      // �ǂݍ��ݎ��̉摜���i�X�P�[�����O�̊�j
    int m_originalHeight;     // �ǂݍ��ݎ��̉摜����
    bool m_visible;           // �\���^��\���̃t���O�iUI�Ǘ��p�j

    Transform2D m_transform;  // 2D�g�����X�t�H�[���i�ʒu�E�g��k���E��]�j

public:
    // �R���X�g���N�^
    // imagePath: �摜�t�@�C���̃p�X�i���C�h������j
    // �w�肳�ꂽ�摜��ǂݍ���ŏ�����
    SpriteRenderer(const std::wstring& imagePath);

    // �`�揈��
    // Transform2D �̏��ɏ]���ăX�v���C�g���g��^��]���ĕ`��
    void Draw() override;

	// �\��,��\���̐؂�ւ�
    void SetVisible(bool visible) override;

	// ���݂̕\����Ԃ��擾
    bool IsVisible() const override;

    // �ǂݍ��񂾉摜�̌��̕����擾�i�X�P�[���v�Z�ȂǂɎg�p�j
    int GetOriginalWidth() const;

    // �ǂݍ��񂾉摜�̌��̍������擾�i�X�P�[���v�Z�ȂǂɎg�p�j
    int GetOriginalHeight() const;

    // Transform2D �ւ̎Q�Ƃ�Ԃ�
    // - �ʒu�E�X�P�[���E��]�̐ݒ�Ɏg�p
    Transform2D& GetTransform();
};

// ����C���^�[�t�F�[�X�Ƃ��ẮA���L���Ă��鏈���������A
// �C���^�[�t�F�[�X�Ƃ��Ă͋^�₪�c�邽�߁A�ʂ̃N���X�ɕ������邱�Ƃ�����
