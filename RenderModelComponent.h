#pragma once
#include "Component.h"
#include "TransformComponent.h"
#include <memory>

// モデルの描画を担当するコンポーネント
class RenderModelComponent : public Component
{
private:
    int m_modelHandle;  // モデルハンドル
    std::shared_ptr<TransformComponent> m_renderTransform;  // 位置・回転情報

public:
    // コンストラクタ
	// model: モデルのハンドル, tf: 位置・回転を管理するTransformComponentのスマートポインタ
    RenderModelComponent(int model, std::shared_ptr<TransformComponent> tf);

    // 更新処理（位置・回転の反映）
    void Update() override;

    // 描画処理（位置・回転の反映付きで描画）
    void Draw() override;
};

