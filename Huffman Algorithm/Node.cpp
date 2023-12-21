#include "Node.h"

float Node::GetFrequency()
{
    return pair.second;
}

std::string Node::GetValue()
{
    return pair.first;
}

char Node::GetLeafNodeValue()
{
    return pair.first.c_str()[0];
}

Node* Node::GetParent()
{
    return parent;
}

void Node::SetFrequency(float freq)
{
    pair.second = freq;
}

void Node::SetValue(std::string val)
{
    pair.first = val;
}

void Node::SetParent(Node* par)
{
    parent = par;
}

void Node::AddLeftChild(std::string value, float freq)
{
    childLeft = new Node(freq, value, this);
}

void Node::AddRightChild(std::string value, float freq)
{
    childRight = new Node(freq, value, this);
}

void Node::AddLeftChild(std::pair<std::string, float> lpair)
{
    childLeft = new Node(lpair, this);
}

void Node::AddRightChild(std::pair<std::string, float> rpair)
{
    childRight = new Node(rpair, this);
}

void Node::AddLeftChild(Node* leftChild)
{
    childLeft = leftChild;
}

void Node::AddRightChild(Node* rightChild)
{
    childRight = rightChild;
}

void Node::ChangeParent(std::string value, float freq)
{
    Node* newParent = new Node(freq, value, this->GetParent()->GetParent());
    Node* oldParent = this->GetParent();
    if (oldParent->GetParent()->GetLeftChild() == oldParent)
    {
        oldParent->GetParent()->AddLeftChild(newParent);
    }
    else {
        oldParent->GetParent()->AddRightChild(newParent);
    }

    newParent->AddLeftChild(oldParent);
}

Node* Node::GetLeftChild()
{
    return childLeft;
}

Node* Node::GetRightChild()
{
    return childRight;
}