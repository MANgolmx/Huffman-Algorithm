#include "Node.h"

int Node::GetFrequency()
{
    return frequency;
}

std::string Node::GetValue()
{
    return value;
}

Node* Node::GetParent()
{
    return parent;
}

void Node::SetFrequency(int freq)
{
    frequency = freq;
}

void Node::SetValue(std::string val)
{
    value = val;
}

void Node::SetParent(Node* par)
{
    parent = par;
}

void Node::AddLeftChild(std::string value, int freq)
{
    childLeft = new Node(freq, value, this);
}

void Node::AddRightChild(std::string value, int freq)
{
    childRight = new Node(freq, value, this);
}

void Node::AddLeftChild(Node* leftChild)
{
    childLeft = leftChild;
}

void Node::AddRightChild(Node* rightChild)
{
    childRight = rightChild;
}

void Node::ChangeParent(std::string value, int freq)
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