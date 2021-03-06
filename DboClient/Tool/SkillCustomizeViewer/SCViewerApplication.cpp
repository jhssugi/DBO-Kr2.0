#include "precomp_scviewer.h"
#include <ddraw.h>
#include "SCViewerApplication.h"
#include "NtlDebug.h"
#include "NtlCharsetPrint.h"
#include "NtlText.h"
#include "NtlBitFlagManager.h"

#include "guicore_precomp.h"
#include "gui_precomp.h"
#include "gui_fontmanager.h"
#include "gui_renderer.h"
#include "GuiUtil.h"

#include "TableContainer.h"
#include "TableFileNameList.h"
#include "..\\..\\Client\\Gui\\SkillCustomizeParser.h"

CGuiDevApplication * CGuiDevApplication::m_pInstance = NULL;

CGuiDevApplication::CGuiDevApplication() : m_pCharset(NULL)
{
	m_pInstance = this;
	m_pSkillCustomizeParser = NULL;
	m_pTableContainer = NULL;

	m_BackgroundColor.red   = 50;
	m_BackgroundColor.green = 50;
	m_BackgroundColor.blue  = 50;
	m_BackgroundColor.alpha = 0;

	m_ForegroundColor.red   = 255;
	m_ForegroundColor.green = 255;
	m_ForegroundColor.blue  = 255;
	m_ForegroundColor.alpha = 255;

	m_pCamera = NULL;
	m_pResMgr = 0;
	m_pSurMgr = 0;
	m_pCompMgr = 0;
	m_pGuiMgr = 0;

	m_fTime = 0.0f;

	m_bActiveBtn = FALSE;
}

CGuiDevApplication::~CGuiDevApplication()
{
	
}

RwBool CGuiDevApplication::CreateSubSystem(RwUInt32 iWidth, RwUInt32 iHeight, RwBool zBuffer)
{
	NTL_FUNCTION("CGuiDevApplication::CreateSubSystem" );

	CNtlApplication::CreateSubSystem(iWidth, iHeight, zBuffer);

	// camera 
	m_pCamera = NTL_NEW CNtlCamera;
	if(!m_pCamera->Create(iWidth, iHeight, zBuffer, 1.f, 500.f))
	{
		NTL_RETURN(FALSE);
	}
	
	// character set
	m_pCharset = RtCharsetCreate(&m_ForegroundColor, &m_BackgroundColor);
    if( m_pCharset == NULL )
	{
		NTL_RETURN(FALSE);
	}	

	m_pResMgr = NTL_NEW gui::CResourceManager;
	m_pSurMgr = NTL_NEW gui::CSurfaceManager(m_pResMgr);	
	m_pCompMgr = NTL_NEW gui::CComponentManager;
	m_pGuiMgr = NTL_NEW gui::CGUIManager(CRectangle(0, 0, iWidth, iHeight));
	
	// Table
	m_pTableContainer = NTL_NEW CTableContainer;
	
	CNtlBitFlagManager flagManager;
	if (false == flagManager.Create(CTableContainer::TABLE_COUNT))
		return false;
	
	CTableFileNameList fileNameList;
	if (false == fileNameList.Create())
		return false;
	
	//DWORD64 dwCreateTableFlag = CTableContainer::TABLE_FLAG_SKILL | CTableContainer::TABLE_FLAG_ACTION | CTableContainer::TABLE_FLAG_HTB_SET | CTableContainer::TABLE_FLAG_TEXT_ALL;
	//CTableFileNameList FileNameList;
	flagManager.Set(CTableContainer::TABLE_SKILL);
	flagManager.Set(CTableContainer::TABLE_HTB_SET);			
	flagManager.Set(CTableContainer::TABLE_ACTION);	
	flagManager.Set(CTableContainer::TABLE_TEXT_ALL);

	fileNameList.SetFileName( CTableContainer::TABLE_SKILL, "Table_Skill_Data" );
	fileNameList.SetFileName( CTableContainer::TABLE_HTB_SET, "Table_HTB_Set_Data" );
	fileNameList.SetFileName( CTableContainer::TABLE_ACTION, "Table_Action_Data" );
	fileNameList.SetFileName( CTableContainer::TABLE_TEXT_ALL, "Table_Text_All_Data" );
	if( !m_pTableContainer->Create( flagManager, "data", &fileNameList, CTable::LOADING_METHOD_BINARY, GetACP(), NULL ) )
		return FALSE;

	CSkillCustomizeParser::SetCommonData( m_pTableContainer->GetSkillTable(), m_pTableContainer->GetHTBSetTable(), m_pTableContainer->GetActionTable(), m_pTableContainer->GetTextAllTable(), m_pSurMgr );

	// gui setup
	gui::CSetupGUI::Init( GetHWnd(), iWidth, iHeight, m_pGuiMgr, "script\\GuiFont.def", "metatag.htm", "script\\FlashFont.def" );

	m_pResMgr->AddPage("GuiDevTest.rsr");
	m_strResPage = "GuiDevTest.rsr";

	m_pResMgr->AddPage("Game.rsr");
	m_strSkillResPage = "Game.rsr";

	m_pSurMgr->AddPage("GuiDevTest.srf");
	m_strSurPage = "GuiDevTest.srf";

	m_pSurMgr->AddPage("SkillCustomize.srf");
	m_strSkillPage = "SkillCustomize.srf";

	m_hCompPage = m_pCompMgr->AddPage("GuiDevTest.frm");
	m_strCompPage = "GuiDevTest.frm";

	m_pCompMgr->CreateComponents( m_hCompPage, m_pGuiMgr, m_pSurMgr );
	gui::CToolTip* pToolTip = new gui::CToolTip( CRectangle( 0, 0, 100, 100 ), m_pGuiMgr, m_pSurMgr );
	pToolTip->SetMouseMargin( 32, 32 );
	gui::GetGlobalComponent()->SetToolTip( pToolTip );

	m_pThis = reinterpret_cast<gui::CDialog*>( m_pCompMgr->GetComponent( m_hCompPage, "dlgView" ) );
	m_pSkillCustomize = reinterpret_cast<gui::CDialog*>( m_pCompMgr->GetComponent( m_hCompPage, "dlgCustomize" ) );
	m_pInput = reinterpret_cast<gui::CInputBox*>( m_pCompMgr->GetComponent( m_hCompPage, "ibxBuild" ) );
	m_pbtnBuild = reinterpret_cast<gui::CButton*>( m_pCompMgr->GetComponent( m_hCompPage, "btnBuild" ) );
	m_pbtnActive = reinterpret_cast<gui::CButton*>( m_pCompMgr->GetComponent( m_hCompPage, "btnActive" ) );
	m_pstbError = reinterpret_cast<gui::CStaticBox*>( m_pCompMgr->GetComponent( m_hCompPage, "stbError" ) );
	m_pscbScroll = reinterpret_cast<gui::CScrollBar*>( m_pCompMgr->GetComponent( m_hCompPage, "scbScroll" ) );
	m_pscbScroll->SetRange( 0, m_pSkillCustomize->GetHeight() - m_pThis->GetHeight() );
	m_pscbScroll->SetValue( 0 );
	m_pInput->SetText( "sample.txt" );

	m_slotReturn = m_pInput->SigReturnPressed().Connect( this, &CGuiDevApplication::OnInputReturn );
	m_slotBtnClick = m_pbtnBuild->SigClicked().Connect( this, &CGuiDevApplication::OnBtnClick );
	m_slotActiveBtnClick = m_pbtnActive->SigClicked().Connect( this, &CGuiDevApplication::OnActiveBtnClick );
	m_slotScrollChange = m_pscbScroll->SigValueChanged().Connect( this, &CGuiDevApplication::OnScrollChanged );
	m_slotSliderMove = m_pscbScroll->SigSliderMoved().Connect( this, &CGuiDevApplication::OnScrollChanged );
	m_slotCaptureWheelMove = m_pGuiMgr->SigCaptureWheelMove().Connect( this, &CGuiDevApplication::OnCaptureWheelMove );
	m_slotResizeCustomize = m_pSkillCustomize->SigResize().Connect( this, &CGuiDevApplication::OnResizeSkillCustomize );

	NTL_RETURN(TRUE);
}	

RwBool CGuiDevApplication::AttachPlugin()
{
	NTL_FUNCTION( "CGuiDevApplication::AttachPlugin" );

	if( !RpWorldPluginAttach() )
		NTL_RETURN(FALSE);
	
	if( !RpCollisionPluginAttach() )
		NTL_RETURN(FALSE);
	
	if( !RtAnimInitialize() )
		NTL_RETURN(FALSE);
	
	if( !RpHAnimPluginAttach() )
		NTL_RETURN(FALSE);
	
	if( !RpSkinPluginAttach() )
		NTL_RETURN(FALSE);

	if ( !RpToonPluginAttach() )
		NTL_RETURN(FALSE);

	if( !RpUserDataPluginAttach() )
		NTL_RETURN(FALSE);

	if( !RpIdPluginAttach() )
		NTL_RETURN(FALSE);
	
	NTL_RETURN(TRUE);
}

RwBool CGuiDevApplication::Resize(RwUInt32 iWidth, RwUInt32 iHeight, RwBool zBuffer)
{
	NTL_FUNCTION("CGuiDevApplication::Resize" );

	CNtlApplication::Resize(iWidth, iHeight, zBuffer, FALSE );

	if(m_pCamera != NULL)
	{
		if (m_pCamera->GetCamera())
		{
			if (iWidth == 0 || iHeight == 0)
			{
			}
			else
			{
				RwRect rt;
				rt.x = 0; rt.y = 0; rt.w = iWidth; rt.h = iHeight;
				m_pCamera->SetCameraSize(&rt); 				
			}
			NTL_RETURN(TRUE);
		}
		else
		{
			NTL_RETURN(FALSE);
		}
	}

	NTL_RETURN(TRUE);
}


LRESULT CGuiDevApplication::PreTranslateMessage(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	if(m_pGuiMgr)
        return m_pGuiMgr->Win32EventProc(window, message, wParam, lParam);
	else
		return 0;
}

RwBool CGuiDevApplication::Update(RwReal fTime, RwReal fElapsedTime)
{
	NTL_FUNCTION("CGuiDevApplication::Update" );

	CEventTimer::KeepAlive();
	
	m_fTime += fElapsedTime;

	if (RwCameraClear(m_pCamera->GetCamera(), &m_BackgroundColor, rwCAMERACLEARZ|rwCAMERACLEARIMAGE))
	{
		//Ready to render scene.
		if( RwCameraBeginUpdate(m_pCamera->GetCamera()) )
		{
			RwBlendFunction eSrcBlend;
			RwBlendFunction eDestBlend;

			RwD3D9SetTexture(NULL, 0);
			RwD3D9SetTexture(NULL, 1);

			RwD3D9SetTextureStageState (0, D3DTSS_COLOROP, D3DTOP_MODULATE); 
			RwD3D9SetTextureStageState (0, D3DTSS_COLORARG1, D3DTA_TEXTURE); 
			RwD3D9SetTextureStageState (0, D3DTSS_COLORARG2, D3DTA_DIFFUSE); 

			// stage 0 alpha : nada 
			RwD3D9SetTextureStageState (0, D3DTSS_ALPHAOP,  D3DTOP_MODULATE); 
			RwD3D9SetTextureStageState (0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE); 
			RwD3D9SetTextureStageState (0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE); 

			RwRenderStateSet(rwRENDERSTATESHADEMODE, (void *)rwSHADEMODEGOURAUD);
			RwRenderStateSet(rwRENDERSTATEZTESTENABLE, (void *) FALSE);
			RwRenderStateSet(rwRENDERSTATEZWRITEENABLE, (void *) FALSE);
			RwRenderStateSet(rwRENDERSTATETEXTURERASTER, (void *) NULL);
			RwRenderStateSet(rwRENDERSTATEVERTEXALPHAENABLE, (void *) TRUE);
			RwRenderStateGet(rwRENDERSTATESRCBLEND, (void *)&eSrcBlend);
			RwRenderStateGet(rwRENDERSTATEDESTBLEND, (void *)&eDestBlend);
			RwRenderStateSet(rwRENDERSTATESRCBLEND, (void *)rwBLENDSRCALPHA);
			RwRenderStateSet(rwRENDERSTATEDESTBLEND, (void *)rwBLENDINVSRCALPHA);

			// gui render
			g_GuiRenderer.ResetRender();

			if(m_pGuiMgr)
				m_pGuiMgr->Show();

			g_GuiRenderer.Render();

			RwD3D9SetTexture(NULL, 0);

			RwRenderStateSet(rwRENDERSTATEZTESTENABLE, (void *) TRUE);
			RwRenderStateSet(rwRENDERSTATEZWRITEENABLE, (void *) TRUE);
			RwRenderStateSet(rwRENDERSTATETEXTURERASTER, (void *) NULL);
			RwRenderStateSet(rwRENDERSTATEVERTEXALPHAENABLE, (void *) FALSE);
			RwRenderStateSet(rwRENDERSTATESRCBLEND, (void *)eSrcBlend);
			RwRenderStateSet(rwRENDERSTATEDESTBLEND, (void *)eDestBlend);

			DisplayInfo();

			RwCameraEndUpdate(RwCameraGetCurrentCamera());
		}

		RwCameraShowRaster(m_pCamera->GetCamera(), GetHWnd(), 0);
	}
	
	NTL_RETURN(TRUE);
}

void CGuiDevApplication::Destroy()
{
	NTL_FUNCTION("CGuiDevApplication::Destroy" );

	NTL_DELETE( m_pSkillCustomizeParser );

	m_pCompMgr->DestroyComponents (m_hCompPage);
	m_pResMgr->RemovePage(m_strResPage);
	m_pResMgr->RemovePage(m_strSkillResPage);
	m_pSurMgr->RemovePage(m_strSurPage);
	m_pSurMgr->RemovePage(m_strSkillPage);
	m_pCompMgr->RemovePage(m_hCompPage);

	if(m_pGuiMgr)
	{
		NTL_DELETE(m_pGuiMgr);
	}

	if(m_pCompMgr)
	{
		NTL_DELETE(m_pCompMgr);
	}

	if(m_pSurMgr)
	{
		NTL_DELETE(m_pSurMgr);
	}

	if(m_pResMgr)
	{
		NTL_DELETE(m_pResMgr);
	}

	CEventListener_Win32::RemoveAll();

	// character set destroy
	if(m_pCharset)
    {
		RtCharsetClose();
		RwRasterDestroy(m_pCharset);
		m_pCharset = NULL;
    }
	
	// camera destroy
	if(m_pCamera)
	{
		m_pCamera->Destroy();
		NTL_DELETE(m_pCamera);
		m_pCamera = NULL;
	}

	// gui
	gui::CSetupGUI::Deinit();

	//
	CNtlApplication::Destroy();
	
	NTL_RETURNVOID();
}

void CGuiDevApplication::DisplayInfo()
{
	RwChar caption[256];
	RwInt32 iIdx = 0;
	
	//fps
	RsSprintf(caption, RWSTRING("FPS: %4.2f"), GetFps());
	RsCharsetPrint(m_pCharset, caption, 0, iIdx++, rsPRINTPOSTOPRIGHT);
}

LRESULT CGuiDevApplication::WndProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch( message )
	{
	case WM_KEYUP:
		{
			
		}
		break;
	default:
		break;
	}

	return CNtlApplication::WndProc(window, message, wParam, lParam);
}

VOID CGuiDevApplication::OnBtnClick( gui::CComponent* pComponent )
{
	OnInputReturn();
}

VOID CGuiDevApplication::OnInputReturn(VOID)
{
	const WCHAR* wszText = m_pInput->GetText();
	RwChar buf[256];

	::WideCharToMultiByte( GetACP(), 0, wszText, -1, buf, 256, NULL, NULL );

	if( strlen( buf ) == 0 )
		ParseSkillCustomizeFile( "sample.txt" );
	else
		ParseSkillCustomizeFile( buf );
}

VOID CGuiDevApplication::ParseSkillCustomizeFile( RwChar* szFileName )
{
	NTL_DELETE( m_pSkillCustomizeParser );

	m_pSkillCustomizeParser = NTL_NEW CSkillCustomizeParser( szFileName );
	
	m_pSkillCustomize->SetPosition( CRectangle( 0, 0, m_pThis->GetWidth(), m_pThis->GetHeight() ) );
	m_pscbScroll->SetValue( 0 );

	m_pSkillCustomizeParser->GenerateGuiItem( m_pSkillCustomize );

	std::string strError;
	m_pSkillCustomizeParser->ReadError( strError );

	if( strError.size() )
		m_pstbError->SetText( strError.c_str() );	
	else
		m_pstbError->SetText( "Load Success" );

	m_bActiveBtn = TRUE;
	OnActiveBtnClick( NULL );
}

VOID CGuiDevApplication::OnScrollChanged( RwInt32 nNewOffset )
{
	CRectangle rtPos = m_pSkillCustomize->GetPosition();

	m_pSkillCustomize->SetPosition( rtPos.left, -nNewOffset );
}

VOID CGuiDevApplication::OnCaptureWheelMove( RwInt32 nFlag, RwInt16 sDelta, CPos& pos )
{
	if( !m_pThis->IsVisible() )
		return;

	if( m_pThis->GetParent()->GetChildComponentReverseAt( pos.x - m_pThis->GetParent()->GetScreenRect().left, pos.y - m_pThis->GetParent()->GetScreenRect().top ) != m_pThis ) 
		return;

	if( m_pThis->PosInRect( pos.x, pos.y ) != gui::CComponent::INRECT ) 
		return;
		
	RwInt32 nValue = m_pscbScroll->GetValue();
	RwInt32 nMaxValue = m_pscbScroll->GetMaxValue();
	RwInt32 nDelta = nValue - sDelta / 10;
	 
	if( nDelta < 0 ) 
		nDelta = 0;
	else if( nDelta > nMaxValue ) 
		nDelta = nMaxValue;
	
	m_pscbScroll->SetValue( nDelta );	
}

VOID CGuiDevApplication::OnResizeSkillCustomize( RwInt32 nOldWidth, RwInt32 nOldHeight )
{
	m_pscbScroll->SetRange( 0, m_pSkillCustomize->GetHeight() - m_pThis->GetHeight() );
	m_pscbScroll->SetValue( 0 );
}

VOID CGuiDevApplication::OnActiveBtnClick( gui::CComponent* pComponent )
{
	if( !m_pSkillCustomizeParser )
		return;

	CSkillCustomizeParser::MAP_SKILLITEM& mapSkill = m_pSkillCustomizeParser->GetComponentMap();
	CSkillCustomizeParser::MAP_SKILLITEM_ITER iter;

	if( mapSkill.empty() )
		return;

	m_bActiveBtn = !m_bActiveBtn;
	
	if( m_bActiveBtn )
		m_pbtnActive->SetText( "디액티브" );		
	else
		m_pbtnActive->SetText( "액티브" );	

	for( iter = mapSkill.begin() ; iter != mapSkill.end() ; ++iter )
	{
		CSkillCustomizeSkillItem* pItem = iter->second;

		pItem->SetActive( m_bActiveBtn );
		pItem->SetLineActive( m_bActiveBtn, LINE_TYPE_UPGRADE );
		pItem->SetLineActive( m_bActiveBtn, LINE_TYPE_OPTION );

		if( m_bActiveBtn )
		{
			pItem->SetColor( 255, 255, 255 );
		}
		else
		{
			pItem->SetColor( 120, 120, 120 );
		}
	}		
}