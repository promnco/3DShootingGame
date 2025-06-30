#pragma once

#include <string>
#include <unordered_map>

// �摜���\�[�X���ꌳ�Ǘ��iFlyweight �p�^�[���j����N���X
class ImageResourceSet
{
public:
    ~ImageResourceSet();

    int Load(const std::wstring& path);         // �摜���[�h
    void Unload(const std::wstring& path);      // �P�̉��
    void Clear();                               // �S���

private:
    std::unordered_map<std::wstring, int> m_imageHandles;
};