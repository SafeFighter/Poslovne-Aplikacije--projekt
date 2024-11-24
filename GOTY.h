
// ***************************************************************************************************** //
//                                                                                                     
//                                          XML Data Binding                                           
//                                                                                                     
//         Generated on: 26.5.2024. 21:30:15                                                           
//       Generated from: C:\Users\matij\OneDrive\Radna površina\PoslovneA – kopija – kopija\GOTY.xml   
//   Settings stored in: C:\Users\matij\OneDrive\Radna površina\PoslovneA – kopija – kopija\GOTY.xdb   
//                                                                                                     
// ***************************************************************************************************** //

#ifndef   GOTYH
#define   GOTYH

#include <System.hpp>
#include <System.Variants.hpp>
#include <System.SysUtils.hpp>
#include <Xml.Xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.XMLDoc.hpp>
#include <XMLNodeImp.h>
#include <Xml.xmlutil.hpp>


// Forward Decls 

__interface IXMLGamesOfTheYearType;
typedef System::DelphiInterface<IXMLGamesOfTheYearType> _di_IXMLGamesOfTheYearType;
__interface IXMLGameType;
typedef System::DelphiInterface<IXMLGameType> _di_IXMLGameType;

// IXMLGamesOfTheYearType 

__interface INTERFACE_UUID("{7F6996BE-D345-41D5-BDED-F3B80F68ED0E}") IXMLGamesOfTheYearType : public Xml::Xmlintf::IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLGameType __fastcall Get_Game(const int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLGameType __fastcall Add() = 0;
  virtual _di_IXMLGameType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLGameType Game[const int Index] = { read=Get_Game };/* default */
};

// IXMLGameType 

__interface INTERFACE_UUID("{E1474D82-8BD1-4DB9-A52C-73B06E9D89E3}") IXMLGameType : public Xml::Xmlintf::IXMLNode
{
public:
  // Property Accessors 
  virtual System::UnicodeString __fastcall Get_Title() = 0;
  virtual System::UnicodeString __fastcall Get_Developer() = 0;
  virtual int __fastcall Get_Year() = 0;
  virtual void __fastcall Set_Title(const System::UnicodeString Value) = 0;
  virtual void __fastcall Set_Developer(const System::UnicodeString Value) = 0;
  virtual void __fastcall Set_Year(const int Value) = 0;
  // Methods & Properties 
  __property System::UnicodeString Title = { read=Get_Title, write=Set_Title };
  __property System::UnicodeString Developer = { read=Get_Developer, write=Set_Developer };
  __property int Year = { read=Get_Year, write=Set_Year };
};

// Forward Decls 

class TXMLGamesOfTheYearType;
class TXMLGameType;

// TXMLGamesOfTheYearType 

class TXMLGamesOfTheYearType : public Xml::Xmldoc::TXMLNodeCollection, public IXMLGamesOfTheYearType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLGamesOfTheYearType 
  virtual _di_IXMLGameType __fastcall Get_Game(const int Index);
  virtual _di_IXMLGameType __fastcall Add();
  virtual _di_IXMLGameType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};

// TXMLGameType 

class TXMLGameType : public Xml::Xmldoc::TXMLNode, public IXMLGameType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLGameType 
  virtual System::UnicodeString __fastcall Get_Title();
  virtual System::UnicodeString __fastcall Get_Developer();
  virtual int __fastcall Get_Year();
  virtual void __fastcall Set_Title(const System::UnicodeString Value);
  virtual void __fastcall Set_Developer(const System::UnicodeString Value);
  virtual void __fastcall Set_Year(const int Value);
};

// Global Functions 

_di_IXMLGamesOfTheYearType __fastcall GetGamesOfTheYear(Xml::Xmlintf::_di_IXMLDocument Doc);
_di_IXMLGamesOfTheYearType __fastcall GetGamesOfTheYear(Xml::Xmldoc::TXMLDocument *Doc);
_di_IXMLGamesOfTheYearType __fastcall LoadGamesOfTheYear(const System::UnicodeString& FileName);
_di_IXMLGamesOfTheYearType __fastcall  NewGamesOfTheYear();

#define TargetNamespace ""

#endif