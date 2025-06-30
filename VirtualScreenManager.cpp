#include "VirtualScreenManager.h"
#include "DxLib.h"

// ���z��ʃT�C�Y�Ƃ��̃n���h���̐ÓI�ϐ���`
// �������l��1280x720�̉��z��ʂ�z��
int VirtualScreenManager::s_virtualWidth = 1280;
int VirtualScreenManager::s_virtualHeight = 720;
int VirtualScreenManager::s_virtualScreenHandle = -1;

// ���z��ʂ̏������i�𑜓x�ƃo�b�t�@�𐶐��j
void VirtualScreenManager::Init(int virtualW, int virtualH)
{
    s_virtualWidth = virtualW;
    s_virtualHeight = virtualH;

    // ���z��ʂ��쐬�iZ�o�b�t�@�t����TRUE�j
    // 3D�`��ɕK�v�Ȑ[�x�o�b�t�@���܂߂Đ���
    s_virtualScreenHandle = MakeScreen(virtualW, virtualH, TRUE);
}

// �`��J�n�����i���z��ʂւ̕`��ݒ�j
void VirtualScreenManager::BeginDraw()
{
    // �`�������z��ʂɐ؂�ւ�
    SetDrawScreen(s_virtualScreenHandle);

    // �F�o�b�t�@�̃N���A�i�O�t���[���̎c���������j
    ClearDrawScreen();

    // Z�o�b�t�@�̊��S�ȏ��������s�����߁A��ʑS�̂ɓh��Ԃ��`������{
    // ��DxLib�� ClearDrawScreen() �ł�Z�o�b�t�@�����S�ɃN���A����Ȃ��ꍇ�������
    DrawBox(0, 0, s_virtualWidth, s_virtualHeight, GetColor(0, 255, 255), TRUE);
}

// �`��I�������i���z��ʁ����E�B���h�E��ʂ֓]���j
void VirtualScreenManager::EndDraw()
{
	int windowW, windowH;               // ����ʂ̃T�C�Y���擾
	GetWindowSize(&windowW, &windowH);  // �E�B���h�E�̕��ƍ������擾

    // ����ʁi�o�b�N�o�b�t�@�j�֖߂�
    SetDrawScreen(DX_SCREEN_BACK);

    // ���z��ʂ̓��e���A�E�B���h�E�T�C�Y�ɃX�P�[�����O���ĕ`��
	// DXLib�� DrawExtendGraph() ���g�p
    DrawExtendGraph
    (
		0                           // �`��J�nX���W
		, 0                         // �`��J�nY���W
		, windowW                   // ����ʂ̕�
		, windowH                   // ����ʂ̍���
		, s_virtualScreenHandle     // ���z��ʂ̃n���h��
        ,TRUE                       // ���ߗL���i�A���t�@�܂ށj
    );
}

// ���݂̉��z��ʂ̕����擾
int VirtualScreenManager::GetVirtualWidth() { return s_virtualWidth; }

// ���݂̉��z��ʂ̍������擾
int VirtualScreenManager::GetVirtualHeight() { return s_virtualHeight; }

// ����ʏ�̃}�E�X���W���A���z��ʏ�̍��W�ɕϊ����ĕԂ�
// �����I�Ƀ}�E�X�d�l�̕ύX�ɑΉ����邽��
POINT VirtualScreenManager::ConvertMousePositionToVirtual()
{
    int mouseX, mouseY;
    GetMousePoint(&mouseX, &mouseY);

    int windowW, windowH;
    GetWindowSize(&windowW, &windowH);

    POINT result;

    // ���z��ʂ̃X�P�[�����O�䗦�Ɋ�Â��č��W�ϊ�
    result.x = static_cast<LONG>(mouseX * s_virtualWidth / static_cast<float>(windowW));
    result.y = static_cast<LONG>(mouseY * s_virtualHeight / static_cast<float>(windowH));

    return result;
}