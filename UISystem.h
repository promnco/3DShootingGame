#pragma once

#include <vector>
#include <memory>
#include "UIComponent.h"

// UIComponent ��ێ��E�`�悷�郌�C���[�I�Ȗ�����S���N���X
class UISystem
{
public:
    // �R���|�[�l���g��ǉ�
    void AddComponent(std::shared_ptr<UIComponent> component);

    // �S�Ă�UI�R���|�[�l���g��`��iVisible�t���O���l���j
    void Draw();

    // �R���|�[�l���g�ꗗ���擾�i�A�j���[�V�����ȂǂŃA�N�Z�X�p�j
    const std::vector<std::shared_ptr<UIComponent>>& GetComponents() const;

    std::shared_ptr<UIComponent> GetComponent(size_t index) const;

private:
    std::vector<std::shared_ptr<UIComponent>> m_components; // UI�v�f�̃��X�g
};

//#pragma once
//#include <vector>
//#include <memory>
//#include "UIComponent.h"
//
//// �P��� UI ���C���[�iHUD �� �^�C�g����� UI �Ȃǁj��\������N���X
//// UIComponent �𕡐��ێ����A�`���ꊇ������\
//class UISystem
//{
//public:
//    // UIComponent �����X�g�ɒǉ�
//    // �`�揇�͒ǉ����ɂȂ�i��ɐςݏd�Ȃ�悤�Ɂj
//    void AddComponent(const std::shared_ptr<UIComponent>& component);
//
//    // �o�^����Ă��邷�ׂĂ� UIComponent �����Ԃɕ`��
//    // �ʏ�͖��t���[���Ăяo��
//    void Draw();
//
//    // ���ׂĂ� UIComponent ���폜
//    // �V�[���؂�ւ��� UI ���Z�b�g���Ɏg�p
//    void Clear();
//
//    // �w��C���f�b�N�X�� UIComponent ���擾
//    // ���݂��Ȃ��C���f�b�N�X���w�肵���ꍇ�� nullptr ��Ԃ�
//    std::shared_ptr<UIComponent> GetComponent(size_t index) const;
//
//private:
//    // �o�^����Ă��� UIComponent �̃��X�g�i�ێ����ɕ`��j
//    std::vector<std::shared_ptr<UIComponent>> m_components;
//};