#include "Game.h"
#include "TitleScene.h"
#include "ModelFactory.h"


// �R���X�g���N�^
Game::Game(int playerModel, int enemyModel)
{
    // �^�C�g���V�[�������������A���݂̃V�[���Ƃ��Đݒ�
    currentScene = std::make_unique<TitleScene>(playerModel, enemyModel);
}


void Game::Update()
{
    if (currentScene)
    {
        // �Q�[���̏�Ԃ��X�V
        currentScene->Update(*this);
    }
}

// �Q�[���̕`�揈��
void Game::Draw()
{
    if (currentScene)
    {
        // ���݂̃V�[����Draw���\�b�h���Ăяo���A�Q�[������ʂɕ`��
        currentScene->Draw();
    }
}

// �V�[���̕ύX����
void Game::ChangeScene(std::unique_ptr<Scene> newScene)
{
    // ���݂̃V�[����V�����V�[���ɒu��������istd::move�ŏ��L�����ړ��j
	// std::move�Ƃ́A���L�����ړ����邽�߂̊֐��ŁA���\�[�X�̌����I�ȊǗ����\�ɂ��܂��B
    currentScene = std::move(newScene);
}