#include "graphedge.h"
#include "graphnode.h"
#include <iostream>
GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    //delete _chatBot;

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{
    //task4 change 2
    
    _childEdges.emplace_back(std::move( std::unique_ptr<GraphEdge>(edge) ));
    edge = nullptr;
}
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    //task4 change 2
    
    _childEdges.emplace_back(std::move( edge ));
    //edge = nullptr;
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot *chatbot)
{
    //_chatBot = chatbot;//shallow copy causing crush
    //_chatBot->SetCurrentNode(this);
}
void GraphNode::MoveChatbotHere(std::unique_ptr<ChatBot> chatbot)
{
    _chatBot = std::move(chatbot);
    _chatBot->SetCurrentNode(this);
}
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    std::cout << chatbot.getChatLogic() << std::endl;
    _ChatBotInst = std::move(chatbot);
    _ChatBotInst.SetCurrentNode(this);
}


void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    //newNode->MoveChatbotHere(std::move(_chatBot));
    newNode->MoveChatbotHere(std::move(_ChatBotInst));
    //_chatBot = nullptr; // invalidate pointer at source
    
}

////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}
