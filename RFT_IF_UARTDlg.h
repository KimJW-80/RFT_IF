
// RFT_IF_CANDlg.h : ��� ����
//

#pragma once

#include "afxwin.h"

////////////////////////////////////////////////////////////////////////////////
#include "RFT_IF_UART_SAMPLE_Rev1.3.h"


// for graph
#include "ChartCtrl.h"
#include "ChartLineSerie.h"
#include <vector>
using namespace std;


// CRFT_IF_CANDlg ��ȭ ����
class CRFT_IF_CANDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CRFT_IF_CANDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_RFT_IF_UART_SAMPLE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.

public:

	//////////////////////////////////////////////////////////////////////////
	// FOR GRAPH
	CChartCtrl m_ChartCtrl_Force;
	CChartCtrl m_ChartCtrl_Torque;
	CChartLineSerie *m_pGraph_F[RFT_NUM_OF_FORCE];

	vector<double> m_vGraphDatas_F[RFT_NUM_OF_FORCE];

	//////////////////////////////////////////////////////////////////////////
	// FOR RFT
	CRT_RFT_UART m_RFT_IF;

	static void callback_RFT_Data_Receive(void *callbackParam);

	//
	//////////////////////////////////////////////////////////////////////////

// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CComboBox m_combo_baudrate;
	afx_msg void OnBnClickedCheckInterfaceOpen();
	CString m_strRxData;
	afx_msg void OnBnClickedCheckBias();
	afx_msg void OnBnClickedCheckFtOutCont();
	CEdit m_nCOM_PortNumber;	
	CComboBox m_combo_Filter_Cutoff_Frq;
	afx_msg void OnBnClickedButtonFilterSetting();
	float m_fDivider_Force;
	float m_fDivider_Torque;
	afx_msg void OnBnClickedCheckDataLogging();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedConfig();
	// sensor baud rate set
	CComboBox m_cmb_cfg_baudrate;
	CComboBox m_cmb_cfg_sensor_out_rate;
	// command request & response
	CEdit m_edit_status;
	afx_msg void OnBnClickedSendCmd();
	afx_msg void OnBnClickedSetBaudrate();
	afx_msg void OnBnClickedSetOutrate();
	CComboBox m_cmb_PortNum;
	CComboBox m_combo_Filter_MovingAverage_Count;
	afx_msg void OnCbnSelchangeComboFilterType();
	afx_msg void OnEnChangeEditComPortNumber();
	int m_nCOM_PortNumbers;
//	CEdit m_nCOM_PortNumber;
};
