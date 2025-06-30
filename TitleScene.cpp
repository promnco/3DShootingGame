#include "TitleScene.h"
#include "DxLib.h"
#include "PlayScene.h"
#include "VirtualScreenManager.h"
#include "UIImage.h"
#include "UISystem.h"
#include "ResourceManager.h"
#include <cmath>

TitleScene::TitleScene(int playerModel, int enemyModel)
    : m_playerModelHandle(playerModel)
    , m_enemyModelHandle(enemyModel)
    , m_animTimer(0)
{
    // �J����������
    m_cameraComponent = std::make_shared<CameraComponent>();
    m_cameraComponent->SetPosition(VGet(0, 0, -10));
    m_cameraComponent->SetTarget(VGet(0, 0, 0));
    m_cameraController = std::make_unique<CameraController>(m_cameraComponent);

    // UI�\�z
    m_uiManager = std::make_unique<UIManager>();
    auto mainUI = std::make_shared<UISystem>();

    // ���S
    auto logo = std::make_shared<UIImage>(L"Assets/UI/titleLogo.png");
	logo->GetTransform().SetPosition({ 500, 150 });
    logo->GetTransform().SetScale({ 0.8f, 0.8f });

    // �{�^��
    auto button = std::make_shared<UIImage>(L"Assets/UI/startButton.png");
    button->GetTransform().SetPosition({ 500, 400 });
    button->GetTransform().SetScale({ 0.5f, 0.5f });

    mainUI->AddComponent(logo);
    mainUI->AddComponent(button);

    m_uiManager->AddSystem("main", mainUI);
}

void TitleScene::Update(Game& game)
{
    m_animTimer++;
    m_cameraController->Update();

    // ���S�̏c�h�ꉉ�o
    auto system = m_uiManager->GetSystem("main");
    if (system)
    {
        auto comps = system->GetComponents();
        if (!comps.empty())
        {
            auto logo = std::dynamic_pointer_cast<UIImage>(comps[0]);
            if (logo)
            {
                VECTOR2 pos = logo->GetTransform().GetPosition();
                pos.y = 150 + std::sin(m_animTimer * 0.05f) * 10;
                logo->GetTransform().SetPosition(pos);
            }
        }
    }

    if (CheckHitKey(KEY_INPUT_RETURN))
    {


        game.ChangeScene(std::make_unique<PlayScene>(m_playerModelHandle, m_enemyModelHandle));
    }
}

void TitleScene::Draw()
{
    m_cameraComponent->ApplyToDxLibCamera();

    // �w�i�i���\�[�X�}�l�[�W���[�ŋ��L�j
    int bgHandle = ResourceManager::GetInstance().GetImage(L"Assets/UI/background_title.png");
    int screenW = VirtualScreenManager::GetVirtualWidth();
    int screenH = VirtualScreenManager::GetVirtualHeight();
    DrawExtendGraph(0, 0, screenW, screenH, bgHandle, TRUE);

    // UI�`��
    if (m_uiManager) m_uiManager->DrawAll();
}


//#include "TitleScene.h"
//#include "DxLib.h"
//#include "PlayScene.h"
//#include "VirtualScreenManager.h"
//#include "UIImage.h"
//#include "UISystem.h"
//
//// �R���X�g���N�^
//// ���f���n���h�����󂯎��A�J�����EUI�̏��������s��
//TitleScene::TitleScene(int playerModel, int enemyModel)
//    : m_playerModelHandle(playerModel)
//    , m_enemyModelHandle(enemyModel)
//    , m_animTimer(0)
//{
//    // �J�����̏����ݒ�i���o�p�J�����j
//	// make_shared���g�p���ăX�}�[�g�|�C���^�ŊǗ�
//    m_cameraComponent = std::make_shared<CameraComponent>();
//        m_cameraComponent->SetPosition(VGet(0, 0, -10));                            // �����璆��������
//        m_cameraComponent->SetTarget(VGet(0, 0, 0));                                // �����_�͌��_
//        m_cameraController = std::make_unique<CameraController>(m_cameraComponent);
//
//    // UI�Ǘ��N���X�̐����ƃ��C��UI���C���[�̍쐬
//    m_uiManager = std::make_shared<UIManager>();
//
//	// ���C��UI�V�X�e���̐���
//    // auto = �^���_�𗘗p���郁���b�g: 
//    // ���Ƃ��Ƃ� UISystem �� std::shared_ptr<UISystem> �ł��������A
//    // auto ���g�����ƂŖ����I�Ȍ^�w�肪�s�v�ɂȂ�A�R�[�h���Ȍ��ɂȂ�
//	auto mainUI = std::make_shared<UISystem>();
//
//    // ���z��ʃT�C�Y���擾�i�E�B���h�E�E�t���X�N���[���ǂ���ɂ��Ή��\�j
//    int screenW = VirtualScreenManager::GetVirtualWidth();
//    int screenH = VirtualScreenManager::GetVirtualHeight();
//
//    // �w�i�摜�̐����E�z�u�i��ʑS�̂Ƀt�B�b�g����悤�ɃX�P�[�����O�j
//    auto background = std::make_shared<UIImage>(_T("Assets/UI/background_title.png"));
//    background->GetTransform().SetPosition({ screenW / 2.0f, screenH / 2.0f }); // �����z�u
//    background->GetTransform().SetScale(
//        {
//        screenW / static_cast<float>(background->GetOriginalWidth()),
//        screenH / static_cast<float>(background->GetOriginalHeight())
//        });
//    mainUI->AddComponent(background); // �w�i��UI�V�X�e���ɒǉ�
//
//    // �^�C�g�����S�̐����E�z�u�i����ɔz�u���Č�ɃA�j���[�V�����Ώۂɂ���j
//    auto logo = std::make_shared<UIImage>(_T("Assets/UI/titleLogo.png"));
//    logo->GetTransform().SetPosition({ screenW / 2.0f, 150.0f });           // �㕔����
//    logo->GetTransform().SetScale({ 0.5f, 0.5f });                          // 50%�ɏk��
//    mainUI->AddComponent(logo);
//
//    // �X�^�[�g�{�^���̐����E�z�u�i�����ɌŒ�j
//    auto startButton = std::make_shared<UIImage>(_T("Assets/UI/startButton.png"));
//    startButton->GetTransform().SetPosition({ screenW / 2.0f, 400.0f });            // ������������
//    startButton->GetTransform().SetScale({ 0.5f, 0.5f });
//    mainUI->AddComponent(startButton);
//
//    // UI�}�l�[�W���[�Ɂumain�v���C���[�Ƃ��ēo�^
//    m_uiManager->AddSystem("main", mainUI);
//}
//
//// ���t���[���Ă΂��X�V����
//void TitleScene::Update(Game& game)
//{
//    m_animTimer++;                  // ���S�h��A�j���[�V�����p�^�C�}�[
//    m_cameraController->Update();   // �J�������o�̍X�V
//
//    // �^�C�g�����S���c�ɗh�炷���o
//    auto system = m_uiManager->GetSystem("main");
//    if (system)
//    {
//        // ���S�̓C���f�b�N�X1�Ɋi�[����Ă���O��
//        auto logo = std::dynamic_pointer_cast<UIImage>(system->GetComponent(1));
//        if (logo)
//        {
//            auto pos = logo->GetTransform().GetPosition();
//            pos.y = 150.0f + std::sin(m_animTimer * 0.05f) * 10.0f; // sin�g�ŏ㉺�ɗh�炷
//            logo->GetTransform().SetPosition(pos);
//        }
//    }
//
//    // Enter�L�[�������ꂽ��v���C�V�[���ɑJ��
//    if (CheckHitKey(KEY_INPUT_RETURN))
//    {
//        // �ێ����Ă������f���n���h�������̃V�[���Ɉ����p��
//        game.ChangeScene(std::make_unique<PlayScene>(m_playerModelHandle, m_enemyModelHandle));
//    }
//}
//
//// �`�揈���F3D�J�����̓K�p��UI�̕`��
//void TitleScene::Draw()
//{
//    m_cameraComponent->ApplyToDxLibCamera(); // DX���C�u�����ɃJ��������K�p
//    m_uiManager->DrawAll();                  // UI�S�̂�`��
//}
