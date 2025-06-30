#include "RenderModelComponent.h"
#include "DxLib.h"

// コンストラクタ
RenderModelComponent::RenderModelComponent(int model, std::shared_ptr<TransformComponent> tf)
	: m_modelHandle(model)		// モデルハンドルを設定
	, m_renderTransform(tf)		// TransformComponentを設定
{
}

// モデルの位置・回転を毎フレーム更新
void RenderModelComponent::Update()
{
	MV1SetPosition(m_modelHandle, m_renderTransform->position);     // モデルの位置を更新
	MV1SetRotationXYZ(m_modelHandle, m_renderTransform->rotation);  // モデルの回転を更新
}

// 描画（位置・回転が正しく反映された状態で描画）
void RenderModelComponent::Draw()
{
    MV1SetPosition(m_modelHandle, m_renderTransform->position);
    MV1SetRotationXYZ(m_modelHandle, m_renderTransform->rotation);
	// モデルを描画
	MV1DrawModel(m_modelHandle);
}
