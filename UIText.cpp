#include "UIText.h"
#include "DxLib.h"

// �R���X�g���N�^
UIText::UIText(const std::wstring& text, unsigned int color)
	: m_text(text)      // �����\������e�L�X�g
	, m_color(color)    // �����\�����镶���F�iRGB�l��z��j
    , m_fontSize(20)    // �f�t�H���g�̃t�H���g�T�C�Y�� 20 �ɐݒ�
    , m_visible(true)   // ������Ԃł͕\����Ԃɂ���
{
}

// �e�L�X�g�`�揈��
// �t�H���g�T�C�Y�ƈʒu�E�F���l�����ĕ������`��
void UIText::Draw()
{
    if (!m_visible) return;  // ��\���t���O�������Ă���ꍇ�͉����`�悵�Ȃ�

    // ���݂̃t�H���g�T�C�Y��ۑ��i��UI�Ɗ����Ȃ��悤�Ɂj
    int oldSize = GetFontSize();
    SetFontSize(m_fontSize);  // �w�肳�ꂽ�t�H���g�T�C�Y�Ɉꎞ�ύX

    // �������`��iTransform �Ŏw�肳�ꂽ�ʒu�ɕ\���j
    DrawString
    (
        static_cast<int>(m_transform.GetX()),  // X���W
        static_cast<int>(m_transform.GetY()),  // Y���W
        m_text.c_str(),                         // �`�悷��e�L�X�g
        m_color                                 // �����F
    );

    // �t�H���g�T�C�Y�����ɖ߂��i����p�h�~�j
    SetFontSize(oldSize);
}

// �\���e�L�X�g��ύX����
void UIText::SetText(const std::wstring& text)
{
    m_text = text;
}

// �e�L�X�g�J���[��ύX����iRGB�l��z��j
void UIText::SetColor(unsigned int color)
{
    m_color = color;
}

// �t�H���g�T�C�Y��ύX����i�s�N�Z���P�ʁj
void UIText::SetFontSize(int size)
{
    m_fontSize = size;
}

// Transform2D ���擾�F�ʒu�E�X�P�[���E��]�Ȃǂ̑���p
Transform2D& UIText::GetTransform()
{
    return m_transform;
}

// �\���t���O��ݒ�ifalse �ɂ���� Draw �͖��������j
void UIText::SetVisible(bool visible)
{
    m_visible = visible;
}

// ���݂̕\����Ԃ��擾�itrue = �\�����j
bool UIText::IsVisible() const
{
    return m_visible;
}