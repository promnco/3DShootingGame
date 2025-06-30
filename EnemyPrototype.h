#pragma once
#include "EnemyEntity.h"
#include "EntityPrototype.h"

// EnemyEntity(�G�I�u�W�F�N�g)�̃v���g�^�C�v���Ǘ�����N���X
// EnemyEntity �𕡐����邽�߂ɁAEntityPrototype ���p�����AClone ���\�b�h���������܂��B
class EnemyPrototype : public EnemyEntity, public EntityPrototype
{
private:
    int m_modelHandle;  // �������Ɏg�p���郂�f���n���h����ێ�

public:
    // �R���X�g���N�^�F���f���n���h���Ə����ʒu���󂯎��A�v���g�^�C�v��������
    // modelHandle �́A�G�̃��f�������ʂ��邽�߂̃n���h��
    // pos �́A�G�̏����ʒu��ݒ�
    EnemyPrototype(int modelHandle, VECTOR pos);

    // Clone ���\�b�h�FEnemyEntity �𕡐�����
    // �v���g�^�C�v�𕡐����ĐV�����C���X�^���X��Ԃ�
    std::shared_ptr<Entity> Clone() const override;
};
