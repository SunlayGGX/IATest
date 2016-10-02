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

    myTree.getRoot().connect(SelectCModule());


    reinterpret_cast<SequenceCModule&>(reinterpret_cast<SequenceCModule&>(myTree.getRoot()).child(0)).connect(
        GeneralActionModule([]() {
            cout << "A";
            return generalModule::returnState::Success;
        })
    );

    reinterpret_cast<SequenceCModule&>(reinterpret_cast<SequenceCModule&>(myTree.getRoot()).child(0)).connect(
        GeneralActionModule([]() {
            cout << "B";
            return generalModule::returnState::Success;
        })
    );

    reinterpret_cast<SequenceCModule&>(reinterpret_cast<SequenceCModule&>(myTree.getRoot()).child(1)).connect(
        FailDModule(
            GeneralActionModule([]() {
                cout << "C";
                return generalModule::returnState::Fail;
            })
        )
    );

    reinterpret_cast<SequenceCModule&>(reinterpret_cast<SequenceCModule&>(myTree.getRoot()).child(1)).connect(
        GeneralActionModule([]() {
            cout << "D";
            return generalModule::returnState::Success;
        })
    );

    myTree();

    delete sequence;
    cout << endl;

    system("pause");
}
