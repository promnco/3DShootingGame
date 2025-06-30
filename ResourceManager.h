#pragma once

#include "ImageResourceSet.h"
#include "SoundResourceSet.h"
#include "ModelResourceSet.h"

// ���\�[�X��ǂݍ���ŊǗ�����N���X
// �V���O���g���p�^�[�����g�p���āA�A�v���P�[�V�����S�̂ň�̃C���X�^���X�����L����
class ResourceManager
{
public:
    // �V���O���g���A�N�Z�X�p���\�b�h
    static ResourceManager& GetInstance();

    // �e�탊�\�[�X�擾
    int GetImage(const std::wstring& path);
    int GetSound(const std::wstring& path);
    int GetModel(const std::wstring& path);

    // �S���\�[�X���
    void ClearAll();

private:
    ResourceManager() = default;                      // �R���X�g���N�^����J
    ResourceManager(const ResourceManager&) = delete; // �R�s�[�֎~
    ResourceManager& operator=(const ResourceManager&) = delete;

    ImageResourceSet m_imageSet;
    SoundResourceSet m_soundSet;
    ModelResourceSet m_modelSet;
};