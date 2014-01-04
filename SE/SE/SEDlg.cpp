
// SEDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SE.h"
#include "SEDlg.h"
#include "afxdialogex.h"
#include "windows.h"
#include <tchar.h>
#include <stdio.h>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSEDlg �Ի���



CSEDlg::CSEDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSEDlg::IDD, pParent)
	, num_value(0)
	, out(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSEDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, input_num);
	DDX_Text(pDX, IDC_EDIT1, num_value);
	//  DDX_Text(pDX, IDC_EDIT2, out);
	DDX_Text(pDX, IDC_EDIT2, out);
}

BEGIN_MESSAGE_MAP(CSEDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSEDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSEDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CSEDlg ��Ϣ�������

BOOL CSEDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CSEDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSEDlg::OnPaint()
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
HCURSOR CSEDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSEDlg::OnBnClickedButton1()
{
	CFileDialog	 dlg(TRUE);
	dlg.m_ofn.lpstrTitle=_T("ѡ���ļ�");
	dlg.m_ofn.lpstrFilter=_T("All Files");
	CString path1;
	CString name;
	path1 = "";
	name = "";
	if(dlg.DoModal()==IDOK)
	{
		path1=dlg.GetPathName();//��ȡ�ļ�·����
		//name=dlg.GetFileName();//��ȡ�ļ���
	}
	if(path1=="")
		return ;//��ʾû��ѡ���κ�Ԫ��
	path = path1;
	//MessageBox(_T("path success"));
		_bstr_t bstr,bstr1;
	bstr = path;
	int l = 0;
	int flag = 0;
	CString exefile;
	for(l = path.GetLength();l > 0;l --)
	{
		if(path[l] == '\\')
		{
			flag = flag + 1;
		}
		else
		{
			flag = 0;
		}
		if (flag == 1)
		{
			break;	
		}
	}
	int i;
	CString pa;
	for (i = l + 1;i < path.GetLength();i++)
	{
		pa.AppendChar( path[i]);
	}
	//for(i = 0;i < l;i++)
	//{
	//	exefile.AppendChar(path[i]);
	//}
	//exefile.AppendChar('\\');
	//exefile.Append(CString("project3.exe"));
	exefile = "project3.exe";
	bstr1 = exefile;
	bstr = pa;
	ShellExecute(NULL,_T("open"),bstr1,bstr,NULL,SW_SHOW);
	HBITMAP hbitmap=(HBITMAP)LoadImage(NULL,bstr,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	ShellExecute(NULL,_T("open"),bstr,NULL,NULL,SW_SHOW);
	Invalidate(true);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CSEDlg::OnBnClickedButton2()
{
	bool ok = UpdateData(true);
	if (ok == false)
	{
		return;
	}
	this->data = *(new DATA());
	data.read();
	data.order();
	_bstr_t bstr1;
	CString te = _T("������̫С����ͼƬ����ȷ");
	bstr1 = te;
	if(data.getnum() <= 2)
	{
		MessageBox(bstr1);
		return ;
	}
	float ans = data.insertvalue(num_value);
	//temp.Format(("%d",ans));
	//temp = CString("���Ϊ") + temp;
	_bstr_t bstr;
	char temp[500] = "�����";

	char nu[100];
	sprintf_s(nu,"%f",ans);
	strcat_s(temp,nu);
	bstr = temp;
	MessageBox(bstr);
	out = ans;

	UpdateData(false);
	
	
	//_T("D:\\game\\GBAģ����(VisualBoyAdvance)������\\GBAģ����(VisualBoyAdvance)������\\VisualBoyAdvance.exe"
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
