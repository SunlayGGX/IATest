#include "BehaviorTreeObject.h"

#include <iostream>
#include <typeinfo>


using namespace slgLib::IAModule::BehaviourTree;
using std::cout;
using std::endl;


int main()
{
    SequenceCModule* sequence = new SequenceCModule();
    BehaviorTreeObject myTree(*sequence);

    myTree.getRoot().connect(SequenceCModule());

    myTree.getRoot().connect(SequenceCModule());


    dynamic_cast<SequenceCModule&>(dynamic_cast<SequenceCModule&>(myTree.getRoot()).child(0)).connect(
        GeneralActionModule([]() {
            cout << "A";
            return generalModule::returnState::Success;
        })
    );

    dynamic_cast<SequenceCModule&>(dynamic_cast<SequenceCModule&>(myTree.getRoot()).child(0)).connect(
        GeneralActionModule([]() {
            cout << "B";
            return generalModule::returnState::Success;
        })
    );

    dynamic_cast<SequenceCModule&>(dynamic_cast<SequenceCModule&>(myTree.getRoot()).child(1)).connect(
        GeneralActionModule([]() {
            cout << "C";
            return generalModule::returnState::Success;
        })
    );

    dynamic_cast<SequenceCModule&>(dynamic_cast<SequenceCModule&>(myTree.getRoot()).child(1)).connect(
        GeneralActionModule([]() {
            cout << "D";
            return generalModule::returnState::Success;
        })
    );

    myTree();

    delete sequence;
}
