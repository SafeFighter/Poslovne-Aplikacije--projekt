object Preuzmi: TPreuzmi
  Left = 0
  Top = 0
  Caption = 'Preuzmi'
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
  object Label2: TLabel
    Left = 256
    Top = 40
    Width = 3
    Height = 15
  end
  object ProgressBar1: TProgressBar
    Left = 256
    Top = 88
    Width = 289
    Height = 21
    TabOrder = 0
  end
  object btnPreuzmi: TButton
    Left = 360
    Top = 115
    Width = 75
    Height = 25
    Caption = 'Preuzmi'
    TabOrder = 1
    OnClick = btnPreuzmiClick
  end
  object btnPovratak: TButton
    Left = 0
    Top = 0
    Width = 75
    Height = 25
    Caption = 'Povratak'
    TabOrder = 2
    OnClick = btnPovratakClick
  end
  object Button1: TButton
    Left = 8
    Top = 112
    Width = 75
    Height = 25
    Caption = '5 kb/s'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 89
    Top = 112
    Width = 75
    Height = 25
    Caption = '100 kb/s'
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 170
    Top = 112
    Width = 75
    Height = 25
    Caption = '500 kb/s'
    TabOrder = 5
    OnClick = Button3Click
  end
  object ComboBox1: TComboBox
    Left = 456
    Top = 8
    Width = 145
    Height = 23
    Style = csDropDownList
    ItemIndex = 0
    TabOrder = 6
    Text = 'HRV'
    OnChange = ComboBox1Change
    Items.Strings = (
      'HRV'
      'ENG')
  end
  object Preuzmi: TIdHTTP
    Intercept = IdInterceptThrottler1
    ProxyParams.BasicAuthentication = False
    ProxyParams.ProxyPort = 0
    Request.ContentLength = -1
    Request.ContentRangeEnd = -1
    Request.ContentRangeStart = -1
    Request.ContentRangeInstanceLength = -1
    Request.Accept = 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8'
    Request.BasicAuthentication = False
    Request.UserAgent = 'Mozilla/3.0 (compatible; Indy Library)'
    Request.Ranges.Units = 'bytes'
    Request.Ranges = <>
    HTTPOptions = [hoForceEncodeParams]
    Left = 224
    Top = 144
  end
  object SaveDialog1: TSaveDialog
    Left = 320
    Top = 152
  end
  object IdInterceptThrottler1: TIdInterceptThrottler
    BitsPerSec = 0
    RecvBitsPerSec = 0
    SendBitsPerSec = 0
    Left = 440
    Top = 152
  end
  object OpenSSL1: TIdSSLIOHandlerSocketOpenSSL
    Intercept = IdInterceptThrottler1
    MaxLineAction = maException
    Port = 0
    DefaultPort = 0
    SSLOptions.Mode = sslmUnassigned
    SSLOptions.VerifyMode = []
    SSLOptions.VerifyDepth = 0
    Left = 552
    Top = 144
  end
end
