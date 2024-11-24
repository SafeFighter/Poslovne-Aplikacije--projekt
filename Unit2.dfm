object Registracija: TRegistracija
  Left = 0
  Top = 0
  Caption = 'Registracija'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 240
    Top = 24
    Width = 126
    Height = 35
    Caption = 'Registracija'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -25
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 195
    Top = 109
    Width = 23
    Height = 15
    Caption = 'Ime:'
  end
  object Label3: TLabel
    Left = 181
    Top = 141
    Width = 45
    Height = 15
    Caption = 'Prezime:'
  end
  object Label4: TLabel
    Left = 222
    Top = 170
    Width = 28
    Height = 15
    Caption = 'Grad:'
  end
  object Label5: TLabel
    Left = 211
    Top = 199
    Width = 39
    Height = 15
    Caption = 'Adresa:'
  end
  object Label6: TLabel
    Left = 212
    Top = 228
    Width = 38
    Height = 15
    Caption = 'Dr'#382'ava:'
  end
  object Label7: TLabel
    Left = 169
    Top = 88
    Width = 81
    Height = 15
    Caption = 'Korisni'#269'ko ime:'
  end
  object Label8: TLabel
    Left = 207
    Top = 257
    Width = 43
    Height = 15
    Caption = 'Lozinka:'
  end
  object editKorisnickoIme: TEdit
    Left = 256
    Top = 80
    Width = 121
    Height = 23
    TabOrder = 0
  end
  object editIme: TEdit
    Left = 256
    Top = 109
    Width = 121
    Height = 23
    TabOrder = 1
  end
  object editPrezime: TEdit
    Left = 256
    Top = 138
    Width = 121
    Height = 23
    TabOrder = 2
  end
  object editGrad: TEdit
    Left = 256
    Top = 167
    Width = 121
    Height = 23
    TabOrder = 3
  end
  object editAdresa: TEdit
    Left = 256
    Top = 196
    Width = 121
    Height = 23
    TabOrder = 4
  end
  object Button1: TButton
    Left = 272
    Top = 283
    Width = 75
    Height = 25
    Caption = 'Registriraj se'
    TabOrder = 5
    OnClick = Button1Click
  end
  object editLozinka: TEdit
    Left = 256
    Top = 254
    Width = 121
    Height = 23
    TabOrder = 6
  end
  object Button2: TButton
    Left = 272
    Top = 328
    Width = 75
    Height = 25
    Caption = 'Povratak'
    TabOrder = 7
    OnClick = Button2Click
  end
  object ComboBox1: TComboBox
    Left = 256
    Top = 225
    Width = 121
    Height = 23
    TabOrder = 8
    OnChange = ComboBox1Change
  end
  object ComboBox2: TComboBox
    Left = 471
    Top = 8
    Width = 145
    Height = 23
    TabOrder = 9
    Text = 'HRV'
    OnChange = ComboBox2Change
    Items.Strings = (
      'HRV'
      'ENG')
  end
  object FDConnection1: TFDConnection
    Params.Strings = (
      'Database=D:\baza1.accdb'
      'DriverID=MSAcc')
    Left = 440
    Top = 144
  end
  object Codec1: TCodec
    AsymetricKeySizeInBits = 1024
    AdvancedOptions2 = []
    CryptoLibrary = CryptographicLibrary1
    OnProgress = Codec1Progress
    Left = 448
    Top = 312
    StreamCipherId = 'native.StreamToBlock'
    BlockCipherId = 'native.AES-128'
    ChainId = 'native.CBC'
  end
  object CryptographicLibrary1: TCryptographicLibrary
    Left = 536
    Top = 312
  end
end
