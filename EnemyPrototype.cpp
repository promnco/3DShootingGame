#include "EnemyPrototype.h"
#include "TransformComponent.h"
#include "RenderModelComponent.h"

// �R���X�g���N�^
// EnemyEntity �̃v���g�^�C�v��������
// modelHandle �͓G���f���̎��ʗp�n���h���Apos �͏����ʒu
// EnemyEntity �̃R���X�g���N�^���Ăяo���A���f���n���h���ƈʒu��ݒ�
EnemyPrototype::EnemyPrototype(int modelHandle, VECTOR pos)
    : EnemyEntity(modelHandle, pos)
    , m_modelHandle(modelHandle)
{

}

// Clone ���\�b�h�FEnemyEntity �̃v���g�^�C�v�𕡐����ĕԂ�
std::shared_ptr<Entity> EnemyPrototype::Clone() const
{
    // �V���� EnemyEntity �̃C���X�^���X���쐬
	// make_shared�̓������Ǘ������������A�X�}�[�g�|�C���^���g�p���Ĉ��S�ɃI�u�W�F�N�g���Ǘ�����֐�
    auto clone = std::make_shared<EnemyEntity>(m_modelHandle, VGet(0, 0, 0));

    // ���������G���e�B�e�B�̏�����
    clone->m_enemyTransform->velocity = VGet(0, 0, 0);  // ���x���������i�ړ����Ȃ���ԂŐ����j
    clone->m_shotTimer = 0;                        // �e���˃^�C�}�[�����Z�b�g
    clone->active = true;                        // �A�N�e�B�u��Ԃɐݒ�

    return clone; // ���������G���e�B�e�B��Ԃ�
}

