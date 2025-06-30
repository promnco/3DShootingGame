#pragma once
#include "Entity.h"
#include <memory>     // std::shared_ptr ���g�p���邽�߂̃w�b�_�[�t�@�C��

// �G���e�B�e�B�̃v���g�^�C�v���Ǘ�������N���X
// ���̃N���X�̓G���e�B�e�B(�I�u�W�F�N�g)�̃N���[���i�R�s�[�j���쐬���邽�߂̃C���^�[�t�F�[�X���
// �v���g�^�C�v�p�^�[�����g�p���āA�G���e�B�e�B�𕡐��ł���悤�ɂ��܂��B
class EntityPrototype
{
public:
    // ���z�f�X�g���N�^�F�h���N���X�œK�؂ɔj���ł���悤�ɉ��z�f�X�g���N�^���
    virtual ~EntityPrototype() {}

    // Clone ���\�b�h�F�G���e�B�e�B�𕡐����邽�߂̃C���^�[�t�F�[�X
    // �h���N���X�ŃN���[�����쐬���鏈������������
    virtual std::shared_ptr<Entity> Clone() const = 0;
};
