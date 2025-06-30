#include "SpriteRendererComponent.h"

// �R���X�g���N�^
SpriteRendererComponent::SpriteRendererComponent(int handle, std::shared_ptr<TransformComponent> tf)
    : m_graphHandle(handle)       // �摜�n���h���iLoadGraph�ȂǂŎ擾�����l�j
    , m_spriteTransform(tf)       // �X�v���C�g�`��ʒu�E��]�E�X�P�[���Ȃǂ̏�������Transform
{
}

// �`�揈��
// TransformComponent �̈ʒu�����ƂɁA�X�P�[���E���S�����E�����x�𔽉f���ĕ`��
void SpriteRendererComponent::Draw()
{
    // �����ȃn���h����Transform���ݒ肳��Ă��Ȃ��ꍇ�͕`����X�L�b�v
    if (m_graphHandle == -1 || m_spriteTransform == nullptr) return;

    int width = 0, height = 0;

    // �摜�T�C�Y���擾�i���摜�̃s�N�Z�����ƍ����j
    GetGraphSize(m_graphHandle, &width, &height);

    // �`���ʒu��Transform��x, y���W����擾�iZ���W��2D�`��ł͎g�p���Ȃ��j
    int drawX = static_cast<int>(m_spriteTransform->position.x);
    int drawY = static_cast<int>(m_spriteTransform->position.y);

    // �u���S�����v�I�v�V�������L���ȏꍇ�A�`��ʒu���摜�̒��S�ɂ��炷
    if (m_centered)
    {
        drawX -= static_cast<int>(width * 0.5f * m_scale);  // �����̕� �~ �X�P�[���� ���Ɉړ�
        drawY -= static_cast<int>(height * 0.5f * m_scale); // �����̍��� �~ �X�P�[���� ��Ɉړ�
    }

    // �A���t�@�u�����h��L���ɂ��A�����x��ݒ�
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);

    // �摜���X�P�[�����O���ĕ`��i����ƉE���̍��W���w��j
    DrawExtendGraph
    (
        drawX,
        drawY,
        drawX + static_cast<int>(width * m_scale),
        drawY + static_cast<int>(height * m_scale),
        m_graphHandle,
        TRUE  // ���ߐF���g�p�i���F�𓧉߂���PNG�ȂǂɑΉ��j
    );

    // �u�����h���[�h�����ɖ߂��i��������Ȃ��Ƒ��̕`��ɂ��e�����o��j
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}