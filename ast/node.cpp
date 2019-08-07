#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Support/raw_ostream.h>
#include "../ir_generator/ir_generator.hpp"
#include "../builtins/type.hpp"
#include "node.hpp"
#include <vector>
#include <memory>
#include <iostream>


llvm::Value* Node::generate()
{
    auto value =  ir_generator.generate(*this);
    
    //std::cout << "-----LLVM IR------(generator class: " << typeid(*ir_generator).name() << ")\n";
    //std::cout << "is value null?" << (value == 0) << "\n";
    //value->print(llvm::errs());
    //std::cout << std::endl;
    //std::cout << "\n------LLVM IR END------\n\n";
    
    return value;
}
llvm::Value* VariableNode::generate()
{
    //std::cout << "start gen variable." << std::endl;
    auto value =  ir_generator.generate(*this);
    //std::cout << "succes." << std::endl;
    return value;
}

llvm::Value* BinaryExpressionNode::generate()
{
    //std::cout << "start gen bin expr." << std::endl;
    auto value =  ir_generator.generate(*this);
    //std::cout << "succes." << std::endl;
    return value;
}

void FunctionNode::register_type(std::vector<std::unique_ptr<Node>> arguments)
{
    arguments_kind.push_back(std::move(arguments));
}