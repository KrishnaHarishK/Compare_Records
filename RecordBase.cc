#include "RecordBase.hh"
#include "StringUtils.hh"

#include<iostream>

/******************************************************************************
 **************************** PUBLIC METHODS **********************************
 *****************************************************************************/

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
RecordBase::RecordBase(const RecordDefinition & aRecordDefinition)
  :
  _NumberOfFields(aRecordDefinition.GetNumberOfFields()),
  _IsDelimitedRecord(aRecordDefinition.IsRecordDelimited()),
  _RecordDefinition(aRecordDefinition),
  _Key(""),
  _RecordString("")
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
RecordBase::~RecordBase()
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
std::string
RecordBase::DumpRecord() const
{
  return _RecordString;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void
RecordBase::DumpRecordToStream(std::ostream & aOutputStream) const
{
  aOutputStream<<_RecordString;  
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
const std::string &
RecordBase::GetKey() const
{
  return _Key;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
std::size_t
RecordBase::GetTextSize() const
{
  return _RecordString.length();
}

/******************************************************************************
 **************************** PROTECTED METHODS *******************************
 *****************************************************************************/

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void
RecordBase::FillFieldArray(const std::string & aRecordString)
{
  if(_IsDelimitedRecord)
  {
    FillFieldArrayDelimited(aRecordString);
  }
  else
  {
    FillFieldArrayUndelimited(aRecordString);
  }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void
RecordBase::ReadRecord(const std::string & aRecordString)
{
//  _RecordString.clear();

  _RecordString = aRecordString;

  FillFieldArray(aRecordString);

  GenerateKey();
}

/******************************************************************************
 **************************** PRIVATE METHODS ********************************
 *****************************************************************************/




