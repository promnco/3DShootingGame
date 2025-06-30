#include "SoundResourceSet.h"
#include "DxLib.h"

SoundResourceSet::~SoundResourceSet()
{
    Clear();
}

// �T�E���h�̓ǂݍ���
int SoundResourceSet::Load(const std::wstring& path)
{
    auto it = m_soundHandles.find(path);
    if (it != m_soundHandles.end())
    {
        return it->second;
    }

    int handle = LoadSoundMem(path.c_str());
    if (handle != -1)
    {
        m_soundHandles[path] = handle;
    }

    return handle;
}

// �w��T�E���h�̃A�����[�h
void SoundResourceSet::Unload(const std::wstring& path)
{
    auto it = m_soundHandles.find(path);
    if (it != m_soundHandles.end())
    {
        DeleteSoundMem(it->second);
        m_soundHandles.erase(it);
    }
}

// �S�ẴT�E���h�����
void SoundResourceSet::Clear()
{
    for (const auto& pair : m_soundHandles)
    {
        DeleteSoundMem(pair.second);
    }
    m_soundHandles.clear();
}