#include "ImageResourceSet.h"
#include "DxLib.h"

ImageResourceSet::~ImageResourceSet()
{
    Clear();
}

// �摜�̃��[�h�i�d���ǂݍ��݂�h���j
int ImageResourceSet::Load(const std::wstring& path)
{
    auto it = m_imageHandles.find(path);
    if (it != m_imageHandles.end())
    {
        return it->second;
    }

    int handle = LoadGraph(path.c_str());
    if (handle != -1)
    {
        m_imageHandles[path] = handle;
    }

    return handle;
}

// �w��摜�̃A�����[�h
void ImageResourceSet::Unload(const std::wstring& path)
{
    auto it = m_imageHandles.find(path);
    if (it != m_imageHandles.end())
    {
        DeleteGraph(it->second);
        m_imageHandles.erase(it);
    }
}

// �S�摜�̉��
void ImageResourceSet::Clear()
{
    for (const auto& pair : m_imageHandles)
    {
        DeleteGraph(pair.second);
    }
    m_imageHandles.clear();
}