object Prijava: TPrijava
  Left = 0
  Top = 0
  Caption = 'Prijava'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 249
    Top = 24
    Width = 79
    Height = 37
    Caption = 'Prijava'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 224
    Top = 67
    Width = 81
    Height = 15
    Caption = 'Korisni'#269'ko ime:'
  end
  object Label3: TLabel
    Left = 224
    Top = 123
    Width = 43
    Height = 15
    Caption = 'Lozinka:'
  end
  object Label4: TLabel
    Left = 208
    Top = 271
    Width = 176
    Height = 15
    Caption = 'Nema'#353' ra'#269'un? Registriraj se ovdje'
  end
  object Edit1: TEdit
    Left = 224
    Top = 88
    Width = 121
    Height = 23
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 224
    Top = 144
    Width = 121
    Height = 23
    TabOrder = 1
  end
  object btnPrijava: TButton
    Left = 240
    Top = 208
    Width = 75
    Height = 25
    Caption = 'Prijavi se'
    TabOrder = 2
    OnClick = btnPrijavaClick
  end
  object btnRegistracija: TButton
    Left = 233
    Top = 292
    Width = 112
    Height = 25
    Caption = 'Registriraj se'
    TabOrder = 3
    OnClick = btnRegistracijaClick
  end
  object Button1: TButton
    Left = 197
    Top = 336
    Width = 187
    Height = 25
    Caption = 'Prijava za administratora'
    TabOrder = 4
    OnClick = Button1Click
  end
  object ComboBox1: TComboBox
    Left = 456
    Top = 39
    Width = 145
    Height = 23
    Style = csDropDownList
    ItemIndex = 0
    TabOrder = 5
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
    Left = 424
    Top = 224
  end
end
