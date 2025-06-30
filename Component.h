#pragma once

// �Q�[���I�u�W�F�N�g�����@�\���������邽�߂̒��ۃN���X
// �ύX�\�� Componet -> IComponent
class Component
{
public:
    // �e�R���|�[�l���g�����t���[���X�V���鏈�����������邽�߂̃��\�b�h
    // �K�v�ɉ����Ĕh���N���X�Ŏ�����񋟂���
    virtual void Update() {}

    // �e�R���|�[�l���g����ʂɕ`�悷�邽�߂̃��\�b�h
    // ���̃��\�b�h�͕K���h���N���X�Ŏ���
    virtual void Draw() = 0;

    // ���z�f�X�g���N�^�F�h���N���X�̃N���[���A�b�v��K�؂ɍs������
    virtual ~Component() = default;
};

// ���ۃN���X�Ƃ́A�C���X�^���X���ł��Ȃ��N���X�ł���A
// ���Ȃ��Ƃ�1�̏������z�֐��i=0�Ő錾���ꂽ�֐��j�����N���X�ł��B