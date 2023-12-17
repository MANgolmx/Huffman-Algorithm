#include "Node.h"

int Node::GetFrequency()
{
    return pair.second;
}

std::string Node::GetValue()
{
    return pair.first;
}

Node* Node::GetParent()
{
    return parent;
}

void Node::SetFrequency(int freq)
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

void Node::AddLeftChild(std::string value, int freq)
{
    childLeft = new Node(freq, value, this);
}

void Node::AddRightChild(std::string value, int freq)
{
    childRight = new Node(freq, value, this);
}

void Node::AddLeftChild(std::pair<std::string, int> lpair)
{
    childLeft = new Node(lpair, this);
}

void Node::AddRightChild(std::pair<std::string, int> rpair)
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