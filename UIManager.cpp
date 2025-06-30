#include "UIManager.h"

// UI�V�X�e���iUISystem�j�𖼑O�œo�^����
// ���ꖼ������Ώ㏑�������
void UIManager::AddSystem(const std::string& name, std::shared_ptr<UISystem> system)
{
	m_systems[name] = system;       // ���O���L�[�ɂ��ăV�X�e����o�^
}

// �w�肳�ꂽ���O��UI�V�X�e�����擾����
// ������Ȃ��ꍇ�� nullptr ��Ԃ�
std::shared_ptr<UISystem> UIManager::GetSystem(const std::string& name) const
{
    auto it = m_systems.find(name);  // ���O�Ō���
    if (it != m_systems.end())
    {
        return it->second;           // ���������ꍇ�̓V�X�e����Ԃ�
    }
    return nullptr;                  // ������Ȃ���� null
}

// �o�^����Ă��邷�ׂĂ�UI�V�X�e���ɑ΂��ĕ`�揈�����s��
void UIManager::DrawAll()
{
    for (const auto& pair : m_systems)
    {
        if (pair.second)  // null�`�F�b�N�inullptr�ł��N���b�V�����Ȃ��悤�Ɂj
        {
            pair.second->Draw();  // �eUI�V�X�e���ɕ`����˗�
        }
    }
}

// �o�^����Ă��邷�ׂĂ�UI�V�X�e�����폜����
// �� �V�[���J�ڂȂǂ�UI���ꊇ���Z�b�g�������Ƃ��Ɏg�p
void UIManager::Clear()
{
    m_systems.clear();
}
