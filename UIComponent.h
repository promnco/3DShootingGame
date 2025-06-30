#pragma once
#include "Transform2D.h"

// Transform2D���g�p����UI�v�f�̈ʒu�A��]�A�X�P�[�����Ǘ����邽�߂̃C���^�[�t�F�[�X
// UI�̊��N���X�i�S�Ă�UI�v�f�̐e�j
// ���̒��ۃN���X������̓I�Ȏ����������Ă���
// �����b�g: UI�v�f�̋��ʋ@�\��񋟂��ATransform2D�𗘗p���Ĉʒu���]�A�X�P�[�����Ǘ��ł���
class UIComponent
{
protected:
	bool m_visible;             // �\�����
	Transform2D m_transform;    // 2D�ό`���i�ʒu�A��]�A�X�P�[���Ȃǁj

public:
    UIComponent();
    virtual ~UIComponent() = default;

    // ���t���[���`�揈���i�p����Ŏ����j
    virtual void Draw() = 0;

    // �\���^��\���؂�ւ�
    virtual void SetVisible(bool visible) = 0;
    virtual bool IsVisible() const = 0;

    // Transform2D �̎擾�E�ݒ�
    Transform2D& GetTransform();
    const Transform2D& GetTransform() const;
};

// ����C���^�[�t�F�[�X�Ƃ��ẮA
// ���������������Ă��邽�߁A���ۃN���X�Ƃ��Ă̖������ʂ����Ă��Ȃ�
// �C���ĂƂ��ẮAUIComponent�𒊏ۃN���X�ɂ��āA
// �ʂ̃N���X��Transform2D���Ǘ�����悤�ɂ��邱�Ƃ��l������