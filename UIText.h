#pragma once

#include <string>
#include "UIComponent.h"
#include "Transform2D.h"

// UI ��ɕ������`�悷�邽�߂̃R���|�[�l���g
// HUD�A���j���[�A�X�R�A�\���ȂǂɎg�p�\
class UIText : public UIComponent
{
public:
    // �R���X�g���N�^�F�\������e�L�X�g�Ə����F���w��
    UIText(const std::wstring& text, unsigned int color);

    // �e�L�X�g��`�悷��i�t�H���g�T�C�Y�A�F�A�ʒu�Ɋ�Â��ĕ`��j
    void Draw() override;

    // �\������e�L�X�g���e��ύX
    void SetText(const std::wstring& text);

    // �����F��ύX����iDxLib �� GetColor �֐��ȂǂŎ擾���� RGB �l�j
    void SetColor(unsigned int color);

    // �t�H���g�T�C�Y��ύX����i�`��T�C�Y�ɉe���j
    void SetFontSize(int size);

    // �e�L�X�g�̈ʒu�E�g�嗦�E��]�Ȃǂ��擾�^�ύX���邽�߂� Transform
    Transform2D& GetTransform();

    // �\���t���O��ݒ�itrue = �\���Afalse = ��\���j
    void SetVisible(bool visible) override;

    // ���݂̕\����Ԃ��擾
    bool IsVisible() const override;

private:
    std::wstring m_text;      // �\�����镶����iUnicode�Ή��j
    unsigned int m_color;     // �`�悷�镶���̐F�iRGB�l�j
    int m_fontSize;           // �t�H���g�T�C�Y�i�s�N�Z���P�ʁj
    bool m_visible;           // �\���t���O

    Transform2D m_transform;  // �e�L�X�g�̈ʒu�E�X�P�[���E��]�Ȃ�
};