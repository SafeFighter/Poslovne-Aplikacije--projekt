
// ***************************************************************************************************** //
//                                                                                                     
//                                          XML Data Binding                                           
//                                                                                                     
//         Generated on: 26.5.2024. 21:30:15                                                           
//       Generated from: C:\Users\matij\OneDrive\Radna površina\PoslovneA – kopija – kopija\GOTY.xml   
//   Settings stored in: C:\Users\matij\OneDrive\Radna površina\PoslovneA – kopija – kopija\GOTY.xdb   
//                                                                                                     
// ***************************************************************************************************** //

#include <System.hpp>
#pragma hdrstop

#include "GOTY.h"


// Global Functions 

_di_IXMLGamesOfTheYearType __fastcall GetGamesOfTheYear(Xml::Xmlintf::_di_IXMLDocument Doc)
{
  return (_di_IXMLGamesOfTheYearType) Doc->GetDocBinding("GamesOfTheYear", __classid(TXMLGamesOfTheYearType), TargetNamespace);
};

_di_IXMLGamesOfTheYearType __fastcall GetGamesOfTheYear(Xml::Xmldoc::TXMLDocument *Doc)
{
  Xml::Xmlintf::_di_IXMLDocument DocIntf;
  Doc->GetInterface(DocIntf);
  return GetGamesOfTheYear(DocIntf);
};

_di_IXMLGamesOfTheYearType __fastcall LoadGamesOfTheYear(const System::UnicodeString& FileName)
{
  return (_di_IXMLGamesOfTheYearType) Xml::Xmldoc::LoadXMLDocument(FileName)->GetDocBinding("GamesOfTheYear", __classid(TXMLGamesOfTheYearType), TargetNamespace);
};

_di_IXMLGamesOfTheYearType __fastcall  NewGamesOfTheYear()
{
  return (_di_IXMLGamesOfTheYearType) Xml::Xmldoc::NewXMLDocument()->GetDocBinding("GamesOfTheYear", __classid(TXMLGamesOfTheYearType), TargetNamespace);
};

// TXMLGamesOfTheYearType 

void __fastcall TXMLGamesOfTheYearType::AfterConstruction(void)
{
  RegisterChildNode(System::UnicodeString("Game"), __classid(TXMLGameType));
  ItemTag = "Game";
  ItemInterface = __uuidof(IXMLGameType);
  Xml::Xmldoc::TXMLNodeCollection::AfterConstruction();
};

_di_IXMLGameType __fastcall TXMLGamesOfTheYearType::Get_Game(const int Index)
{
  return (_di_IXMLGameType) List->Nodes[Index];
};

_di_IXMLGameType __fastcall TXMLGamesOfTheYearType::Add()
{
  return (_di_IXMLGameType) AddItem(-1);
};

_di_IXMLGameType __fastcall TXMLGamesOfTheYearType::Insert(const int Index)
{
  return (_di_IXMLGameType) AddItem(Index);
};

// TXMLGameType 

System::UnicodeString __fastcall TXMLGameType::Get_Title()
{
  return GetChildNodes()->Nodes[System::UnicodeString("Title")]->Text;
};

void __fastcall TXMLGameType::Set_Title(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("Title")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLGameType::Get_Developer()
{
  return GetChildNodes()->Nodes[System::UnicodeString("Developer")]->Text;
};

void __fastcall TXMLGameType::Set_Developer(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("Developer")]->NodeValue = Value;
};

int __fastcall TXMLGameType::Get_Year()
{
  return XmlStrToInt(GetChildNodes()->Nodes[System::UnicodeString("Year")]->Text);
};

void __fastcall TXMLGameType::Set_Year(const int Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("Year")]->NodeValue = Value;
};
