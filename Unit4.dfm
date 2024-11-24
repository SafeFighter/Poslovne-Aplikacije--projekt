object AdminPrijava: TAdminPrijava
  Left = 0
  Top = 0
  Caption = 'AdminPrijava'
  ClientHeight = 418
  ClientWidth = 524
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnCreate = FormCreate
  TextHeight = 15
  object userName: TLabel
    Left = 174
    Top = 67
    Width = 81
    Height = 15
    Caption = 'Korisni'#269'ko ime:'
  end
  object lozinka: TLabel
    Left = 174
    Top = 117
    Width = 43
    Height = 15
    Caption = 'Lozinka:'
  end
  object Label1: TLabel
    Left = 112
    Top = 26
    Width = 273
    Height = 35
    Caption = 'Prijava za administratora'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -25
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 174
    Top = 88
    Width = 121
    Height = 23
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 174
    Top = 138
    Width = 121
    Height = 23
    TabOrder = 1
  end
  object btnPrijava: TButton
    Left = 192
    Top = 176
    Width = 75
    Height = 25
    Caption = 'Prijavi se'
    TabOrder = 2
    OnClick = btnPrijavaClick
  end
  object Button1: TButton
    Left = 192
    Top = 216
    Width = 75
    Height = 25
    Caption = 'Povratak'
    TabOrder = 3
    OnClick = Button1Click
  end
  object ComboBox1: TComboBox
    Left = 379
    Top = 8
    Width = 145
    Height = 23
    Style = csDropDownList
    ItemIndex = 0
    TabOrder = 4
    Text = 'HRV'
    OnChange = ComboBox1Change
    Items.Strings = (
      'HRV'
      'ENG')
  end
  object FDConnection1: TFDConnection
    Params.Strings = (
      'Database=D:\baza1.accdb'
      'DriverID=MSAcc')
    Left = 418
    Top = 70
  end
end
