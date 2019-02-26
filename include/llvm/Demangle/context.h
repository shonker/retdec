
#ifndef RETDEC_CONTEXT_H
#define RETDEC_CONTEXT_H

#include <memory>
#include <map>

#include "llvm/Demangle/StringView.h"

namespace retdec {
namespace demangler {
namespace borland {

class Node;
class TypeNode;
class BuiltInTypeNode;
class IntegralTypeNode;
class FloatTypeNode;
class CharTypeNode;
enum class ThreeStateSignness;
class PointerTypeNode;
class ReferenceTypeNode;
class NamedTypeNode;
class Qualifiers;
class NameNode;
class NestedNameNode;

class Context
{
public:
	using StringView = llvm::itanium_demangle::StringView;

	Context() = default;

	bool hasBuiltInType(
		const StringView &name, const Qualifiers &quals) const;
	std::shared_ptr<BuiltInTypeNode> getBuiltInType(
		const StringView &name,  const Qualifiers &quals) const;
	void addBuiltInType(
		const std::shared_ptr<BuiltInTypeNode> &type);

	bool hasCharType(
		const ThreeStateSignness &signness, const Qualifiers &quals) const;
	std::shared_ptr<CharTypeNode> getCharType(
		const ThreeStateSignness &signness, const Qualifiers &quals) const;
	void addCharType(
		const std::shared_ptr<CharTypeNode> &type);

	bool hasIntegralType(
		const StringView &name, bool isUnsigned, const Qualifiers &quals) const;
	std::shared_ptr<IntegralTypeNode> getIntegralType(
		const StringView &name, bool isUnsigned, const Qualifiers &quals) const;
	void addIntegralType(
		const std::shared_ptr<IntegralTypeNode> &type);

	bool hasFloatType(
		const StringView &name,  const Qualifiers &quals) const;
	std::shared_ptr<FloatTypeNode> getFloatType(
		const StringView &name,  const Qualifiers &quals) const;
	void addFloatType(
		const std::shared_ptr<FloatTypeNode> &type);

//	bool hasPointerType(
//		std::shared_ptr<Node> pointee, const Qualifiers &quals) const;
//	std::shared_ptr<PointerTypeNode> getPointerType(
//		std::shared_ptr<Node> pointee, const Qualifiers &quals) const;
//	void addPointerType(
//		const std::shared_ptr<PointerTypeNode> &type);

	bool hasReferenceType(std::shared_ptr<Node> pointee) const;
	std::shared_ptr<ReferenceTypeNode> getReferenceType(std::shared_ptr<Node> pointee) const;
	void addReferenceType(const std::shared_ptr<ReferenceTypeNode> &type);

	bool hasNamedType(
		const StringView &name, const Qualifiers &quals) const;
	std::shared_ptr<NamedTypeNode> getNamedType(
		const StringView &name, const Qualifiers &quals) const;
	void addNamedType(
		const std::shared_ptr<NamedTypeNode> &type);

	bool hasFunction(const StringView &mangled) const;
	std::shared_ptr<Node> getFunction(const StringView &mangled) const;
	void addFunction(const StringView &mangled, const std::shared_ptr<Node> &function);

//	bool hasName(const StringView &name) const;
	std::shared_ptr<NameNode> getName(const StringView &name) const;
	void addName(const std::shared_ptr<NameNode> &name);

	std::shared_ptr<NestedNameNode> getNestedName(std::shared_ptr<Node> super, std::shared_ptr<Node> name);
	void addNestedName(const std::shared_ptr<NestedNameNode> &name);

private:
	using BuiltInTypeNodes = std::map<std::tuple<std::string, bool, bool>, std::shared_ptr<BuiltInTypeNode>>;
	BuiltInTypeNodes builtInTypes;

	using CharTypeNodes = std::map<std::tuple<ThreeStateSignness, bool, bool>, std::shared_ptr<CharTypeNode>>;
	CharTypeNodes charTypes;

	using IntegralTypeNodes = std::map<std::tuple<std::string, bool, bool, bool>, std::shared_ptr<IntegralTypeNode>>;
	IntegralTypeNodes integralTypes;

//	using PointerTypeNodes = std::map<std::shared_ptr<Node>, std::shared_ptr<PointerTypeNode>>;
//	PointerTypeNodes pointerTypes;

	using ReferenceTypeNodes = std::map<std::shared_ptr<Node>, std::shared_ptr<ReferenceTypeNode>>;
	ReferenceTypeNodes referenceTypes;

	using NamedTypeNodes = std::map<std::tuple<std::string, bool, bool>, std::shared_ptr<NamedTypeNode>>;;
	NamedTypeNodes namedTypes;

	using FunctionNodes = std::map<std::string, std::shared_ptr<Node>>;
	FunctionNodes functions;

	using NameNodes = std::map<std::string, std::shared_ptr<NameNode>>;
	NameNodes nameNodes;

	using NestedNameNodes = std::map<std::tuple<std::shared_ptr<Node>, std::shared_ptr<Node>>, std::shared_ptr<NestedNameNode>>;
	NestedNameNodes nestedNameNodes;

};

}    // borland
}    // demangler
}    // retdec

#endif //RETDEC_CONTEXT_H
