#pragma once

// �O���錾�i�z�Q�Ƒ΍�
// Game�N���X�����̃w�b�_�[�t�@�C�����Ŏg�����߁A�����őO���錾���Ă���
class Game;  

// �Q�[���V�[���̒��ۊ��N���X
class Scene
{
public:
    virtual ~Scene() = default;

	// �V�[���J�n���̏���������
	// virtual void Initialize(Game& game) = 0;

    // ���t���[���̍X�V����
	// Game&�������Ƃ��Ď󂯎�邱�ƂŁAGame�N���X�̃����o�֐����Ăяo����悤�ɂ���
	// ���̃A�v���[�`�ɂ��AScene�̔h���N���X�Ԃł��Q�[���̏�ԁi�X�R�A�⃉�C�t�Ȃǁj�̂���肪�\�ɂȂ�
    virtual void Update(Game& game) = 0;

    // �`�揈��
    virtual void Draw() = 0;
};