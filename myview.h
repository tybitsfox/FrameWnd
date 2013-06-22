#define		DEFAULT_MY_VIEW_ONE

class myview:public CWnd
{
public:
	CBitmap cbmp;
	myview(){}
	~myview(){}
	int OnCreate(LPCREATESTRUCT lpcreatestruct);
	BOOL PreCreateWindow(CREATESTRUCT &cs);
	void OnPaint();
DECLARE_MESSAGE_MAP()
};