
// JosephDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Joseph.h"
#include "JosephDlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include "Circle.h"

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


// CJosephDlg �Ի���



CJosephDlg::CJosephDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CJosephDlg::IDD, pParent)
	, m_HeadCount(0)
	, m_Start(0)
	, m_Gap(0)
	, m_strText(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CJosephDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_HEADCOUNT, m_HeadCount);
	DDX_Text(pDX, IDC_START, m_Start);
	DDX_Text(pDX, IDC_GAP, m_Gap);
	//	DDX_Text(pDX, IDC_EDIT1, m_strText);
	DDX_Control(pDX, IDC_JOSEPH, m_btn);
}

BEGIN_MESSAGE_MAP(CJosephDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_JOSEPH, &CJosephDlg::OnBnClickedJoseph)
//	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CJosephDlg ��Ϣ�������

BOOL CJosephDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	HICON hicon = AfxGetApp()->LoadIcon(IDI_START);//IDI_ICON1������ӵ�ICON�ļ���� 
	m_btn.SetIcon(hicon); //m_icon�ǰ�ť�ĳ�Ա���� 
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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CJosephDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CJosephDlg::OnPaint()
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
HCURSOR CJosephDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CJosephDlg::OnBnClickedJoseph()
{
	UpdateData();

	CCircle circle(m_HeadCount, m_Start, m_Gap);
	CListCtrl * pList = (CListCtrl *)GetDlgItem(IDC_LIST);
	pList->DeleteAllItems();
	if (!circle.JudgeHeadCount())
	{
		pList->DeleteAllItems();
		AfxMessageBox(_T("������Ӧ�ô���0"));
		return;
	}
	if (!circle.JudgeStart())
	{
		pList->DeleteAllItems();
		AfxMessageBox(_T("��ʼλ��Ӧ�ô���0��С��������"));
		return;
	}
	if (!circle.JudgeGap())
	{
		pList->DeleteAllItems();
		AfxMessageBox(_T("���Ӧ������0"));
		return;
	}
	circle.Run();
	CProgressCtrl* proCtrl = (CProgressCtrl *)GetDlgItem(IDC_PROGRESS1);
	proCtrl->SetRange(0, m_HeadCount);
	proCtrl->SetPos(0);     //��ʼ��������

	for (int i = 1; i <= m_HeadCount; i++)
	{
		CString szStr;
		szStr.Format(_T("��%d�����˵ı����%d"), i, circle.roll[i]);
		int nCount = pList->GetItemCount();
		pList->InsertItem(nCount, szStr);
		proCtrl->SetStep(1);   //���ò���
		proCtrl->StepIt();
		//Sleep(1000);
		//�༭����ʾ����
		int nPos = (i * 100 / m_HeadCount);
		CString s;
		s.Format(_T("%d"), nPos);
		GetDlgItem(IDC_EDIT1)->SetWindowText((s + (CString)"%"));
		GetDlgItem(IDC_EDIT1)->UpdateWindow();
	}
}