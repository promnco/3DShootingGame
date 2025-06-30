#pragma once
#include <memory>      // �X�}�[�g�|�C���^�istd::unique_ptr�j���g�p���邽�߂̃w�b�_�[�t�@�C��
#include "Scene.h"

// �Q�[�����Ǘ�����N���X
class Game
{
public:
    // �R���X�g���N�^
    Game(int playerModel, int enemyModel);

    // �Q�[���̍X�V�����F�v���C���[��G�̓����A��Ԃ��X�V
    void Update();

    // �Q�[���̕`�揈���F��ʂɕ`����s��
    void Draw();

    // �V�[���̕ύX�����F���݂̃V�[����V�����V�[���ɐ؂�ւ���
    void ChangeScene(std::unique_ptr<Scene> newScene);

private:
    // ���݂̃V�[����ێ�����X�}�[�g�|�C���^�i���I�������Ǘ��������ōs���j
    std::unique_ptr<Scene> currentScene;

    // Tips
	// unique_ptr�͏��L�������X�}�[�g�|�C���^�ŁA
    // ���I�Ɋm�ۂ����������������ŉ�����邽�߁A���������[�N��h�����Ƃ��ł���
	// std::make_unique���g�p����ƁA��O���S�Ō����I�ɃI�u�W�F�N�g�𐶐��ł���
	//      ��)�����g���Ă��Ȃ��̂ŏd�_�I�ɂ����炢
};