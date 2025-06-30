#pragma once
#include "Component.h"
#include "TransformComponent.h"
#include <memory>

// ���f���̕`���S������R���|�[�l���g
class RenderModelComponent : public Component
{
private:
    int m_modelHandle;  // ���f���n���h��
    std::shared_ptr<TransformComponent> m_renderTransform;  // �ʒu�E��]���

public:
    // �R���X�g���N�^
	// model: ���f���̃n���h��, tf: �ʒu�E��]���Ǘ�����TransformComponent�̃X�}�[�g�|�C���^
    RenderModelComponent(int model, std::shared_ptr<TransformComponent> tf);

    // �X�V�����i�ʒu�E��]�̔��f�j
    void Update() override;

    // �`�揈���i�ʒu�E��]�̔��f�t���ŕ`��j
    void Draw() override;
};

