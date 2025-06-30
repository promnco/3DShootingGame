#include "SpriteRenderer.h"

// �R���X�g���N�^
SpriteRenderer::SpriteRenderer(const std::wstring& imagePath)
	: m_handle(-1)          // �摜�n���h���̏����l�i�����ȏ�ԁj
	, m_originalWidth(0)    // ���̉摜���̏����l
	, m_originalHeight(0)   // ���̉摜�����̏����l
	, m_visible(true)       // ������Ԃ͕\��
{
    // �摜�̓ǂݍ��݁i�t�@�C���p�X�w��j
	// LoadGraph �͉摜�t�@�C����ǂݍ��݁A�O���t�B�b�N�n���h����Ԃ�
	// c_str() �� std::wstring ���� const wchar_t* �ɕϊ�
    m_handle = LoadGraph(imagePath.c_str());

    // �ǂݍ��ݐ������ɉ摜�T�C�Y���擾���ĕۑ�
    if (m_handle != -1)
    {
        GetGraphSize(m_handle, &m_originalWidth, &m_originalHeight);
    }
}

// �`�揈��
void SpriteRenderer::Draw()
{
    // ��\���܂��͉摜�n���h���������ȏꍇ�͕`����X�L�b�v
    if (!m_visible || m_handle == -1)
        return;

    // �ʒu�E�X�P�[���E��]�����擾
    VECTOR2 pos = m_transform.GetPosition();
    VECTOR2 scale = m_transform.GetScale();
    float rotation = m_transform.GetRotation();

    // �摜�̒��S�_�i��]�E�X�P�[���̊�j
    int centerX = m_originalWidth / 2;
    int centerY = m_originalHeight / 2;

    // ���S��]�t���̃X�v���C�g�`��
	// DX���C�u������ DrawRotaGraph2 �֐����g�p
    DrawRotaGraph2
    (
        static_cast<int>(pos.x),     // �`�撆�S�ʒu X
        static_cast<int>(pos.y),     // �`�撆�S�ʒu Y
        centerX,                     // ��]�E�g��̊�_ X�i�摜�̒��S�j
        centerY,                     // ��]�E�g��̊�_ Y�i�摜�̒��S�j
        scale.x,                     // �X�P�[�����O X�iY�����͎g���Ă��Ȃ��j
        rotation,                    // ��]�p�i���W�A���j
        m_handle,                    // �O���t�B�b�N�n���h��
        TRUE                         // ���ߕ`��ON
    );
}

// �\���t���O��ݒ�
void SpriteRenderer::SetVisible(bool visible)
{
    m_visible = visible;
}

// �\���t���O���擾
bool SpriteRenderer::IsVisible() const
{
    return m_visible;
}

// ���̉摜�����擾
int SpriteRenderer::GetOriginalWidth() const
{
    return m_originalWidth;
}

// ���̉摜�������擾
int SpriteRenderer::GetOriginalHeight() const
{
    return m_originalHeight;
}

// Transform2D �I�u�W�F�N�g�ւ̎Q�Ƃ��擾
// �O������ʒu�E�X�P�[���E��]�̐��䂪�\
Transform2D& SpriteRenderer::GetTransform()
{
    return m_transform;
}