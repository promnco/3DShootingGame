#pragma once
#include "DxLib.h"
#include <windows.h> // POINT �\���̗p

// ���z��ʂ̕`��ƍ��W�ϊ����Ǘ����郆�[�e�B���e�B�N���X
// ���̃N���X�́A���z��ʂ̃T�C�Y��ݒ肵�A���ۂ̉�ʂɃX�P�[�����O���ĕ`�悷��@�\
// �C���X�^���X�����֎~����̂́A���[�e�B���e�B�N���X�Ƃ��Ă̐�����ۂ��߂ł��B
// ���[�e�B���e�B�N���X�͒ʏ�A�ÓI���\�b�h�݂̂�񋟂��A�C���X�^���X������K�v���Ȃ����߁B
// ���[�e�B���e�B�N���X�Ƃ́A����̋@�\��񋟂��邽�߂ɐ݌v����Ă���A��Ԃ������Ȃ����Ƃ���ʓI�B
class VirtualScreenManager
{
private:
    VirtualScreenManager() = delete; // �C���X�^���X���֎~

	static int s_virtualWidth;          // ���z��ʂ̕�
	static int s_virtualHeight;         // ���z��ʂ̍���
	static int s_virtualScreenHandle;   // ���z��ʂ̃n���h��

public:
    // ���z��ʂ̏�����
    static void Init(int virtualW, int virtualH);

    // ���z��ʂɕ`��J�n�i�N���A�܂ށj
    static void BeginDraw();

    // ���z��ʂ�����ʂɃX�P�[�����O�`��
    static void EndDraw();

    // ���z��ʂ̕��E�������擾
    static int GetVirtualWidth();
    static int GetVirtualHeight();

    // �}�E�X���W�����z��ʍ��W�ɕϊ�
    static POINT ConvertMousePositionToVirtual();
};