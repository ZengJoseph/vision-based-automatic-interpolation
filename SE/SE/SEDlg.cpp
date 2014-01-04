
// SEDlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CSEDlg 对话框



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


// CSEDlg 消息处理程序

BOOL CSEDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSEDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSEDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSEDlg::OnBnClickedButton1()
{
	CFileDialog	 dlg(TRUE);
	dlg.m_ofn.lpstrTitle=_T("选择文件");
	dlg.m_ofn.lpstrFilter=_T("All Files");
	CString path1;
	CString name;
	path1 = "";
	name = "";
	if(dlg.DoModal()==IDOK)
	{
		path1=dlg.GetPathName();//获取文件路径名
		//name=dlg.GetFileName();//获取文件名
	}
	if(path1=="")
		return ;//表示没有选择任何元素
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
	// TODO: 在此添加控件通知处理程序代码
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
	CString te = _T("数据量太小或者图片不正确");
	bstr1 = te;
	if(data.getnum() <= 2)
	{
		MessageBox(bstr1);
		return ;
	}
	float ans = data.insertvalue(num_value);
	//temp.Format(("%d",ans));
	//temp = CString("结果为") + temp;
	_bstr_t bstr;
	char temp[500] = "结果是";

	char nu[100];
	sprintf_s(nu,"%f",ans);
	strcat_s(temp,nu);
	bstr = temp;
	MessageBox(bstr);
	out = ans;

	UpdateData(false);
	
	
	//_T("D:\\game\\GBA模拟器(VisualBoyAdvance)汉化版\\GBA模拟器(VisualBoyAdvance)汉化版\\VisualBoyAdvance.exe"
	// TODO: 在此添加控件通知处理程序代码
}
