// Entity �̓f�[�^�\���ł���A�s���̎����̓R���|�[�l���g�ɕ������Ă����B
// ����ɂ��A���R���|�[�l���g�w�� (ECS) �ɓK�����݌v�ƂȂ�B
// ����ȍs���i���͏�����AI�Ȃǁj�́APlayerEntity �� EnemyEntity �̂悤�ɔh���N���X�Ŏ��̂��I�u�W�F�N�g�w�� (OOP) �I�ȉ�@�B

// �I�u�W�F�N�g�w�� (OOP) �̍l����:
// �v���O�������I�u�W�F�N�g�i�f�[�^�Ƃ��̑�����܂Ƃ߂����́j�Ƃ��đ����A
// �I�u�W�F�N�g���m�̑��ݍ�p��ʂ��ăv���O�������\�z����B

// �R���|�[�l���g�w�� (ECS) �̍l����:
// �v���O�����������ȕ��i�i�R���|�[�l���g�j�ɕ������A������g�ݍ��킹�ċ@�\����������B

// �Q�̈Ⴂ:
// �I�u�W�F�N�g�w���̓I�u�W�F�N�g���m�̑��ݍ�p���d�����A
// �R���|�[�l���g�w���͕��i�̍ė��p����g�ݍ��킹�̏_����d������B

// �Q��g�ݍ��킹��ꍇ:
// �I�u�W�F�N�g�w���̃N���X���R���|�[�l���g�Ƃ��Ĉ����A
// ������g�ݍ��킹�ăG���e�B�e�B���\�����邱�Ƃ��ł���B
// ����ɂ��A�I�u�W�F�N�g�w���̗��_�i�J�v�Z�����A�p���A���Ԑ��j���������A
// �R���|�[�l���g�w���̗��_�i�ė��p���A�_��j������ł���B

#pragma once
#include "Component.h"
#include <vector>           // �R���|�[�l���g���i�[���邽�߂̓��I�z��
#include <memory>           // �X�}�[�g�|�C���^���g�����߂̃w�b�_�[�t�@�C��

// �Q�[�����̃G���e�B�e�B��\�������{�N���X
class Entity
{
public:

    // �f�X�g���N�^
    virtual ~Entity() {}

    // �G���e�B�e�B�ɐV�����R���|�[�l���g��ǉ�
	// std;;shared_ptr<Component>��C++11�ȍ~�̃X�}�[�g�|�C���^
	// �X�}�[�g�|�C���^�Ƃ́A���\�[�X�̎����Ǘ���񋟂��A���������[�N��h�����߂Ɏg�p�����B
    // std::shared_ptr<Component> ���g�����ƂŁA�R���|�[�l���g�̏��L���̓G���e�B�e�B�ɈϏ�����Ȃ��i���\�[�X�Ǘ��������������j
	// ���̂��߁A�G���e�B�e�B���j�������ƁA�֘A����R���|�[�l���g�������I�ɔj�������B
    void AddComponent(std::shared_ptr<Component> component);

	// Entity(GameObject)�̃R���|�[�l���g���쐬����֐�
	// void Create(std::shared_ptr<Component> component);

    // �G���e�B�e�B�̍X�V�����F�e�G���e�B�e�B���ƂɌʂɎ��������
    virtual void Update();

    // �G���e�B�e�B�̕`�揈���F�e�G���e�B�e�B���ƂɌʂɎ��������
    virtual void Draw();

	// �e�������������Ƀ��f���̕`��ɉe����^���邩�ǂ����������t���O
    bool active = true;

protected:
    // �R���|�[�l���g�̃��X�g�F�G���e�B�e�B�����R���|�[�l���g���i�[����
    std::vector<std::shared_ptr<Component>> m_components;
};