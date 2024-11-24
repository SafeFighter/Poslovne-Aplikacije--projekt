object PocetnaAdmin: TPocetnaAdmin
  Left = 0
  Top = 0
  Caption = 'PocetnaAdmin'
  ClientHeight = 777
  ClientWidth = 1039
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  TextHeight = 15
  object Image1: TImage
    Left = 456
    Top = 48
    Width = 137
    Height = 120
  end
  object Label1: TLabel
    Left = 21
    Top = 249
    Width = 29
    Height = 15
    Caption = 'Naziv'
  end
  object Label3: TLabel
    Left = 17
    Top = 307
    Width = 33
    Height = 15
    Caption = 'Cijena'
  end
  object Label4: TLabel
    Left = 14
    Top = 280
    Width = 36
    Height = 15
    Caption = 'Datum'
  end
  object Label2: TLabel
    Left = 13
    Top = 336
    Width = 37
    Height = 15
    Caption = 'Ocjena'
  end
  object Label5: TLabel
    Left = 485
    Top = 304
    Width = 37
    Height = 15
    Caption = 'Ocjena'
  end
  object Label7: TLabel
    Left = 489
    Top = 275
    Width = 33
    Height = 15
    Caption = 'Cijena'
  end
  object Label8: TLabel
    Left = 493
    Top = 249
    Width = 29
    Height = 15
    Caption = 'Naziv'
  end
  object Label9: TLabel
    Left = 511
    Top = 220
    Width = 11
    Height = 15
    Caption = 'ID'
  end
  object Label6: TLabel
    Left = 706
    Top = 267
    Width = 24
    Height = 15
    Caption = 'Zanr'
  end
  object Label10: TLabel
    Left = 418
    Top = 535
    Width = 29
    Height = 15
    Caption = 'Naziv'
  end
  object Label11: TLabel
    Left = 418
    Top = 564
    Width = 53
    Height = 15
    Caption = 'Developer'
  end
  object Label12: TLabel
    Left = 418
    Top = 593
    Width = 38
    Height = 15
    Caption = 'Godina'
  end
  object Label13: TLabel
    Left = 839
    Top = 355
    Width = 29
    Height = 15
    Caption = 'Naziv'
  end
  object Label14: TLabel
    Left = 829
    Top = 384
    Width = 39
    Height = 15
    Caption = 'Izdava'#269
  end
  object Label15: TLabel
    Left = 737
    Top = 421
    Width = 131
    Height = 15
    Caption = 'Broj prodanih primjeraka'
  end
  object Label16: TLabel
    Left = 829
    Top = 442
    Width = 38
    Height = 15
    Caption = 'Godina'
  end
  object Pregled: TButton
    Left = 8
    Top = 0
    Width = 75
    Height = 25
    Caption = 'Pregled'
    TabOrder = 0
  end
  object btnProfil: TButton
    Left = 486
    Top = 0
    Width = 75
    Height = 25
    Caption = 'Profil'
    TabOrder = 1
  end
  object btnOdjava: TButton
    Left = 559
    Top = 0
    Width = 75
    Height = 25
    Caption = 'Odjava'
    TabOrder = 2
    OnClick = btnOdjavaClick
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 48
    Width = 433
    Height = 120
    DataSource = DIgre
    TabOrder = 3
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
  end
  object btnUcitajSliku: TButton
    Left = 8
    Top = 174
    Width = 75
    Height = 25
    Caption = 'Ucitaj sliku'
    TabOrder = 4
    OnClick = btnUcitajSlikuClick
  end
  object Edit1: TEdit
    Left = 56
    Top = 246
    Width = 121
    Height = 23
    TabOrder = 5
  end
  object Edit2: TEdit
    Left = 56
    Top = 304
    Width = 121
    Height = 23
    TabOrder = 6
  end
  object DateTimePicker: TDateTimePicker
    Left = 56
    Top = 275
    Width = 121
    Height = 23
    Date = 45134.000000000000000000
    Time = 0.726213784721039700
    TabOrder = 7
  end
  object btnDodaj: TButton
    Left = 56
    Top = 362
    Width = 75
    Height = 25
    Caption = 'Dodaj'
    TabOrder = 8
    OnClick = btnDodajClick
  end
  object Edit3: TEdit
    Left = 56
    Top = 333
    Width = 121
    Height = 23
    TabOrder = 9
  end
  object ComboBox1: TComboBox
    Left = 232
    Top = 246
    Width = 145
    Height = 23
    TabOrder = 10
  end
  object btnObrisi: TButton
    Left = 232
    Top = 275
    Width = 75
    Height = 25
    Caption = 'Obri'#353'i'
    TabOrder = 11
    OnClick = btnObrisiClick
  end
  object Edit4: TEdit
    Left = 528
    Top = 275
    Width = 121
    Height = 23
    TabOrder = 12
  end
  object Edit5: TEdit
    Left = 528
    Top = 246
    Width = 121
    Height = 23
    TabOrder = 13
  end
  object Edit6: TEdit
    Left = 528
    Top = 304
    Width = 121
    Height = 23
    TabOrder = 14
  end
  object ComboBox2: TComboBox
    Left = 528
    Top = 217
    Width = 121
    Height = 23
    TabOrder = 15
    OnChange = ComboBox2Change
  end
  object btnIzmijeni: TButton
    Left = 528
    Top = 336
    Width = 75
    Height = 25
    Caption = 'Izmijeni'
    TabOrder = 16
    OnClick = btnIzmijeniClick
  end
  object btnOsvjezi: TButton
    Left = 102
    Top = 174
    Width = 139
    Height = 25
    Caption = 'Osvjezi tablicu'
    TabOrder = 17
    OnClick = btnOsvjeziClick
  end
  object btnRecenzija: TButton
    Left = 272
    Top = 174
    Width = 121
    Height = 25
    Caption = 'Dodaj recenziju'
    TabOrder = 18
    OnClick = btnRecenzijaClick
  end
  object btnDodaj2: TButton
    Left = 744
    Top = 296
    Width = 89
    Height = 25
    Caption = 'Dodaj zanr'
    TabOrder = 19
    OnClick = btnDodaj2Click
  end
  object Button1: TButton
    Left = 40
    Top = 688
    Width = 75
    Height = 25
    Caption = 'Ucitaj XML'
    TabOrder = 20
    OnClick = Button1Click
  end
  object ListView1: TListView
    Left = 40
    Top = 532
    Width = 369
    Height = 150
    Columns = <>
    TabOrder = 21
    ViewStyle = vsReport
  end
  object Button2: TButton
    Left = 456
    Top = 619
    Width = 75
    Height = 25
    Caption = 'Dodaj'
    TabOrder = 22
    OnClick = Button2Click
  end
  object Edit7: TEdit
    Left = 493
    Top = 532
    Width = 121
    Height = 23
    TabOrder = 23
  end
  object Edit8: TEdit
    Left = 493
    Top = 561
    Width = 121
    Height = 23
    TabOrder = 24
  end
  object Edit9: TEdit
    Left = 493
    Top = 590
    Width = 121
    Height = 23
    TabOrder = 25
  end
  object Button3: TButton
    Left = 136
    Top = 688
    Width = 75
    Height = 25
    Caption = 'Obri'#353'i'
    TabOrder = 26
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 632
    Top = 688
    Width = 75
    Height = 25
    Caption = 'Ucitaj JSON'
    TabOrder = 27
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 713
    Top = 688
    Width = 75
    Height = 25
    Caption = 'Obrisi'
    TabOrder = 28
    OnClick = Button5Click
  end
  object Edit10: TEdit
    Left = 884
    Top = 352
    Width = 121
    Height = 23
    TabOrder = 29
  end
  object Edit11: TEdit
    Left = 884
    Top = 381
    Width = 121
    Height = 23
    TabOrder = 30
  end
  object Edit12: TEdit
    Left = 884
    Top = 410
    Width = 121
    Height = 23
    TabOrder = 31
  end
  object Edit13: TEdit
    Left = 884
    Top = 439
    Width = 121
    Height = 23
    TabOrder = 32
  end
  object ListView2: TListView
    Left = 632
    Top = 508
    Width = 373
    Height = 161
    Columns = <
      item
        AutoSize = True
        Caption = 'Title'
      end
      item
        AutoSize = True
        Caption = 'Publisher'
      end
      item
        AutoSize = True
        Caption = 'Units sold'
      end
      item
        AutoSize = True
        Caption = 'Release year'
      end>
    ReadOnly = True
    RowSelect = True
    TabOrder = 33
    ViewStyle = vsReport
  end
  object Button6: TButton
    Left = 852
    Top = 477
    Width = 75
    Height = 25
    Caption = 'Dodaj'
    TabOrder = 34
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 794
    Top = 688
    Width = 75
    Height = 25
    Caption = 'Spremi'
    TabOrder = 35
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 933
    Top = 477
    Width = 75
    Height = 25
    Caption = 'Izmijeni'
    TabOrder = 36
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 537
    Top = 619
    Width = 75
    Height = 25
    Caption = 'Izmijeni'
    TabOrder = 37
    OnClick = Button9Click
  end
  object DBLookupComboBox1: TDBLookupComboBox
    Left = 748
    Top = 267
    Width = 121
    Height = 23
    DataField = 'Zanr'
    DataSource = DIgre
    KeyField = 'Zanr'
    ListField = 'Zanr'
    ListSource = DataSource1
    TabOrder = 38
  end
  object XMLDocument1: TXMLDocument
    FileName = 
      'C:\Users\matij\OneDrive\Radna povr'#353'ina\Nova mapa\PoslovneA '#8211' kop' +
      'ija '#8211' kopija\GOTY.xml'
    Left = 405
    Top = 622
  end
  object DIgre: TDataSource
    DataSet = ADOQuery1
    Left = 152
    Top = 464
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.ACE.OLEDB.12.0;Data Source=D:\baza1.accdb;Per' +
      'sist Security Info=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.ACE.OLEDB.12.0'
    Left = 240
    Top = 456
  end
  object OpenDialog1: TOpenDialog
    Left = 352
    Top = 464
  end
  object ADOQuery1: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM igre')
    Left = 80
    Top = 456
  end
  object ADOQuery2: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM igre')
    Left = 472
    Top = 440
  end
  object ADOQuery3: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM Zanr')
    Left = 624
    Top = 440
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery3
    Left = 544
    Top = 440
  end
end
