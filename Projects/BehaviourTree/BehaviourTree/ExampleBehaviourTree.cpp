#include "BehaviorTreeObject.h"

#include <iostream>
#include <typeinfo>


using namespace slgLib::IAModule::BehaviourTree;
using std::cout;
using std::endl;


int main()
{
    /*SequenceCModule* sequence = new SequenceCModule();
    BehaviorTreeObject myTree(*sequence);*/

    BehaviorTreeObject myTree(SequenceCModule::SequenceCModule());

    myTree.connect(SequenceCModule());

    myTree.connect(SelectCModule());




    auto sayA = []() {
        cout << "A";
        return generalModule::returnState::Success;
    };

    auto sayB = []() {
        cout << "B";
        return generalModule::returnState::Success;
    };

    auto sayC = []() {
        cout << "C";
        return generalModule::returnState::Success;
    };

    auto sayD = []() {
        cout << "D";
        return generalModule::returnState::Success;
    };



    myTree.child(0).connect(
        GeneralActionModule<decltype(sayA)>(sayA)
    );

    myTree.child(0).connect(
        GeneralActionModule<decltype(sayB)>(sayB)
    );

    myTree.child(1).connect(
        FailDModule(
            GeneralActionModule<decltype(sayC)>(sayC)
        )
    );

    myTree.child(1).connect(
        GeneralActionModule<decltype(sayD)>(sayD)
    );

    myTree();

    //delete sequence;
    cout << endl;

    system("pause");
}
