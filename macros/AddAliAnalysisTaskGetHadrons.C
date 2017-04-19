// #include "AliAnalysisTaskGetHadrons.h"

AliAnalysisTaskGetHadrons *AddAliAnalysisTaskGetHadrons(TString name = "AliAnalysisTaskGetHadrons")
{
  AliAnalysisManager *mgr = AliAnalysisManager::GetAnalysisManager();

  //creae a subfolder in the file
  TString filename = mgr->GetCommonFileName(); 
  filename += ":AliAnalysisTaskGetHadrons";

  //Create an instance of your task
  AliAnalysisTaskGetHadrons *task = new AliAnalysisTaskGetHadrons(name.Data());

  mgr->AddTask(task);//add task to manager
  mgr->ConnectInput(task, 0, mgr->GetCommonInputContainer()); //add manager to your task
  mgr->ConnectOutput(task, 1, mgr->CreateContainer("histogram", TList::Class(), AliAnalysisManager::kOutputContainer, filename.Data())); // same for the output
  
  return task;//return a pointer to your class
}
