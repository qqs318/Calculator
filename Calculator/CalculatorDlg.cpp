
// CalculatorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

#define ID_CURSTATE_NONE -1
#define ID_CURSTATE_JIA   0
#define ID_CURSTATE_JIAN  1
#define ID_CURSTATE_CHENG 2
#define ID_CURSTATE_CHU   3

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg �Ի���



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
//	DDX_Control(pDX, IDC_STATIC_DIS, m_cDisStatic);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_0, &CCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_Z, &CCalculatorDlg::OnBnClickedButtonZ)
	ON_BN_CLICKED(IDC_BUTTON_D, &CCalculatorDlg::OnBnClickedButtonD)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CCalculatorDlg::OnBnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_JIA, &CCalculatorDlg::OnBnClickedButtonJia)
	ON_BN_CLICKED(IDC_BUTTON_DENG, &CCalculatorDlg::OnBnClickedButtonDeng)
	ON_BN_CLICKED(IDC_BUTTON_JIAN, &CCalculatorDlg::OnBnClickedButtonJian)
	ON_BN_CLICKED(IDC_BUTTON_CHENG, &CCalculatorDlg::OnBnClickedButtonCheng)
	ON_BN_CLICKED(IDC_BUTTON_CHU, &CCalculatorDlg::OnBnClickedButtonChu)
END_MESSAGE_MAP()


// CCalculatorDlg ��Ϣ�������

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_nCurState = ID_CURSTATE_NONE;
	m_bInputState = TRUE;
	m_dFirstValue = 0.;
	m_dSecondValue = 0.;
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCalculatorDlg::CurValueAdded(CString cNum)
{
	CString cCurrentNum;
	GetDlgItem(IDC_STATIC_DIS)->GetWindowText(cCurrentNum);
	if (!m_bInputState)
	{
		cCurrentNum = "0";
		m_bInputState = TRUE;
	}
	if (cNum == "." && cCurrentNum.Find(".") != -1)
	{
		return;
	}
	if (cCurrentNum == "0" && cNum == "0")
	{
		return;
	}
	if (cCurrentNum == "0" && cNum !=".")
	{
		cCurrentNum = "";
	}

	int nCount = cCurrentNum.GetLength();
	int nMax = 17; //С�������ʾ17λ������С���㣩
	if (cCurrentNum.Find(".") == -1)
	{
		nMax = 16; // ��С���������ʾ16λ
	}
	if (nCount < nMax)
	{
		GetDlgItem(IDC_STATIC_DIS)->SetWindowText(cCurrentNum + cNum);
	}
}

void CCalculatorDlg::OnBnClickedButton0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CurValueAdded("0");
}

void CCalculatorDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CurValueAdded("1");
}

void CCalculatorDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CurValueAdded("2");
}

void CCalculatorDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CurValueAdded("3");
}

void CCalculatorDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CurValueAdded("4");
}

void CCalculatorDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CurValueAdded("5");
}

void CCalculatorDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CurValueAdded("6");
}

void CCalculatorDlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CurValueAdded("7");
}

void CCalculatorDlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CurValueAdded("8");
}

void CCalculatorDlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CurValueAdded("9");
}

void CCalculatorDlg::OnBnClickedButtonZ()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString cCurrentNum;
	GetDlgItem(IDC_STATIC_DIS)->GetWindowText(cCurrentNum);
	if (cCurrentNum.Find("-") == -1 && cCurrentNum!="0")
	{
		GetDlgItem(IDC_STATIC_DIS)->SetWindowText("-"+cCurrentNum);
	}
	if (cCurrentNum.Find("-") != -1)
	{
		GetDlgItem(IDC_STATIC_DIS)->SetWindowText(cCurrentNum.Right(cCurrentNum.GetLength()-1));
	}
}

void CCalculatorDlg::OnBnClickedButtonD()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CurValueAdded(".");
}

void CCalculatorDlg::OnBnClickedButtonDel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (!m_bInputState)
	{
		return;
	}
	CString cCurrentNum;
	GetDlgItem(IDC_STATIC_DIS)->GetWindowText(cCurrentNum);
	if (cCurrentNum == "0")
	{
		return;
	}
	int nCount = cCurrentNum.GetLength();
	if (nCount == 1)
	{
		cCurrentNum = "0";
	}
	else
	{
		cCurrentNum = cCurrentNum.Left(nCount - 1);
	}

	GetDlgItem(IDC_STATIC_DIS)->SetWindowText(cCurrentNum);
}


void CCalculatorDlg::OnBnClickedButtonJia()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_dFirstValue = GetCurValue();
	m_nCurState = ID_CURSTATE_JIA;
	m_bInputState = FALSE;
}

void CCalculatorDlg::SetCurValue(double dCurValue)
{
	CString cValue;
	cValue.Format("%f", dCurValue);
	cValue.Trim("0");
	CString a = cValue.Right(1);
	if (cValue.Right(1) == ".")
	{
		cValue = cValue.Left(cValue.GetLength() - 1);
	}
	GetDlgItem(IDC_STATIC_DIS)->SetWindowText(cValue);

}

double CCalculatorDlg::GetCurValue()
{
	CString cCurrentNum;
	GetDlgItem(IDC_STATIC_DIS)->GetWindowText(cCurrentNum);
// 	if (cCurrentNum.Find(".") != -1)
// 	{
// 		cCurrentNum = cCurrentNum.Trim("0");
// 	}
	return atof(cCurrentNum);
}

void CCalculatorDlg::OnBnClickedButtonDeng()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_dSecondValue = GetCurValue();
	double dRes = 0.;
	BOOL bAble = TRUE;
	switch (m_nCurState)
	{
	case ID_CURSTATE_JIA:
		dRes = m_dFirstValue + m_dSecondValue;
		break;
	case ID_CURSTATE_JIAN:
		dRes = m_dFirstValue - m_dSecondValue;
		break;
	case ID_CURSTATE_CHENG:
		dRes = m_dFirstValue*m_dSecondValue;
		break;
	case ID_CURSTATE_CHU:
		dRes = m_dFirstValue / m_dSecondValue;
		break;
	default:
		bAble = FALSE;
		break;
	}
	if (bAble)
	{
		SetCurValue(dRes);
	}
	m_nCurState = ID_CURSTATE_NONE;
	m_bInputState = FALSE;
}


void CCalculatorDlg::OnBnClickedButtonJian()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_dFirstValue = GetCurValue();
	m_nCurState = ID_CURSTATE_JIAN;
	m_bInputState = FALSE;
}


void CCalculatorDlg::OnBnClickedButtonCheng()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_dFirstValue = GetCurValue();
	m_nCurState = ID_CURSTATE_CHENG;
	m_bInputState = FALSE;
}


void CCalculatorDlg::OnBnClickedButtonChu()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_dFirstValue = GetCurValue();
	m_nCurState = ID_CURSTATE_CHU;
	m_bInputState = FALSE;
}
