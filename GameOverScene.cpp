#include "GameOverScene.h"
#include "DxLib.h"
#include "Game.h"
#include "TitleScene.h"
#include "ResourceManager.h"
#include "UIText.h"
#include "UISystem.h"
#include <tchar.h>

// �R���X�g���N�^
GameOverScene::GameOverScene(int finalScore, int playerModel, int enemyModel)
    : m_score(finalScore)
    , m_playerModelHandle(playerModel)
    , m_enemyModelHandle(enemyModel)
{
    // �w�i�摜�̓ǂݍ���
    m_backgroundHandle = ResourceManager::GetInstance().GetImage(L"Assets/UI/background_title.png");

    // BGM�Đ��i�K�v�ɉ����āj
    m_soundManager.Load();
    m_soundManager.PlayGameOver();

    // UI ������
    m_uiManager = std::make_unique<UIManager>();
    auto uiSystem = std::make_shared<UISystem>();

    // "GAME OVER" �e�L�X�g
    auto gameOverText = std::make_shared<UIText>(L"GAME OVER", GetColor(255, 0, 0));
    gameOverText->GetTransform().SetPosition({ 500, 250 });
    uiSystem->AddComponent(gameOverText);

    // �X�R�A�\��
	// �F�F���F
    auto scoreText = std::make_shared<UIText>(
        L"Final Score: " + std::to_wstring(m_score),
		GetColor(0, 0, 0)); // ���F�ŃX�R�A��\��
    scoreText->GetTransform().SetPosition({ 400, 300 });
    uiSystem->AddComponent(scoreText);

    // ���b�Z�[�W�\��
    auto promptText = std::make_shared<UIText>(L"Press ENTER to return to Title", GetColor(0,0,0));
    promptText->GetTransform().SetPosition({ 400, 350 });
    uiSystem->AddComponent(promptText);

    m_uiManager->AddSystem("gameOverUI", uiSystem);
}

// �X�V����
void GameOverScene::Update(Game& game)
{
    if (CheckHitKey(KEY_INPUT_RETURN))
    {
        m_soundManager.StopBGM();  // �����~�߂�
        game.ChangeScene(std::make_unique<TitleScene>(m_playerModelHandle, m_enemyModelHandle));
    }
}

// �`�揈��
void GameOverScene::Draw()
{
    int screenW = 1280;
    int screenH = 720;

    DrawExtendGraph(0, 0, screenW, screenH, m_backgroundHandle, TRUE);
    m_uiManager->DrawAll();
}

//#include "GameOverScene.h"
//#include "DxLib.h"        
//#include "Game.h"         
//#include "TitleScene.h"   
//#include <tchar.h>            // _T �}�N�����g�p���邽�߂̃w�b�_�[�t�@�C��
//
//// �R���X�g���N�^
//GameOverScene::GameOverScene(int finalScore, int playerModel, int enemyModel)
//    : m_score(finalScore)
//    , m_playerModelHandle(playerModel)
//    , m_enemyModelHandle(enemyModel)
//{
//    // �ŏI�X�R�A�ƃ��f���̃n���h����������
//}
//
//
//void GameOverScene::Update(Game& game)
//{
//    // Enter�L�[�������ꂽ�ꍇ�A�^�C�g���V�[���ɑJ��
//    if (CheckHitKey(KEY_INPUT_RETURN))
//    {
//        // �^�C�g���V�[���ɑJ�ځi�V���� TitleScene �𐶐����ăQ�[���̃V�[����ύX�j
//        game.ChangeScene(std::make_unique<TitleScene>(m_playerModelHandle, m_enemyModelHandle));
//    }
//}
//
//
//void GameOverScene::Draw()
//{
//    // "GAME OVER" �̕������ԐF�ŕ\��
//    DrawString(500, 250, _T("GAME OVER"), GetColor(255, 0, 0));
//
//    // �ŏI�X�R�A�𔒐F�ŕ\��
//    DrawFormatString(480, 300, GetColor(255, 255, 255), _T("Final Score: %d"), m_score);
//
//    // "Press ENTER to return to Title" �̃��b�Z�[�W��\��
//    DrawString(420, 350, _T("Press ENTER to return to Title"), GetColor(255, 255, 255));
//}
