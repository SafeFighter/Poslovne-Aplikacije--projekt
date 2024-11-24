object Pocetna: TPocetna
  Left = 0
  Top = 0
  Caption = 'Pocetna'
  ClientHeight = 615
  ClientWidth = 1088
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnCreate = FormCreate
  TextHeight = 15
  object Image1: TImage
    Left = 199
    Top = 285
    Width = 137
    Height = 121
  end
  object Label1: TLabel
    Left = 207
    Top = 8
    Width = 34
    Height = 15
    Caption = 'Label1'
  end
  object Label2: TLabel
    Left = 40
    Top = 83
    Width = 59
    Height = 15
    Caption = 'Odabir igre'
  end
  object Label3: TLabel
    Left = 408
    Top = 32
    Width = 50
    Height = 15
    Caption = 'Sortiranje'
  end
  object Label4: TLabel
    Left = 559
    Top = 35
    Width = 26
    Height = 15
    Caption = 'Filtar'
  end
  object Pregled: TButton
    Left = 0
    Top = 0
    Width = 186
    Height = 25
    Caption = 'Besplatne igre na EpicGames'
    TabOrder = 0
    OnClick = PregledClick
  end
  object Button2: TButton
    Left = 655
    Top = 0
    Width = 106
    Height = 25
    Caption = 'Izmijeni adresu'
    TabOrder = 1
    OnClick = Button2Click
  end
  object btnOdjava: TButton
    Left = 870
    Top = 0
    Width = 75
    Height = 25
    Caption = 'Odjava'
    TabOrder = 2
    OnClick = btnOdjavaClick
  end
  object DBGrid1: TDBGrid
    Left = 199
    Top = 104
    Width = 618
    Height = 120
    DataSource = DIgre
    TabOrder = 3
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'ID'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Naziv'
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Datum_izlaska'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Cijena'
        Width = 60
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Slika'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Ocjena'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Zanr'
        Width = 150
        Visible = True
      end>
  end
  object ComboBox1: TComboBox
    Left = 48
    Top = 104
    Width = 145
    Height = 23
    TabOrder = 4
    OnChange = ComboBox1Change
  end
  object Memo1: TMemo
    Left = 360
    Top = 285
    Width = 329
    Height = 121
    Lines.Strings = (
      'Memo1')
    TabOrder = 5
  end
  object btnUcitajTablicu: TButton
    Left = 199
    Top = 230
    Width = 162
    Height = 25
    Caption = 'U'#269'itaj tablicu'
    TabOrder = 6
    OnClick = btnUcitajTablicuClick
  end
  object ComboBox2: TComboBox
    Left = 408
    Top = 56
    Width = 145
    Height = 23
    TabOrder = 7
    OnChange = ComboBox2Change
  end
  object btnFiltar: TButton
    Left = 774
    Top = 55
    Width = 75
    Height = 25
    Caption = 'Filtar'
    TabOrder = 8
    OnClick = btnFiltarClick
  end
  object ComboBox3: TComboBox
    Left = 559
    Top = 56
    Width = 202
    Height = 23
    TabOrder = 9
  end
  object btnResetFilter: TButton
    Left = 376
    Top = 230
    Width = 105
    Height = 25
    Caption = 'Poni'#353'ti filtar'
    TabOrder = 10
    OnClick = btnResetFilterClick
  end
  object btnReport: TButton
    Left = 504
    Top = 230
    Width = 97
    Height = 25
    Caption = 'Izvje'#353'taj'
    TabOrder = 11
    OnClick = btnReportClick
  end
  object btnPreuzmi: TButton
    Left = 280
    Top = 440
    Width = 361
    Height = 25
    Caption = 'Preuzmi Witcher pozadinu'
    TabOrder = 12
    OnClick = btnPreuzmiClick
  end
  object ComboBox4: TComboBox
    Left = 504
    Top = 1
    Width = 145
    Height = 23
    TabOrder = 13
    Text = 'HRV'
    OnChange = ComboBox4Change
    Items.Strings = (
      'HRV'
      'ENG')
  end
  object Button1: TButton
    Left = 767
    Top = 0
    Width = 97
    Height = 25
    Caption = 'Obri'#353'i ra'#269'un'
    TabOrder = 14
    OnClick = Button1Click
  end
  object DIgre: TDataSource
    DataSet = ADOQuery1
    Left = 104
    Top = 448
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.ACE.OLEDB.12.0;User ID=Admin;Data Source=D:\b' +
      'aza1.accdb;Mode=Share Deny None;Persist Security Info=False;Jet ' +
      'OLEDB:System database="";Jet OLEDB:Registry Path="";Jet OLEDB:Da' +
      'tabase Password="";Jet OLEDB:Engine Type=6;Jet OLEDB:Database Lo' +
      'cking Mode=1;Jet OLEDB:Global Partial Bulk Ops=2;Jet OLEDB:Globa' +
      'l Bulk Transactions=1;Jet OLEDB:New Database Password="";Jet OLE' +
      'DB:Create System Database=False;Jet OLEDB:Encrypt Database=False' +
      ';Jet OLEDB:Don'#39't Copy Locale on Compact=False;Jet OLEDB:Compact ' +
      'Without Replica Repair=False;Jet OLEDB:SFP=False;Jet OLEDB:Suppo' +
      'rt Complex Data=False;Jet OLEDB:Bypass UserInfo Validation=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.ACE.OLEDB.12.0'
    Left = 208
    Top = 464
  end
  object ADOQuery1: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM igre')
    Left = 40
    Top = 464
  end
  object ADOQuery2: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM recenzije')
    Left = 448
    Top = 464
  end
  object frxReport1: TfrxReport
    Version = '2023.3.4'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick, pbCopy, pbSelection]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 45151.636823171300000000
    ReportOptions.LastChange = 45151.636823171300000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 640
    Top = 440
    Datasets = <
      item
        DataSet = frxDBIgre
        DataSetName = 'frxDBIgre'
      end
      item
        DataSet = frxDBRecenzije
        DataSetName = 'frxDBDataset1'
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 210.000000000000000000
      PaperHeight = 297.000000000000000000
      PaperSize = 9
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      Frame.Typ = []
      MirrorMode = []
      object ReportTitle1: TfrxReportTitle
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 22.677180000000000000
        Top = 18.897650000000000000
        Width = 718.110700000000000000
        object frxMemoView1: TfrxMemoView
          AllowVectorExport = True
          Left = 7.559060000000000000
          Top = 3.779530000000000000
          Width = 124.724490000000000000
          Height = 18.897650000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          Frame.Typ = []
          Memo.UTF8W = (
            'Izvje'#353'taj o igrama')
        end
      end
      object MasterData1: TfrxMasterData
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 294.803340000000000000
        Top = 102.047310000000000000
        Width = 718.110700000000000000
        DataSet = frxDBIgre
        DataSetName = 'frxDBIgre'
        RowCount = 0
        object Memo2: TfrxMemoView
          AllowVectorExport = True
          Left = 7.559060000000000000
          Top = 7.559060000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'Naziv')
        end
        object frxDBIgreNaziv: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 117.165430000000000000
          Top = 11.338590000000000000
          Width = 124.724490000000000000
          Height = 18.897650000000000000
          DataField = 'Naziv'
          DataSet = frxDBIgre
          DataSetName = 'frxDBIgre'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBIgre."Naziv"]')
        end
        object Memo3: TfrxMemoView
          AllowVectorExport = True
          Left = 7.559060000000000000
          Top = 30.236240000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'Datum izlaska')
        end
        object Memo4: TfrxMemoView
          AllowVectorExport = True
          Left = 7.559060000000000000
          Top = 52.913420000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'Zanr')
        end
        object Memo5: TfrxMemoView
          AllowVectorExport = True
          Left = 7.559060000000000000
          Top = 75.590600000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'Cijena')
        end
        object Memo6: TfrxMemoView
          AllowVectorExport = True
          Left = 7.559060000000000000
          Top = 94.488250000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'Ocjena')
        end
        object frxDBIgreCijena: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 117.165430000000000000
          Top = 75.590600000000000000
          Width = 158.740260000000000000
          Height = 18.897650000000000000
          DataField = 'Cijena'
          DataSet = frxDBIgre
          DataSetName = 'frxDBIgre'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBIgre."Cijena"]')
        end
        object frxDBIgreZanr: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 117.165430000000000000
          Top = 56.692950000000000000
          Width = 124.724490000000000000
          Height = 18.897650000000000000
          DataField = 'Zanr'
          DataSet = frxDBIgre
          DataSetName = 'frxDBIgre'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBIgre."Zanr"]')
        end
        object frxDBIgreDatum_izlaska: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 117.165430000000000000
          Top = 34.015770000000000000
          Width = 143.622140000000000000
          Height = 18.897650000000000000
          DataField = 'Datum_izlaska'
          DataSet = frxDBIgre
          DataSetName = 'frxDBIgre'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBIgre."Datum_izlaska"]')
        end
        object frxDBIgreOcjena: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 117.165430000000000000
          Top = 94.488250000000000000
          Width = 79.370130000000000000
          Height = 18.897650000000000000
          DataField = 'Ocjena'
          DataSet = frxDBIgre
          DataSetName = 'frxDBIgre'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBIgre."Ocjena"]')
        end
        object Picture2: TfrxPictureView
          AllowVectorExport = True
          Left = 11.338590000000000000
          Top = 132.283550000000000000
          Width = 177.637910000000000000
          Height = 132.283550000000000000
          DataField = 'Slika'
          DataSet = frxDBIgre
          DataSetName = 'frxDBIgre'
          Frame.Typ = []
          HightQuality = False
          Transparent = False
          TransparentColor = clWhite
        end
      end
      object DetailData1: TfrxDetailData
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 52.913420000000000000
        Top = 419.527830000000000000
        Width = 718.110700000000000000
        DataSet = frxDBRecenzije
        DataSetName = 'frxDBDataset1'
        Filter = '<frxDBIgre."ID">=<frxDBDataset1."ID_igre">'
        RowCount = 0
        object frxDBDataset1Sadrzaj_recenzija: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 11.338590000000000000
          Top = 15.118120000000000000
          Width = 238.110390000000000000
          Height = 18.897650000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          DataSet = frxDBRecenzije
          DataSetName = 'frxDBDataset1'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset1."Sadrzaj_recenzija"]')
        end
      end
    end
  end
  object frxDBIgre: TfrxDBDataset
    UserName = 'frxDBIgre'
    CloseDataSource = False
    DataSet = QueryIgreReport
    BCDToCurrency = False
    DataSetOptions = []
    Left = 712
    Top = 448
  end
  object frxDBRecenzije: TfrxDBDataset
    UserName = 'frxDBDataset1'
    CloseDataSource = False
    DataSet = QueryRecenzijeReport
    BCDToCurrency = False
    DataSetOptions = []
    Left = 536
    Top = 512
  end
  object frxPDFExport1: TfrxPDFExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    DataOnly = False
    EmbedFontsIfProtected = False
    InteractiveFormsFontSubset = 'A-Z,a-z,0-9,#43-#47 '
    OpenAfterExport = False
    PrintOptimized = False
    Outline = False
    Background = False
    HTMLTags = True
    Quality = 95
    Author = 'FastReport'
    Subject = 'FastReport PDF export'
    Creator = 'FastReport'
    ProtectionFlags = [ePrint, eModify, eCopy, eAnnot]
    HideToolbar = False
    HideMenubar = False
    HideWindowUI = False
    FitWindow = False
    CenterWindow = False
    PrintScaling = False
    PdfA = False
    PDFStandard = psNone
    PDFVersion = pv17
    Left = 648
    Top = 520
  end
  object frxRTFExport1: TfrxRTFExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    DataOnly = False
    PictureType = gpPNG
    OpenAfterExport = False
    Wysiwyg = True
    Creator = 'FastReport'
    SuppressPageHeadersFooters = False
    HeaderFooterMode = hfText
    AutoSize = False
    Left = 752
    Top = 536
  end
  object QueryIgreReport: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM igre')
    Left = 296
    Top = 496
  end
  object QueryRecenzijeReport: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM recenzije')
    Left = 376
    Top = 520
  end
  object RESTClient1: TRESTClient
    Accept = 'application/json, text/plain; q=0.9, text/html;q=0.8,'
    AcceptCharset = 'utf-8, *;q=0.8'
    BaseURL = 'https://epic-free-games1.p.rapidapi.com/currentGames'
    Params = <>
    SynchronizedEvents = False
    Left = 24
    Top = 160
  end
  object RESTRequest1: TRESTRequest
    Client = RESTClient1
    Params = <>
    Response = RESTResponse1
    SynchronizedEvents = False
    Left = 32
    Top = 248
  end
  object RESTResponse1: TRESTResponse
    ContentType = 'application/json'
    Left = 32
    Top = 336
  end
  object Codec1: TCodec
    AsymetricKeySizeInBits = 1024
    AdvancedOptions2 = []
    CryptoLibrary = CryptographicLibrary1
    Left = 768
    Top = 312
    StreamCipherId = 'native.StreamToBlock'
    BlockCipherId = 'native.AES-128'
    ChainId = 'native.CBC'
  end
  object CryptographicLibrary1: TCryptographicLibrary
    Left = 856
    Top = 312
  end
  object ADOQuery3: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 888
    Top = 448
  end
end
