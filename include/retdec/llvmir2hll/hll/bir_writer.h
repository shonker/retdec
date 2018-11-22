/**
* @file include/retdec/llvmir2hll/hll/bir_writer.h
* @brief Class for writing BIR to stdout.
* @copyright (c) 2018 Avast Software, licensed under the MIT license
*/

#ifndef RETDEC_LLVMIR2HLL_HLL_BIR_WRITER_H
#define RETDEC_LLVMIR2HLL_HLL_BIR_WRITER_H

#include <cstddef>
#include <string>

#include "retdec/llvmir2hll/ir/module.h"
#include "retdec/llvmir2hll/support/smart_ptr.h"
#include "retdec/llvmir2hll/support/types.h"
#include "retdec/llvmir2hll/support/visitor.h"

namespace retdec {
namespace llvmir2hll {

class BIRWriter: public Visitor {
public:
	BIRWriter();
	virtual ~BIRWriter() override;

	void emit(ShPtr<Module> m);

protected:
	void emitGlobals();
	void emitFunctions();
	void emitIndent(unsigned indent);
	void emitCurrentIndent();
	void emitLabel(ShPtr<Statement> stmt);

public:
	virtual void visit(ShPtr<GlobalVarDef> varDef) override;
	virtual void visit(ShPtr<Function> func) override;
	// Statements
	virtual void visit(ShPtr<AssignStmt> stmt) override;
	virtual void visit(ShPtr<BreakStmt> stmt) override;
	virtual void visit(ShPtr<CallStmt> stmt) override;
	virtual void visit(ShPtr<ContinueStmt> stmt) override;
	virtual void visit(ShPtr<EmptyStmt> stmt) override;
	virtual void visit(ShPtr<ForLoopStmt> stmt) override;
	virtual void visit(ShPtr<UForLoopStmt> stmt) override;
	virtual void visit(ShPtr<GotoStmt> stmt) override;
	virtual void visit(ShPtr<IfStmt> stmt) override;
	virtual void visit(ShPtr<ReturnStmt> stmt) override;
	virtual void visit(ShPtr<SwitchStmt> stmt) override;
	virtual void visit(ShPtr<UnreachableStmt> stmt) override;
	virtual void visit(ShPtr<VarDefStmt> stmt) override;
	virtual void visit(ShPtr<WhileLoopStmt> stmt) override;
	// Expressions
	virtual void visit(ShPtr<AddOpExpr> expr) override;
	virtual void visit(ShPtr<AddressOpExpr> expr) override;
	virtual void visit(ShPtr<AndOpExpr> expr) override;
	virtual void visit(ShPtr<ArrayIndexOpExpr> expr) override;
	virtual void visit(ShPtr<AssignOpExpr> expr) override;
	virtual void visit(ShPtr<BitAndOpExpr> expr) override;
	virtual void visit(ShPtr<BitOrOpExpr> expr) override;
	virtual void visit(ShPtr<BitShlOpExpr> expr) override;
	virtual void visit(ShPtr<BitShrOpExpr> expr) override;
	virtual void visit(ShPtr<BitXorOpExpr> expr) override;
	virtual void visit(ShPtr<CallExpr> expr) override;
	virtual void visit(ShPtr<CommaOpExpr> expr) override;
	virtual void visit(ShPtr<DerefOpExpr> expr) override;
	virtual void visit(ShPtr<DivOpExpr> expr) override;
	virtual void visit(ShPtr<EqOpExpr> expr) override;
	virtual void visit(ShPtr<GtEqOpExpr> expr) override;
	virtual void visit(ShPtr<GtOpExpr> expr) override;
	virtual void visit(ShPtr<LtEqOpExpr> expr) override;
	virtual void visit(ShPtr<LtOpExpr> expr) override;
	virtual void visit(ShPtr<ModOpExpr> expr) override;
	virtual void visit(ShPtr<MulOpExpr> expr) override;
	virtual void visit(ShPtr<NegOpExpr> expr) override;
	virtual void visit(ShPtr<NeqOpExpr> expr) override;
	virtual void visit(ShPtr<NotOpExpr> expr) override;
	virtual void visit(ShPtr<OrOpExpr> expr) override;
	virtual void visit(ShPtr<StructIndexOpExpr> expr) override;
	virtual void visit(ShPtr<SubOpExpr> expr) override;
	virtual void visit(ShPtr<TernaryOpExpr> expr) override;
	virtual void visit(ShPtr<Variable> var) override;
	// Casts
	virtual void visit(ShPtr<BitCastExpr> expr) override;
	virtual void visit(ShPtr<ExtCastExpr> expr) override;
	virtual void visit(ShPtr<FPToIntCastExpr> expr) override;
	virtual void visit(ShPtr<IntToFPCastExpr> expr) override;
	virtual void visit(ShPtr<IntToPtrCastExpr> expr) override;
	virtual void visit(ShPtr<PtrToIntCastExpr> expr) override;
	virtual void visit(ShPtr<TruncCastExpr> expr) override;
	// Constants
	virtual void visit(ShPtr<ConstArray> constant) override;
	virtual void visit(ShPtr<ConstBool> constant) override;
	virtual void visit(ShPtr<ConstFloat> constant) override;
	virtual void visit(ShPtr<ConstInt> constant) override;
	virtual void visit(ShPtr<ConstNullPointer> constant) override;
	virtual void visit(ShPtr<ConstString> constant) override;
	virtual void visit(ShPtr<ConstStruct> constant) override;
	virtual void visit(ShPtr<ConstSymbol> constant) override;
	// Types
	virtual void visit(ShPtr<ArrayType> type) override;
	virtual void visit(ShPtr<FloatType> type) override;
	virtual void visit(ShPtr<IntType> type) override;
	virtual void visit(ShPtr<PointerType> type) override;
	virtual void visit(ShPtr<StringType> type) override;
	virtual void visit(ShPtr<StructType> type) override;
	virtual void visit(ShPtr<FunctionType> type) override;
	virtual void visit(ShPtr<VoidType> type) override;
	virtual void visit(ShPtr<UnknownType> type) override;

protected:
	/// The module to be written.
	ShPtr<Module> module;

	unsigned currIndent = 0;
};

} // namespace llvmir2hll
} // namespace retdec

#endif
