// Component������Entity�N���X
// ����ɂ��A�ϒ��z���Component�����R�ɒǉ��ł���悤�ɂȂ�܂�
#include "Entity.h"

// AddComponent ���\�b�h�F�V�����R���|�[�l���g���G���e�B�e�B�ɒǉ�
// std::shared_ptr<Component> �������Ƃ��Ď󂯎��A�G���e�B�e�B�̃R���|�[�l���g���X�g�ɒǉ�����
void Entity::AddComponent(std::shared_ptr<Component> component)
{
    // components�x�N�^�[�ɐV�����R���|�[�l���g��ǉ�
    m_components.push_back(component);
}

// Update ���\�b�h�F�S�ẴR���|�[�l���g���X�V
void Entity::Update()
{
    // components���X�g�̊e�R���|�[�l���g�ɑ΂���Update���Ăяo��
    for (auto& comp : m_components)
    {
        comp->Update();  // �e�R���|�[�l���g��Update���������s
    }
}

// Draw ���\�b�h�F�S�ẴR���|�[�l���g��`��
void Entity::Draw()
{
    // components���X�g�̊e�R���|�[�l���g�ɑ΂���Draw���Ăяo��
    for (auto& comp : m_components)
    {
        comp->Draw();  // �e�R���|�[�l���g��Draw���������s
    }
}