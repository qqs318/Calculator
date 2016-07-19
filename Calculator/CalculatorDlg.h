
// CalculatorDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CCalculatorDlg 对话框
class CCalculatorDlg : public CDialogEx
{
// 构造
public:
	CCalculatorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton7();
//	CString m_cCurrentNum; // 当前显示框的值
	int  m_nCurState; // 用于标记当前计算状态
	BOOL m_bInputState; // 用于标记当前是否处于输入数值状态，输入数值时，可以del
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
