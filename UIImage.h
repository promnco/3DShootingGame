#pragma once
#include "SpriteRenderer.h"

// UI�摜��\������R���|�[�l���g�N���X�i�{�^���E�A�C�R���E���S�ȂǂɎg�p�j
// �{�^���E�A�C�R���E���S�E�����ȂǁA�ÓI��UI�摜�\����S��
class UIImage : public SpriteRenderer
{
public:
    // �R���X�g���N�^�F�摜�p�X���w��
    UIImage(const std::wstring& imagePath);

    // �K�v�ɉ�����UIImage�ŗL�̏�����ǉ��\
};