#pragma once

#include "Component.h"
#include "DxLib.h"
#include "TransformComponent.h"
#include <memory>
#include <string>

// 2D�X�v���C�g�摜��`�悷�邽�߂̃R���|�[�l���g
// ���݂�UI�V�X�e���ɂ��u��������\��A�����I�ɂ͔p�~(UI�V�X�e�������O�ɍ쐬���ꂽ����)
class SpriteRendererComponent : public Component
{
private:
    int m_graphHandle;  // DxLib�Ŏ擾�����摜�̃n���h���iLoadGraph ���Ŏ擾�j

    // �摜�̕`��ʒu��X�P�[�����O�A��]���Ǘ�����Transform
    // UI��pTransform�Ƃ��ė��p
    std::shared_ptr<TransformComponent> m_spriteTransform;

    float m_scale = 1.0f;     // �X�v���C�g�̃X�P�[�����O�{���i1.0�œ��{�j
    bool m_centered = false;  // true�Ȃ�X�v���C�g�̒��S����ɕ`��ifalse�Ȃ獶���j
    int m_alpha = 255;        // �X�v���C�g�̓����x�i0 = ���S����, 255 = �s�����j

public:
    // �R���X�g���N�^
    SpriteRendererComponent(int handle, std::shared_ptr<TransformComponent> tf);

    // �`��{���i�X�P�[���j��ݒ�
    void SetScale(float scale) { m_scale = scale; }

    // �X�v���C�g�𒆉���ŕ`�悷�邩�ǂ�����ݒ�
    void SetCentered(bool centered) { m_centered = centered; }

    // �X�v���C�g�̓����x�i�A���t�@�l�j��ݒ�i0?255�j
    void SetAlpha(int alpha) { m_alpha = alpha; }

    // �X�v���C�g��2D�\���œ��I�ω������Ȃ����߁A�ʏ�͍X�V�����͕s�v
    void Update() override {}

    // �X�v���C�g����ʂɕ`�悷��i�ʒu�E�X�P�[���E���S�����E�����x�𔽉f�j
    void Draw() override;
};