#pragma once

#include <string>
#include <unordered_map>

// �T�E���h���\�[�X���ꊇ�Ǘ�����N���X�iFlyweight �p�^�[���j
class SoundResourceSet
{
public:
    ~SoundResourceSet();

    int Load(const std::wstring& path);         // �T�E���h�̓ǂݍ���
    void Unload(const std::wstring& path);      // �P�̃A�����[�h
    void Clear();                               // ���ׂẴT�E���h�����

private:
    std::unordered_map<std::wstring, int> m_soundHandles;
};