
// JosephDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CJosephDlg �Ի���
class CJosephDlg : public CDialogEx
{
// ����
public:
	CJosephDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_JOSEPH_DIALOG };

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
	int m_HeadCount;
	int m_Start;
	int m_Gap;
	afx_msg void OnBnClickedJoseph();
	CString m_strText;
//	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CButton m_btn;
};
