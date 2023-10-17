object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 762
  ClientWidth = 809
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 8
    Top = 614
    Width = 75
    Height = 25
    Caption = 'Connect'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 645
    Width = 75
    Height = 25
    Caption = 'Query'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 170
    Top = 614
    Width = 75
    Height = 25
    Caption = 'Open'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 251
    Top = 614
    Width = 75
    Height = 25
    Caption = #54260#45908#49440#53469
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 332
    Top = 614
    Width = 75
    Height = 25
    Caption = 'DB Insert'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 8
    Top = 677
    Width = 75
    Height = 25
    Caption = #50672#44208#49345#53468#54869#51064
    TabOrder = 5
    OnClick = Button6Click
  end
  object PageControl1: TPageControl
    Left = 8
    Top = 8
    Width = 800
    Height = 600
    ActivePage = TabSheet1
    TabOrder = 6
    object TabSheet1: TTabSheet
      Caption = 'TabSheet1'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 792
        Height = 570
        Align = alClient
        ReadOnly = True
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'TabSheet2'
      ImageIndex = 1
      object DBGrid1: TDBGrid
        Left = 0
        Top = 0
        Width = 792
        Height = 570
        Align = alClient
        DataSource = DataSource1
        Options = [dgEditing, dgAlwaysShowEditor, dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -12
        TitleFont.Name = 'Segoe UI'
        TitleFont.Style = []
      end
    end
  end
  object Button7: TButton
    Left = 647
    Top = 703
    Width = 75
    Height = 25
    Caption = #45216#51676#48320#44221
    TabOrder = 7
    OnClick = Button7Click
  end
  object Edit1: TEdit
    Left = 344
    Top = 704
    Width = 297
    Height = 23
    TabOrder = 8
  end
  object Button8: TButton
    Left = 8
    Top = 708
    Width = 75
    Height = 25
    Caption = #45216#51676#54869#51064
    TabOrder = 9
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 332
    Top = 645
    Width = 75
    Height = 25
    Caption = 'CSV '#48320#54872
    TabOrder = 10
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 413
    Top = 614
    Width = 172
    Height = 25
    Caption = 'DB Insert by Transaction'
    TabOrder = 11
    OnClick = Button10Click
  end
  object FDConnection1: TFDConnection
    Params.Strings = (
      'Database=MarketData'
      'User_Name=root'
      'Password=0213'
      'DriverID=MySQL')
    Left = 168
    Top = 144
  end
  object FDPhysMySQLDriverLink1: TFDPhysMySQLDriverLink
    VendorLib = 
      'C:\Users\Bart\Documents\Embarcadero\Studio\Projects\test01\libma' +
      'riadb.dll'
    Left = 456
    Top = 64
  end
  object DataSource1: TDataSource
    DataSet = FDQuery1
    Left = 520
    Top = 64
  end
  object FDQuery1: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'SELECT * FROM employees;')
    Left = 568
    Top = 64
  end
  object OpenDialog1: TOpenDialog
    Options = [ofReadOnly, ofHideReadOnly, ofEnableSizing]
    Left = 280
    Top = 80
  end
  object FolderOpenDialog: TFileOpenDialog
    FavoriteLinks = <>
    FileTypes = <>
    Options = []
    Left = 176
    Top = 72
  end
end
