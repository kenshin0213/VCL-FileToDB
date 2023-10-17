//---------------------------------------------------------------------------

#include <vcl.h>
#include <System.SysUtils.hpp>
#include <DateUtils.hpp>
#pragma hdrstop

#include "Unit1.h"
#include "FileCtrl.hpp"

#include "include/trio_inv.h"
#include "include/trio_ord.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	TodayDate = Now().FormatString("yyyymmdd");
	WriteLog("Date: " + TodayDate);
	FDQuery1->SQL->Clear();
}
//---------------------------------------------------------------------------

AnsiString TForm1::GetCurTime()
{
	AnsiString curTime = Now().FormatString("hh:nn:ss.zzz");
	return curTime;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::WriteLog(const AnsiString &_msg)
{
	if(_msg.Length() != 0) {
		Memo1->Lines->Add("[" + GetCurTime() + "] " + _msg);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MakeInsertQry(char *_pRawData, const AnsiString &_trCode, const unsigned int &_seq,  AnsiString &_qry)
{
	// 3. ������ �Ľ��ؼ� sql�� �����
	char *pData = _pRawData + 3;

	if (_trCode == "j8")  {

		Tj8OutBlock* pSiseData = (Tj8OutBlock*)pData;

		_qry.sprintf("INSERT INTO %s VALUES ('%d','%s'\
					  ,'%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s'\
					  ,'%.*s','%.*s','%.*s','%c'  ,'%.*s','%.*s','%.*s','%.*s');" // ����: char �� _movolume ����

					, _trCode.c_str()
					, _seq                         , TodayDate.c_str()
					, sizeof(pSiseData->code	 ), pSiseData->code
					, sizeof(pSiseData->time	 ), pSiseData->time
					, sizeof(pSiseData->sign	 ), pSiseData->sign
					, sizeof(pSiseData->change	 ), pSiseData->change
					, sizeof(pSiseData->price	 ), pSiseData->price
					, sizeof(pSiseData->chrate	 ), pSiseData->chrate
					, sizeof(pSiseData->high	 ), pSiseData->high
					, sizeof(pSiseData->low		 ), pSiseData->low
					, sizeof(pSiseData->offer	 ), pSiseData->offer
					, sizeof(pSiseData->bid		 ), pSiseData->bid
					, sizeof(pSiseData->volume	 ), pSiseData->volume
					, sizeof(pSiseData->volrate	 ), pSiseData->volrate
					, sizeof(pSiseData->movolume ), pSiseData->movolume
					, pSiseData->_movolume
					, sizeof(pSiseData->value	 ), pSiseData->value
					, sizeof(pSiseData->open	 ), pSiseData->open
					, sizeof(pSiseData->avgprice ), pSiseData->avgprice
					, sizeof(pSiseData->janggubun), pSiseData->janggubun
					);
	}
	else if (_trCode == "k8"){
		Tk8OutBlock* pSiseData = (Tk8OutBlock*)pData;

		_qry.sprintf("INSERT INTO %s VALUES ('%d','%s'\
					  ,'%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s'\
					  ,'%.*s','%.*s','%.*s','%c'  ,'%.*s','%.*s','%.*s','%.*s');" // ����: char �� _movolume ����

					, _trCode.c_str()
					, _seq                        , TodayDate.c_str()
					, sizeof(pSiseData->code	 ), pSiseData->code
					, sizeof(pSiseData->time	 ), pSiseData->time
					, sizeof(pSiseData->sign	 ), pSiseData->sign
					, sizeof(pSiseData->change	 ), pSiseData->change
					, sizeof(pSiseData->price	 ), pSiseData->price
					, sizeof(pSiseData->chrate	 ), pSiseData->chrate
					, sizeof(pSiseData->high	 ), pSiseData->high
					, sizeof(pSiseData->low		 ), pSiseData->low
					, sizeof(pSiseData->offer	 ), pSiseData->offer
					, sizeof(pSiseData->bid		 ), pSiseData->bid
					, sizeof(pSiseData->volume	 ), pSiseData->volume
					, sizeof(pSiseData->volrate	 ), pSiseData->volrate
					, sizeof(pSiseData->movolume ), pSiseData->movolume
					, pSiseData->_movolume
					, sizeof(pSiseData->value	 ), pSiseData->value
					, sizeof(pSiseData->open	 ), pSiseData->open
					, sizeof(pSiseData->avgprice ), pSiseData->avgprice
					, sizeof(pSiseData->janggubun), pSiseData->janggubun
					);
	}

	else if ((_trCode == "h1") || (_trCode == "k3")) {
		Th1OutBlock* pSiseData = (Th1OutBlock*)pData;

		_qry.sprintf("INSERT INTO %s VALUES ('%d','%s'\
					  ,'%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s'\
					  ,'%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s'\
					  ,'%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s'\
					  ,'%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s','%.*s'\
					  ,'%.*s','%.*s','%.*s','%.*s','%.*s');"

					, _trCode.c_str()
					, _seq							 ,TodayDate.c_str()
					, sizeof(pSiseData->code        ), pSiseData->code
					, sizeof(pSiseData->hotime 		), pSiseData->hotime
					, sizeof(pSiseData->offer       ), pSiseData->offer
					, sizeof(pSiseData->bid         ), pSiseData->bid
					, sizeof(pSiseData->offerrem    ), pSiseData->offerrem
					, sizeof(pSiseData->bidrem      ), pSiseData->bidrem
					, sizeof(pSiseData->P_offer     ), pSiseData->P_offer
					, sizeof(pSiseData->P_bid       ), pSiseData->P_bid
					, sizeof(pSiseData->P_offerrem  ), pSiseData->P_offerrem
					, sizeof(pSiseData->P_bidrem    ), pSiseData->P_bidrem
					, sizeof(pSiseData->S_offer     ), pSiseData->S_offer
					, sizeof(pSiseData->S_bid       ), pSiseData->S_bid
					, sizeof(pSiseData->S_offerrem  ), pSiseData->S_offerrem
					, sizeof(pSiseData->S_bidrem    ), pSiseData->S_bidrem
					, sizeof(pSiseData->S4_offer    ), pSiseData->S4_offer
					, sizeof(pSiseData->S4_bid      ), pSiseData->S4_bid
					, sizeof(pSiseData->S4_offerrem ), pSiseData->S4_offerrem
					, sizeof(pSiseData->S4_bidrem   ), pSiseData->S4_bidrem
					, sizeof(pSiseData->S5_offer    ), pSiseData->S5_offer
					, sizeof(pSiseData->S5_bid      ), pSiseData->S5_bid
					, sizeof(pSiseData->S5_offerrem ), pSiseData->S5_offerrem
					, sizeof(pSiseData->S5_bidrem   ), pSiseData->S5_bidrem
					, sizeof(pSiseData->T_offerrem  ), pSiseData->T_offerrem
					, sizeof(pSiseData->T_bidrem    ), pSiseData->T_bidrem
					, sizeof(pSiseData->S6_offer    ), pSiseData->S6_offer
					, sizeof(pSiseData->S6_bid      ), pSiseData->S6_bid
					, sizeof(pSiseData->S6_offerrem ), pSiseData->S6_offerrem
					, sizeof(pSiseData->S6_bidrem   ), pSiseData->S6_bidrem
					, sizeof(pSiseData->S7_offer    ), pSiseData->S7_offer
					, sizeof(pSiseData->S7_bid      ), pSiseData->S7_bid
					, sizeof(pSiseData->S7_offerrem ), pSiseData->S7_offerrem
					, sizeof(pSiseData->S7_bidrem   ), pSiseData->S7_bidrem
					, sizeof(pSiseData->S8_offer    ), pSiseData->S8_offer
					, sizeof(pSiseData->S8_bid      ), pSiseData->S8_bid
					, sizeof(pSiseData->S8_offerrem ), pSiseData->S8_offerrem
					, sizeof(pSiseData->S8_bidrem   ), pSiseData->S8_bidrem
					, sizeof(pSiseData->S9_offer    ), pSiseData->S9_offer
					, sizeof(pSiseData->S9_bid      ), pSiseData->S9_bid
					, sizeof(pSiseData->S9_offerrem ), pSiseData->S9_offerrem
					, sizeof(pSiseData->S9_bidrem   ), pSiseData->S9_bidrem
					, sizeof(pSiseData->S10_offer   ), pSiseData->S10_offer
					, sizeof(pSiseData->S10_bid     ), pSiseData->S10_bid
					, sizeof(pSiseData->S10_offerrem), pSiseData->S10_offerrem
					, sizeof(pSiseData->S10_bidrem  ), pSiseData->S10_bidrem
					, sizeof(pSiseData->volume      ), pSiseData->volume
					);
	}
	else {
		// ���� ó��
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ExcuteQry(const AnsiString &_qry)
{
	FDQuery1->SQL->Text = _qry;

	try {
	// SQL �� ����
		FDQuery1->ExecSQL();
		//ShowMessage("SQL �� ���� ����!");
	} catch (Exception &e) {
		WriteLog("INSERT SQL �� ���� �� ���� �߻�: " + e.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DeleteTable(const AnsiString &_trCode, const AnsiString &_symbol)
{
	AnsiString deleteQry;
	deleteQry.sprintf("DELETE FROM %s \
					   WHERE DATE = '%s' \
					   AND   CODE = '%s';", _trCode.c_str(), TodayDate.c_str(), _symbol.c_str());

	FDQuery1->SQL->Text = deleteQry;
	try {
	// SQL �� ����
		FDQuery1->ExecSQL();
		//ShowMessage("SQL �� ���� ����!");
	} catch (Exception &e) {
		WriteLog(_trCode + " ���̺� ������ ���� �߻�: " + e.Message);
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CreateFolder(const UnicodeString &_folderPath)
{
     try
    {
		// ���� ���� �Լ� ȣ��
		ForceDirectories(_folderPath);

		ShowMessage(L"������ ���������� �����Ǿ����ϴ�.");
	}
	catch (Exception &e)
    {
		ShowMessage(L"���� ���� �� ���� �߻�: " + e.Message);
	}
}
//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
void __fastcall TForm1::MakeCsvFile()
{
	int vectorIdx = 0;

	UnicodeString csvFolderPath = Path + "\\csv";
	CreateFolder(csvFolderPath);

	for (const UnicodeString& fileName : vFileList) {

		TStringList* stringList = new TStringList();
		TStringList* csvStringList = new TStringList();
		++vectorIdx;

		try {
			UnicodeString fileFullName = Path + "\\" + fileName;
			stringList->LoadFromFile(fileFullName);
			AnsiString csvStr;

			AnsiString symbol = fileName.SubString(1, 6);
			AnsiString logMsg;
			logMsg.sprintf("%d: %s", vectorIdx, symbol.c_str());
			WriteLog(logMsg);

			if (stringList->Count != 0) {
				// ù 2�ڸ��� h1/k3/j8/k8 ���� ��� ����
				AnsiString trCode = stringList->Strings[0].SubString(0,2);
				// table�� ���� ��¥ ������ ����.
				DeleteTable(trCode, symbol);

				for (int i = 0; i < stringList->Count; ++i) {
					// 2. ���� ������ ���پ� �б� , data = stringList->Strings[i];
					// 3. ������ �Ľ��ؼ� sql�� �����
					MakeInsertQry(((AnsiString)stringList->Strings[i]).c_str(), trCode, i+1, csvStr);
					csvStringList->Add(csvStr);
				}
				// ���Ͽ� �ֱ�
				AnsiString tobeFileName = csvFolderPath + "\\" + symbol + ".csv";
				csvStringList->SaveToFile(tobeFileName);

				Application->ProcessMessages();
			}
		} catch (const Exception &e)
		{
			UnicodeString msg = "Error" + e.Message;
			WriteLog(msg);
		}
		delete stringList;
		delete csvStringList;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ConvertToCSV(char *_pRawData, const AnsiString &_trCode, const unsigned int &_seq,  AnsiString &_qry)
{
	char *pData = _pRawData + 3;

	if (_trCode == "j8")  {

		Tj8OutBlock* pSiseData = (Tj8OutBlock*)pData;

		_qry.sprintf("('%d,','%s,'\
					  ,'%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,'\
					  ,'%.*s,','%.*s,','%.*s,','%c,'  ,'%.*s,','%.*s,','%.*s,','%.*s');" // ����: char �� _movolume ����

					, _seq                         , TodayDate.c_str()
					, sizeof(pSiseData->code	 ), pSiseData->code
					, sizeof(pSiseData->time	 ), pSiseData->time
					, sizeof(pSiseData->sign	 ), pSiseData->sign
					, sizeof(pSiseData->change	 ), pSiseData->change
					, sizeof(pSiseData->price	 ), pSiseData->price
					, sizeof(pSiseData->chrate	 ), pSiseData->chrate
					, sizeof(pSiseData->high	 ), pSiseData->high
					, sizeof(pSiseData->low		 ), pSiseData->low
					, sizeof(pSiseData->offer	 ), pSiseData->offer
					, sizeof(pSiseData->bid		 ), pSiseData->bid
					, sizeof(pSiseData->volume	 ), pSiseData->volume
					, sizeof(pSiseData->volrate	 ), pSiseData->volrate
					, sizeof(pSiseData->movolume ), pSiseData->movolume
					, pSiseData->_movolume
					, sizeof(pSiseData->value	 ), pSiseData->value
					, sizeof(pSiseData->open	 ), pSiseData->open
					, sizeof(pSiseData->avgprice ), pSiseData->avgprice
					, sizeof(pSiseData->janggubun), pSiseData->janggubun
					);
	}
	else if (_trCode == "k8"){
		Tk8OutBlock* pSiseData = (Tk8OutBlock*)pData;

		_qry.sprintf("('%d,','%s,'\
					  ,'%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,'\
					  ,'%.*s,','%.*s,','%.*s,','%c,'  ,'%.*s,','%.*s,','%.*s,','%.*s');" // ����: char �� _movolume ����

					, _trCode.c_str()
					, _seq                        , TodayDate.c_str()
					, sizeof(pSiseData->code	 ), pSiseData->code
					, sizeof(pSiseData->time	 ), pSiseData->time
					, sizeof(pSiseData->sign	 ), pSiseData->sign
					, sizeof(pSiseData->change	 ), pSiseData->change
					, sizeof(pSiseData->price	 ), pSiseData->price
					, sizeof(pSiseData->chrate	 ), pSiseData->chrate
					, sizeof(pSiseData->high	 ), pSiseData->high
					, sizeof(pSiseData->low		 ), pSiseData->low
					, sizeof(pSiseData->offer	 ), pSiseData->offer
					, sizeof(pSiseData->bid		 ), pSiseData->bid
					, sizeof(pSiseData->volume	 ), pSiseData->volume
					, sizeof(pSiseData->volrate	 ), pSiseData->volrate
					, sizeof(pSiseData->movolume ), pSiseData->movolume
					, pSiseData->_movolume
					, sizeof(pSiseData->value	 ), pSiseData->value
					, sizeof(pSiseData->open	 ), pSiseData->open
					, sizeof(pSiseData->avgprice ), pSiseData->avgprice
					, sizeof(pSiseData->janggubun), pSiseData->janggubun
					);
	}

	else if ((_trCode == "h1") || (_trCode == "k3")) {
		Th1OutBlock* pSiseData = (Th1OutBlock*)pData;

		_qry.sprintf("('%d,','%s,'\
					  ,'%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,'\
					  ,'%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,'\
					  ,'%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,'\
					  ,'%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,','%.*s,'\
					  ,'%.*s,','%.*s,','%.*s,','%.*s,','%.*s');"

					, _seq							 ,TodayDate.c_str()
					, sizeof(pSiseData->code        ), pSiseData->code
					, sizeof(pSiseData->hotime 		), pSiseData->hotime
					, sizeof(pSiseData->offer       ), pSiseData->offer
					, sizeof(pSiseData->bid         ), pSiseData->bid
					, sizeof(pSiseData->offerrem    ), pSiseData->offerrem
					, sizeof(pSiseData->bidrem      ), pSiseData->bidrem
					, sizeof(pSiseData->P_offer     ), pSiseData->P_offer
					, sizeof(pSiseData->P_bid       ), pSiseData->P_bid
					, sizeof(pSiseData->P_offerrem  ), pSiseData->P_offerrem
					, sizeof(pSiseData->P_bidrem    ), pSiseData->P_bidrem
					, sizeof(pSiseData->S_offer     ), pSiseData->S_offer
					, sizeof(pSiseData->S_bid       ), pSiseData->S_bid
					, sizeof(pSiseData->S_offerrem  ), pSiseData->S_offerrem
					, sizeof(pSiseData->S_bidrem    ), pSiseData->S_bidrem
					, sizeof(pSiseData->S4_offer    ), pSiseData->S4_offer
					, sizeof(pSiseData->S4_bid      ), pSiseData->S4_bid
					, sizeof(pSiseData->S4_offerrem ), pSiseData->S4_offerrem
					, sizeof(pSiseData->S4_bidrem   ), pSiseData->S4_bidrem
					, sizeof(pSiseData->S5_offer    ), pSiseData->S5_offer
					, sizeof(pSiseData->S5_bid      ), pSiseData->S5_bid
					, sizeof(pSiseData->S5_offerrem ), pSiseData->S5_offerrem
					, sizeof(pSiseData->S5_bidrem   ), pSiseData->S5_bidrem
					, sizeof(pSiseData->T_offerrem  ), pSiseData->T_offerrem
					, sizeof(pSiseData->T_bidrem    ), pSiseData->T_bidrem
					, sizeof(pSiseData->S6_offer    ), pSiseData->S6_offer
					, sizeof(pSiseData->S6_bid      ), pSiseData->S6_bid
					, sizeof(pSiseData->S6_offerrem ), pSiseData->S6_offerrem
					, sizeof(pSiseData->S6_bidrem   ), pSiseData->S6_bidrem
					, sizeof(pSiseData->S7_offer    ), pSiseData->S7_offer
					, sizeof(pSiseData->S7_bid      ), pSiseData->S7_bid
					, sizeof(pSiseData->S7_offerrem ), pSiseData->S7_offerrem
					, sizeof(pSiseData->S7_bidrem   ), pSiseData->S7_bidrem
					, sizeof(pSiseData->S8_offer    ), pSiseData->S8_offer
					, sizeof(pSiseData->S8_bid      ), pSiseData->S8_bid
					, sizeof(pSiseData->S8_offerrem ), pSiseData->S8_offerrem
					, sizeof(pSiseData->S8_bidrem   ), pSiseData->S8_bidrem
					, sizeof(pSiseData->S9_offer    ), pSiseData->S9_offer
					, sizeof(pSiseData->S9_bid      ), pSiseData->S9_bid
					, sizeof(pSiseData->S9_offerrem ), pSiseData->S9_offerrem
					, sizeof(pSiseData->S9_bidrem   ), pSiseData->S9_bidrem
					, sizeof(pSiseData->S10_offer   ), pSiseData->S10_offer
					, sizeof(pSiseData->S10_bid     ), pSiseData->S10_bid
					, sizeof(pSiseData->S10_offerrem), pSiseData->S10_offerrem
					, sizeof(pSiseData->S10_bidrem  ), pSiseData->S10_bidrem
					, sizeof(pSiseData->volume      ), pSiseData->volume
					);
	}
	else {
		// ���� ó��
	}

}

//---------------------------------------------------------------------------
void __fastcall TForm1::SelectFolder()
{
	UnicodeString Dir;
	// SelectDirectory�� �ι�° �μ��� �ʱ��� �����ϸ� ��ȭ���� ������ �ش� ��η� ����.
	//if (SelectDirectory("Select a directory", "", Dir)){
	//TSelectDirExtOption options = TSelectDirExtOption() << sdNewUI << sdShowEdit;

	vFileList.clear();

	// SelectDirectory �Լ� ����Ҷ� �ɼ��ټ� �ִ� Ŭ���� TSelectDirExtOpts
	TSelectDirExtOpts options = TSelectDirExtOpts() << sdNewUI << sdShowEdit;
	//if (SelectDirectory("Select a directory", "C:\\Program Files", Dir, options)){
	if (SelectDirectory("Select a directory", "",  Dir, options)){
		WriteLog(Dir);

		AnsiString dir = Path = Dir;
		TSearchRec searchRec;
		if (FindFirst(Dir + "\\*.txt", faAnyFile, searchRec) == 0)
		{
			do
			{
				vFileList.push_back(AnsiString(searchRec.Name).c_str());
				//vFileList.push_back(AnsiString(dir + "\\" +searchRec.Name).c_str());
			} while (FindNext(searchRec) == 0);
			FindClose(searchRec);
		}
	}
	else{
		Memo1->Lines->Add("���� ������ ��ҵǾ����ϴ�.");
	}
}

//---------------------------------------------------------------------------
void __fastcall TForm1::DBInsert()
{
	// ���ϸ���Ʈ�� �ִ� ���ϵ��� �ϳ��� �����ͼ� ���̺� �°� �ֱ�
	// �������� ù 2�ڸ��� h1/k3/j8/k8�̰� �� ������ ���̺��� �����Ǿ� ������
	// �� 2�ڸ� ���� �������� �־ ���̺��� ��������.

	// 1. ���ϰ�������
	// ���ͷ� ����� ���� �����̳ʿ��� �ϳ��� �����;���.
	int vectorIdx = 0;
	for (const UnicodeString& fileName : vFileList) {

		TStringList* stringList = new TStringList();
		++vectorIdx;

		try {
			UnicodeString fileFullName = Path + "\\" + fileName;
			stringList->LoadFromFile(fileFullName);
			AnsiString qry;

			AnsiString symbol = fileName.SubString(1, 6);
			AnsiString logMsg;
			logMsg.sprintf("%d: %s", vectorIdx, symbol.c_str());
			WriteLog(logMsg);

			if (stringList->Count != 0) {
				// ù 2�ڸ��� h1/k3/j8/k8 ���� ��� ����
				AnsiString trCode = stringList->Strings[0].SubString(0,2);
				// table�� ���� ��¥ ������ ����.
				DeleteTable(trCode, symbol);

				for (int i = 0; i < stringList->Count; ++i) {
					// 2. ���� ������ ���پ� �б� , data = stringList->Strings[i];
					// 3. ������ �Ľ��ؼ� sql�� �����
					MakeInsertQry(((AnsiString)stringList->Strings[i]).c_str(), trCode, i+1, qry);

					// 4. DB Insert �ϱ�
					ExcuteQry(qry);
				}
				Application->ProcessMessages();
			}
		} catch (const Exception &e)
		{
			UnicodeString msg = "Error" + e.Message;
			WriteLog(msg);
		}
		delete stringList;
	}
}

//---------------------------------------------------------------------------
void __fastcall TForm1::InsertDataByTransaction()
{
	FDQuery1->SQL->Text = "ALTER TABLE j8 DISABLE KEYS;";
	FDQuery1->ExecSQL();

	FDQuery1->SQL->Text = "ALTER TABLE k8 DISABLE KEYS;";
	FDQuery1->ExecSQL();

	FDQuery1->SQL->Text = "SET unique_checks = 0;";
	FDQuery1->ExecSQL();


	// ���ͷ� ����� ���� �����̳ʿ��� �ϳ��� �����;���.
	int vectorIdx = 0;
	for (const UnicodeString& fileName : vFileList) {

		TStringList* stringList = new TStringList();
		++vectorIdx;

		try {
			stringList->LoadFromFile(fileName);
			AnsiString qry;

			AnsiString symbol = fileName.SubString(fileName.Length() - 11, 6);
			AnsiString logMsg;
			logMsg.sprintf("%d: %s", vectorIdx, symbol.c_str());
			WriteLog(logMsg);

			if (stringList->Count != 0) {
				// ù 2�ڸ��� h1/k3/j8/k8 ���� ��� ����
				AnsiString trCode = stringList->Strings[0].SubString(0,2);
				// table�� ���� ��¥ ������ ����.
				DeleteTable(trCode, symbol);
				Application->ProcessMessages();

				FDConnection1->StartTransaction();
				for (int i = 0; i < stringList->Count; ++i) {
					// 2. ���� ������ ���پ� �б� , data = stringList->Strings[i];
					// 3. ������ �Ľ��ؼ� sql�� �����
					MakeInsertQry(((AnsiString)stringList->Strings[i]).c_str(), trCode, i+1, qry);

					FDQuery1->SQL->Text = qry;
					FDQuery1->Execute();
				}
				FDConnection1->Commit();

			}
		} catch (const Exception &e)
		{
			UnicodeString msg = "Error" + e.Message;
			WriteLog(msg);
		}
//
//			}
		delete stringList;
	}

	FDQuery1->SQL->Text = "ALTER TABLE j8 ENABLE KEYS;";
	FDQuery1->ExecSQL();

	FDQuery1->SQL->Text = "ALTER TABLE k8 ENABLE KEYS;";
	FDQuery1->ExecSQL();

	FDQuery1->SQL->Text = "SET unique_checks = 1;";
	FDQuery1->ExecSQL();
}
//---------------------------------------------------------------------------



 //==========================================================================

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	FDConnection1->Open();
	Button6Click(this);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	//FDQuery1->Open();
    WriteLog(FDQuery1->SQL->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	OpenDialog1->Execute();
	{
		// ����ڰ� ������ �������� �� ������ �ڵ�
		UnicodeString selectedFilePath = OpenDialog1->FileName;
		WriteLog("������ ���� ���: " + selectedFilePath);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	SelectFolder();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	DBInsert();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	// ���� ���� Ȯ��
	if (FDConnection1->Connected) {
		WriteLog("DB ���� ����!");

	} else {
		WriteLog("DB ���� ����!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	// ��¥����
	TodayDate = Edit1->Text;
	AnsiString msg;
	msg = "��¥����: " + TodayDate;
	WriteLog(msg);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	WriteLog(TodayDate);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
	MakeCsvFile();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
	InsertDataByTransaction();
}
//---------------------------------------------------------------------------



