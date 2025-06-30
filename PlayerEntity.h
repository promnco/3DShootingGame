#pragma once
#include "Entity.h"
#include "TransformComponent.h"
#include "RenderModelComponent.h"
#include <memory>

// �v���C���[�̃I�u�W�F�N�g��\���N���X
class PlayerEntity : public Entity
{
public:
	// �v���C���[�̈ʒu��\���񋓌^
	std::shared_ptr<TransformComponent> m_playerTransform;

	int m_hp;                   // �v���C���[��HP
	int m_invincibleTimer;      // ���G���Ԃ̃^�C�}�[

	// �R���X�g���N�^
	PlayerEntity(int modelHandle);

	void HandleInput();			// ���͂���������
	void Update() override;		// �X�V�������s��
};