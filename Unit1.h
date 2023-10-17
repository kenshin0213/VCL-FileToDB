//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ComCtrls.hpp>

#include <vector>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TFDConnection *FDConnection1;
	TFDPhysMySQLDriverLink *FDPhysMySQLDriverLink1;
	TDataSource *DataSource1;
	TFDQuery *FDQuery1;
	TButton *Button1;
	TButton *Button2;
	TOpenDialog *OpenDialog1;
	TButton *Button3;
	TFileOpenDialog *FolderOpenDialog;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TDBGrid *DBGrid1;
	TMemo *Memo1;
	TButton *Button7;
	TEdit *Edit1;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
private:	// User declarations
	//std::vector<UnicodeString> vDirectory;
	std::vector<UnicodeString> vFileList;
	UnicodeString Path;
	std::vector<std::vector<UnicodeString>> vFileName;   // to be: 디렉토리 컨테이너와 idx 맞춰서 파일명만 관리하게끔 수정해 보자.

	void __fastcall DBInsert();
	void __fastcall InsertDataByTransaction();
	void __fastcall SelectFolder();
    void __fastcall MakeCsvFile();
	void __fastcall ConvertToCSV(char *_pRawData, const AnsiString &_trCode, const unsigned int &_seq,  AnsiString &_qry);
	void __fastcall MakeInsertQry(char *_pRawData, const AnsiString &_trCode, const unsigned int &_seq,  AnsiString &_qry);
	void __fastcall DeleteTable(const AnsiString &trCode, const AnsiString &symbol);
	void __fastcall ExcuteQry(const AnsiString &Qry);
	void __fastcall WriteLog(const AnsiString &msg);
    void __fastcall CreateFolder(const UnicodeString &folderPath);

	AnsiString GetCurTime();
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	AnsiString TodayDate;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
