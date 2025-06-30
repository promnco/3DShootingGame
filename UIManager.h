#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include "UISystem.h"

// ������ UISystem�iUI ���C���[�j���Ǘ�����N���X
// ��: "TitleUI", "HUD", "PauseMenu" �Ȃǖ��O�t���ŊǗ�
class UIManager
{
public:
    // UISystem �𖼑O�t���œo�^
    void AddSystem(const std::string& name, std::shared_ptr<UISystem> system);

    // ���O�� UISystem ���擾�i���݂��Ȃ���� nullptr ��Ԃ��j
    std::shared_ptr<UISystem> GetSystem(const std::string& name) const;

    // �o�^����Ă��邷�ׂĂ� UISystem ��`��
    void DrawAll();

    // �S UISystem ���N���A�i�V�[���J�ڂȂǂɁj
    void Clear();

private:
	// UISystem �𖼑O�ŊǗ�����}�b�v
    std::unordered_map<std::string, std::shared_ptr<UISystem>> m_systems;
};