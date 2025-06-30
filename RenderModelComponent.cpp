#include "RenderModelComponent.h"
#include "DxLib.h"

// �R���X�g���N�^
RenderModelComponent::RenderModelComponent(int model, std::shared_ptr<TransformComponent> tf)
	: m_modelHandle(model)		// ���f���n���h����ݒ�
	, m_renderTransform(tf)		// TransformComponent��ݒ�
{
}

// ���f���̈ʒu�E��]�𖈃t���[���X�V
void RenderModelComponent::Update()
{
	MV1SetPosition(m_modelHandle, m_renderTransform->position);     // ���f���̈ʒu���X�V
	MV1SetRotationXYZ(m_modelHandle, m_renderTransform->rotation);  // ���f���̉�]���X�V
}

// �`��i�ʒu�E��]�����������f���ꂽ��Ԃŕ`��j
void RenderModelComponent::Draw()
{
    MV1SetPosition(m_modelHandle, m_renderTransform->position);
    MV1SetRotationXYZ(m_modelHandle, m_renderTransform->rotation);
	// ���f����`��
	MV1DrawModel(m_modelHandle);
}
