#define		DEFAULT_MY_VIEW_ONE

class myview:public CWnd
{
public:
	int paintnum;
	CString g_str;
	CBitmap cbmp;
	CTreeCtrl tree;
	myview()
	{
		paintnum=0;
	}
	~myview(){}
	int OnCreate(LPCREATESTRUCT lpcreatestruct);
	BOOL PreCreateWindow(CREATESTRUCT &cs);
	void OnPaint();
	afx_msg void on_tree_chg(NMHDR *phdr,LRESULT *lresult);//树形列表控件选择改变。
DECLARE_MESSAGE_MAP()
};