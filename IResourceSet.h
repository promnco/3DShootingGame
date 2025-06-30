#pragma once
#include <string>

// ���ׂẴ��\�[�X�Z�b�g���������ׂ����ʃC���^�[�t�F�[�X
class IResourceSet
{
public:
    virtual ~IResourceSet() = default;

    // �w�肵���p�X�̃��\�[�X�����[�h���A���̃n���h����Ԃ�
    virtual int Load(const std::string& path) = 0;

    // ����̃��\�[�X���A�����[�h����
    virtual void Unload(const std::string& path) = 0;

    // �o�^���ꂽ���ׂẴ��\�[�X�����
    virtual void Clear() = 0;
};