#pragma once

// �Q�[�����Ŏg�p����T�E���h���Ǘ�����N���X
class SoundManager
{
public:
    // �T�E���h�t�@�C�������ʂ��邽�߂̕ϐ�
    // int = bgm      : BGM
    // int = shot     : ���ˉ�
    // int = hit      : �����艹
    // int = gameOver : �Q�[���I�[�o�[��
	// int = button   : �{�^�����i�����I�ɒǉ��\��j
	// int = titleBGM : �^�C�g����ʂ�BGM�i�����I�ɒǉ��\��j
	// int = gameOberBGM : �Q�[���I�[�o�[����BGM�i�����I�ɒǉ��\��j
	int m_bgm, m_shot, m_hit, m_gameOver, m_button, m_titleBGM, m_gameOverBGM;

    // �T�E���h�̓ǂݍ��ݏ������s��
    void Load();

    // BGM���Đ�����
    void PlayBGM();

    // BGM�̍Đ����~����
    void StopBGM();

    // ���ˉ����Đ�����
    void PlayShot();

    // �����艹���Đ�����
    void PlayHit();

    // �Q�[���I�[�o�[�����Đ�����
    void PlayGameOver();

    // �����I�ȉ��P�ĂƂ��āA���̍Đ�����{��������@�ɂ��ċL�q
    // ���݂͌ʂɊ֐���p�ӂ��Ă��邪�A�����ŉ������ʂ��čĐ�������@��������
    // �Ⴆ�΁A������ int ��n���Aswitch����֐��|�C���^�Astd::function�Astd::map �Ȃǂ��g�p���ĊǗ�������@

    // +��
	// �V���O���g���p�^�[�����g�p���āASoundManager�̃C���X�^���X��������ɂ��邱�Ƃ�������
	// �t�@�T�[�h�p�^�[�����g�p���āA�T�E���h�̍Đ��������Ȍ��ɂ��邱�Ƃ�������
};