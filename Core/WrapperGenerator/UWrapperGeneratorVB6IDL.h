#ifndef UWrapperGeneratorVB6IDL_H
#define UWrapperGeneratorVB6IDL_H

#include "UWrapperGenerator.h"
#include <fstream>

class UWrapperGeneratorVB6IDL : public UWrapperGenerator {
private:
    std::ofstream m_dataStream;
    std::string m_enumStrDataBuf;
    std::string m_funcStrDataBuf;
    std::string m_typeStrDataBuf;

    bool m_ignoreUnsigned;
    
public:
    UWrapperGeneratorVB6IDL(const std::string& genPath);
    virtual ~UWrapperGeneratorVB6IDL() {}

    virtual bool IsReady() override final { return m_dataStream.is_open(); };
    virtual void Start() override final;
    virtual void End() override final;

    
    void ProcessFuncDecl(clang::FunctionDecl* func); //< Process and validate (remove from list if needed) functions
    void ProcessEnumDecl(clang::EnumDecl* enumDecl); //< Process and validate (remove from list if needed) functions
    void ProcessRecordDecl(clang::RecordDecl* record); //< Process and validate (remove from list if needed) functions

    virtual void Generate();

private:
    std::string ClangBuiltinTypeToVB6Typelib(const clang::BuiltinType* type, bool* success = 0);
    std::string ClangTypeToVB6Typelib(const clang::QualType& type, bool* success, bool canHaveRef, bool* isRef = 0);
};

#endif