
// CalculatorDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CCalculatorDlg �Ի���
class CCalculatorDlg : public CDialogEx
{
// ����
public:
	CCalculatorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton7();
//	CString m_cCurrentNum; // ��ǰ��ʾ���ֵ
	int  m_nCurState; // ���ڱ�ǵ�ǰ����״̬
	BOOL m_bInputState; // ���ڱ�ǵ�ǰ�Ƿ���������ֵ״̬��������ֵʱ������del
	double m_dFirstValue;
	double m_dSecondValue;
//	CStatic m_cDisStatic;
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtonZ();
	afx_msg void OnBnClickedButtonD();
	afx_msg void OnBnClickedButtonDel();
	afx_msg void OnBnClickedButtonJia();

	void CurValueAdded(CString cNum);
	double GetCurValue();
	void   SetCurValue(double dCurValue);
	
	afx_msg void OnBnClickedButtonDeng();
	afx_msg void OnBnClickedButtonJian();
	afx_msg void OnBnClickedButtonCheng();
	afx_msg void OnBnClickedButtonChu();
};
