object DodajRecenziju: TDodajRecenziju
  Left = 0
  Top = 0
  Caption = 'DodajRecenziju'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  TextHeight = 15
  object btnSpremi: TButton
    Left = 40
    Top = 151
    Width = 75
    Height = 25
    Caption = 'Spremi'
    TabOrder = 0
    OnClick = btnSpremiClick
  end
  object Memo1: TMemo
    Left = 40
    Top = 56
    Width = 457
    Height = 89
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
  end
  object btnOdustani: TButton
    Left = 136
    Top = 151
    Width = 75
    Height = 25
    Caption = 'Odustani'
    TabOrder = 2
    OnClick = btnOdustaniClick
  end
  object ComboBox1: TComboBox
    Left = 40
    Top = 27
    Width = 145
    Height = 23
    TabOrder = 3
    OnChange = ComboBox1Change
  end
  object btnOsvjezi: TButton
    Left = 232
    Top = 151
    Width = 75
    Height = 25
    Caption = 'Osvjezi'
    TabOrder = 4
    OnClick = btnOsvjeziClick
  end
  object ComboBox2: TComboBox
    Left = 464
    Top = 8
    Width = 145
    Height = 23
    TabOrder = 5
    Text = 'HRV'
    OnChange = ComboBox2Change
    Items.Strings = (
      'HRV'
      'ENG')
  end
  object Button1: TButton
    Left = 328
    Top = 151
    Width = 75
    Height = 25
    Caption = 'Izmjeni'
    TabOrder = 6
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 422
    Top = 151
    Width = 75
    Height = 25
    Caption = 'Obri'#353'i'
    TabOrder = 7
    OnClick = Button2Click
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.ACE.OLEDB.12.0;Data Source=D:\baza1.accdb;Per' +
      'sist Security Info=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.ACE.OLEDB.12.0'
    Left = 290
    Top = 305
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM igre')
    Left = 90
    Top = 305
  end
end
