#include "UISystem.h"

void UISystem::AddComponent(std::shared_ptr<UIComponent> component)
{
    m_components.push_back(component);
}

void UISystem::Draw()
{
    for (const auto& component : m_components)
    {
        if (component->IsVisible())
        {
            component->Draw();
        }
    }
}

const std::vector<std::shared_ptr<UIComponent>>& UISystem::GetComponents() const
{
    return m_components;
}

std::shared_ptr<UIComponent> UISystem::GetComponent(size_t index) const
{
    if (index < m_components.size())
    {
        return m_components[index];
    }
    return nullptr;
}

//#include "UISystem.h"
//
//// UIComponent ���V�X�e���ɒǉ�
//// �`�揇�͒ǉ����ƂȂ�i��ɒǉ����ꂽ���̂قǏ�ɕ`�悳���j
//void UISystem::AddComponent(const std::shared_ptr<UIComponent>& component)
//{
//    m_components.push_back(component);
//}
//
//// �o�^����Ă��� UIComponent �����ׂĕ`�悷��
//// ��\���iIsVisible() == false�j�̂��͕̂`�悵�Ȃ�
//void UISystem::Draw()
//{
//    for (const auto& component : m_components)
//    {
//        // null �`�F�b�N�ƕ\���t���O���m�F
//        if (component && component->IsVisible())
//        {
//            component->Draw();  // ���ۂ̕`�揈�����Ăяo��
//        }
//    }
//}
//
//// �o�^���ꂽ���ׂĂ� UIComponent ���폜����
//// �V�[���J�ڂ� UI �č\�z���Ɏg�p
//void UISystem::Clear()
//{
//    m_components.clear();  // ���� vector ����ɂ���
//}
//
//// �w�肳�ꂽ�C���f�b�N�X�� UIComponent ���擾����
//// �͈͊O�A�N�Z�X��h�~���A���S�� nullptr ��Ԃ�
//std::shared_ptr<UIComponent> UISystem::GetComponent(size_t index) const
//{
//    if (index < m_components.size())
//    {
//        return m_components[index];  // �L���ȃC���f�b�N�X�Ȃ�Ԃ�
//    }
//    return nullptr;  // �����ȏꍇ�� null ��Ԃ�
//}