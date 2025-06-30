#include "DxLib.h"
#include "Game.h"
#include "ModelFactory.h"
#include "VirtualScreenManager.h"
#include <ctime>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // ���O�o�͖�����
    SetOutApplicationLogValidFlag(FALSE);

    // ���z��ʂ̑z��T�C�Y
    const int VIRTUAL_WIDTH = 1280;
    const int VIRTUAL_HEIGHT = 720;

    // �𑜓x�����z��ʂƓ����ɂ��ď�����
    SetGraphMode(VIRTUAL_WIDTH, VIRTUAL_HEIGHT, 32);

	// �e��ݒ�
    ChangeWindowMode(TRUE);             // �E�B���h�E���[�h�i�C�Ӂj
    SetUseZBuffer3D(TRUE);              // Z�o�b�t�@�L���i3D�p�j
    SetWriteZBuffer3D(TRUE);            // �������ݗL��
	SetDrawScreen(DX_SCREEN_BACK);      // �`�����o�b�N�o�b�t�@��
	SetBackgroundColor(0, 255, 255);    // �w�i�F��ΐF�ɐݒ�
    DxLib_Init();

    // ����������
	// �g�p��-> Game.cpp (�G�̃����_�������Ȃ�)
    srand(static_cast<unsigned int>(time(NULL)));

    // ���f���̓ǂݍ���
    int playerModel = ModelFactory::Instance().GetModel("player.mv1");
    int enemyModel  = ModelFactory::Instance().GetModel("enemy.mv1");

    // �Q�[���C���X�^���X����
	// �V�[���J�ڂ�Q�[���̏�ԊǗ����s��
    Game game(playerModel, enemyModel);

    // ���z��ʏ������iZ�o�b�t�@�t���j
    VirtualScreenManager::Init(VIRTUAL_WIDTH, VIRTUAL_HEIGHT);

    // ���C�����[�v
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // ���z��ʂɕ`��J�n�i�`�������z��ʂ� + ���S�������j
        VirtualScreenManager::BeginDraw();

        // �Q�[���X�V�E�`��i���z��ʓ��ōs����j
        game.Update();
        game.Draw();

        // ���z��� �� ����ʂɃX�P�[�����O�`��
        VirtualScreenManager::EndDraw();

        // ����� �� �\��ʂ֔��f
		// �����ŉ��z��ʂ̓��e������ʂɃX�P�[�����O���ĕ\��
        ScreenFlip();
    }

    // ���f�����
    ModelFactory::Instance().Clear();

    // DxLib�I��
    DxLib_End();
    return 0;
}