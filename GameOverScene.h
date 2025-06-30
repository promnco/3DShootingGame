#pragma once

#include "Scene.h"
#include "UIManager.h"
#include "SoundManager.h"
#include <memory>

// �Q�[���I�[�o�[��ʂ�\������N���X
class GameOverScene : public Scene
{
private:
    // �ŏI�X�R�A
    int m_score;

    // ���f���n���h���i�����̊g���p�j
    int m_playerModelHandle;
    int m_enemyModelHandle;

    // �w�i�摜
    int m_backgroundHandle;

    // UI
    std::unique_ptr<UIManager> m_uiManager;

    // �T�E���h
    SoundManager m_soundManager;

public:
    // �R���X�g���N�^
    GameOverScene(int finalScore, int playerModel, int enemyModel);

    // �X�V����
    void Update(Game& game) override;

    // �`�揈��
    void Draw() override;
};

//#pragma once
//#include "Scene.h"
//
//// �Q�[���I�[�o�[��ʂ�\������N���X
//// UI�V�X�e���͖�����
//class GameOverScene : public Scene
//{
//private:
//    // �Q�[���I�[�o�[��ʂŕ\������X�R�A
//    int m_score;
//
//    // �v���C���[�ƓG�̃��f���n���h���iDX���C�u�����̃��f�����ʎq�j
//    // ���񂶂Ă�ł͎g�p����Ȃ����A�����̊g���̂��߂ɕێ�
//    int m_playerModelHandle;
//    int m_enemyModelHandle;
//
//public:
//    // �R���X�g���N�^�F�ŏI�X�R�A�ƃv���C���[�E�G�̃��f���n���h�����󂯎���ăQ�[���I�[�o�[��ʂ�������
//    GameOverScene(int finalScore, int playerModel, int enemyModel);
//
//    // �Q�[���I�[�o�[��ʂ̍X�V����
//    void Update(Game& game) override;
//
//    // �Q�[���I�[�o�[��ʂ̕`�揈��
//    void Draw() override;
//};