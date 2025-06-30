#pragma once
#include "Entity.h"
#include <vector>            // std::vector ���g�p���邽�߂̃w�b�_�[�t�@�C��
#include <memory>            // std::shared_ptr ���g�p���邽�߂̃w�b�_�[�t�@�C��

// �G���e�B�e�B(�Q�[�����̃I�u�W�F�N�g)�̊Ǘ��ƍX�V�E�`�揈�����s���N���X
class EntitySystem
{
private:
	// �G���e�B�e�B���X�g�F�Q�[�����ŊǗ������S�ẴG���e�B�e�B���i�[����ϒ��z��
    std::vector<std::shared_ptr<Entity>> m_entities;

public:
    // �V�����G���e�B�e�B���V�X�e���ɒǉ�
    // �󂯎�����G���e�B�e�B�� entities ���X�g�ɒǉ�����
    void AddEntity(std::shared_ptr<Entity> entity);

    // �S�ẴG���e�B�e�B�̍X�V�������s��
    // �G���e�B�e�B������ Update ���\�b�h���Ăяo���āA��Ԃ��X�V
    void Update();

    // �S�ẴG���e�B�e�B�̕`�揈�����s��
    // �G���e�B�e�B������ Draw ���\�b�h���Ăяo���āA��ʂɕ`��
    void Draw();
};