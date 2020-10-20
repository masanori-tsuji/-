//================================================================
//
// 入力処理 [input.cpp]
// Author : Suzuki Mahiro
//
//================================================================

//****************************************************************
//インクルードファイル
//****************************************************************
#include "input.h"

//****************************************************************
//静的メンバ変数宣言
//****************************************************************
LPDIRECTINPUT8 CInput::m_pInput = NULL;			// DirectInputオブジェクトへのポインタ

//****************************************************************
//コンストラクタ
//****************************************************************
CInput::CInput()
{
}

//****************************************************************
//デストラクタ
//****************************************************************
CInput::~CInput()
{
}

//****************************************************************
// インプットの初期化
//****************************************************************
HRESULT CInput::Init(HINSTANCE hInstance)
{
	// DirectInputオブジェクトの作成
	if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pInput, NULL)))
	{
		return E_FAIL;
	}

	return S_OK;
}

//****************************************************************
// インプットの終了
//****************************************************************
void CInput::Uninit(void)
{
	//インプットの消去
	if (m_pInput != NULL)
	{
		m_pInput->Release();
		m_pInput = NULL;
	}
}