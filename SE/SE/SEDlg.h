
// SEDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "DATA.h"

// CSEDlg �Ի���
class CSEDlg : public CDialogEx
{
// ����
public:
	CSEDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SE_DIALOG };
	DATA data;
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
	CString path;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
//	CEdit input_num;
	afx_msg void OnBnClickedButton2();
	int num_value;
//	int out;
	float out;
};
