#include "UIComponent.h"

// �R���X�g���N�^
// ������Ԃł͕\���t���O�� true�i�\���j�ɂ���
UIComponent::UIComponent()
    : m_visible(true)
{

}

// �\���E��\����؂�ւ���
// true�F�\��
// false�F��\���iDraw() ������Ɏg�p�j
void UIComponent::SetVisible(bool visible)
{
    m_visible = visible;
}

// ���݂̕\����Ԃ��擾
// true�F�\����
// false�F��\��
bool UIComponent::IsVisible() const
{
    return m_visible;
}

// UI�R���|�[�l���g�� Transform2D �ւ̎Q�Ƃ�Ԃ��i�ǂݏ����\�j
// �ʒu�E�X�P�[�����O�E��]�Ȃǂ̏��𑀍�ł���
Transform2D& UIComponent::GetTransform()
{
    return m_transform;
}

// UI�R���|�[�l���g�� Transform2D �ւ̎Q�Ƃ�Ԃ��i�ǂݎ���p�j
// �O������ Transform �����Q�Ƃ������ꍇ�Ɏg��
const Transform2D& UIComponent::GetTransform() const
{
    return m_transform;
}