#pragma once

#include <string>
#include <unordered_map>

// ���f�����\�[�X���Ǘ�����N���X�iFlyweight �p�^�[���j
class ModelResourceSet
{
public:
    ~ModelResourceSet();

    int Load(const std::wstring& path);          // ���f���̓ǂݍ���
    void Unload(const std::wstring& path);       // �P�̃A�����[�h
    void Clear();                                // �S�Ẵ��f�������

private:
    std::unordered_map<std::wstring, int> m_modelHandles;
};